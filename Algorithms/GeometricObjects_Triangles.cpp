#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const double EPS = 1e-9;
const double pi = acos(-1);

//area: A = 0.5*b*h
//perimeter: p = a+b+c, semiperimeter: s = 0.5*p
//area_semi_p: H = sqrt(s * (s-a) * (s-b) * (s-c)) <- Heron's formula
//inscribed_circle_semi_p_radius = A/s
//LawOfCosines: c^2 = a^2 + b^2 - 2*a*b*cos(ang)
//LawOfSines: a/sin(ang_a) = b/sin(ang_b) = c/sin(ang_c) = 2*R (circumcircle)
//Pythagorean: a^2 + b^2 = c^2

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

double perimeter(double a, double b, double c){
	return a+b+c;
}
 
double area(double ab, double bc, double ca) {
  // Heron's formula, split sqrt(a * b) into sqrt(a) * sqrt(b); in implementation
  double s = 0.5 * perimeter(ab, bc, ca);
  return sqrt(s) * sqrt(s - ab) * sqrt(s - bc) * sqrt(s - ca); 
}
  
double rInCircle(double ab, double bc, double ca){
	return area(ab, bc, ca) / (0.5 * perimeter(ab, bc, ca));
}

double rInCircle(point a, point b, point c){
	return rInCircle(dist(a, b), dist(b, c), dist(c, a));
}

// assumption: the required points/lines functions have been written
// returns 1 if there is an inCircle center, returns 0 otherwise
// if this function returns 1, ctr will be the inCircle center
// and r is the same as rInCircle
int inCircle(point p1, point p2, point p3, point &ctr, double &r) {
  r = rInCircle(p1, p2, p3);
  if (fabs(r) < EPS) return 0;                   // no inCircle center

  line l1, l2;                    // compute these two angle bisectors
  double ratio = dist(p1, p2) / dist(p1, p3);
  point p = translate(p2, scale(toVec(p2, p3), ratio / (1 + ratio)));
  pointsToLine(p1, p, l1);

  ratio = dist(p2, p1) / dist(p2, p3);
  p = translate(p1, scale(toVec(p1, p3), ratio / (1 + ratio)));
  pointsToLine(p2, p, l2);

  areIntersect(l1, l2, ctr);           // get their intersection point
  return 1; 
}

// returns true if point d is inside the circumCircle defined by a,b,c
int inCircumCircle(point a, point b, point c, point d) {
  return (a.x - d.x) * (b.y - d.y) * ((c.x - d.x) * (c.x - d.x) + (c.y - d.y) * (c.y - d.y)) +
         (a.y - d.y) * ((b.x - d.x) * (b.x - d.x) + (b.y - d.y) * (b.y - d.y)) * (c.x - d.x) +
         ((a.x - d.x) * (a.x - d.x) + (a.y - d.y) * (a.y - d.y)) * (b.x - d.x) * (c.y - d.y) -
         ((a.x - d.x) * (a.x - d.x) + (a.y - d.y) * (a.y - d.y)) * (b.y - d.y) * (c.x - d.x) -
         (a.y - d.y) * (b.x - d.x) * ((c.x - d.x) * (c.x - d.x) + (c.y - d.y) * (c.y - d.y)) -
         (a.x - d.x) * ((b.x - d.x) * (b.x - d.x) + (b.y - d.y) * (b.y - d.y)) * (c.y - d.y) > 0 ? 1 : 0;
}

bool canFormTriangle(double a, double b, double c) {
  return (a + b > c) && (a + c > b) && (b + c > a); }

double rCircumCircle(double ab, double bc, double ca) {
	return ab * bc * ca / (4.0 * area(ab, bc, ca)); 
}

double rCircumCircle(point a, point b, point c){
	return rCircumCircle(dist(a, b), dist(b, c), dist(c, a)); 
}

int main(){
	
	cout << pi << endl;
	
	return 0;
}
