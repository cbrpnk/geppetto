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

SOURCE=$(GEPPETTO)/components/component_base.cpp \
$(GEPPETTO)/components/camera.cpp \
$(GEPPETTO)/components/geometry.cpp \
$(GEPPETTO)/components/physics.cpp \
$(GEPPETTO)/components/shader.cpp \
$(GEPPETTO)/components/userinput.cpp \
$(GEPPETTO)/math/math.cpp \
$(GEPPETTO)/math/mat3.cpp \
$(GEPPETTO)/math/mat4.cpp \
$(GEPPETTO)/math/vec3.cpp \
$(GEPPETTO)/math/vec4.cpp \
$(GEPPETTO)/entity.cpp \
$(GEPPETTO)/game.cpp \
$(GEPPETTO)/stage.cpp \
game.cpp \
stage.cpp \
cube.cpp \
player.cpp \
main.cpp \

default:
	if [ -f $(OUT) ]; then mv $(OUT) $(OUT)_old; fi
	$(CC) $(FLAGS) -o $(OUT) $(LINKS) $(SOURCE)
	./$(OUT)

