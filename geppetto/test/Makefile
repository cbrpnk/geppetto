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

OUT_TEST=test

SOURCE_TEST=main_test.cpp \
../math/mat3.cpp \
../math/mat4.cpp \
../math/vec3.cpp \
../math/vec4.cpp \
../math/math.cpp \
mat3_test.cpp \
mat4_test.cpp \
vec3_test.cpp \
vec4_test.cpp \

tests:
	$(CC) $(FLAGS) -o $(OUT_TEST) $(LINKS) $(SOURCE_TEST)
	./$(OUT_TEST)
