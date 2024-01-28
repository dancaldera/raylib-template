# Run the next bash command to run the game on macOS

## Raylib Version 5.1,

By default, the game will use the C version, to use the C++ you must change the Makefile, uncomment the C++ version and comment the C version.

To build the game, run the following command:

Example of the build command in Linux (Ubuntu 22):
```bash
gcc -I./lib -L./lib -w -lraylib -lGL -lm -lpthread -lX11 -lXrandr -lXinerama -lXi -lXcursor ./main.c -o main
```

Example of the build command in macOS:
```bash
clang -I./include -L./lib -w -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo ./main.c -o main
```

```bash
make
```

To clean the build, run the following command:

```bash
make clean
```

To run the game, run the following command:

```bash
make run
```

To build and run the game, run the following command:

```bash
make all
```
