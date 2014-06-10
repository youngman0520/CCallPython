#include <Python.h>
#include <iostream>

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

int main(int argc, char *argv[])
{
	Py_Initialize();
	
	if (!Py_IsInitialized())  
        return -1;  
    PyRun_SimpleString("import sys");  
    PyRun_SimpleString("sys.path.append('./')"); 

    PyObject *sys = PyImport_ImportModule("sys");
	PyObject *path = PyObject_GetAttrString(sys, "path");
	PyList_Append(path, PyString_FromString("."));

	// Convert the file name to a Python string.
	PyObject *pName = PyUnicode_FromString("test");

	// Import the file as a Python module.
	PyObject *pModule = PyImport_Import( pName );
	if( !pModule ) {
		cout << " Unable to load python module"  << endl; 
		return 0; 
	}

	// Create a dictionary for the contents of the module.
	PyObject *pDict = PyModule_GetDict(pModule);
	if( !pDict ) {
		cout << " Unable to load python pDict"  << endl; 
		return 0; 
	}

	PyObject *pFunc = PyDict_GetItemString(pDict, "test_func");
	pFunc = PyDict_GetItemString(pDict, "square");
	if( !pFunc ) {
		printDict(pDict);
		cout << " Unable to load python test_func"  << endl; 
		return 0; 
	}


	Py_Finalize();
	return 0;
}
