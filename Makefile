CC=g++

FLAGS=-Wall -std=c++11

LINKS=-lGLEW \
-lglfw \
-lGL \
-lGLU \
-lX11 \
-lpthread \
-lXrandr \
-lXi

OUT=geppetto

OUT_TEST=test/test

SOURCE=main.cpp \
engine/camera_component.cpp \
engine/component.cpp \
engine/component_controller.cpp \
engine/entity.cpp \
engine/geometry_component.cpp \
engine/logic_component.cpp \
engine/physics_component.cpp \
engine/scene.cpp \
engine/user_input_component.cpp \
lib/gmath.cpp \
lib/mat3.cpp \
lib/mat4.cpp \
lib/vec3.cpp \
lib/vec4.cpp \

SOURCE_TEST=test/main_test.cpp \
lib/mat3.cpp \
lib/mat4.cpp \
lib/vec3.cpp \
lib/vec4.cpp \
lib/gmath.cpp \
test/mat3_test.cpp \
test/mat4_test.cpp \
test/vec3_test.cpp \
test/vec4_test.cpp \



default:
	$(CC) $(FLAGS) -o $(OUT) $(LINKS) $(SOURCE)
	./$(OUT)

tests:
	$(CC) $(FLAGS) -o $(OUT_TEST) $(LINKS) $(SOURCE_TEST)
	./$(OUT_TEST)
