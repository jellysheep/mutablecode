# compile script for gcc using c++11 standard
# just run "make" or "make run"

CC = gcc
CXX = g++
CPPFLAGS = -g -I./include -I./src -std=c++11
LDFLAGS = -g
LDLIBS = -lstdc++

HEADERS = include/Interpreter.hpp include/Operation.hpp include/Program.hpp include/Tape.hpp
SRCS = src/main.cpp src/Interpreter.cpp
BUILDDIR = build
OBJS_TMP = $(subst .cpp,.o,$(SRCS))
OBJS = $(subst src/,$(BUILDDIR)/,$(OBJS_TMP))

BIN = $(BUILDDIR)/mutablecode

all: $(BIN)

run: all
	$(BIN)

debugrun: all
	gdb $(BIN) -ex run -ex quit

$(BIN): $(BUILDDIR)/ $(OBJS)
	$(CC) $(LDFLAGS) -o $(BIN) $(OBJS) $(LDLIBS)

$(BUILDDIR)/%.o: src/%.cpp $(HEADERS)
	$(CXX) -c $(CPPFLAGS) $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJS)

dist-clean: clean
	rm -f $(BIN)
	rm -rf $(BUILDDIR)

$(BUILDDIR)/:
	mkdir -p $(BUILDDIR)