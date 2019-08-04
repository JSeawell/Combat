# Makefile for Project#3

# Name: Jake Seawell
# Date: 10/23/18
# Description: This Makefile shows all the files
# necessary to compile and run the executable
# file "FantasyCombat", for CS162 Project#3.

CXX = g++
CXXFLAGS = -std=c++0x
//CXXFLAGS += -g

OBJS = Character.o Barbarian.o Vampire.o BlueMen.o Medusa.o HarryPotter.o choiceFunction.o Menu.o intVal.o
SRCS = Character.cpp Barbarian.cpp Vampire.cpp BlueMen.cpp Medusa.cpp HarryPotter.cpp choiceFunction.cpp Menu.cpp intVal.cpp Combat_Main.cpp
HDRS = Character.hpp Barbarian.hpp Vampire.hpp BlueMen.hpp Medusa.hpp HarryPotter.hpp choiceFunction.hpp Menu.hpp intVal.hpp


FantasyCombat: Character.o Barbarian.o Vampire.o BlueMen.o Medusa.o HarryPotter.o choiceFunction.o Menu.o intVal.o Combat_Main.cpp
	${CXX} ${CXXFLAGS} ${OBJS} Combat_Main.cpp -o FantasyCombat

Character.o: Character.cpp Character.hpp
	${CXX} ${CXXFLAGS} -c Character.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp
	${CXX} ${CXXFLAGS} -c Barbarian.cpp

Vampire.o: Vampire.cpp Vampire.hpp
	${CXX} ${CXXFLAGS} -c Vampire.cpp

BlueMen.o: BlueMen.cpp BlueMen.hpp
	${CXX} ${CXXFLAGS} -c BlueMen.cpp

Medusa.o: Medusa.cpp Medusa.hpp
	${CXX} ${CXXFLAGS} -c Medusa.cpp

HarryPotter.o: HarryPotter.cpp HarryPotter.hpp
	${CXX} ${CXXFLAGS} -c HarryPotter.cpp

choiceFunction.o: choiceFunction.cpp choiceFunction.hpp
	${CXX} ${CXXFLAGS} -c choiceFunction.cpp

Menu.o: Menu.cpp Menu.hpp
	${CXX} ${CXXFLAGS} -c Menu.cpp

intVal.o: intVal.cpp intVal.hpp
	${CXX} ${CXXFLAGS} -c intVal.cpp

clean:
	rm *.o FantasyCombat

#target(what to create): dependencies(what is used to make)
#(tab)action(rule to build)
