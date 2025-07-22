imobiliaria: main.o imovel.o agendador.o corretor.o cliente.o
	g++ main.o imovel.o agendador.o corretor.o cliente.o -o imobiliaria

main.o: main.cpp imovel.h corretor.h cliente.h agendador.h
	g++ -c main.cpp

agendador.o: agendador.cpp agendador.h imovel.h corretor.h
	g++ -c agendador.cpp

imovel.o: imovel.cpp imovel.h
	g++ -c imovel.cpp

corretor.o: corretor.cpp corretor.h imovel.h
	g++ -c corretor.cpp

cliente.o: cliente.cpp cliente.h
	g++ -c cliente.cpp