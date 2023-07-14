# Wrapper Python Package over native library

## Introduction
This repo stores the source code for python wrapper package over a native C
shared library using python's C APIs. The package just offers a simple `sort`
function which tries to sort the integers and uses the shared library's 
function internally to do the heavy lifting of sorting.

>The code in repo is not of production grade, please don't use it for prod
purposes and the right now the code have only been tested and configured to
work upon Mac OS x86_64. I hope the C friends would spare me as I haven't 
touched C in last 12-14 years :-P

## Prereuisites
* C compiler and related build tools i.e. GCC or clang, make
* [Criterion C/C++ testing library](https://github.com/Snaipe/Criterion)
* Python3.9 or 3.10 (tested at least with for now)

## Installation
There are two modules in this source code, one is for the C shared library
`wildsort` and other is for python package `pywildsort`.

* For compiling and installing shared library `wildsort`, please check 
[INSTALL.md](wildsort/INSTALL.md).
* For compiling python package `pywildsort`, check [INSTALL.md](pywildsort/INSTALL.md).

## Usage
```sh
pip install <path-to-pywildsort-pkg>/pywildsort-0.1.17.tar.gz

## If you have followed the installation step, then path will be in cloned
## repo's pywildsort/dist folder.
```
```python
from wildsort import sort

if __name__ == "__main__":
    list = [12, 3, 89, 18, 90]
    list = sort(list)
    print(list)
```
If all goes well :-) , the above example should print sorted list
```
[3, 12, 18, 89, 90]
```
