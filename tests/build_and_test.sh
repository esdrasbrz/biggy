# this script will build the library and execute tests.sh

# changes the directory to build
cd ../build
./make-lib.sh

# returns the directory
cd ../tests
./test.sh
