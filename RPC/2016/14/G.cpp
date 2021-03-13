#include <bits/stdc++.h>
using namespace std;

int main(){
  int x1,x2,x3,y1,y2,y3;
  scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
  double r;
  scanf("%lf",&r);
  double a,b,c;
  a = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
  b = sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
  c = sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
  double r2;
  double A = 0.25*sqrt(4*pow(a,2)*pow(b,2)-pow(a*a+b*b-(c*c),2));
  r2= (2*A)/(a+b+c);
  double resp = abs(r-r2);
  double porcent = (resp*100.0)/r;
  if(r==r2){
    printf("0\n");return 0;
  }
  if(r2<r){
    printf("-%.3lf\n",porcent);
  }
  else{
    printf("%.3lf\n",porcent);
  }

}
