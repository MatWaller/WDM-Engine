#OBJS specifies which files to compile as part of the project
OBJS = src/main.cpp src/Engine/Graphics/DisplayManager.cpp src/Engine/Graphics/Texture.cpp src/Engine/Graphics/Ttf.cpp
#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = bin/SDL

#This is the target that compiles our executable
all : $(OBJS)
	g++ $(OBJS) -w -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -fpermissive -o $(OBJ_NAME)
