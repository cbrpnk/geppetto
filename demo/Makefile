CC=g++

FLAGS=-g -Wall -Wextra -std=c++11

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

SOURCE=$(GEPPETTO)/camera_component.cpp \
$(GEPPETTO)/component.cpp \
$(GEPPETTO)/component_controller.cpp \
$(GEPPETTO)/custom_class.cpp \
$(GEPPETTO)/entity.cpp \
$(GEPPETTO)/game.cpp \
$(GEPPETTO)/geometry_component.cpp \
$(GEPPETTO)/physics_component.cpp \
$(GEPPETTO)/scene.cpp \
$(GEPPETTO)/user_input_component.cpp \
$(GEPPETTO)/math/gmath.cpp \
$(GEPPETTO)/math/mat3.cpp \
$(GEPPETTO)/math/mat4.cpp \
$(GEPPETTO)/math/vec3.cpp \
$(GEPPETTO)/math/vec4.cpp \
demo_scene.cpp \
player.cpp \
main.cpp \

default:
	$(CC) $(FLAGS) -o $(OUT) $(LINKS) $(SOURCE)
	./$(OUT)

