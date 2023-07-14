CC=gcc
CFLAGS=--std=c99 -Wall

SRC=src
BIN=bin

SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(BIN)/%.o, $(SRCS))

INCLUDE_HEADERS=-I/usr/local/Cellar/python@3.10/3.10.12_1/Frameworks/Python.framework/Versions/3.10/include/python3.10
INCLUDE_HEADERS+=-I$$HOME/.local/share/wildsort/include

LINK_LOCATION=-L/usr/local/Cellar/python@3.10/3.10.12_1/Frameworks/Python.framework/Versions/3.10/lib

all: $(OBJS)


$(BIN)/%.o: $(SRCS) $(BIN)
	$(CC) $(CFLAGS) $(INCLUDE_HEADERS) $(LINK_LOCATION) -c $< -o $@

$(BIN):
	mkdir -p $(BIN)

clean:
	rm -rf $(BIN)
