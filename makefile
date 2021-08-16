app : src/main.cpp src/renderer.cpp src/renderable.cpp
	g++ -o app src/main.cpp src/renderer.cpp src/renderable.cpp $$(pkg-config --libs glfw3 glew opengl)
