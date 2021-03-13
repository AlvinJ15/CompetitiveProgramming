#include <bits/stdc++.h>
using namespace std;
main(){
  string palabra1,palabra2;
	int suma1,suma2;
  while(getline(cin,palabra1)){
    getline(cin,palabra2);
    suma1=suma2=0;
    for(int i=0;i<palabra1.size();i++){
      if((palabra1[i]>='a'&&palabra1[i]<='z') || (palabra1[i]>='A'&&palabra1[i]<='Z')){
        if(palabra1[i]>='a'&&palabra1[i]<='z')
          suma1+=palabra1[i]-'a'+1;
        else
          suma1+=palabra1[i]-'A'+1;
      }
    }
    for(int i=0;i<palabra2.size();i++){
      if((palabra2[i]>='a'&&palabra2[i]<='z') || (palabra2[i]>='A'&&palabra2[i]<='Z')){
        if(palabra2[i]>='a'&&palabra2[i]<='z')
          suma2+=palabra2[i]-'a'+1;
        else
          suma2+=palabra2[i]-'A'+1;
      }
    }
    while(suma1>=10){
      int v=suma1;
      int aux=0;
      while(v){
        aux+=v%10;
        v/=10;
      }
      suma1=aux;
    }
    while(suma2>=10){
      int v=suma2;
      int aux=0;
      while(v){
        aux+=v%10;
        v/=10;
      }
      suma2=aux;
    }
    double p1=(100.0*suma2)/suma1;
    double p2=(100.0*suma1)/suma2;
    if(suma1==0&&suma2==0)
      printf("\n");
    else{
      printf("%.2f",min(p1,p2));
      cout<<" %"<<endl;
    }
   
  }


}
