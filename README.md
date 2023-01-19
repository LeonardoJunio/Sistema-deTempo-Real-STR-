# Mini Projetos - Sistema de Tempo Real

* C++

Projetos relacionados á Disciplina de Sistema de Tempo Real


<h1 align="center">Mini Projetos - Sistema de Tempo Real</h1>

<p align="center">Projetos relacionados á Disciplina de Sistema de Tempo Real</p>

<hr> 

### :hammer_and_wrench: Tecnologias e Conceitos:

* C++ 12.2

<div align="center" style="display: inline_block">
	<img src="https://img.shields.io/static/v1?label=C++&message=v12.2&color=F34B7D&style=flat"/>
	<img src="https://img.shields.io/static/v1?label=license&message=MIT&color=green&style=flat"/>
</div>

### :gear: Configurações:

* Obs: Dockerfiles estruturados para rodar o codigo assim que executado o docker, com isso para parar a execução aparentemente só fechando o terminal.
* Rodar o dockerfile (docker build -f c_cpp.Dockerfile -t my-gcc-app ./ && docker run -it --rm my-gcc-app)
* Caso deseje rodar no modo iterativo do docker, comentar as linhas referente ao CMD e RUN. Após isso, executar:
```bash
g++ program-source-code.c -o executable-file-name
make executable-file-name (assuming that executable-file-name.cpp exists)
./executable_file_name
```

### :warning: Erros/Aprimoramentos:

* Reorganizar nomes dos arquivos
* Testar e verificar quais as funcionalidades de cada projeto (até o momento só foi verificado o 'Ordenação Tempo')
* Melhorar readme
* Melhorar código/estrutura do projeto
* Transferir para inglês(?)

##

<div align="center">
	<p>Feito com :computer: + :heart: por Leonardo Junio</p>
</div>





