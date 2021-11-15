#include <iostream>
#include <io.h>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
	string path = "C:\\Users\\teddy\\TechBase\\*.*";

	struct _finddata_t fd;

	intptr_t handle;

	if ((handle = _findfirst(path.c_str(), &fd)) == -1L)

        std::cout << "No file in directory!" << std::endl;

	printf("\tFile list information \n");
    printf("====================================\n");
	do
	{
		cout << "File: " << fd.name << endl;

	} while (_findnext(handle, &fd) == 0);

	_findclose(handle);
	printf("====================================\n");
}
