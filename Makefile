ImplementMinStack: ImplementMinStack.o
	g++ -g -o ImplementMinStack.exe ImplementMinStack.o -pthread    

ImplementMinStack.o: ImplementMinStack/ImplementMinStack.cpp
	g++ -g  -c -pthread ImplementMinStack/ImplementMinStack.cpp
