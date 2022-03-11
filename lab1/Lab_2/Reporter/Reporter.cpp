#include <iostream>
#include <cstring>
#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <cstdio>

struct employee {
	int num;
	char name[10];
	double hours;
};

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong number of parameters\n";
		return 1;
	}

	double salary = atof(argv[3]);

	FILE* bin = NULL;
	if (fopen_s(&bin, argv[1], "r") != NULL) {
		return GetLastError();
	}

	FILE* rep = NULL;
	if (fopen_s(&rep, argv[2], "w") != NULL) {
		return GetLastError();
	}

	if (bin == NULL)
	{
		std::cout << "Bin file not found\n";
		fclose(rep);
		return 1;
	}

	char outString[100];
	employee tmp{};

	if (sprintf_s(outString, "File report %s \n ¹ Name Hours Salary\n", argv[1]) == -1) {
		return GetLastError();
	}

	fwrite(outString, strlen(outString), 1, rep);

	while (fread(&tmp, sizeof(employee), 1, bin))
	{
		sprintf_s(outString, "%d %s %0.2f %0.2f\n",
			tmp.num, tmp.name, tmp.hours, tmp.hours * salary);
		fwrite(outString, strlen(outString), 1, rep);
	}

	fclose(rep);
	fclose(bin);

}
