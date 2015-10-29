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
		cout << "E�kenar ��gen olu�turuldu." << endl;
	}
	else if (controlKind(side1, side2, side3) == 2)
	{
		cout << "�kizkenar ��gen olu�turuldu." << endl;
	}
	else
	{
		cout << "�e�itkenar ��gen olu�turuldu." << endl;
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
	cout << "Girilen de�erlerle ��gen olu�maz l�tfen yeniden giriniz: " << endl;

	cout << "A kenar�: ";
	cin >> x;
	setSideA(x);
	cout;

	cout << "B kenar�: ";
	cin >> y;
	setSideB(y);
	cout;

	cout << "C kenar�: ";
	cin >> z;
	setSideC(z);
	cout;

	return true;
}

void Triangle::errorMessage() const
{
	cout << " kenar yanl��! Tekrar giriniz: " << endl;
}