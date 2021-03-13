#include <bits/stdc++.h>
using namespace std;
char palabra [100010];
char respuesta [300010];
bool pal(int i,int j){
  while(i<=j){
    if(respuesta[i]!=respuesta[j])return false;
    i++;j--;
  }
  return true;
}
main(){
  int n;
  int i,j,a,b,fin;
  while(scanf("%100010s",palabra)!=EOF){
    n=(int)strlen(palabra);
    
    i=0,j=n-1,a=0,b=300000;
    for(i=0;i<n;i++){
      respuesta[i]=palabra[i];
    }
    fin=n-1;
    while(true){
      if(pal(0,fin))break;
      respuesta[fin+1]=respuesta[j-1];
      fin++;
      j--;
    }
    /*for(int l=0;l<300010;l++)
      respuesta[l]='$';
    while(i<=j){
      if(i==j){
        respuesta[a]=palabra[i];
        break;
      }
      if(palabra[i]==palabra[j]|| palabra[i]+32==palabra[j]||palabra[i]-32==palabra[j]){
        respuesta[a++]=palabra[i];
        respuesta[b--]=palabra[j];
        i++;j--;
      }
      else{
        respuesta[a++]=palabra[i];
        respuesta[b--]=palabra[i];
        i++;
      }
    }
    for(int i=0;i<300010;i++){
      if(respuesta[i]!='$')
        printf("%c",respuesta[i]);
    }*/
    for(i=0;i<=fin;i++)
      printf("%c",respuesta[i]);
    printf("\n");
  }

}
