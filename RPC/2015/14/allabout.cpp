#include <bits/stdc++.h>
using namespace std;
string X,Y,op,Z,ig;
vector<char> resp;
void base(int base){
  double rX=0,rY=0,rZ=0;
  double temp;
  //cout<<"BASE:"<<base<<endl;
  for(int i =X.size()-1;i>=0;i--){
    if(base==1)
      if(X[i]!='1')
        return;
    if(X[i]>='0' && X[i]<='9'){
      temp=((X[i]-'0')*(pow(base,X.size()-1-i)));
      rX+=temp;
    }
    else{
      rX+=(X[i]-'a'+10)*pow(base,X.size()-1-i);
    }
  }
  //cout<<"X:"<<rX<<endl;
  
  for(int i =Y.size()-1;i>=0;i--){
    if(base==1)
      if(Y[i]!='1')
        return;
    if(Y[i]>='0' && Y[i]<='9'){
      rY+=(Y[i]-'0')*pow(base,Y.size()-1-i);
    }
    else{
      rY+=(Y[i]-'a'+10)*pow(base,Y.size()-1-i);
    }
  }
 // cout<<"Y:"<<rY<<endl;
  
  for(int i =Z.size()-1;i>=0;i--){
    if(base==1)
      if(Z[i]!='1')
        return;
    if(Z[i]>='0' && Z[i]<='9'){
      rZ+=(Z[i]-'0')*pow(base,Z.size()-1-i);
    }
    else{
      rZ+=(Z[i]-'a'+10)*pow(base,Z.size()-1-i);
    }
  }
  //cout<<"Z:"<<rZ<<endl;

  if(op[0]=='+'){

    if(rX+rY==rZ){
      if(base==36){
        resp.push_back('0');}
      else{
        if(base>=10)
            resp.push_back(base-10+'a');
        else
          resp.push_back(base+'0');}
    }
  }
   
  if(op[0]=='-'){
    
    if(rX-rY==rZ){
      if(base==36){
        resp.push_back('0');}
      else{

      if(base>=10)
          resp.push_back(base-10+'a');
      else
        resp.push_back(base+'0');}
    }
  }

  if(op[0]=='*'){ 
    if(rX*rY==rZ){
      if(base==36){
        resp.push_back('0');}
      else{
      if(base>=10)
          resp.push_back(base-10+'a');
      else
        resp.push_back(base+'0');}
    }
  }

  if(op[0]=='/'){
    if(rX/rY==rZ){
      if(base==36){
        resp.push_back('0');}
      else{
      if(base>=10)
          resp.push_back(base-10+'a');
      else
        resp.push_back(base+'0');}
    }
  }
}
main(){
  int test;
  cin>>test;
  while(test--){
    resp.clear();
    cin>>X>>op>>Y>>ig>>Z;
    char var='0';
    for(int i =0;i<X.size();i++)
      if(X[i]>=var)
        var=X[i];
    for(int i =0;i<Y.size();i++)
      if(Y[i]>=var)
        var=Y[i];
    for(int i =0;i<Z.size();i++)
      if(Z[i]>=var)
        var=Z[i];
    if(var!='1'){
      if(var>='0' && var<='9'){
        var=var-'0'+1; 
      }
      else{
        var=var-'a'+11;
      }
    }
    else
      var=1;
    for(int i =var;i<=36;i++){
      base(i);
    }
    if(resp.size()==0)
      cout<<"invalid";
    else{
      for(int i =0;i<resp.size();i++)
        printf("%c",resp[i]);
    }
    
    printf("\n");
  
  
  
  }


}
