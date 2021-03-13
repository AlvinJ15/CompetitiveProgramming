#include <bits/stdc++.h>
using namespace std;

main(){
  string c;
  int test;
  cin>>test;
  while(test--){
  cin>>c;
  int a =(int) sqrt(c.size());
  if(a*a==c.size()){
   
    char tabla[a][a];
    
    for(int i=0;i<a;i++)
      for(int j=0;j<a;j++){
        tabla[i][j]=c[i*a+j];
      }
    char reemplazo[a][a];
    for(int i=0;i<a;i++)
      for(int j=0;j<a;j++)
         reemplazo[j][i]=tabla[i][j];

    for(int i =0;i<a;i++){
      for(int j=0;j<a/2;j++){
        swap(reemplazo[i][j],reemplazo[i][a-1-j]);
      }
    }
    vector<char> resp;
   /* char reemplazo[a][a];
    for(int i=0;i<a;i++)
      for(int j=0;j<a;j++)
         reemplazo[j][i]=tabla[i][j];*/
    for(int i =0;i<a;i++)
      for(int j=0;j<a;j++)
        if(reemplazo[i][j]!='*')
           printf("%c",reemplazo[i][j]);
    cout<<endl;

  }
  else{
    a=a+1;
    char tabla[a][a];
    for(int i =0;i<a;i++)
      for(int j=0;j<a;j++)
        tabla[i][j]='*';
    for(int i=0;i<a;i++)
      for(int j=0;j<a;j++){
        tabla[i][j]=c[i*a+j];
      }
    char reemplazo[a][a];
    for(int i=0;i<a;i++)
      for(int j=0;j<a;j++)
         reemplazo[j][i]=tabla[i][j];

    for(int i =0;i<a;i++){
      for(int j=0;j<a/2;j++){
        swap(reemplazo[i][j],reemplazo[i][a-1-j]);
      }
    }
    vector<char> resp;
   /* char reemplazo[a][a];
    for(int i=0;i<a;i++)
      for(int j=0;j<a;j++)
         reemplazo[j][i]=tabla[i][j];*/
    for(int i =0;i<a;i++)
      for(int j=0;j<a;j++)
        if(reemplazo[i][j]!='*')
          printf("%c",reemplazo[i][j]);
    cout<<endl;
  }
  }


}
