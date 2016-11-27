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

OUT_TEST=test/test

SOURCE_TEST=test/main_test.cpp \
geppetto/math/mat3.cpp \
geppetto/math/mat4.cpp \
geppetto/math/vec3.cpp \
geppetto/math/vec4.cpp \
geppetto/math/gmath.cpp \
test/mat3_test.cpp \
test/mat4_test.cpp \
test/vec3_test.cpp \
test/vec4_test.cpp \

tests:
	$(CC) $(FLAGS) -o $(OUT_TEST) $(LINKS) $(SOURCE_TEST)
	./$(OUT_TEST)
