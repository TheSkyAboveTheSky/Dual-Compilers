#!/bin/bash

# Change directory to AR and compile main.c
cd AR && gcc -o AR AR.c

# Change directory to FR and compile main.c
cd ../FR && gcc -o FR FR.c

# Change back to the parent directory and compile main.c
cd .. && gcc -o main main.c

# Run the main executable
./main
