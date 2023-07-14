## Setup the virtual environment
Make sure you have the python 3.9 or 3.10 (only tested for now) installed on
your machine before you proceed further.

Setup virtual env so that you can run the steps mentioned in `release.sh` file
using below steps:
```sh
python3 -m venv .venv
source ./.venv/bin/activate
```

>Above steps will only work on Mac OS & linux platforms, for windows refer to
the python documentation about setting up the virtual environment.

## Creating source distribution
You can run the indiviual steps as mentioned below:
```sh
python setup.py build
python setup.py install
python setup.py sdist
```

>Don't worry about some of the warning message emitted by above command, it should
work fine, also only source distribution is tried as of now.

or 
```sh
chmod +x release.sh
./release.sh
```

>All steps executed above are under `pywildsort` directory.

## TODOs
[] Creating platform dependent wheels for major platforms i.e. Debian, Arch, Windows etc.
[] Upload the wheels to https://test.pypi.org
