#ifndef EXAMPLE2_H_INCLUDED
#define EXAMPLE2_H_INCLUDED

#include <python3.3/Python.h>

void example2()
{
    Py_Initialize();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");

    PyObject *pModule = NULL;
    pModule = PyImport_ImportModule( "example2" );

    PyObject *pFunc = NULL;
    pFunc = PyObject_GetAttrString(pModule, "say_hello_world");

    PyEval_CallObject(pFunc, NULL);

    Py_Initialize();
}


#endif // EXAMPLE2_H_INCLUDED
