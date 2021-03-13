#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
void imprimir(){
    printf("SAda\n");
  }
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

vector<Point> convex_hull(vector<Point> p) {
    vector<Point> ret;
    sort(p.begin(), p.end());
    // build lower hull
    for (int i = 0; i < p.size(); ++i) {
        while (ret.size() >= 2 &&
               left_turn(ret[ret.size() - 2], ret[ret.size() - 1], p[i])) {
            ret.pop_back();
        }
        ret.push_back(p[i]);
    }
    int lower_hull_size = ret.size();
    // build upper hull
    for (int i = p.size() - 2; i >= 0; --i) {
        while (ret.size() - lower_hull_size >= 1 &&
               left_turn(ret[ret.size() - 2], ret[ret.size() - 1], p[i])) {
            ret.pop_back();
        }
        ret.push_back(p[i]);
    }
    return ret;
}
 double area(const vector<Point> &P) {
  double result = 0.0, x1, y1, x2, y2;
  for (int i = 0; i < (int)P.size()-1; i++) {
    x1 = P[i].x; x2 = P[i+1].x;
    y1 = P[i].y; y2 = P[i+1].y;
    result += (x1 * y2 - x2 * y1);
  }

  return fabs(result) / 2.0; }
double triangle_area (const Point& p1, const Point& p2, const Point& p3) {
    return abs((double) p1.x * p2.y +
               (double) p2.x * p3.y +
               (double) p3.x * p1.y -
               (double) p1.y * p2.x -
               (double) p2.y * p3.x -
               (double) p3.y * p1.x) / 2.0;
}
double triangle_area2 (const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    vector <Point>  ab;
    ab.push_back(p1);
    ab.push_back(p2);
    ab.push_back(p3);
    ab.push_back(p4);
    ab.push_back(ab[0]);
    return area(ab);
}


map<pair<pair<int,vector<Point> >,pair<int,int> >,double> mapa;
Point pivot(0,0);
struct vec { double x, y;  // name: `vec' is different from STL vector
  vec(double _x, double _y) : x(_x), y(_y) {} };
vec toVec(Point a, Point b) {       // convert 2 points to vector a->b
  return vec(b.x - a.x, b.y - a.y); }
double dist(Point p1, Point p2) {                // Euclidean distance
  return hypot(p1.x - p2.x, p1.y - p2.y); }
double cross2(vec a, vec b) { return a.x * b.y - a.y * b.x; }
bool ccw(Point p, Point q, Point r) {
  return cross2(toVec(p, q), toVec(p, r)) > 0; }
bool collinear(Point p, Point q, Point r) {
  return fabs(cross2(toVec(p, q), toVec(p, r))) < EPS; }


bool angleCmp(Point a, Point b) {                 // angle-sorting function
  if (collinear(pivot, a, b))                               // special case
    return dist(pivot, a) < dist(pivot, b);    // check which one is closer
  double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
  double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
  return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; } 
int N;
vector<Point> arr;
double memo[1001][5];
Point center(0,0);
bool lessa(Point a, Point b)
{
    if (a.x - center.x >= 0 && b.x - center.x < 0)
        return true;
    if (a.x - center.x < 0 && b.x - center.x >= 0)
        return false;
    if (a.x - center.x == 0 && b.x - center.x == 0) {
        if (a.y - center.y >= 0 || b.y - center.y >= 0)
            return a.y > b.y;
        return b.y > a.y;
    }

    // compute the cross2 product of vectors (center -> a) x (center -> b)
    int det = (a.x - center.x) * (b.y - center.y) - (b.x - center.x) * (a.y - center.y);
    if (det < 0)
        return true;
    if (det > 0)
        return false;

    // points a and b are on the same line from the center
    // check which Point is closer to the center
    int d1 = (a.x - center.x) * (a.x - center.x) + (a.y - center.y) * (a.y - center.y);
    int d2 = (b.x - center.x) * (b.x - center.x) + (b.y - center.y) * (b.y - center.y);
    return d1 > d2;
}
/*double area(vector<Point> puntos){
  double a = 0;
  int j = puntos.size()-1;
  for(int i=0;i<puntos.size();i++){
    a+=(puntos[j].x+puntos[i].x)* (puntos[j].y-puntos[i].y);
    j=i;
  }
  //printf("%f\n",a/2);
  return a/2;
}*/
 
 /*double recur(vector<Point> vacio, int index,int m){
  //cout << index <<" "<<m<<" "<<vacio.size()<<endl;
  
  double ans=0;
  //printf("%f\n",mapa[make_pair(make_pair(N,vacio),make_pair(index,m))]);
   if(mapa.count(make_pair(make_pair(N,vacio),make_pair(index,m)))!=0){
  //  cout<< "asdas";
    return mapa[make_pair(make_pair(N,vacio),make_pair(index,m))];
  
  }

  vector<Point> vec1(vacio);
  if(index>=N){
    if(vacio.size()==4||vacio.size()==3){
      vec1.push_back(vec1[0]);
      ans=area(vec1);
      mapa.insert(make_pair(make_pair(make_pair(N,vacio),make_pair(index,m)),ans));
      return ans;
    }
    else
      return 0;
  }
  /*if(memo[index][m]>-0.5){
    return memo[index][m];
  }*/
 
 /* if(N-index==m){
      for(int i =0;i<m;i++){
        vec1.push_back(arr[index+i]);
    vec1.push_back(vec1[0]);
    return memo[index][m]= area(vec1);}
  }
  
  if(vacio.size()==4 ){
    vec1.push_back(vec1[0]);
    ans=area(vec1);
    mapa.insert(make_pair(make_pair(make_pair(N,vacio),make_pair(index,m)),ans));
    return ans;
  }
  if(m==0 ){
    vec1.push_back(vec1[0]);
    ans=area(vec1);
    mapa.insert(make_pair(make_pair(make_pair(N,vacio),make_pair(index,m)),ans));
    return ans;
  }
  if(m==1){
    
    vacio.push_back(vacio[0]);
    ans=area(vacio);
    vacio.erase(vacio.begin()+vacio.size());
    vec1.push_back(arr[index]);
    ans=max(ans,recur(vec1,index+1,m-1));
    mapa.insert(make_pair(make_pair(make_pair(N,vacio),make_pair(index,m)),ans));
    return ans;
  }
  vec1.push_back(arr[index]);
  vector<Point> vec2(vacio);
  ans=max(recur(vec2,index+1,m),recur(vec1,index+1,m-1));
  mapa.insert(make_pair(make_pair(make_pair(N,vacio),make_pair(index,m)),ans));
  return ans;
}*/
  vector<Point> CH(vector<Point> P) {   // the content of P may be reshuffled
  int i, j, n = (int)P.size();
  if (n <= 3) {
    if (!(P[0] == P[n-1])) P.push_back(P[0]); // safeguard from corner case
    return P;                           // special case, the CH is P itself
  }

  // first, find P0 = Point with lowest Y and if tie: rightmost X
  int P0 = 0;
  for (i = 1; i < n; i++){
    if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
      P0 = i;
    //imprimir(); 
  }

  Point temp = P[0]; P[0] = P[P0]; P[P0] = temp;    // swap P[P0] with P[0]

  // second, sort points by angle w.r.t. pivot P0
  pivot = P[0];                    // use this global variable as reference
  sort(++P.begin(), P.end(), angleCmp);              // we do not sort P[0]

  // third, the ccw tests
  vector<Point> S;
  S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);   // initial S
  i = 2;                                         // then, we check the rest
  while (i < n) {          // note: N must be >= 3 for this method to work
    j = (int)S.size()-1;
    if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);  // left turn, accept
    else S.pop_back(); }   // or pop the top of S until we have a left turn
  return S; }
  
main(){
  int T;	
  cin>>T;
  int x,y;
  double resp;
  vector<Point> p,aux;
  while(scanf("%d",&N),N!=-1){
    resp=0;

    arr.clear();
    //mapa.clear();
    //memset(memo,-1,sizeof memo);
    for(int i=0;i< N;i++){
      cin>>x>>y;
      arr.push_back(Point(x,y));
     // imprimir(); 
    }
    //sort(arr.begin(),arr.begin()+N);
    //arr.push_back(arr[0]);
   // imprimir(); 
    p = CH(arr); 
  //  printf("%d\n",p.size());
    p.pop_back();
   // printf("%d\n",p.size());
    
    int A=0,B=1,C=2,D;
    int bA=A,bB=B,bC=C,bD;
    while(true){

          while(true){

            while (triangle_area(p[A],p[B],p[C])<=triangle_area(p[A],p[B],p[C+1%p.size()])){
              C=(C+1)%p.size();
              
            }
            if(triangle_area(p[A],p[B],p[C])<=triangle_area(p[A],p[(B+1)%p.size()],p[C])){
              B=(B+1)%p.size();
              continue;
            }
            else
              break;
          }
          if(triangle_area(p[A],p[B],p[C])>triangle_area(p[bA],p[bB],p[bC])){
            bA=A;bB=B;bC=C;         
          }
          A=(A+1)%p.size();
          if(A==B)B=(B+1)%p.size();
          if(B==C)C=(C+1)%p.size();
          if(A==0)break;
    }
    resp = triangle_area(p[bA],p[bB],p[bC]);

    
   
 
      printf("%2.f\n",resp);
  
  }

}
