#include <Python.h>
#include <iostream>
#include <stdio.h>
// sudo apt-get install python-dev  或者 sudo aptitude install python-dev

using namespace std; 

void printDict(PyObject* obj) {  
    if (!PyDict_Check(obj)) return;  

    PyObject *keys = PyDict_Keys(obj);  
    for (int i = 0; i < PyList_GET_SIZE(keys); i++) {  
        PyObject *k = PyList_GET_ITEM(keys, i);  
        char* c_name = PyString_AsString(k);  
        cout << c_name << endl; 
    }  
} 

int main(int argc, char* argv[])
{
  Py_Initialize();
  PyRun_SimpleString("import sys");
  PyRun_SimpleString("sys.path.append('./')");

  PyObject *pModule = PyImport_ImportModule( "helloworld" );

  // printDict( PyModule_GetDict(pModule) );

  PyObject *pFunc = PyObject_GetAttrString(pModule, "say_hello_world");
  
  PyEval_CallObject(pFunc, NULL);

  Py_Initialize();

  return 0; 
}