#include <bits/stdc++.h>
using namespace std;
main(){
	
  string ecuacion;
  int test;
  cin>>test;
  while(test--){
  cin>>ecuacion;
  int ig;
  for(int i=0;i<ecuacion.length();i++)
    if(ecuacion[i]=='='){
      ig=i;
      break;}
  int var=0;
  int signo;
  int rX=0,rN=0;
  bool flag=true;
  for(int i=0;i<ig;i++){
     signo=1;
     flag=true;
     if(ecuacion[i]=='-'){
       signo=-1;
       i++;
     }
     if(ecuacion[i]=='+')
       i++;
     var=0;
     while(i<ig&&ecuacion[i]!='x' && ecuacion[i]!='+'&&ecuacion[i]!='-'){
       var=var*10+ecuacion[i]-'0';
       i++;
     }
     if(ecuacion[i]=='x'){
       flag=false;
       i++;
     }
     if(var==0&&!flag)
       var=1;
     var*=signo;
     flag?rN+=var:rX+=var;
     i--;
  }
  for(int i=ig+1;i<ecuacion.length();i++){
     signo=-1;
     flag=true;
     if(ecuacion[i]=='-'){
       signo=1;
       i++;
     }
     if(ecuacion[i]=='+')
       i++;
     var=0;
     while(i<ecuacion.length()&&ecuacion[i]!='x' && ecuacion[i]!='+'&&ecuacion[i]!='-'){
       var=var*10+ecuacion[i]-'0';
       i++;
     }
     if(i<ecuacion.length() && ecuacion[i]=='x'){
       flag=false;
       i++;
     }
     if(var==0&&!flag)
       var=1;
     var*=signo;
     flag?rN+=var:rX+=var;
     i--;
  }
  if(rX==0&&rN==0)
    cout<<"IDENTITY"<<endl;
  else if(rX==0)
    cout<<"IMPOSSIBLE"<<endl;
  else
    cout<<(int)floor(-1*(double)rN/rX)<<endl;
  }
}
