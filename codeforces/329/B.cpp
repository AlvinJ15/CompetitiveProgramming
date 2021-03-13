#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;
struct point{
  double x,y;
  point(){x=y=0.0;}
  point(double _x,double _y): x(_x),y(_y){};
};
struct line {double a,b,c;
  line(){a=b=c=0.0;}
  line(double _a,double _b,double _c):a(_a),b(_b),c(_c){};
};

bool areParallel(line l1,line l2){
    return (fabs(l1.a-l2.a)<EPS)&&(fabs(l1.b-l2.b)<EPS);
}
bool areIntersect(line l1,line l2,point &p){
    if(areParallel(l1,l2))return false;
    p.x = (l2.b*l1.c-l1.b*l2.c)/(l2.a*l1.b-l1.a*l2.b);
    if(fabs(l1.b)>EPS)p.y=-(l1.a*p.x+l1.c);
    else p.y=-(l2.a*p.x+l2.c);
    return true;
}
bool pairCompare(const pair<point,point>& firstElem,const pair<point,point>& secondElem){
  if(firstElem.first.y==secondElem.first.y){
    return firstElem.second.y<secondElem.second.y;
  }
  else
  
  return firstElem.first.y < secondElem.first.y;
}

main(){
	
  int n,k,b,x1,x2;

  scanf("%d",&n);
  
  
  scanf("%d%d",&x1,&x2);
  line la(1,0,-x1),lb(1,0,-x2);
  line l;
  point p1,p2;
  bool bandera;
  vector<pair<point,point> > arr;
  for(int i=0;i<n;i++){
      scanf("%d%d",&k,&b);
      l.a=-k;
      l.c=-b;
      l.b=1;
      if(areIntersect(l,la,p1) && areIntersect(l,lb,p2)){
        arr.push_back(make_pair(p1,p2));
      }
  }
  sort(arr.begin(),arr.end(),pairCompare);
  for(int i=0;i<arr.size()-1;i++){
   // printf("%f,%f  %f,%f\n",arr[i].first.x,arr[i].first.y,arr[i].second.x,arr[i].second.y);
    if(arr[i].first.y==arr[i+1].first.y)
      continue;
    if(arr[i].second.y<=arr[i+1].second.y )
      continue;
    else{
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
}
