#include <bits/stdc++.h>
#define EPS 1e-9

using namespace std;

#define REP( i, n ) \
  for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
  for ( int i = (n) - 1; i >= 0; i-- )

typedef long long int64;
typedef complex< int > point;

const int MAXN = 2000;

int T, N, H;
int dp[MAXN][MAXN];
int from[MAXN][MAXN];
point hull[MAXN];
point P[MAXN];

int cross( const point& a, const point& b ) {
  return imag( conj(a) * b );
}

int area2( const point& a, const point& b, const point& c ) {
  return cross( b - a, c - a );
}

namespace std {
  bool operator < ( const point& a, const point& b ) {
    if ( real(a) != real(b) )
          return real(a) < real(b);
    return imag(a) < imag(b);
  }
};
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

int main() {
  vector<Point> p,arr,alvin;
  double resp;
  for ( scanf( "%d", &T ); T--; ) {
    int sol = 0;
    resp=0;
    arr.clear();
    scanf( "%d", &N );
    REP( i, N ) {
      int x, y;
      scanf( "%d %d", &x, &y );
      P[i] = point( x, y );
      arr.push_back(Point(x,y));
    }

    sort( P, P + N );
     p = CH(arr); 

    p.pop_back();

    int A=0,B=1,C=2,D;
    int bA=A,bB=B,bC=C,bD;
    if(p.size()>3){
    while(true){

          while(true){
            //imprimir();
            while (triangle_area(p[A],p[B],p[C])<=triangle_area(p[A],p[B],p[(C+1)%p.size()])){
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
          //cout<<"A:" <<A<<endl;
          if(A==B)B=(B+1)%p.size();
          if(B==C)C=(C+1)%p.size();
          if(A==0)break;
    }}
    alvin.clear();
    alvin.push_back(p[bA]);
    alvin.push_back(p[bB]);
    alvin.push_back(p[bC]);
    sort(alvin.begin(),alvin.begin()+3);
    alvin.push_back(alvin[0]);
    resp = area(alvin);
    //printf("%f\n",resp);
    if(N>3){
    H = 0; int top = 1;
    for ( int i = 0; i < N; hull[H++] = P[i++] )
      while ( H > top &&
        area2( hull[H - 2], hull[H - 1], P[i] ) < 0 )
      H--;

    top = H;
    for ( int i = N - 2; i >= 0; hull[H++] = P[i--] )
      while ( H > top &&
        area2( hull[H - 2], hull[H - 1], P[i] ) < 0 )
      H--;
    H--;
    
    REP( i, H ) from[i][i] = i;

    for ( int delta = 1; delta < H; delta++ )
    REP( i, H ) {
      int j = ( i + delta ) % H;
      dp[i][j] = -1;
      int k = from[i][(j - 1 + H)%H];
      for (;;) {
        int val = area2( hull[i], hull[k], hull[j] );
        assert( val >= 0 );
        if ( val > dp[i][j] ) {
          dp[i][j] = val;
          from[i][j] = k;
        }
        if ( k == from[(i + 1)%H][j] )
              break;
        k = (k + 1) % H;
      }
    }

    
    REP( i, H )
    REP( j, i )
    sol = max( sol, dp[i][j] + dp[j][i] );
  }
    resp = max(resp,(double)sol/2);
    if(resp-int(resp)==0)
      printf("%d\n",(int)resp);
    else
      printf("%d.5\n",(int)resp);
   // printf( "%d.%d\n", sol / 2, 5 * (sol%2) );
  }

  return 0;
}