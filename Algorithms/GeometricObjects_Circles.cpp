#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const double pi = acos(-1);
//d = 2*r, c = 2*pi*r, area = pi*r*r
//arc = deg/360.0 * c
//chord = sqrt(2 * r*r * (1- cos(deg)) OR chord = 2 * r * sin(deg/2)
//sector_area = deg/360.0 * A

const double EPS = 1e-9;

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

int insideCircle(point p, point c, double r){
	double dx = p.x - c.x, dy = p.y - c.y;
	double Euc = dx*dx + dy*dy, rSq = r*r;
	
	return rSq - Euc > EPS? 0 : Euc == rSq ? 1 : 2; 
	//0 - inside
	//1 - border
	//2 - outside
}	


//Given 2 points on the circle (p1 and p2) and radius r of the corresponding circle, we
//can determine the location of the centers (c1 and c2) of the two possible circles
bool circle2PtsRad(point p1, point p2, double r, point &c) {
	double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
	double det = r * r / d2 - 0.25;

  	if (det < 0.0) return false;

  	double h = sqrt(det);

  	c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
  	c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;

  	return true; 
} // to get the other center, reverse p1 and p2
  
int main(){
	//point p1(0.9, 0.5), p2(0.0, 0.0); 
	
	//cout << insideCircle(p1, p2, 1.0) << endl;
	//cout << pi << endl;

	point p1, p2(0.0, -1.0), ans;
	
	circle2PtsRad(p1, p2, 2.0, ans);
	cout << "One of the center is (" << ans.x << ", " << ans.y << ")\n";
	
	circle2PtsRad(p2, p1, 2.0, ans);     // we simply reverse p1 with p2
	cout << "One of the center is (" << ans.x << ", " << ans.y << ")\n";
	  
	return 0;	
}
