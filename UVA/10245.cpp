#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const double INF = 1000000000;

struct point{
	double x, y;
	point(double x0, double y0): x(x0), y(y0){};
};

double dist(point p1, point p2){
	return hypot(p1.x-p2.x, p1.y-p2.y);
}

double combine(int l, int m, int r, double d_m, const vector<point>& p){
	double d = d_m, line = (p[m].x+p[m+1].x)/2.0;
	
	
	for (int i = m; i >= l && p[i].x > line-d; i--)
		for (int j = m+1; j <= r && p[j].x < line+d; j++)
			d = min(d, dist(p[i], p[j]));
			
	return d;
}

double divide(int l, int r, const vector<point>& p){
	if (l >= r) return INF;
	
	int m = (l+r)/2;
	
	double dist_l = divide(l, m, p), dist_r = divide(m+1, r, p);
	double dist_m = min(dist_l, dist_r);
	
	return min(dist_m, combine(l, m, r, dist_m, p));
}

bool order(point p1, point p2){
	if (p1.x == p2.x) return p1.y < p2.y;
	return p1.x < p2.x;
}

int main(){
	int total;
	double d;
	vector<point> P;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    	cout.setf(ios::fixed);
    	cout.setf(ios::showpoint);
    	cout.precision(4);
    
	while (cin >> total && total){
		P.clear(); P.assign(total, point(0, 0));
		
		for (int i = 0; i < total; i++) cin >> P[i].x >> P[i].y;
		
		sort(P.begin(), P.end(), order);
		
		d = divide(0, total-1, P);
		
		if (d >= 10000) cout << "INFINITY\n";
		else cout << d << "\n";
	}
}
