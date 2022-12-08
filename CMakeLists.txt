#------build file from LS----------
#hey made a change
cmake_minimum_required(VERSION 3.23)

project(Ants LANGUAGES CXX VERSION 0.1.0)
configure_file(AntsConfig.h.in AntsConfig.h)


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Vector3D REQUIRED)
find_package(Eigen3 REQUIRED)

#Create the AntSimulation Library
add_library(AntSimulation STATIC)
target_sources(AntSimulation
    PRIVATE
      world.cpp
      random.cpp
      food.cpp
      pheromone.cpp
      ant.cpp
      pheromonemap.cpp
      foodmap.cpp
      antsimutils.cpp
    PUBLIC FILE_SET HEADERS
    BASE_DIRS ${PROJECT_SOURCE_DIR}
    FILES
    random.h
    world.h
    food.h
    foodmap.h
    pheromone.h
    pheromonemap.h
    ant.h
    antsimutils.h
)

target_link_libraries(AntSimulation
    PUBLIC
    Vector3D::Vector3D
    Eigen3::Eigen)

install(TARGETS AntSimulation
    EXPORT AntSimulationTargets
    FILE_SET HEADERS
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include)

install(EXPORT AntSimulationTargets
    FILE AntSimulationTargets.cmake
    NAMESPACE AntSimulation::
    DESTINATION lib/cmake/AntSimulation)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "AntSimulationConfigVersion.cmake"
    VERSION ${AntSimulation_VERSION}
    COMPATIBILITY AnyNewerVersion)

install(
    FILES
        "AntSimulationConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/AntSimulationConfigVersion.cmake"
    DESTINATION lib/cmake/${PROJECT_NAME}
)

#Create AntSimulation UnitTests Library
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(AntSimulationUnittests)
target_sources(AntSimulationUnittests
    PRIVATE Worldtest.cpp
    Anttest.cpp
    Foodtest.cpp
    Pheromonetest.cpp
    )

#UNCOMMENT THIS LATER AND ADD VECTOR3D LIBRARY
target_link_libraries(AntSimulationUnittests PRIVATE
          ${GTEST_LIBRARIES}
     ${GTEST_MAIN_LIBRARIES}
    AntSimulation
        Vector3D::Vector3D
    )

#create the Qt GUI Executable
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Widgets Concurrent  REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS GUI Widgets Charts)

add_executable(Ants)
target_sources(Ants PRIVATE
  main.cpp
  mainwindow.cpp
  mainwindow.h
  gridwidget.h
  gridwidget.cpp
  mainwindowform.ui
  qtresources/qtresources.qrc
  )

target_link_libraries(Ants PRIVATE
  Qt6::Widgets
  Qt6::Concurrent
  #the two lines below were not on his LS example
  Qt6::Gui
  Qt6::Charts
  AntSimulation
  )
