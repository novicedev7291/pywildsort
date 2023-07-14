#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "pyerrors.h"

#include <wildsort/wildsort.h>

static const size_t MAX_SIZE = 1000;

static PyObject *WildsortError;

static PyObject *errorneous_return(const char *message) {
  PyErr_SetString(WildsortError, message);
  return NULL;
}

static PyObject *wildsort_sort(PyObject *self, PyObject *args) {
  PyObject *input;

  if (!PyArg_ParseTuple(args, "O", &input)) {
    return errorneous_return("Failed to parse the input list!");
  }

  PyObject *iter = PyObject_GetIter(input);
  if (!iter) {
    return errorneous_return(
        "Input provided is not iterable, only iterable i.e. list supported");
  }

  int *temp = (int *)malloc(sizeof(int) * MAX_SIZE);
  int i = 0;

  while (1) {
    PyObject *next = PyIter_Next(iter);
    if (!next) {
      break;
    }

    if (!PyLong_Check(next)) {
      return errorneous_return("Element type should int only");
    }

    int ele = PyLong_AsSize_t(next);
    Py_DECREF(next);

    temp[i] = ele;
    i++;
  }
  Py_DECREF(input);
  Py_DECREF(iter);

  int size = i + 1;
  int *values = (int *)malloc(sizeof(int) * (size + 1));

  memcpy(&values[1], temp, sizeof(int) * size);
  values[0] = size;
  free(temp);

  bad_sort(values);

  PyObject *sorted = PyList_New(size - 1);
  for (int j = 1; j < size; j++) {
      PyObject *val = Py_BuildValue("i", values[j]);
      PyList_SetItem(sorted, j - 1, val);
  }
  free(values);

  return sorted;
}

static PyMethodDef WildsortMethods[] = {
    {"sort", wildsort_sort, METH_VARARGS,
     "Sort a list but not in performant way"},
    {NULL, NULL, 0, NULL} /*Sentinel values, not sure what it is now*/
};

static struct PyModuleDef wildsortmodule = {PyModuleDef_HEAD_INIT, "wildsort",
                                            NULL, -1, WildsortMethods};

PyMODINIT_FUNC PyInit_wildsort(void) {
  PyObject *m = PyModule_Create(&wildsortmodule);

  if (m == NULL) {
    return NULL;
  }

  WildsortError = PyErr_NewException("wildsort.error", NULL, NULL);
  Py_XINCREF(WildsortError);
  if (PyModule_AddObject(m, "error", WildsortError) < 0) {
    Py_XDECREF(WildsortError);
    Py_CLEAR(WildsortError);
    Py_DECREF(m);
    return NULL;
  }

  return m;
}
