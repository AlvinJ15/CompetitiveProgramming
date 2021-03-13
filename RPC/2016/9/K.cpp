#include <bits/stdc++.h>
using namespace std;
#define EPS 
struct point{int x,y;
  point(){x=y=0;}
  point (int _x,int _y):x(_x),y(_y){}
};
point center;
bool lessi(point a, point b)
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

                  // compute the cross product of vectors (center -> a) x (center -> b)
                  int det = (a.x - center.x) * (b.y - center.y) - (b.x - center.x) * (a.y - center.y);
                      if (det < 0)
                                return true;
                          if (det > 0)
                                    return false;

                              // points a and b are on the same line from the center
                              // check which point is closer to the center
                              int d1 = (a.x - center.x) * (a.x - center.x) + (a.y - center.y) * (a.y - center.y);
                                  int d2 = (b.x - center.x) * (b.x - center.x) + (b.y - center.y) * (b.y - center.y);
                                      return d1 > d2;
}

vector<point> elem;
main(){
	int N;
  int x,y,sx,sy;
  while(scanf("%d",&N),N){
    elem.clear();
    sx=0;sy=0;
    for(int i=0;i<N;i++){
      scanf("%d%d",&x,&y);
      sx+=x;
      sy+=y;
      elem.push_back(point(x,y));
    }
    center= point(sx/elem.size(),sy/elem.size());
    sort(elem.begin(),elem.end(),lessi);
    for(int i=0;i<N;i++){
      printf("%d %d\n",elem[i].x,elem[i].y);
    }
    cout<<endl;
  }


}
