#include <iostream>
#include "Triangle.h"
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Turkish");

	Triangle example(1,0,0);
	cout << "-----------" << endl;
	cout << example.getSideA() << ", " << example.getSideB() << ", " << example.getSideC() << endl;
	cout << "-----------" << endl;
	example.output();
	cout << "-----------" << endl;

	
	system("PAUSE");
	return 0;
}