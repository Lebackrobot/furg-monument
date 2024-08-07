CC=g++
SOURCE=main.cpp
BIN=code

LIBRARYS=-L/lib/x86_64-linux-gnu/ -lglut -lGLU -lGL -lm

all: clean compile

clean:
	@echo "Cleaning up..."
	rm -f ${BIN}

compile:
	$(CC) $(SOURCE) -o $(BIN) $(LIBRARYS)
