CC=g++
CFLAGS=-g -std=c++11 -Wall -pedantic
OBJS=main.o GameManager.o StateMachine.o MenuState.o HelpState.o LevelState.o Level.o Player.o Enemy.o conio.o

all: Rogue

Rogue: main.o GameManager.o StateMachine.o MenuState.o HelpState.o LevelState.o Level.o Player.o Enemy.o conio.o
	$(CC) $(CFLAGS) $(OBJS) -o Rogue

main.o: main.cpp GameManager.h
	$(CC) $(CFLAGS) -c main.cpp

GameManager.o: GameManager.cpp GameManager.h
	$(CC) $(CFLAGS) -c GameManager.cpp

StateMachine.o: StateMachine.cpp StateMachine.h State.h MenuState.h
	$(CC) $(CFLAGS) -c StateMachine.cpp

MenuState.o: MenuState.cpp MenuState.h State.h conio.h
	$(CC) $(CFLAGS) -c MenuState.cpp

HelpState.o: HelpState.cpp HelpState.h State.h conio.h
	$(CC) $(CFLAGS) -c HelpState.cpp

LevelState.o: LevelState.cpp LevelState.h Level.h
	$(CC) $(CFLAGS) -c LevelState.cpp

Level.o: Level.cpp Level.h
	$(CC) $(CFLAGS) -c Level.cpp

Player.o: Player.cpp Player.h
	$(CC) $(CFLAGS) -c Player.cpp

Enemy.o: Enemy.cpp Enemy.h
	$(CC) $(CFLAGS) -c Enemy.cpp

conio.o: conio.cpp conio.h 
	$(CC) $(CFLAGS) -c conio.cpp

clean:
	rm *.o
