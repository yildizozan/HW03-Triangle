#include "Triangle.h"
#include <iostream>
#include <math.h>

// Constructions Functions
Triangle::Triangle()
	:a(1.0), b(1.0), c(1.0)
{
	setControl(a, b, c);
}

Triangle::Triangle(double x)
	: a(x), b(1.0), c(1.0)
{
	setControl(a, b, c);
}

Triangle::Triangle(double x, double y)
	: a(x), b(y), c(1.0)
{
	setControl(a, b, c);
}

Triangle::Triangle(double x, double y, double z)
	: a(x), b(y), c(z)
{
	setControl(a, b, c);
}

// Deconstructions Functions
Triangle::~Triangle()
{
}

/* Set Functions */
// General Control
bool Triangle::setControl(double side1, double side2, double side3) 
{
	while (controlZero(getSideA(), getSideB(), getSideC()))	// It should be grater than zero.
	{
		update();
	}
	while (controlSides(getSideA(), getSideB(), getSideC()))		// A total of two sides grater than third side.
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
		setScalene(getSideA(), getSideB(), getSideC());
	}

	return true;
}

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

void Triangle::setEquilateral(double x, double y, double z)		// Equitateral triangle
{
	cout << "Eþkenar üçgen oluþturuldu." << endl
		<< "Üçgenin çevresi: " << setPrimeterCalc(x, y, z) << " br" << endl
		<< "Üçgenin alaný: " << setAreaCalc(x, y, z) << " br^2" << endl;
	setAngles(x, y, z);
	return;
}

void Triangle::setIsosceles(double x, double y, double z)		// Isosceles triangle
{
	cout << "Ýkizkenar üçgen oluþturuldu." << endl
		<< "Üçgenin çevresi: " << setPrimeterCalc(x, y, z) << " br" << endl
		<< "Üçgenin alaný: " << setAreaCalc(x, y, z) << " br^2" << endl;
	setAngles(x, y, z);
	return;
}

void Triangle::setScalene(double x, double y, double z)			// Scalene triangle
{
	cout << "Çeþitkenar üçgen oluþturuldu." << endl
		<< "Üçgenin çevresi: " << setPrimeterCalc(x, y, z) << " br" << endl
		<< "Üçgenin alaný: " << setAreaCalc(x, y, z) << " br^2" << endl;
	setAngles(x, y, z);

	return;
}

void Triangle::setAngles(double x, double y, double z)			// Print all angle
{
	cout << "A açýsý: " << setAnglesACalc(x, y, z) << endl
		<< "B açýsý: " << setAnglesBCalc(x, y, z) << endl
		<< "C açýsý: " << setAnglesCCalc(x, y, z) << endl;
	return;
}

double Triangle::setAnglesACalc(double x, double y, double z)	// Cosines theorem for cngle A
{
	const double PI = 3.14159265;
	double calcAngle = (-1) * ((x*x - y*y - z*z) / (2 * y*z));
	setAngleA(acos(calcAngle) * 180 / PI);
	return acos(calcAngle) * 180 / PI;
}

double Triangle::setAnglesBCalc(double x, double y, double z)	// Cosines theorem for angle B
{
	const double PI = 3.14159265;
	double calcAngle = (-1) * ((y*y - x*x - z*z) / (2 * x*z));
	double result = acos(calcAngle) * 180 / PI;
	setAngleB(result);
	return result;
}

double Triangle::setAnglesCCalc(double x, double y, double z)	// Cosines theorem for angle C
{
	const double PI = 3.14159265;
	double calcAngle = (-1) * ((z*z - a*a - c*c) / (2 * x*y));
	setAngleC(acos(calcAngle) * 180 / PI);
	return acos(calcAngle) * 180 / PI;
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

}

void Triangle::output()
{
}

bool Triangle::update()
{
	double x, y, z;
	cout << "Girilen deðerlerle üçgen oluþmaz lütfen yeniden giriniz: " << endl;

	cout << "A kenarý: ";
	cin >> x;
	setSideA(x);
	cout;

	cout << "B kenarý: ";
	cin >> y;
	setSideB(y);
	cout;

	cout << "C kenarý: ";
	cin >> z;
	setSideC(z);
	cout;

	return true;
}

void Triangle::errorMessage() const
{
	cout << " kenar yanlýþ! Tekrar giriniz: " << endl;
}

