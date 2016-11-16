# this script will build the library and test create-test.c

# changes the directory to build
cd ../../build
./make-lib.sh

# returns the directory
cd ../tests/create

# compile and execute test

# remove last object
rm create-test.o

export LD_LIBRARY_PATH=../../build/:$LD_LIBRARY_PATH

# compile the main-test.c with biggy library
gcc create-test.c -L../../build/ -lbiggy -Wall -g -o create-test.o
valgrind ./create-test.o
