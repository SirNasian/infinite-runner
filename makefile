SRC = $(shell find src/ -type f -name "*.cpp" -o -name "*.c")
OBJ = $(shell echo $(SRC) | sed "s/\<src\//obj\//g" | sed "s/\.c\(pp\)\?/.o/g")
LIB = $(shell pkg-config --libs glfw3 glew opengl)

compile : bin/infinite-runner
build : clean bin/infinite-runner

bin/infinite-runner : $(OBJ)
	mkdir -p bin && g++ -o $@ $(OBJ) $(LIB)

# TODO: Figure out a better way to detect header changes.
#       This rule won't recompile OTHER source files that include the given header.
obj/%.o : src/%.cpp include/%.hpp
	mkdir -p $$(echo $@ | sed "s/\(.*\/\).*\.o/\1/") && g++ -o $@ -c $<

# TODO: Figure out a better way to detect header changes.
#       This rule won't recompile OTHER source files that include the given header.
obj/%.o : src/%.c include/%.h
	mkdir -p $$(echo $@ | sed "s/\(.*\/\).*\.o/\1/") && g++ -o $@ -c $<

obj/%.o : src/%.cpp
	mkdir -p $$(echo $@ | sed "s/\(.*\/\).*\.o/\1/") && g++ -o $@ -c $<

obj/%.o : src/%.c
	mkdir -p $$(echo $@ | sed "s/\(.*\/\).*\.o/\1/") && g++ -o $@ -c $<

clean :
	rm -rf obj bin
