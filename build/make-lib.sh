# removes biggy directory from /usr/local/include and creates a new one
rm -rf /usr/local/include/biggy
mkdir /usr/local/include/biggy

# switch to biggy_int directory
cd ../src/biggy_int/

# Compile the source code to .o binary output
gcc -c *.c
# copy the headers to /usr/local/include
cp *.h /usr/local/include/biggy

# returns to build dir
cd ../../build

# share .o files to .so library
gcc ../src/biggy_int/*.o -shared -lm -o libbiggy.so
