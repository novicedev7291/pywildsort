## Prerequisite
* Install cmake atleast version 3.20
* Install criterion testing library mentioned in README in parent directory, for
mac it can be installed as below:
```sh
brew install criterion
```

## Compilation & Installation

Follow the below steps to build and install the shared library
```sh
cd wildsort
mkdir -p build && cd build
cmake ../
cmake --build .
cmake --install . --prefix <folder_path_to_install>
```

>~~Please note that as of now the above may work only on Mac OS x86_64, to run on
other platform you may have to tweak `Makefile` and at the time of writing this~~,
I am not sure about the steps involved to make it work on windows. ~~All steps 
executed above are under `wildsort` directing inside parent directory of git repo.~~

## TODOs
- [ ] Config to support source code development on linux as well as windows.
- [X] ~~Generalize `Makefile` to support platform specific shared library.~~ Instead used `cmake` so that cross-platform and multi build systems can be supported.
