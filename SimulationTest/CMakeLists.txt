project(simulationtest)

add_executable(simulationtest Input/mouseinput.cpp Tests/Butida/butida.cpp Tests/Butida/wall.cpp MobileSimulator/mobilesimulator.cpp Input/touchscreeninput.cpp Input/keyboardinput.cpp Tests/Butida/stone.cpp Tests/Theo/balls.cpp Tests/Theo/ground.cpp Simulator/textrenderer.cpp Simulator/simulator.cpp Tests/Theo/theojansen.cpp Tests/Theo/leg.cpp Tools/bodyconstructor.cpp Tools/debugdraw.cpp Tests/Car/teeter.cpp Tests/Car/ground.cpp Tests/Car/car.cpp Tests/Car/bridge.cpp Tests/Car/box.cpp main.cpp Tools/collisiondetection.cpp Tools/convertutililty.cpp Engine/audiomanager.cpp Engine/body.cpp Engine/drawablelayer.cpp Engine/graphicsmgr.cpp Engine/groundbody.cpp Engine/mapdrawer.cpp Engine/staticbody.cpp Views/camera.cpp)
include_directories(./libs/fmodex/inc)
find_library(AUDIOLIB fmodex ./libs/fmodex/lib )

target_link_libraries(simulationtest  Box2D tmxparser z tinyxml SDL2 SDL2_image SDL2_ttf GL GLU glut ${AUDIOLIB})

add_subdirectory(Tools)
add_subdirectory(Simulator)
add_subdirectory(Views)
add_subdirectory(Tests)
add_subdirectory(Settings)
add_subdirectory(Systems)
add_subdirectory(libs)
add_subdirectory(Engine)

add_subdirectory(Resources)
add_subdirectory(MobileSimulator)
add_subdirectory(Input)