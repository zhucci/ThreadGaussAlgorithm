SourcePath = /home/zhucci/Documents/Code/Thread/source
BinPath =  /home/zhucci/Documents/Code/Thread/bin

thread: $(BinPath)/parallel.o $(BinPath)/sequential.o $(BinPath)/main.o
	g++  $(BinPath)/main.o $(BinPath)/parallel.o $(BinPath)/sequential.o \
		 -o $(BinPath)/thread -lpthread
$(BinPath)/main.o: $(SourcePath)/main.cpp
	g++ -c -g $(SourcePath)/main.cpp -o $(BinPath)/main.o
$(BinPath)/sequential.o: $(SourcePath)/sequential.cpp
	g++ -c -g $(SourcePath)/sequential.cpp -o $(BinPath)/sequential.o
$(BinPath)/parallel.o: $(SourcePath)/parallel.cpp
	g++ -c -g $(SourcePath)/parallel.cpp -o $(BinPath)/parallel.o -lpthread
