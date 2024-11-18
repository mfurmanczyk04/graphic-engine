cmake_minimum_required(VERSION 3.31)
project(GraphicEngine)

add_executable(engine 
main.cpp
BitmapHandler.cpp
BitmapObject.cpp
CircleShape.cpp
Engine.cpp
FallingObject.cpp
HealthCrystal.cpp
HealthDisplay.cpp
HexagonShape.cpp
InputState.cpp
LineSegment.cpp
Player.cpp
Point2D.cpp
PolygonShape.cpp
PrimitiveRenderer.cpp
Rock.cpp
)

#set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML REQUIRED COMPONENTS window graphics system)

file(COPY assets DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

target_compile_features(engine PRIVATE cxx_std_17)
target_compile_definitions(engine PUBLIC SFML_STATIC)

target_link_libraries(engine sfml-graphics sfml-window sfml-system)

