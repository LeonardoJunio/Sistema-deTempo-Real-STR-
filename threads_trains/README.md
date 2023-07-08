<h1 align="center">Threads - Trains</h1>

<p align="center">Simple example of running threads with mutex, making a simple analogy to trains and tracks.</p>

<hr> 

### :hammer_and_wrench: Technologies & Concepts:

* C++ 12.2

<div align="center" style="display: inline_block">
	<img src="https://img.shields.io/static/v1?label=Cpp&message=v12.2&color=F34B7D&style=flat"/>
	<img src="https://img.shields.io/static/v1?label=license&message=MIT&color=green&style=flat"/>
</div>

### :gear: Settings:

* Launch dockerfile:
```bash
docker build -f c_cpp.Dockerfile -t my-gcc-app ./ && docker run -it --rm -v ./:/App my-gcc-app
```

* Run the following commands:
```bash
cd threads_trains/
make
./bin/app 
```

### :warning: Bugs/Improvements:

* Develop unit tests

##

<div align="center">
	<p>Made with :computer: + :heart: by Leonardo Junio</p>
</div>
