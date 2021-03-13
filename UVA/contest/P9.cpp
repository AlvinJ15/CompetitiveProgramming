#include <stdio.h>                                                                                                                                             
#include <vector> 
#define N 1000
char arr[N][N];
std::vector<int> x;
std::vector<int> y;
int n;

void imprimir(){
    int i,j;
    for(i=0;i<n;i++){
             for(j=0;j<n;j++){
                
                 printf("%c ",arr[i][j]);
             }
             printf("\n");
       }
       printf("\n");
}
  int revisar(int i,int j){
    int a,b;
    a=i;
    int booleano=0;
    if(i<0 || j<0 ||i>n-1 ||j>n-1)
      return 0;
    while(a>=0){
        if(arr[a][j]=='X')
            break;
        if(arr[a][j]=='x')
          return 0;
        a--;
      
    }
    a=i;
    while(a<n){
        if(arr[a][j]=='X')
            break;
        if(arr[a][j]=='x')
          return 0;
        a++;
    }
    a=j;
    while(a>=0){
        if(arr[i][a]=='X')
            break;
        if(arr[i][a]=='x')
          return 0;
        a--;
    }
    a=j;
    while(a<n){
        if(arr[i][a]=='X')
            break;
        if(arr[i][a]=='x')
          return 0;
        a++;
    }
    return 1;
    
}
int libres(int i,int j){
    int num=0;

    if(j>0){
        if(arr[i][j-1]=='.'){
          revisar(i,j-1)?num++:num;
        }
      }
    if(j<n-1){
      if(arr[i][j+1]=='.')
          revisar(i,j+1)?num++:num;
    }
       
    if(i>0) {
      if(arr[i-1][j]=='.')
        revisar(i-1,j)?num++:num;
    }
    if(i<n-1)
      if(arr[i+1][j]=='.')
        revisar(i+1,j)?num++:num;
    
    return num;
}

void llenar(int i,int j){
    int a,b;
    a=i;
    arr[i][j]='x';
    /*while(a>=0){
        if(arr[a][j]=='X')
            break;
        arr[a][j]='x';
        a--;
    }
    a=i;
    while(a<n){
        if(arr[a][j]=='X')
            break;
        arr[a][j]='x';
        a++;
    }
    a=j;
    while(a>=0){
        if(arr[i][a]=='X')
            break;
        arr[i][a]='x';
        a--;
    }
    a=j;
    while(a<n){
        if(arr[i][a]=='X')
            break;
        arr[i][a]='x';
        a++;
    }*/
    
}
int main()
{
    int i,j,k,piedra;
    char c;
   while(scanf("%d",&n)!=EOF){
        k=0;
        piedra=0;
        x.clear();
        y.clear();
       for(i=0;i<n;i++){
           //  for(j=0;j<n;j++){
                 scanf("%s",&arr[i][0]);
                
                     
                 
                 
             //}
       }
       for(i=0;i<n;i++){
        for(j=0;j<n;j++){
          if(arr[i][j]=='X'){
            x.push_back(i);
            y.push_back(j);
          }
        }
       }

      // imprimir();
       for(i=0;i<x.size();i++){
          if(libres(x[i],y[i])==4){
              llenar(x[i],y[i]-1);
              llenar(x[i],y[i]+1);
              llenar(x[i]-1,y[i]);
              llenar(x[i]+1,y[i]);
              x.erase(x.begin()+i);
              y.erase(y.begin()+i);
              i--;
              piedra+=4;
          }
       }
      //imprimir();
       for(i=0;i<x.size();i++){
          if(libres(x[i],y[i])==3){
              if(revisar(x[i],y[i]-1)&&arr[x[i]][y[i]-1]=='.' )
                llenar(x[i],y[i]-1);
              if(revisar(x[i],y[i]+1)&&arr[x[i]][y[i]+1]=='.')
                llenar(x[i],y[i]+1);
              if(revisar(x[i]-1,y[i])&&arr[x[i]-1][y[i]]=='.')
                llenar(x[i]-1,y[i]);
              if(revisar(x[i]+1,y[i])&&arr[x[i]+1][y[i]]=='.')
                llenar(x[i]+1,y[i]);
              x.erase(x.begin()+i);
              y.erase(y.begin()+i);
              i--;
              piedra+=3;
          }
       }
       //imprimir();
        for(i=0;i<x.size();i++){
          if(libres(x[i],y[i])==2){
              if(revisar(x[i],y[i]-1)&&arr[x[i]][y[i]-1]=='.')
                llenar(x[i],y[i]-1);
              if(revisar(x[i],y[i]+1)&&arr[x[i]][y[i]+1]=='.')
                llenar(x[i],y[i]+1);
              if(revisar(x[i]-1,y[i])&&arr[x[i]-1][y[i]]=='.')
                llenar(x[i]-1,y[i]);
              if(revisar(x[i]+1,y[i])&&arr[x[i]+1][y[i]]=='.')
                llenar(x[i]+1,y[i]);
              x.erase(x.begin()+i);
              y.erase(y.begin()+i);
              i--;
              piedra+=2;
          }
       }
    // imprimir();
       for(i=0;i<x.size();i++){
          if(libres(x[i],y[i])==1){
              if(revisar(x[i],y[i]-1)&&arr[x[i]][y[i]-1]=='.')
                llenar(x[i],y[i]-1);
              if(revisar(x[i],y[i]+1)&&arr[x[i]][y[i]+1]=='.')
                llenar(x[i],y[i]+1);
              if(revisar(x[i]-1,y[i])&&arr[x[i]-1][y[i]]=='.')
                llenar(x[i]-1,y[i]);
              if(revisar(x[i]+1,y[i])&&arr[x[i]+1][y[i]]=='.')
                llenar(x[i]+1,y[i]);
              x.erase(x.begin()+i);
              y.erase(y.begin()+i);
              i--;
              piedra+=1;
          }
       }
      //imprimir();
       for(i=0;i<n;i++){
           for(j=0;j<n;j++){
               if(arr[i][j]=='.' && revisar(i,j)){
                   llenar(i,j);
                   piedra++;
               }
           }
       }
      
     //  imprimir();
      printf("%d\n",piedra);
   }
}
