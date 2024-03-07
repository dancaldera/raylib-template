# Run the next bash command to run the game on macOS

## Raylib Version 5.1,

Version Web, first you need to install emscripten, then run the following command:

### make everything in the web raylib version

and run the following command:

```bash
source ~/emsdk/emsdk_env.sh
```

```bash
make web
```

To handle a python server, run the following command:

```bash
python -m http.server 8080
```

Then open your browser and go to http://localhost:8080
