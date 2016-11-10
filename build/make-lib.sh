# switch to biggy_int directory
cd ../src/biggy_int/

# Compile the source code to .o binary output
gcc biggy_int.c parser.c -Wall -g -o biggy_int.o


# returns to build dir
cd ../../build

# share .o files to .so library
gcc ../src/biggy_int/biggy_int.o -shared -lm -o libbiggy.so
