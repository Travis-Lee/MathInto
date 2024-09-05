#!/bin/bash
if [ ! -d build_macOS_x86 ]; then
    mkdir -p build_macOS_x86
fi
cd build_macOS_x86


BUILD_DIR="macOS-release"
if [ ! -d $BUILD_DIR ]; then
    mkdir -p $BUILD_DIR
fi
cd $BUILD_DIR

cmake ../.. 

make -j4 VERBOSE=1

cd ../../
DEMO_DIR=build_macOS_x86/$BUILD_DIR/test_demo
if [ ! -d $DEMO_DIR ]; then
    mkdir -p $DEMO_DIR
fi

echo "build_dir:$BUILD_DIR"

cp  build_macOS_x86/$BUILD_DIR/01_Intro/test/test $DEMO_DIR

echo "Complete Unit Test"
./build_macOS_x86/macOS-release/01_Intro/test/test
echo "Test Done"
