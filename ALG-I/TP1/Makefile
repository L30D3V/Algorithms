CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -g

SRCS =  tp1.cpp
OBJS = ${SRCS:.cpp=.o}

MAIN = tp1.exe

all: ${MAIN}
	@echo   Blackjack TP has been compiled succesfully

${MAIN}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${MAIN}

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	${RM} ${PROGS} ${OBJS} *.o *~.