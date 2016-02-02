# Let's get into making a makefile sou you can understand a little better.
# To start off with, create a file with just this in it:
CFLAGS=-Wall -g

all: fizzbuzz  ex1 ex3

clean:
	rm -rf fizzbuzz fizzbuzz.dSYM ex1 ex1.dSYM ex3 ex3.dSYM


# Extra credit
# Create an all: ex1 target that will build ex1 with just the command make.
# Uncomment to run
#CFLAGS=-Wall -g

#all: ex1

#!#? Want to learn more?
# https://www.gnu.org/software/make/manual/make.html
