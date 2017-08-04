#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct point{
	double x, y;
	point(double x0, double y0): x(x0), y(y0){};
};

double area(const vector<point>& P){
	double result = 0.0;
	
	for (int i = 0; i < P.size()-1; i++)
		result += (P[i].x * P[i+1].y - P[i].y*P[i+1].x);
		
	return fabs(result)/2.0;
}

int main(){
	int total;
	vector<point> P;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	cin >> total;
	P.assign(total+1, point(0,0));
	
	for (int i = 0; i < total; i++)
		cin >> P[i].x >> P[i].y;
	P.push_back(P[0]);
	
	cout << area(P) << "\n";
	return 0;
}
