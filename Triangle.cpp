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

// Set Functions
bool Triangle::setControl(double border1, double border2, double border3)
{
	if (triangleControlNoZero(border1, border2, border3))
	{
		cout << "Kenarlardan biri herhangi biri sýfýr olamaz" << endl;
		return false;
	}
	else if (triangleControlBorder(border1, border2, border3))
	{
		cout << "Üçgen kenarlarý uygun deðil" << endl;
		return false;
	}
	else
	{
		if (triangleControlKind(border1, border2, border3) == 1)
		{
			cout << "Eþkenar üçgen oluþturuldu." << endl;
		}
		else if (triangleControlKind(border1, border2, border3) == 2)
		{
			cout << "Ýkizkenar üçgen oluþturuldu." << endl;
		}
		else
		{
			cout << "Çeþitkenar üçgen oluþturuldu." << endl;
		}
		return true;
	}

}

bool Triangle::triangleControlNoZero(double border1, double border2, double border3)
{
	if (border1 <= 0 || border2 <= 0 || border3 <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Triangle::triangleControlBorder(double border1, double border2, double border3)
{
	if (!(border1 < border2 + border3 && border2 < border1 + border3 && border3 < border1 + border2))
	// ((border1 + border2 <= border3 && border1 + border3 <= border2 && border2 + border3 <= border1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Triangle::triangleControlKind(double border1, double border2, double border3)
{
	if (border1 == border2 && border2 == border3)
	{
		return 1;
	}
	else if (border1 == border2 || border1 == border3 || border2 == border3)
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