#include <bits/stdc++.h>
using namespace std;
main(){
	double fatiga,altura;
  int dia,H,U,D,F;
  while(scanf("%d%d%d%d",&H,&U,&D,&F),H|U|D|F){
     fatiga=U*((F/(double)100));
     altura=0;
     dia=0;
     altura=0;
     while(altura>=0){
       if(U-fatiga*dia>0)
       altura+=(double)((double)U-fatiga*dia);
       dia++;
       if(altura>H)break;
       altura-=D;
     }
     if(altura<0)
       printf("failure on day %d\n",dia);
     else
       printf("success on day %d\n",dia);
  }  

}
