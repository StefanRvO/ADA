COMPILER = g++#Compiler
CFLAGS = -std=c++11#Compiler Flags
CPPFILES = main.cpp
CPPFILES += Node.cpp Node.hpp
INCLUDES = -I /usr/include/libboost1.55/
OUTFILE = test
OBJECTS=$(CPPFILES:.cpp=.o)

all:
	${COMPILER} ${CPPFILES} ${INCLUDES} ${LFLAGS} ${CFLAGS} -o ${OUTFILE}
	./${OUTFILE}

clean:  rm $(OUTFILE)
