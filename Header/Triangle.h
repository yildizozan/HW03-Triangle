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
	void setAngleA(double newAngleA) { angleA = newAngleA; }
	void setAngleB(double newAngleB) { angleB = newAngleB; }
	void setAngleC(double newAngleC) { angleC = newAngleC; }

	bool setControl(double, double, double); // all control functions in here
	void setAngles(double, double, double);

	double setAnglesACalc(double, double, double);
	double setAnglesBCalc(double, double, double);
	double setAnglesCCalc(double, double, double);


	// Triangle Variety
	void setEquilateral(double, double, double);
	void setIsosceles(double, double, double);
	void setScalene(double, double, double);


	void input();
	void output();
	bool update();
	void errorMessage() const;


	
private:
	double a, b, c;
	double angleA, angleB, angleC;

	static bool controlZero(const double, const double, const double);			// Sides must be grater than zero;
	static bool controlSides(double, double, double);							// A total of two sides grater than third side.
	static int controlKind(double, double, double);								// 

	double setAreaCalc(double, double, double);
	double setPrimeterCalc(double, double, double);

};

