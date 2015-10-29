#include <iostream>
#include "Triangle.h"
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Turkish");

	Triangle example(1,1,0);
	example.input();
	example.output();

	
	system("PAUSE");
	return 0;
}