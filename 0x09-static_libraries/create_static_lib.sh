#!/bin/bash

# Compile all .c files into object files (.o)
for file in *.c; do
    if [ -f "$file" ]; then
        gcc -c "$file"
    fi
done

# Create the static library liball.a from all the .o files
ar rcs liball.a *.o

# Clean up the temporary object files (.o)
rm -f *.o