CC=g++

FLAGS=-g -Wall -std=c++11

LINKS=-lGLEW \
-lglfw \
-lGL \
-lGLU \
-lX11 \
-lpthread \
-lXrandr \
-lXi

OUT=demo

GEPPETTO=../geppetto

SOURCE=$(GEPPETTO)/component.cpp \
$(GEPPETTO)/components/camera_component.cpp \
$(GEPPETTO)/components/geometry_component.cpp \
$(GEPPETTO)/components/physics_component.cpp \
$(GEPPETTO)/components/user_input_component.cpp \
$(GEPPETTO)/entity.cpp \
$(GEPPETTO)/game.cpp \
$(GEPPETTO)/stage.cpp \
$(GEPPETTO)/math/gmath.cpp \
$(GEPPETTO)/math/mat3.cpp \
$(GEPPETTO)/math/mat4.cpp \
$(GEPPETTO)/math/vec3.cpp \
$(GEPPETTO)/math/vec4.cpp \
demo_game.cpp \
demo_stage.cpp \
cube.cpp \
player.cpp \
main.cpp \

default:
	if [ -f $(OUT) ]; then mv $(OUT) $(OUT)_old; fi
	$(CC) $(FLAGS) -o $(OUT) $(LINKS) $(SOURCE)
	./$(OUT)

