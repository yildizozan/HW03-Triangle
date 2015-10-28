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
	double getBorder1() const { return a; }
	double getBorder2() const { return b; }
	double getBorder3() const { return c; }

	// Set Functions
	void setBorder1(double x) { a = x; }
	void setBorder2(double y) { b = y; }
	void setBorder3(double z) { c = z; }

	bool setControl(double, double, double);

	void input();
	void output();

	bool setAngle(double angleA, double angleB, double angleC);
	double setArea(double angleA, double angleB, double angleC);
	double setPrimeter(double angleA, double angleB, double angleC);

	
private:
	double a;
	double b;
	double c;

	static bool controlZero(double, double, double);
	static bool triangleControlBorder(double, double, double);
	static int triangleControlKind(double, double, double);
};

