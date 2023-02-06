# this is a comment
SRC=main.cpp button.cpp keyboard.cpp wheel.cpp wheel_board.cpp venigma.cpp vsetup.cpp
OBJ=$(SRC:.cpp=.o) # replaces the .c from SRC with .o
EXE=fxenigma

CC=g++
CFLAGS=-Wall -g  `fox-config --cflags`
LDFLAGS= `fox-config --libs`
RM=rm

%.o: %.cpp         # combined w/ next line will compile recently changed .c files
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY : all     # .PHONY ignores files named all
all: $(EXE)      # all is dependent on $(EXE) to be complete

.PHONY: depend
depend:
	$(CC) -MM $(SRC) >.dependencies

.dependencies: $(SRC)
	$(CC) -MM $(SRC) >$@

include .dependencies

$(EXE): $(OBJ)   # $(EXE) is dependent on all of the files in $(OBJ) to exist
	$(CC) $(OBJ) $(LDFLAGS) -o $@

.PHONY : clean   # .PHONY ignores files named clean
clean:
	-$(RM) $(OBJ) core    # '-' causes errors not to exit the process
