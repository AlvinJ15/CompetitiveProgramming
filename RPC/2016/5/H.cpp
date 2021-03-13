#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define PI acos(-1.0)
struct point{double x,y;
point(){x=y=0.0;}
point(double _x,double _y):x(_x),y(_y){}
};
struct vec{double x,y;
    vec(double _x,double _y):x(_x),y(_y){}
};
vec toVec(point a,point b){
    return vec(b.x-a.x,b.y-a.y);
}
double norm_sq(vec v){
    return v.x*v.x+v.y*v.y;
}
double dot(vec a,vec b){
    return (a.x*b.x+a.y*b.y);
}

double angle(point a,point o,point b){
    vec oa=toVec(o,a),ob=toVec(o,b);
    return acos(dot(oa,ob)/sqrt(norm_sq(oa)*norm_sq(ob)));
}
double cross(vec a,vec b){
    return a.x*b.y-a.y*b.x;
}
bool ccw(point p,point q,point r){
    return cross(toVec(p,q),toVec(p,r))>0;
}
bool inPolygon(point pt, const vector<point> &P){
   // cout<<P.size()<<endl;
    if((int)P.size()==0)return false;
    double sum=0;
    for(int i=0;i<(int)P.size()-1;i++){
        if(ccw(pt,P[i],P[i+1]))
            sum+=angle(P[i],pt,P[i+1]);
        else sum-=angle(P[i],pt,P[i+1]);
        
    }
    return fabs(fabs(sum)-2*PI)<EPS;
}
main(){
    int test;
    cin>>test;
    int x,y,a,b;
    point var;
    vector<point> P;
    while(test--){
        scanf("%d%d",&a,&b);
        P.clear();
        while(a--){
            scanf("%d%d",&x,&y);
            P.push_back(point(x,y));
        }
        P.push_back(P[0]);
        int resp=0;
        while(b--){
            scanf("%d%d",&x,&y);
            if(inPolygon(point(x,y),P)){
                resp++;
            }
        }
        printf("%d\n",resp);
    }
    
    
}