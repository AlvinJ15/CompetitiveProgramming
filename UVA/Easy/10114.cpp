#include <bits/stdc++.h>
using namespace std;
main(){
  int a,d,mes;
  double b,c,por,D;
	double meses[102];
  int resp;
  while(scanf("%d%lf%lf%d",&a,&b,&c,&d),a>=0){
    for(int i=0;i<101;i++)
      meses[i]=0;
    for(int i=0;i<d;i++){
      scanf("%d%lf",&mes,&por);
      meses[mes]=por;
    }
    D=c+b;
    b=c/a;
    D=D*(1-meses[0]);
    double ant=meses[0];
    if(c<D){
      printf("0 months\n");
      continue;
    }
    for(int i=1;i<=a;i++){
      c-=b;
      if(meses[i]!=0)ant=meses[i];
      D=D*(1-ant);
      resp=i;
      if(c<D)break;
    }
    if(resp==1)
      printf("1 month\n");
    else
      printf("%d months\n",resp);
  }


}
