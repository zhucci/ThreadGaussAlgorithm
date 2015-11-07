SourcePath = /home/zhucci/Documents/Labour/Thread/source
BinPath =  /home/zhucci/Documents/Labour/Thread/bin

thread: parallel sequential main
	g++  $(BinPath)/main.o $(BinPath)/parallel.o $(BinPath)/sequential.o \
		 -o $(BinPath)/thread
main: $(SourcePath)/main.cpp
	g++ -c  $(SourcePath)/main.cpp -o $(BinPath)/main.o
sequential: $(SourcePath)/sequential.cpp
	g++ -c  $(SourcePath)/main.cpp -o $(BinPath)/sequential.o
parallel: $(SourcePath)/parallel.cpp
	g++ -c  $(SourcePath)/parallel.cpp -o $(BinPath)/parallel.o -lpthread
