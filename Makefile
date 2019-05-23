PROGRAM = data_collect
CPP = g++

CPPFLAGS = -Wall -W -std=c++11 -Wwrite-strings

LIB = -lzmq

SRC = main.cpp data_collect.cpp conf.cpp data.cpp network.cpp util.cpp json.cpp db.cpp

OBJ = $(SRC:.cpp=.o)

all: $(PROGRAM)

$(PROGRAM): $(OBJ)
	$(CPP) $(CPPFLAGS) -o $@ $(OBJ) $(LIB)

clean:
	rm -f $(PROGRAM) $(OBJ) *.o
