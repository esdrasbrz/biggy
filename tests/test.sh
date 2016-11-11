# remove last object
rm test.o

export LD_LIBRARY_PATH=../build/:$LD_LIBRARY_PATH

# compile the main-test.c with biggy library
gcc main-test.c -L../build/ -lbiggy -Wall -g -o test.o
valgrind ./test.o
