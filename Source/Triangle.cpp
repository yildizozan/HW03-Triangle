#include "Triangle.h"
#include <iostream>
#include <math.h>

#define PI 	3.141592653589793238

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
bool Triangle::setControl(double side1, double side2, double side3) 
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

	return true;
}

// silinicek gereksiz
bool Triangle::controlZero(const double side1, const double side2, const double side3)
{
	if (side1 <= 0 || side2 <= 0 || side3 <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Triangle::controlSides(double side1, double side2, double side3)
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

int Triangle::controlKind(double side1, double side2, double side3)		// 
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

double Triangle::setControlValue(double value)		// Triangle side length must be grater than zero
{
	while (value <= 0)
	{
		cout << "Pozitif de�er olmal�! Yeniden: ";
		cin >> value;
	}
	return value;
}

void Triangle::setEquilateral(double x, double y, double z)		// Equitateral triangle
{
	cout << "E�kenar ��gen olu�turuldu." << endl
		<< "��genin �evresi: " << setPrimeterCalc(x, y, z) << " br" << endl
		<< "��genin alan�: " << setAreaCalc(x, y, z) << " br^2" << endl;
	setAngles(x, y, z);
	return;
}

void Triangle::setIsosceles(double x, double y, double z)		// Isosceles triangle
{
	cout << "�kizkenar ��gen olu�turuldu." << endl
		<< "��genin �evresi: " << setPrimeterCalc(x, y, z) << " br" << endl
		<< "��genin alan�: " << setAreaCalc(x, y, z) << " br^2" << endl;
	setAngles(x, y, z);
	return;
}

void Triangle::setScelene(double x, double y, double z)			// Scalene triangle
{
	cout << "�e�itkenar ��gen olu�turuldu." << endl
		<< "��genin �evresi: " << setPrimeterCalc(x, y, z) << " br" << endl
		<< "��genin alan�: " << setAreaCalc(x, y, z) << " br^2" << endl;
	setAngles(x, y, z);

	return;
}

void Triangle::setAngles(double x, double y, double z)			// Print all angle
{
	cout << "A a��s�: " << setAnglesACalc(x, y, z) << endl
		<< "B a��s�: " << setAnglesBCalc(x, y, z) << endl
		<< "C a��s�: " << setAnglesCCalc(x, y, z) << endl;
	return;
}

double Triangle::setAnglesACalc(double x, double y, double z)	// Cosines theorem for angle A
{
	double calcAngle = (-1) * ((x*x - y*y - z*z) / (2 * y*z));
	double result = acos(calcAngle) * 180 / PI;
	setAngleA(result);
	return result;
}

double Triangle::setAnglesBCalc(double x, double y, double z)	// Cosines theorem for angle B
{
	double calcAngle = (-1) * ((y*y - x*x - z*z) / (2 * x*z));
	double result = acos(calcAngle) * 180 / PI;
	setAngleB(result);
	return result;
}

double Triangle::setAnglesCCalc(double x, double y, double z)	// Cosines theorem for angle C
{
	double calcAngle = (-1) * ((z*z - x*x - y*y) / (2 * x*y));
	double result = acos(calcAngle) * 180 / PI;
	setAngleC(result);
	return result;
}


double Triangle::setAreaCalc(double x, double y, double z)
{
	double s = setPrimeterCalc(x, y, z) / 2;
	double area = sqrt(s*(s - x)*(s - y)*(s - z));
	return area;
}

double Triangle::setPrimeterCalc(double x, double y, double z)
{
	return x + y + z;
}


// Input - Output Functions
void Triangle::input()
{
	double value;

	welcome();
	cout << "L�tfen olu�turmak istedi�iniz ��genin kenar �l��lerini giriniz." << endl;

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

	cout << "A kenar�: ";
	cin >> value;
	value = setControlValue(value);		// Value must be grater than zero
	setSideA(value);
	cout;

	cout << "B kenar�: ";
	cin >> value;
	value = setControlValue(value);		// Value must be grater than zero
	setSideB(value);
	cout;

	cout << "C kenar�: ";
	cin >> value;
	value = setControlValue(value);		// Value must be grater than zero
	setSideC(value);
	cout;

	return true;
}

void Triangle::welcome()
{
	cout << "Welcome the Triangle program! Created by Ozan Y�ld�z. ( v2.1.0 )" << endl << endl;
	return;
}

void Triangle::errorMessage() const
{
	cout << " kenar yanl��! Tekrar giriniz: " << endl;
}

