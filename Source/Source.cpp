#include <iostream>
#include "Triangle.h"
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Turkish");

	Triangle example(6,5,5);
	cout << "-----------" << endl;
	cout << example.getBorder1() << ", " << example.getBorder2() << ", " << example.getBorder3() << endl;
	cout << "-----------" << endl;
	example.output();
	cout << "-----------" << endl;

	
	system("PAUSE");
	return 0;
}