all: collatz_sequence collatz_tree

collatz_sequence: collatz_sequence.cpp
	clang++ collatz_sequence.cpp -o collatz_sequence.out

collatz_tree: collatz_tree.cpp
	clang++ collatz_tree.cpp -o collatz_tree.out

