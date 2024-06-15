clean:
    @rm -rf build
    @mkdir build

build f:
    @clang -o build/{{f}} -Wall -Wextra -std=c2x -pedantic {{f}}.c