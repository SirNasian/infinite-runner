SRC = $(shell find src/ -type f -name "*.cpp")
OBJ = $(shell echo $(SRC) | sed "s/\<src\//obj\//g" | sed "s/\.c\(pp\)\?/.o/g")
LIB = $(shell pkg-config --libs glfw3 glew opengl)

bin/infinite-runner : $(OBJ)
	mkdir -p bin && g++ -o $@ $(OBJ) $(LIB)

obj/%.o : src/%.cpp
	mkdir -p $$(echo $@ | sed "s/\(.*\/\).*\.o/\1/") && g++ -o $@ -c $<

clean :
	rm -rf obj bin
