
all:
	catkin_init_workspace ./src
	catkin_make

clean:
	@ rm -rf ./src/CMakeLists.txt
	@ rm -rf ./src/build-*
	@ rm -rf ./build
	@ rm -rf ./devel

