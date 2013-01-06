#!/usr/bin/env sh

cd ../build
make
if [ $? -ne 0 ]
then
    echo "---make failed---"
    exit 1
fi

cd ../bin

#./find_test
./sort_test
