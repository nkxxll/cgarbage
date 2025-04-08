CC=gcc
CFLAGS=-Wall -Wextra -pedantic
CPRGS=muint
BIN=../bin
LIBS=-I ../munit

all: test munit

munit: main.c filler.h snekobject.c snekobject.h
	gcc $< $(CFLAGS) -o $(BIN)/$@ $(LIBS)

.PHONY: test

test: munit
	./$BIN/munit

