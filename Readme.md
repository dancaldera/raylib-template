Run the next bash command to run the game on macos:
```bash
eval cc main.c $(pkg-config --libs --cflags raylib) -o main && ./main
```

.vscode basic configurations
```json
{
  "configurations": [
    {
      "name": "Mac",
      "includePath": ["${workspaceFolder}/**", "/opt/homebrew/Cellar/raylib/5.0/include/**"],
      "defines": [],
      "macFrameworkPath": ["/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks"],
      "compilerPath": "/usr/bin/clang",
      "cStandard": "c17",
      "cppStandard": "c++17",
      "intelliSenseMode": "macos-clang-arm64"
    }
  ],
  "version": 4
}
```