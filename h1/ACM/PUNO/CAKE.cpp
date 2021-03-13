#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;
int N;

struct Point {
	int x;
	int y;
	Point(int _x, int _y) : x(_x), y(_y) {}
	Point() : x(0), y(0) {}
	bool operator <(const Point& p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
	bool operator == (Point other) const {
		return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); }
	};
	bool left_turn(const Point& p1, const Point& p2, const Point& p3) {
		return (p2.y - p1.y) * (p3.x - p1.x) - (p2.x - p1.x) * (p3.y - p1.y) > 0;
	}
	double triangle_area (const Point& p1, const Point& p2, const Point& p3) {
		return abs((double) p1.x * p2.y +
			(double) p2.x * p3.y +
			(double) p3.x * p1.y -
			(double) p1.y * p2.x -
			(double) p2.y * p3.x -
			(double) p3.y * p1.x) / 2.0;
	}
	double area(const vector<Point> &P) {
		double result = 0.0, x1, y1, x2, y2;
		for (int i = 0; i < (int)P.size()-1; i++) {
			x1 = P[i].x; x2 = P[i+1].x;
			y1 = P[i].y; y2 = P[i+1].y;
			result += (x1 * y2 - x2 * y1);
		}

		return fabs(result) / 2.0; }


vector<Point> arr;
		main(){
			int x,y;
			double areaTotal;
			double area1,area2;
			while(scanf("%d",&N),N){
				arr.clear();
				for(int i=0;i<N;i++){
					scanf("%d%d",&x,&y);
					arr.push_back(Point(x,y));
				}
				arr.push_back(arr[0]);
				areaTotal=area(arr);
				cout<<"T:"<<areaTotal<<endl;
				vector<Point> aux;
				for(int i=0;i<=N/2;i++){
					aux.push_back(arr[i]);
				}
				aux.push_back(aux[0]);
				area1=area(aux);
				area2=areaTotal-area1;
				pair<double,double> resp;
				resp=make_pair(area1,area2);
				cout<<area1<<" "<<area2<<endl;
				for(int i=1;i<=N;i++){
					area1=area1-triangle_area(arr[i],arr[i-1],arr[(N/2+i-1)%N])+triangle_area(arr[i],arr[(N/2+i-1)%N],arr[(N/2+i)%N]);
					area2=areaTotal-area1;
					cout<<"area1:"<<area1<<" area2:"<<area2<<endl;
					if(abs(area2)>abs(resp.second)){
						resp.first=area1;
						resp.second=area2;
					}

				}

				printf("%lf %lf\n",resp.first*2,resp.second*2);
			}


		}
