#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const double EPS = 1e-9;
const double pi = acos(-1);

struct point_i{
	int x, y;
	
	point_i(){x = y = 0;}
	point_i(int x_0, int y_0): x(x_0), y(y_0){};
};

struct point{
	double x, y;

	point(){x = y = 0.0;}
	point(double x_0, double y_0): x(x_0), y(y_0){};	
	
	bool operator < (point other) const{
		if (x - other.x > EPS) return x < other.x;
		
		return y < other.y;
	}
	
	bool operator == (point other) const{
		return (fabs(x - other.x) < EPS && fabs(y - other.y < EPS));
	}
};

double dist(point p1, point p2){
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

point rotate(point p, double theta){
	double rad = theta*(pi/180.0);	

	return point(p.x * cos(rad) - p.y * sin(rad), 
		     p.x * sin(rad) + p.y * cos(rad));
}

int main(){
	vector<point> P;
	sort(P.begin(), P.end());

	//cout << pi << endl;
	
	return 0;
}
