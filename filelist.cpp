#include <iostream>
#include <io.h>
#include <stdio.h>
#include <string>

using namespace std;

void filelist (string path);

int main()
{
	string path = "C:\\Users\\teddy\\TechBase\\*.*";
	filelist(path);
}

void filelist(string path)
{
	struct _finddata_t fd;

	intptr_t handle;

	if ((handle = _findfirst(path.c_str(), &fd)) == -1L)

        std::cout << "No file in directory!" << std::endl;
	
	std::cout << "in the " << path << std::endl;
	printf("\n\tFile list information \n");
    printf("====================================\n");
	do
	{
		cout << "File: " << fd.name << endl;

	} while (_findnext(handle, &fd) == 0);

	_findclose(handle);
	printf("====================================\n");
}
