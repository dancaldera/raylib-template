CC = clang++
# For C++, use CXX = clang++
# For C, use CC = clang

# Assuming raylib.h is ./include, and libraylib.a is in ./lib
INCLUDE_PATHS = -I./include
LIBRARY_PATHS = -L./lib

# Add std=c++17 or std=c++2a if you want to use C++17 or C++20 features
STANDARD = -std=c++17

# Adjust linker flags based on your OS and needs
# For macOS:
LINKER_FLAGS = -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
# For Linux:
# LINKER_FLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
# For Windows:
# LINKER_FLAGS = -lraylib -lopengl32 -lgdi32 -lwinmm

# Name of your executable
EXECUTABLE = main

# Your source files
SOURCES = main.cpp

# The target that compiles your executable
$(EXECUTABLE): $(SOURCES)
	$(CC) $(SOURCES) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(LINKER_FLAGS) $(STANDARD) -o $(EXECUTABLE)

# The target that cleans your build directory
clean:
	rm $(EXECUTABLE)

# The target that runs your executable
run:
	./$(EXECUTABLE)

# The target that compiles and runs your executable
all: $(EXECUTABLE) run clean
