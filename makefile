app : src/main.cpp src/renderer.cpp src/renderable.cpp src/shader.cpp
	g++ -o app src/main.cpp src/renderer.cpp src/renderable.cpp src/shader.cpp $$(pkg-config --libs glfw3 glew opengl)
