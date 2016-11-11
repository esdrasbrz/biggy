#!/bin/bash

SOURCE_DIRS=(../src/biggy_int)
INCLUDE_DIR=/usr/local/include/biggy

# removes biggy directory from /usr/local/include and creates a new one
rm -rf $INCLUDE_DIR
mkdir $INCLUDE_DIR

# switch to source directories
for dir in ${SOURCE_DIRS[@]}
do
    # Compile the source code to .o binary output
    gcc -fPIC -c $dir/*.c
    # copy the headers to /usr/local/include
    cp $dir/*.h $INCLUDE_DIR
done

# share .o files to .so library
gcc ./*.o -shared -lm -o libbiggy.so

# export the library path
export LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH
