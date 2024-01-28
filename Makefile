# Validate if system is linux or macOS
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CC = g++
endif
ifeq ($(UNAME_S),Darwin)
	CC = clang++
endif


# Assuming raylib.h is ./include, and libraylib.a is in ./lib
ifeq ($(UNAME_S),Linux)
	INCLUDE_PATHS = -I./include
	LIBRARY_PATHS = -I./lib
endif
ifeq ($(UNAME_S),Darwin)
	INCLUDE_PATHS = -I./include
	LIBRARY_PATHS = -L./lib
endif

# TODO: Change this to other platforms
PLATFORM=PLATFORM_DESKTOP

# Add std=c++11 or std=c++2a if you want to use C++11 or C++20 features
STANDARD = -w -std=c++11

# Adjust linker flags based on your OS and needs
ifeq ($(UNAME_S),Linux)
	LINKER_FLAGS = -lraylib -lGL -lm -lpthread -lX11 -lXrandr -lXinerama -lXi -lXcursor
endif
ifeq ($(UNAME_S),Darwin)
	LINKER_FLAGS = -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
endif

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
