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

GEPPETTO=../geppetto

OBJECTS= main.o \
game.o \
stage.o \
cube.o \
player.o \
$(GEPPETTO)/components/component_base.o \
$(GEPPETTO)/components/camera.o \
$(GEPPETTO)/components/geometry.o \
$(GEPPETTO)/components/physics.o \
$(GEPPETTO)/components/shader.o \
$(GEPPETTO)/components/userinput.o \
$(GEPPETTO)/math/math.o\
$(GEPPETTO)/math/mat3.o \
$(GEPPETTO)/math/mat4.o \
$(GEPPETTO)/math/vec3.o \
$(GEPPETTO)/math/vec4.o \
$(GEPPETTO)/entity.o \
$(GEPPETTO)/game.o \
$(GEPPETTO)/stage.o \

OUT=demo


$(OUT) : $(OBJECTS)
	$(CC) $(FLAGS) $(LINKS) -o $(OUT) $(OBJECTS)

%.o : %.cpp
	$(CC) -c $(FLAGS) $(LINKS) -o $@ $<

-include Makefile.deps

Makefile.deps:
	$(CC) $(FLAGS) -MM *.cpp > Makefile.deps
	$(CC) $(FLAGS) -MM $(GEPPETTO)/*.cpp >> Makefile.deps
	$(CC) $(FLAGS) -MM $(GEPPETTO)/components/*.cpp >> Makefile.deps
	$(CC) $(FLAGS) -MM $(GEPPETTO)/math/*.cpp >> Makefile.deps

clean:
	rm $(OUT)
	rm Makefile.deps
	rm ./*.o
	rm $(GEPPETTO)/*.o
	rm $(GEPPETTO)/components/*.o
	rm $(GEPPETTO)/math/*.o
