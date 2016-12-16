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

SOURCE=$(GEPPETTO)/gcomponent.cpp \
$(GEPPETTO)/gcomponents/g_camera.cpp \
$(GEPPETTO)/gcomponents/g_geometry.cpp \
$(GEPPETTO)/gcomponents/g_physics.cpp \
$(GEPPETTO)/gcomponents/g_user_input.cpp \
$(GEPPETTO)/gentity.cpp \
$(GEPPETTO)/ggame.cpp \
$(GEPPETTO)/gstage.cpp \
$(GEPPETTO)/math/gmath.cpp \
$(GEPPETTO)/math/mat3.cpp \
$(GEPPETTO)/math/mat4.cpp \
$(GEPPETTO)/math/vec3.cpp \
$(GEPPETTO)/math/vec4.cpp \
game.cpp \
stage.cpp \
cube.cpp \
player.cpp \
main.cpp \

default:
	if [ -f $(OUT) ]; then mv $(OUT) $(OUT)_old; fi
	$(CC) $(FLAGS) -o $(OUT) $(LINKS) $(SOURCE)
	./$(OUT)

