#ifndef EXAMPLE1_H_INCLUDED
#define EXAMPLE1_H_INCLUDED

#include <python3.3/Python.h>

void example1()
{
    Py_Initialize();
    PyRun_SimpleString("print('Hello World from Example 1!')");
    Py_Finalize();
}

#endif // EXAMPLE1_H_INCLUDED
