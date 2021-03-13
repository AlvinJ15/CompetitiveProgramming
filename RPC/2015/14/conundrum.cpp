#include <bits/stdc++.h>
using namespace std;
main(){
  string c;
  cin>>c;
	int i =0,co=0;
  for(int i =0;i<c.size();i++){
    if(i%3==0)
      if(c[i]!='P')
        co++;
    if(i%3==1) 
      if(c[i]!='E')
          co++;
    if(i%3==2)
      if(c[i]!='R')
        co++;
  }
  cout<<co<<endl;

}
