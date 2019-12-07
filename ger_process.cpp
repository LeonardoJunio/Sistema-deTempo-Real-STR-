#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <iostream>
#include <sys/time.h>
#include <sys/resource.h>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include <curses.h>
#include <math.h> 
#include <sched.h> 
#include <termio.h>
#include <unistd.h>
#include <fstream>
#include <sstream>

using namespace std;

//Ordena(sort) de acordo com o rss: resident set size e exibe 30 resultados
string info = "ps -aeo user,comm,pid,psr,pcpu,pri,ni,cputime --sort -rss | head -30";

//Pausa o processo de acordo com o pid fornecido
void pausar(int pid){
    if(!(kill(pid,SIGSTOP)))
        cout << "Processo pausado." << endl;
    else
        cout << "Erro ao pausar processo." << endl;
}

//Continua o processo de acordo com o pid fornecido
void continuar(int pid){
    if(!(kill(pid,SIGCONT)))
        cout << "Processo continuado." << endl;
    else
        cout << "Erro ao continuar processo." << endl;
}

//Para/finaliza o processo de acordo com o pid fornecido
void parar(int pid){
    if(!(kill(pid,SIGKILL)))
        cout << "Processo finalizado." << endl;
    else
        cout << "Erro ao finalizar processo." << endl;
}

//Muda o processador de execucao do processo de acordo com o pid fornecido
//Para alterar mais rapido, aconselha pausar, mudar cpu e depois continuar o processo
//Caso nao seja feito isso, talvez leva mais tempo para a troca, mas a mesma é realizada também
void mudar_cpu(int pid){
    int cpu;
    cpu_set_t mask;

    cout << "Escolha uma CPU para assumir o processo: ";
    cin >> cpu;

    CPU_ZERO(&mask);
    CPU_SET(cpu, &mask);

    if((sched_setaffinity(pid, sizeof(mask), &mask)) == 0)
        cout << "Processador de execução trocado." << endl;
    else
        cout << "Operacao invalida." << endl;
}

//Muda a prioridade de execucao do processo de acordo com o pid fornecido
//Digitar um valor que subtraia a prioridade atual, por exemplo:
//Processo com prioridade=19, valor_escolhido=5, entao nova_prioridade será 14
void mudar_prioridade(int pid){
    int prioridade;

    cout << "Defina uma nova prioridade para o processo: ";
    cin >> prioridade;

    if(!(setpriority(PRIO_PROCESS, pid, prioridade) == -1))
        cout << "Prioridade alterada com sucesso." << endl;
    else
        cout << "Erro ao setar nova prioridade." << endl;
}

//Exibe um processo de acordo com o filtro(nome do processo) selecionado
void filtro(){
    string filtro;

    cout << "Digite uma palavra-chave para a busca: ";
    cin >> filtro;

    cout << endl << "Resultado: " << endl;
    system((info + " | grep " + filtro).c_str());
    //Adicionado o comando abaixo para aguardar o usuario digitar enter
    //Pois se não, exibe a informçao muito rapidamente.
    system("read -p \"Pressione enter para sair\" saindo");
}

int main(){
    int opcao;
    pid_t pid;

    do{
        //Exibe as informações dos processos no inicio de cada escolha
        system(info.c_str());

        cout << "MENU: 1-Pausar; 2-Continuar; 3-Parar; 4-Mudar CPU; 5-Mudar Prioridade; 6-Filtrar; 0-Sair" << endl;
        cout << "Escolha uma opção valida: ";
        cin >> opcao;

        while(opcao>6 || opcao<0){
            cout << "Operação inválida, digite novamente." << endl;
            cin >> opcao;
        }
        
        if(opcao < 6 && opcao != 0){
            cout << "Digite o PID do processo: " << endl;
            cin >> pid;
        }
        
        switch(opcao){
            case 0:
                cout << "Finalizando Programa." << endl; 
                break;
            case 1:
                pausar(pid);
                filtro();
                break;
            case 2:
                continuar(pid);
                filtro();
                break;
            case 3:
                parar(pid);
                filtro();
                break;
            case 4: 
                mudar_cpu(pid);
                filtro();
                break;
            case 5:
                mudar_prioridade(pid);
                filtro();
                break;              
            case 6:
                filtro();
                break;            
            default:
                cout << "Algum erro aconteceu." << endl; 
                break;
        }
    }while(opcao!=0);

    return 0;
}
        
