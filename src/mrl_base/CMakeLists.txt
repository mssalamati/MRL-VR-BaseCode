cmake_minimum_required(VERSION 2.8.3)
project(mrl_vr)

find_package(Qt5Widgets)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# catkin related
find_package(catkin REQUIRED COMPONENTS roscpp sensor_msgs urdf cv_bridge image_transport)
set( QT_USE_QTGUI TRUE )
set( QT_USE_QTOPENGL TRUE )
set( QT_USE_QTXML TRUE )

include_directories(${catkin_INCLUDE_DIRS} include)

# source, header and resources files list
set(CPP_SOURCES src/main.cpp forms/mainwindow.cpp forms/dialogaddrobot.cpp forms/singlerobotwidget.cpp util/rosmanager.cpp)
set(CPP_HDRS forms/mainwindow.h forms/dialogaddrobot.h forms/singlerobotwidget.h util/rosmanager.h)
set(QRC_RESOURCES resources/mrlres.qrc)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

## Declare a catkin package
catkin_package()

# Add the include directories for the Qt 5 Widgets module to
# the compile lines.
include_directories(${Qt5Widgets_INCLUDE_DIRS})

# Use the compile definitions defined in the Qt 5 Widgets module
add_definitions(${Qt5Widgets_DEFINITIONS})

# Generate headers from ui files
qt5_wrap_ui(UIS_HDRS forms/mainwindow.ui forms/dialogaddrobot.ui forms/singlerobotwidget.ui)

# Generate moc files from cpp
qt5_wrap_cpp(MOC_SOURCES ${CPP_SOURCES} ${CPP_HDRS})

# Generate resources
qt5_add_resources(RESOURCES_RCC ${QRC_RESOURCES})

# Add compiler flags for building executables (-fPIE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS} -std=c++11")

## Ros include dirs
include_directories(include ${catkin_INCLUDE_DIRS})

# Tell CMake to create the helloworld executable
add_executable(dls_gui ${CPP_SOURCES} ${UIS_HDRS} ${MOC_SOURCES} ${RESOURCES_RCC})
#add_executable(testRos src/mcore.cc)
qt5_use_modules(dls_gui Widgets)

#Link the helloworld executable to the Qt 5 widgets library.
target_link_libraries(dls_gui Qt5::Widgets ${catkin_LIBRARIES})

#target_link_libraries(testRos ${catkin_LIBRARIES})
