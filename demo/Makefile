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

SOURCE=$(GEPPETTO)/gcomponents/gcomponent.cpp \
$(GEPPETTO)/gcomponents/gcamera.cpp \
$(GEPPETTO)/gcomponents/ggeometry.cpp \
$(GEPPETTO)/gcomponents/gphysics.cpp \
$(GEPPETTO)/gcomponents/guserinput.cpp \
$(GEPPETTO)/gentity.cpp \
$(GEPPETTO)/ggame.cpp \
$(GEPPETTO)/gstage.cpp \
$(GEPPETTO)/gmath/gmath.cpp \
$(GEPPETTO)/gmath/gmat3.cpp \
$(GEPPETTO)/gmath/gmat4.cpp \
$(GEPPETTO)/gmath/gvec3.cpp \
$(GEPPETTO)/gmath/gvec4.cpp \
game.cpp \
stage.cpp \
cube.cpp \
player.cpp \
main.cpp \

default:
	if [ -f $(OUT) ]; then mv $(OUT) $(OUT)_old; fi
	$(CC) $(FLAGS) -o $(OUT) $(LINKS) $(SOURCE)
	./$(OUT)

