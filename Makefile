# Mention default target.
all:

# Implicit rule to compile C++ files.  Modify to your taste.
%.o: %.cc
	g++ -c -O2 -Wall -Wextra -pedantic $<

%.o: %.cpp
	g++ -c -O2 -Wall -Wextra -pedantic $<

# Components of the library.
library-objects = \
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

# Conservatively assume all the program source files depend on all the library
# headers.  You can change this if it is not the case.
$(program-objects1) : $(library-headers)
$(program-objects2) : $(library-headers)

# How to link the program.  The implicit rule covers individual objects.
$(program1) : $(program-objects1) $(library-objects)
	clang++ $^ -o $@.out

$(program2) : $(program-objects2) $(library-objects)
	clang++ $^ -o $@.out


# Delete all generated files we know about.
clean :
	rm -f $(library-objects) $(testsuite-cleanfiles) $(program-objects) $(program)

# I removed the *.tag dependency tracking system because it had few advantages
# over manually entering all the dependencies.  If there were a portable,
# reliable dependency tracking system, I'd use it, but I know of no such;
# cons and depcomp are almost good enough.

# Come back and define default target.
all : library $(program1) $(program2)
