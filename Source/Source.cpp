/* 
 * File:   Triangle.cpp
 * Author: Ozan Yildiz
 * No: 151044082
 * 
 * Created on October 28, 2015, 9:58 PM
 * 
 * HW03 - Triangle
 *
 *      Input:
 *      Triangle sides
 * 
 *      Output:
 *      Calculate primeter
 *      Calculate area
 *      AngleA, AngleB, AngleC
 *      If triangle is  right angle, to show "Dik üçgendir" on the screen.
 */

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