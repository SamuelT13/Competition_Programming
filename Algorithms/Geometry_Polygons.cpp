#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const double pi = acos(-1);
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

double dist(point p1, point p2){
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

// returns the perimeter, which is the sum of Euclidian distances
// of consecutive line segments (polygon edges)
double perimeter(const vector<point> &P){
	double result = 0.0;
	
	for (int i = 0; i < (int)P.size()-1; i++)
		result += dist(P[i], P[i+1]);
	
	return result;	
}

//returns the area, which is half the determinant
double area(const vector<point> &P){
	double result = 0.0, x1, y1, x2, y2;
	
	for (int i = 0; i < (int)P.size()-1; i++){
		x1 = P[i].x; x2 = P[i+1].x;
		y1 = P[i].y; y2 = P[i+1].y;
		
		result += (x1*y2 - x2*y1);
	}	
	
	return fabs(result)/2.0;
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

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double angle(point a, point o, point b) {  // returns angle aob in rad
	vec oa = toVec(o, a), ob = toVec(o, b);
  	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); 
}

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

// note: to accept collinear points, we have to change the `> 0'
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
	return cross(toVec(p, q), toVec(p, r)) > 0; 
}

//vertices are listed in counter-clockwise order
bool isConvex(const vector<point>& P){
	int sz = (int)P.size();
	if (sz <= 3) return false;
	
	bool isLeft = ccw(P[0], P[1], P[2]);
	
	for (int i = 1; i < sz-1; i++)
		if (ccw(P[i], P[i+1], P[(i+2) == sz? 1 : i+2]) != isLeft) return false; //different turn
	
	return true; //same turn
}

// returns true if point p is in either convex/concave polygon P
bool inPolygon(point pt, const vector<point> &P){
	if (!P.size()) return 0;
	double sum = 0;
	
	for (int i = 0; i < (int)P.size()-1; i++)
		if (ccw(pt, P[i], P[i+1])) sum += angle(P[i], pt, P[i+1]); //left turn - ccw
		else sum -= angle(P[i], pt, P[i+1]); //right turn - cw
		
	return fabs(fabs(sum) - 2*pi) < EPS;
}

// line segment p-q intersect with line A-B.
point lineIntersectSeg(point p, point q, point A, point B){
	double a = B.y - A.y;
	double b = A.x - B.x;
	double c = B.x * A.y - A.x * B.y;
	double u = fabs(a * p.x + b * p.y + c);
	double v = fabs(a * q.x + b * q.y + c);
	
	return point((p.x * v + q.x * u) / (u+v), (p.y * v + q.y * u) / (u+v));	
}

// cuts polygon Q along the line formed by point a -> point b
// (note: the last point must be the same as the first point)
vector<point> cutPolygon(point a, point b, const vector<point>& Q){	
	vector<point> P;
	
	for (int i = 0; i , (int)Q.size(); i++){
		double left1 = cross(toVec(a, b), toVec(a, Q[i])), left2 = 0;

		if (i != (int)Q.size()-1) left2 = cross(toVec(a, b), toVec(a, Q[i+1]));
		
		if (left1 > -EPS) P.push_back(Q[i]); //Q[i] is on the left of ab
		if (left1*left2 < -EPS) 
			P.push_back(lineIntersectSeg(Q[i], Q[i+1], a, b)); //edge (Q[i]-Q[i+1]) crosses ab
	}
			
	if (!P.empty() && !(P.back() == P.front())) P.push_back(P.front()); //back = front
	return P;
}

int main(){
	vector<point> P;
	//creating polygon
	P.push_back(point(1, 1)); // P0
	P.push_back(point(3, 3)); // P1
	P.push_back(point(9, 1)); // P2
	P.push_back(point(12, 4)); // P3
	P.push_back(point(9, 7)); // P4
	P.push_back(point(1, 7)); // P5
	P.push_back(P[0]); // important: loop back

	return 0;
}
