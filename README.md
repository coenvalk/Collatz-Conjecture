# Collatz Conjecture
[![Build Status](https://travis-ci.org/coenvalk/Collatz-Conjecture.svg?branch=master)](https://travis-ci.org/coenvalk/Collatz-Conjecture)

The collatz conjecture is a conjecture that is based on two simple rules,
starting with a number N:

1. if N is even, the next N is N / 2
1. if N is odd, the next N is 3N + 1

The conjecture is that all numbers will go to one. This is one of the
big unsolved problems in mathematics.

These three small programs are intended to show the collatz conjecture
in two different ways. collatz_tree shows how numbers branch out
following the rule in reverse. collatz_sequence shows how a number goes
down to one. collatz_largest shows the longest trail to one for a set of
numbers under N. There is a default of 100 for all of these programs, but
this can be changed with a command line argument:

```INPUT:
./collatz_sequence.out 10
EXPECTED OUTPUT:
10
5
16
8
4
2
1
10: 6
```

Program makes use of a Big Integer library:
Written and maintained by Matt McCutchen <matt@mattmccutchen.net>
