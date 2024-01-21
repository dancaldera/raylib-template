# Run the next bash command to run the game on macOS

## Raylib Version 5.1 using c++17

To run a c++ base version, having the following files in the lib directory:

```bash
clang -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL lib/libraylib.a -I ./lib  src/main.cpp -o main -std=c++17 && ./main
```

To run a c++ base version with raylib 5.0 installed with brew, having the following files in the lib directory:

```bash
clang -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL -I /opt/homebrew/Cellar/raylib/5.0/include -L /opt/homebrew/Cellar/raylib/5.0/lib -lraylib src/main.cpp -o main -std=c++17 && ./main
```

if neccessary, you can run with clang++ instead of clang

```bash
clang++ -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL -I /opt/homebrew/Cellar/raylib/5.0/include -L /opt/homebrew/Cellar/raylib/5.0/lib -lraylib src/main.cpp -o main -std=c++17 && ./main
```

you must have the following files in the lib directory:

- libraylib.a
- raylib.h
- raymath.h
