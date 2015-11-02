/* 
 * File:   Triangle.cpp
 * Author: Ozan Yıldız
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

#include "Triangle.h"
#include <iostream>
#include <math.h>


// Constructions Functions
Triangle::Triangle()
	:a(1.0), b(1.0), c(1.0)
{
}

Triangle::Triangle(double x)
	: a(x), b(1.0), c(1.0)
{
	if (a < 0)
	{
		a = 0;
		b = 0;
		c = 0;
	}
}

Triangle::Triangle(double x, double y)
	: a(x), b(y), c(1.0)
{
	if (a < 0 || b <= 0)
	{
		a = 0;
		b = 0;
	}
}

Triangle::Triangle(double x, double y, double z)
	: a(x), b(y), c(z)
{
	if (a <= 0 || b <= 0 || c <= 0)
	{
		a = 0;
		b = 0;
		c = 0;
	}
}

// Deconstructions Functions
Triangle::~Triangle()
{
}

/* Set Functions */
// General Control
bool Triangle::setControl(double side1, double side2, double side3)  // Triangle general control
{
	while (controlSides(getSideA(), getSideB(), getSideC()))
	{
		update();
	}

	if (controlKind(getSideA(), getSideB(), getSideC()) == 1)
	{
		setEquilateral(getSideA(), getSideB(), getSideC());
	}
	else if (controlKind(getSideA(), getSideB(), getSideC()) == 2)
	{
		setIsosceles(getSideA(), getSideB(), getSideC());
	}
	else
	{
		setScelene(getSideA(), getSideB(), getSideC());
	}
        if (setRightTriangle())
        {
            cout << "Dik üçgendir kendileri" << endl;
        }

	return true;
}



bool Triangle::controlSides(double side1, double side2, double side3)   // This control is side length
{
	if (!(side1 < side2 + side3 && side2 < side1 + side3 && side3 < side1 + side2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Triangle::controlKind(double side1, double side2, double side3)    // Which one triangle?
{
	if (side1 == side2 && side2 == side3)
	{
		return 1;
	}
	else if (side1 == side2 || side1 == side3 || side2 == side3)
	{
		return 2;
	}
	else
	{
		return 3;
	}
}

double Triangle::setControlValue(double value)  // Triangle side length must be grater than zero
{
	while (value <= 0)
	{
		cout << "Pozitif deðer olmalý! Yeniden: ";
		cin >> value;
	}
	return value;
}

void Triangle::setEquilateral(const double x, const double y, const double z)   // Equitateral triangle
{
	cout << "Eþkenar üçgen oluþturuldu." << endl
		<< "Üçgenin çevresi: " << setPrimeterCalc(x, y, z) << " br" << endl
		<< "Üçgenin alaný: " << setAreaCalc(x, y, z) << " br^2" << endl;
	setAngles(x, y, z);
	return;
}

void Triangle::setIsosceles(const double x, const double y, const double z)     // Isosceles triangle
{
	cout << "Ýkizkenar üçgen oluþturuldu." << endl
		<< "Üçgenin çevresi: " << setPrimeterCalc(x, y, z) << " br" << endl
		<< "Üçgenin alaný: " << setAreaCalc(x, y, z) << " br^2" << endl;
	setAngles(x, y, z);
	return;
}

bool Triangle::setRightTriangle()   // Right Triangle Control
{
    int control = false;
    
    if(getAngleA()==90 || getAngleB()==90 || getAngleC()==90)
    {
        control = true;
    }
    return control;
}

void Triangle::setScelene(const double x, const double y, const double z)   // Scalene triangle
{
	cout << "Çeþitkenar üçgen oluþturuldu." << endl
		<< "Üçgenin çevresi: " << setPrimeterCalc(x, y, z) << " br" << endl
		<< "Üçgenin alaný: " << setAreaCalc(x, y, z) << " br^2" << endl;
	setAngles(x, y, z);

	return;
}

void Triangle::setAngles(const double x, const double y, const double z)    // Print all angle
{
	cout << "A açýsý: " << setAnglesACalc(x, y, z) << endl
		<< "B açýsý: " << setAnglesBCalc(x, y, z) << endl
		<< "C açýsý: " << setAnglesCCalc(x, y, z) << endl;
	return;
}

double Triangle::setAnglesACalc(const double x, const double y, const double z)	// Cosines theorem for angle A
{
	double calcAngle = (-1) * ((x*x - y*y - z*z) / (2 * y*z));
	double result = acos(calcAngle) * 180 / PI;
	setAngleA(result);
	return result;
}

double Triangle::setAnglesBCalc(const double x, const double y, const double z)	// Cosines theorem for angle B
{
	double calcAngle = (-1) * ((y*y - x*x - z*z) / (2 * x*z));
	double result = acos(calcAngle) * 180 / PI;
	setAngleB(result);
	return result;
}

double Triangle::setAnglesCCalc(const double x, const double y, const double z)	// Cosines theorem for angle C
{
	double calcAngle = (-1) * ((z*z - x*x - y*y) / (2 * x*y));
	double result = acos(calcAngle) * 180 / PI;
	setAngleC(result);
	return result;
}


double Triangle::setAreaCalc(double x, double y, double z)  // Triangle Area Calc
{
	double s = setPrimeterCalc(x, y, z) / 2;
	double area = sqrt(s*(s - x)*(s - y)*(s - z));
	return area;
}

double Triangle::setPrimeterCalc(double x, double y, double z)  // Triangle Primeter Calc
{
	return x + y + z;
}


// Input - Output Functions
void Triangle::input()
{
	double value;

	welcome();
	cout << "Lütfen oluþturmak istediðiniz üçgenin kenar ölçülerini giriniz." << endl;

	update();

	setControl(getSideA(), getSideB(), getSideC());
}

void Triangle::output()
{
	cout << getSideA() << " " << getSideB() << " " << getSideC() << endl;
}

bool Triangle::update()
{
	double value;

	cout << "A kenarý: ";
	cin >> value;
	value = setControlValue(value);     // Value must be grater than zero
	setSideA(value);
	cout;

	cout << "B kenarý: ";
	cin >> value;
	value = setControlValue(value);     // Value must be grater than zero
	setSideB(value);
	cout;

	cout << "C kenarý: ";
	cin >> value;
	value = setControlValue(value);     // Value must be grater than zero
	setSideC(value);
	cout;

	return true;
}

void Triangle::welcome()
{
	cout << "Welcome the Triangle program! Created by Ozan Yýldýz. ( v2.5.6 )" << endl 
                << "Source is: https://github.com/yildizozann/HW03-Triangle" << endl << endl;
	return;
}

