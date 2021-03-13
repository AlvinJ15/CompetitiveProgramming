#include <bits/stdc++.h>
using namespace std;
string p;
int vocal;
bool c;
bool con;
int is(char c){
  return c=='a' || c=='e'||c=='i'||c=='o'||c=='u';
}
main(){
  while(true)	{
    cin>>p;
    vocal=0;
    c=true;
    con=true;
    if(p.size()==3 && p[0]=='e' && p[1]=='n' && p[2]=='d')break;
    for(int i=0;i<p.size();i++){
      if(p[i]=='a' || p[i]=='e' || p[i]=='i' || p[i]=='o' || p[i]=='u')vocal++;
      if(i>0){
        if(p[i]==p[i-1]){
          if(p[i]!='e' && p[i]!='o')
          con=false;}
      }
      if(i>1){
        if((is(p[i-2])+is(p[i-1])+is(p[i]))==3||(is(p[i-2])+is(p[i-1])+is(p[i]))==0)
          c=false;
      }
    }
    cout<<"<"<<p<<">";
    if(vocal>0&&c&&con)
      cout<<" is acceptable."<<endl;
    else
      cout<<" is not acceptable."<<endl;
    
  }


}
