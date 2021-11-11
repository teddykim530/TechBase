#include <iostream>

#include <io.h>

#include <string>

using namespace std;



int main(){



	string path = "C:\\Users\\JYP\\Desktop\\p\\resource\\spam\\*.*";



	struct _finddata_t fd;

	intptr_t handle;

	if ((handle = _findfirst(path.c_str(), &fd)) == -1L)

		cout << "No file in directory!" << endl;

	do

	{

		cout << fd.name << endl;

	} while (_findnext(handle, &fd) == 0);

	_findclose(handle);



}



출처: https://nauco.tistory.com/5 [UNDERSTANDING]