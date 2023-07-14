## Prerequisite
Install criterion testing library mentioned in README in parent directory, for
mac it can be installed as below:
```sh
brew install criterion
```
Depending upon where brew install the library, you may have to tweak the path
in `Makefile` under this directory mentioned for compilation -I and -L flag, 
but chances are less you have to change this on Mac x86_64.

## Compilation & Installation

Follow the below steps to build and install the shared library
```sh
make
make install
```

The above will install the `libwildsort.so` or similar in your *HOME* directory
at below path:
```
$HOME/.local/share
```

>Please note that as of now the above may work only on Mac OS x86_64, to run on
other platform you may have to tweak `Makefile` and at the time of writing this,
I am not sure about the steps involved to make it work on windows. All steps 
executed above are under `wildsort` directing inside parent directory of git repo.

## TODOs
- [ ] Config to support source code development on linux as well as windows.
- [ ] Generalize `Makefile` to support platform specific shared library.
