SourcePath = /home/zhucci/Documents/Code/Thread/source
BinPath =  /home/zhucci/Documents/Code/Thread/bin

thread: parallel sequential main
	g++  $(BinPath)/main.o $(BinPath)/parallel.o $(BinPath)/sequential.o \
		 -o $(BinPath)/thread
main: $(SourcePath)/main.cpp
	g++ -c -g $(SourcePath)/main.cpp -o $(BinPath)/main.o
sequential: $(SourcePath)/sequential.cpp
	g++ -c -g $(SourcePath)/sequential.cpp -o $(BinPath)/sequential.o
parallel: $(SourcePath)/parallel.cpp
	g++ -c -g $(SourcePath)/parallel.cpp -o $(BinPath)/parallel.o -lpthread
