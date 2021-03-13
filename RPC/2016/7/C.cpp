#include <bits/stdc++.h>
using namespace std;
int arr[100005];
bool func(int a,int b){
  return a>b;
}
main(){
  char s[100005];
  bool positivo;
  int suma;
  vector<int> sortear;
  while(1){
    suma=0;
    positivo=false;
    scanf("%s",s);

    int tam= strlen(s);
    if(s[0]=='E')break;
    if(s[0]!='-'){
    for(int k=0;k<tam;k++){
      arr[k]=s[k]-'0';
      suma+=arr[k];
    }
    int i;
    int acumulado=0;
    for(i=tam-1;i>=1;i--){
      acumulado+=9-arr[i];
      if(acumulado>=2){
        positivo=true;
        break;
      }
    }
    int indice;
    int k;
    if(positivo){
      for(k=i-1;k>=0;k--){
        if(arr[k]>=1){
          arr[k]-=1;
          for(int h=tam-1;h>=i;h--){
            if(arr[h]<9){
              arr[h]+=1;
              break;
            }
          }
          for(int h=tam-1;h>=i;h--){
            if(arr[h]<9){
              arr[h]+=1;
              break;
            }
          }
          break;
        }
      }
      sortear.clear();
      for(int j=k+1;j<tam;j++){
        sortear.push_back(arr[j]);
      }
      sort(sortear.begin(),sortear.end(),func);
      if(arr[0]!=0){
        printf("%d",arr[0]);
      }
      for(int h=1;h<=k;h++){
        printf("%d",arr[h]);
      }
      for(int h=0;h<sortear.size();h++)
        printf("%d",sortear[h]);
    }
    else{
      int div=suma/9;
      if((suma%9+1)!=0){
        printf("-%d",suma%9+1);
      }
      for(int h=0;h<div;h++)
        printf("%d",9);
    }
    printf("\n");
    }
    else{
      vector<int> resp;
      int h;
      bool flag=true;
      printf("-");
      for(h=tam-1;h>=1;h--){
        if(s[h]<'9'&&flag){
          s[h]++;
          flag=false;
        }
        resp.push_back(s[h]-'0');
      }
      if(flag)
        resp.push_back(1);
      reverse(resp.begin(),resp.end());
      for(int h=0;h<resp.size();h++)
        printf("%d",resp[h]);
      printf("\n");
    }
  }


}
