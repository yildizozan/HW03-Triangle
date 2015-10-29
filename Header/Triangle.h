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

	// Set Functions
	void setSideA(double x) { a = x; }
	void setSideB(double y) { b = y; }
	void setSideC(double z) { c = z; }

//	void setAngleA(double newangleA) { angleA = newangleA; }
//	void setAngleA(double newangleB) { angleB = newangleB; }
//	void setAngleA(double newangleC) { angleC = newangleC; }

	bool setControl(double, double, double); // all control functions in here

	void input();
	void output();
	bool update();
	void errorMessage() const;

	bool setAngle(double angleA, double angleB, double angleC);
	double setArea(double angleA, double angleB, double angleC);
	double setPrimeter(double angleA, double angleB, double angleC);

	
private:
	double a, b, c;
	double angleA, angleB, angleC;

	static bool controlZero(double, double, double);			// Sides must be grater than zero;
	static bool controlSides(double, double, double);			// A total of two sides grater than third side.
	static int controlKind(double, double, double);				// 
};

