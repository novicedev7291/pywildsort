CC=gcc
CFLAGS=--std=c99 -Wall

LIBNAME=wildsort
BIN=bin
SRC=src
PACKAGE_DIR=package

SRCS=$(wildcard $(SRC)/*.c)
#BINS=$(patsubst $(SRC)/%.c, $(BIN)/%.o, $(SRCS))
BINS=$(SRCS, .c=.o)
PACKAGE=package

TEST=test
TESTBIN=test/bin
TESTSRCS=$(wildcard $(TEST)/*.c)
TESTBINS=$(patsubst $(TEST)/%.c, $(TESTBIN)/%.o, $(TESTSRCS))
CRITERION_H=/usr/local/Cellar/criterion/2.4.1_2/include
CRITERION_LIB=/usr/local/Cellar/criterion/2.4.1_2/lib
LIB_DIR=package/lib
INSTALL_DIR=$$HOME/.local/share/$(LIBNAME)

all: release test

$(TESTBIN):
	mkdir -p $@

$(TESTBIN)/%.o: $(TESTSRCS)
	$(CC) $(CFLAGS) $< -o $@ -I $(CRITERION_H) -L $(CRITERION_LIB) -L $(LIB_DIR) -lcriterion -lwildsort

test: $(TESTBIN) $(TESTBINS)
	for test in $(TESTBINS); do DYLD_LIBRARY_PATH=$$DYLD_LIBRARY_PATH:$$PWD/$(LIB_DIR) ./$$test ; done

$(PACKAGE_DIR):
	mkdir -p $@ $@/lib $@/include/$(LIBNAME)

LIB=libwildsort.so

$(BIN):
	mkdir -p $@

$(BIN)/%.o: $(SRC)/*.h $(SRCS) $(BIN)
	$(CC) $(CFLAGS) -c $< -o $@

release: $(SRCS) $(BINS) $(PACKAGE_DIR)
	$(CC) $(CFLAGS) -fPIC -shared $< -o $(LIB)
	mv $(LIB) $(PACKAGE_DIR)/lib
	cp $(SRC)/*.h $(PACKAGE_DIR)/include/$(LIBNAME)

install: 
	mkdir -p $(INSTALL_DIR)
	cp -R $(PACKAGE_DIR)/lib $(INSTALL_DIR)/lib
	cp -R $(PACKAGE_DIR)/include/ $(INSTALL_DIR)/include

uninstall:
	rm -rf $(INSTALL_DIR)

clean:
	rm -rf $(BIN)
	rm -rf $(PACKAGE_DIR)
	rm -rf $(TESTBIN)
