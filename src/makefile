CC=g++
CFLAGS=-I
OBJS=main.o GameManager.o StateMachine.o MenuState.o HelpState.o conio.o

all: Rogue

Rogue: main.o GameManager.o StateMachine.o MenuState.o HelpState.o conio.o
	$(CC) $(OBJS) -o Rogue

main.o: main.cpp GameManager.h
	$(CC) -c main.cpp

GameManager.o: GameManager.cpp GameManager.h
	$(CC) -c GameManager.cpp

StateMachine.o: StateMachine.cpp StateMachine.h State.h MenuState.h
	$(CC) -c StateMachine.cpp

MenuState.o: MenuState.cpp MenuState.h State.h conio.h
	$(CC) -c MenuState.cpp

HelpState.o: HelpState.cpp HelpState.h State.h conio.h
	$(CC) -c HelpState.cpp

conio.o: conio.cpp conio.h 
	$(CC) -c conio.cpp

clean:
	rm *.o Rogue
