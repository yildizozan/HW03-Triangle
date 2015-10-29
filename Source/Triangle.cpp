#include "Triangle.h"
#include <iostream>


// Constructions Functions
Triangle::Triangle()
{
	a = 1.0;
	b = 1.0;
	c = 1.0;
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
	while ( controlZero( getSideA(), getSideB(), getSideC() ) )
	{
		update();
	}
	while ( controlSides(getSideA(), getSideB(), getSideC() ) )
	{
		update();
	}

	if (controlKind(side1, side2, side3) == 1)
	{
		cout << "Eþkenar üçgen oluþturuldu." << endl;
	}
	else if (controlKind(side1, side2, side3) == 2)
	{
		cout << "Ýkizkenar üçgen oluþturuldu." << endl;
	}
	else
	{
		cout << "Çeþitkenar üçgen oluþturuldu." << endl;
	}

	return true;
}

bool Triangle::controlZero(double side1, double side2, double side3)
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

int Triangle::controlKind(double side1, double side2, double side3)
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

// Input - Output Functions
void Triangle::input()
{

}

void Triangle::output()
{
}

bool Triangle::update()
{
	int x, y, z;
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