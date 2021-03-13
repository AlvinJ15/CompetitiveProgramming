#include <bits/stdc++.h>
using namespace std;
main(){
	int T,cases=1;
  cin>>T;
  string p;
  long long k,d;
  while(T--){
    for(int i=0;i<5;i++){
      cin>>p>>k>>d;
      if(k*3<d){
        if(cases!=1)cout<<endl;
        cout<<p<<" plz uninstall";
        cases++;
      }
    }
    for(int i=0;i<5;i++){
      cin>>p>>k>>d;
      if(k*2<d){
        if(cases!=1)cout<<endl;
        cases++;
        cout<<p<<" plz uninstall";
      }
    }
    
  }


}
