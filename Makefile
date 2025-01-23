tum: derleme calistirma

derleme:
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/ListeDugum.o -c ./src/ListeDugum.cpp
	g++ -I ./include/ -o ./lib/Liste.o -c ./src/Liste.cpp
	g++ -I ./include/ -o ./lib/IkiliAramaAgaci.o -c ./src/IkiliAramaAgaci.cpp
	g++ -I ./include/ -o ./bin/program ./lib/Dugum.o ./lib/ListeDugum.o ./lib/Liste.o ./lib/IkiliAramaAgaci.o ./src/main.cpp

calistirma:
	cls
	./bin/program
