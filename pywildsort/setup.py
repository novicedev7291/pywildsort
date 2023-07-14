from distutils.core import setup, Extension

from pathlib import Path
home = str(Path.home())

WILDSORT_LIBNAME = "wildsort"

wildsort_module = Extension("wildsort", 
                            sources=["src/wildsort.c"],
                            include_dirs=[f"{home}/.local/share/wildsort/include"],
                            libraries=[WILDSORT_LIBNAME],
                            library_dirs=[f"{home}/.local/share/wildsort/lib"])

setup(name = "pywildsort",
      version = "0.1.1",
      description = "Wrapper package around wildsort c lib to sort list",
      ext_modules = [wildsort_module])
