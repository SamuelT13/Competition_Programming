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

point pivot(0, 0);
bool angleCmp(point a, point b){
	if (collinear(pivot, a, b)) //special case
		return dist(pivot, a) < dist(pivot, b);
		
	double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
	double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
	
	return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; //compare the 2 angles	
}

//O(n log n) Graham’s Scan
vector<point> CH(vector<point> P){
	int n = (int)P.size();
	
	if (n <= 3){
		if (!(P[0] == P[n-1])) P.push_back(P[0]);
		return P; //CH is P itself
	}
	
	// first, find P0 = point with lowest Y and if tie: rightmost X
	int P0 = 0;
	for (int i = 1; i < n; i++)
		if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
			P0 = i;
		
	point temp = P[0];
	P[0] = P[P0];
	P[P0] = temp;

	// second, sort points by angle w.r.t. pivot P0
	pivot = P[0];
	sort(++P.begin(), P.end(), angleCmp); //don't sort P[0]

	// third, the ccw tests
	vector<point> S;
	S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);
	int i = 2, j;
	
	while (i < n){
		j = (int)S.size()-1;
		
		if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]); //left turn, OK
		else S.pop_back();
	}
	
	return S;
}

int main() {
	// 6 points, entered in counter clockwise order, 0-based indexing
  	vector<point> P;
  	P.push_back(point(1, 1));
  	P.push_back(point(3, 3));
  	P.push_back(point(9, 1));
  	P.push_back(point(12, 4));
  	P.push_back(point(9, 7));
  	P.push_back(point(1, 7));
  	P.push_back(P[0]); // loop back

  	printf("Perimeter of polygon = %.2lf\n", perimeter(P)); // 31.64
  	printf("Area of polygon = %.2lf\n", area(P)); // 49.00
  	printf("Is convex = %d\n", isConvex(P)); // false (P1 is the culprit)

  	//// the positions of P6 and P7 w.r.t the polygon
  	//7 P5--------------P4
  	//6 |                  \
  	//5 |                    \
  	//4 |   P7                P3
  	//3 |   P1___            /
  	//2 | / P6    \ ___    /
  	//1 P0              P2
  	//0 1 2 3 4 5 6 7 8 9 101112

  	point P6(3, 2); // outside this (concave) polygon
  	printf("Point P6 is inside this polygon = %d\n", inPolygon(P6, P)); // false
  	point P7(3, 4); // inside this (concave) polygon
  	printf("Point P7 is inside this polygon = %d\n", inPolygon(P7, P)); // true

  	// cutting the original polygon based on line P[2] -> P[4] (get the left side)
  	//7 P5--------------P4
  	//6 |               |  \
  	//5 |               |    \
  	//4 |               |     P3
  	//3 |   P1___       |    /
  	//2 | /       \ ___ |  /
  	//1 P0              P2
  	//0 1 2 3 4 5 6 7 8 9 101112
  	// new polygon (notice the index are different now):
  	//7 P4--------------P3
  	//6 |               |
  	//5 |               |
  	//4 |               |
  	//3 |   P1___       |
  	//2 | /       \ ___ |
  	//1 P0              P2
  	//0 1 2 3 4 5 6 7 8 9

  	//P = cutPolygon(P[2], P[4], P);
  	//printf("Perimeter of polygon = %.2lf\n", perimeter(P)); // smaller now 29.15
  	///printf("Area of polygon = %.2lf\n", area(P)); // 40.00

  	// running convex hull of the resulting polygon (index changes again)
  	//7 P3--------------P2
  	//6 |               |
  	//5 |               |
  	//4 |   P7          |
  	//3 |               |
  	//2 |               |
  	//1 P0--------------P1
  	//0 1 2 3 4 5 6 7 8 9
	
  	P = CH(P); // now this is a rectangle
  	printf("Perimeter of polygon = %.2lf\n", perimeter(P)); // precisely 28.00
  	printf("Area of polygon = %.2lf\n", area(P)); // precisely 48.00
  	printf("Is convex = %d\n", isConvex(P)); // true
  	printf("Point P6 is inside this polygon = %d\n", inPolygon(P6, P)); // true
  	printf("Point P7 is inside this polygon = %d\n", inPolygon(P7, P)); // true
	
  	return 0;
}
