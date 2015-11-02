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

#ifndef TRIANGLE_H
#define	TRIANGLE_H

using namespace std;

class Triangle
{
public:
	Triangle();
	Triangle(double);
	Triangle(double, double);
	Triangle(double, double, double);
	~Triangle();

	/* Accessor Functions */
	// Get Functions
	double getSideA() const { return a; }
	double getSideB() const { return b; }
	double getSideC() const { return c; }
        
        double getAngleA() const { return angleA; }
	double getAngleB() const { return angleB; }
	double getAngleC() const { return angleC; }

	// Set Functions
	void setSideA(double x) { a = x; }
	void setSideB(double y) { b = y; }
	void setSideC(double z) { c = z; }
	void setAngleA(double newAngleA) { angleA = newAngleA; }
	void setAngleB(double newAngleB) { angleB = newAngleB; }
	void setAngleC(double newAngleC) { angleC = newAngleC; }

	bool setControl(double side1, double side2, double side3);	// all control functions in here
	double setControlValue(double);
	void setAngles(const double, const double, const double);

	double setAnglesACalc(const double, const double, const double);
	double setAnglesBCalc(const double, const double, const double);
	double setAnglesCCalc(const double, const double, const double);


	// Triangle Variety
	void setEquilateral(const double, const double, const double);
	void setIsosceles(const double, const double, const double);
	void setScelene(const double, const double, const double);
        bool setRightTriangle();

	void welcome();
	void input();
	void output();
	bool update();


	
private:
	double a, b, c;
	double angleA, angleB, angleC;
        
        const static double PI = 3.141592653589793238;

			// Sides must be grater than zero;
	static bool controlSides(double, double, double);							// A total of two sides grater than third side.
	static int controlKind(double, double, double);								// 

	double setAreaCalc(double, double, double);
	double setPrimeterCalc(double, double, double);

};

#endif	/* TRIANGLE_H */

