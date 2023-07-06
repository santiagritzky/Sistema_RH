compilar:
	g++ -o projetolp1 main.cpp asg.cpp empresa.cpp funcionario.cpp gerente.cpp pessoa.cpp vendedor.cpp

rodar:
	./projetolp1

all:
	g++ -o projetolp1 main.cpp asg.cpp empresa.cpp funcionario.cpp gerente.cpp pessoa.cpp vendedor.cpp
	./projetolp1

limpar:
	rm projetolp1