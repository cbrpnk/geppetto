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
../gmath/gmat3.cpp \
../gmath/gmat4.cpp \
../gmath/gvec3.cpp \
../gmath/gvec4.cpp \
../gmath/gmath.cpp \
gmat3_test.cpp \
gmat4_test.cpp \
gvec3_test.cpp \
gvec4_test.cpp \

tests:
	$(CC) $(FLAGS) -o $(OUT_TEST) $(LINKS) $(SOURCE_TEST)
	./$(OUT_TEST)
