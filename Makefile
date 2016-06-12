# Let's get into making a makefile so you can understand a little better.
# To start off with, create a file with just this in it:
CFLAGS=-Wall -g

all: fizzbuzz  ex1 ex3 ex4 ex5 ex6 ex7 ex8 ex9 ex10 ex11 ex12 ex13 ex14 ex15 ex16 ex17

clean:
	rm -rf fizzbuzz fizzbuzz.dSYM ex1 ex1.dSYM ex3 ex3.dSYM ex4 ex4.dSYM ex5 ex5.dSYM ex6 ex6.dSYM ex7 ex7.dSYM ex8 ex8.dSYM ex9 ex9.dSYM ex10 ex10.dSYM ex11 ex11.dSYM ex12 ex12.dSYM ex13 ex13.dSYM ex14 ex14.dSYM ex15 ex15.dSYM ex16 ex16.dSYM ex17 ex17.dSYM 


# Extra credit
# Create an all: ex1 target that will build ex1 with just the command make.
# Uncomment to run
#CFLAGS=-Wall -g

#all: ex1

#!#? Want to learn more?
# https://www.gnu.org/software/make/manual/make.html
