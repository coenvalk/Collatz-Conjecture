# Mention default target.
all:

# Implicit rule to compile C++ files.  Modify to your taste.
%.o: %.cc
	clang++ -c -O2 -Wall -Wextra -pedantic $<
%.o: %.cpp
	clang++ -c -O2 -Wall -Wextra -pedantic $<

# Components of the library.
library-objects = \
	BigInt/BigUnsigned.o \
	BigInt/BigInteger.o \
	BigInt/BigIntegerAlgorithms.o \
	BigInt/BigUnsignedInABase.o \
	BigInt/BigIntegerUtils.o \

local-library-objects = \
	BigUnsigned.o \
	BigInteger.o \
	BigIntegerAlgorithms.o \
	BigUnsignedInABase.o \
	BigIntegerUtils.o \


library-headers = \
	BigInt/NumberlikeArray.hh \
	BigInt/BigUnsigned.hh \
	BigInt/BigInteger.hh \
	BigInt/BigIntegerAlgorithms.hh \
	BigInt/BigUnsignedInABase.hh \
	BigInt/BigIntegerLibrary.hh \

# To ``make the library'', make all its objects using the implicit rule.
library: $(library-objects)

# Conservatively assume that all the objects depend on all the headers.
$(library-objects): $(library-headers)

# The rules below build a program that uses the library.  They are preset to
# build ``sample'' from ``sample.cc''.  You can change the name(s) of the
# source file(s) and program file to build your own program, or you can write
# your own Makefile.

# Components of the program.
program1 = collatz_tree
program-objects1 = collatz_tree.o

program2 = collatz_sequence
program-objects2 = collatz_sequence.o

program3 = collatz_largest
program-objects3 = collatz_largest.o

# Conservatively assume all the program source files depend on all the library
# headers.  You can change this if it is not the case.
$(program-objects1) : $(library-headers)
$(program-objects2) : $(library-headers)
$(program-objects3) : $(library-headers)

# How to link the program.  The implicit rule covers individual objects.
$(program1) : $(program-objects1) $(local-library-objects)
	clang++ $^ -o $@.out

$(program2) : $(program-objects2) $(local-library-objects)
	clang++ $^ -o $@.out

$(program3) : $(program-objects3) $(local-library-objects)
	clang++ $^ -o $@.out

# Delete all generated files we know about.
clean :
	rm -f $(local-library-objects) $(testsuite-cleanfiles) $(program-objects1) $(program-objects2) $(program-objects3) $(program)

# I removed the *.tag dependency tracking system because it had few advantages
# over manually entering all the dependencies.  If there were a portable,
# reliable dependency tracking system, I'd use it, but I know of no such;
# cons and depcomp are almost good enough.

# Come back and define default target.
all : library $(program1) $(program2) $(program3)


test1:
	./collatz_sequence.out > output.txt
	diff output.txt tests/test1.txt

test2:
	./collatz_largest.out > output.txt
	diff output.txt tests/test2.txt

test3:
	./collatz_tree.out > output.txt
	diff output.txt tests/test3.txt

test4:
	./collatz_sequence.out 1000 > output.txt
	diff output.txt tests/test4.txt

test5:
	./collatz_largest.out 1000 > output.txt
	diff output.txt tests/test5.txt

test6:
	./collatz_tree.out 1000 > output.txt
	diff output.txt tests/test6.txt

test: test1 test2 test3 test4 test5 test6
	rm output.txt
