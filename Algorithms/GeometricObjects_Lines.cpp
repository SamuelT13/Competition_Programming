#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const double EPS = 1e-9;
const double pi = acos(-1);

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

struct line {double a, b, c;};

void pointsToLine(point p1, point p2, line& l){
	if (fabs(p1.x - p2.x) < EPS){
		l.a = 1.0; l.b = 0.0; l.c = -p1.x;
	}
	
	else{
		l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0; //Value of b fixed to 1.0
		l.c = -(double)(l.a * p1.x) - p1.y;
	}
}

bool areParallel(line l1, line l2){
	return (fabs(l1.a - l2.a)) < EPS && (fabs(l1.b - l2.b) < EPS); //a and b are equal
}

bool areSame(line l1, line l2){
	return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS); //a, b, and c are equal
}

bool areIntersect(line l1, line l2, point& p){
	if (areParallel(l1, l2)) return false;
	
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	
	//test for vertical line
	if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
	else 				  p.y = -(l2.a * p.x + l2.c);
	
	return true;
}

struct vec{
	double x, y;
	
	vec(double x_0, double y_0): x(x_0), y(y_0){};		
};

vec toVec(point a, point b){
	return vec(b.x - a.x, b.y - a.y);
}

vec scale(vec v, double s){
	return vec(v.x * s, v.y * s);
}

point translate(point p, vec v){
	return point(p.x + v.x, p.y + v.y);
}

double dot(vec a, vec b){
	return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v){
	return v.x*v.x + v.y*v.y;
}
	
//distance from p to line defined by points a, b (must be different)
//closest point is stored in c
double distToLine(point p, point a, point b, point &c){
	//formula: c = a + u * ab
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	c = translate(a, scale(ab, u));
	
	return dist(p, c);
}

//distance from p to line segment ab (a can be equal to b)
double distToLineSegment(point p, point a, point b, point &c){
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	
	if (u < 0.0){ //closer to a
		c = point(a.x, a.y);
		return dist(p, a);
	}
	
	if (u > 1.0){ //closer to b
		c = point(b.x, b.y);
		return dist(p, b);
	}
	
	return distToLine(p, a, b, c);
}

//angle aob in rad
double angle(point a, point o, point b){
	vec oa = toVec(o, a), ob = toVec(o, b);
	
	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));	
}

//CounterClockwiseTest - CCW
double cross(vec a, vec b){
	return a.x * b.y - a.y * b.x; 
}

// note: to accept collinear points, we have to change the ‘> 0’
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r){
	return cross(toVec(p, q), toVec(p, r)) > 0;
}

// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r){
	return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

int main(){
	cout << pi << endl;
	return 0;
}
