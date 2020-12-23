.PHONY: clean run

OBJ = $(shell find src/ -type f -name "*.cpp" | sed "s/^src\(.*\)\.cpp/obj\1.o/")

infinite-runner : $(OBJ)
	g++ -o infinite-runner $(OBJ) $(shell pkgconf --libs glew glfw3)

obj/%.o : src/%.cpp obj
	g++ -o $@ -c $<

obj :
	mkdir obj

run : infinite-runner
	./infinite-runner

clean :
	rm -rf infinite-runner obj
