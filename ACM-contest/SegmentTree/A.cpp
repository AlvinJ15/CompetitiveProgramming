#include <bits/stdc++.h>
using namespace std;
main(){
  cout<<250000<<endl;	
  for(int i=0;i<250000;i++)
    printf("%d ",i%50000+1);
  cout<<10000<<endl;
  for(int i=1;i<=10000;i++){
    printf("%d %d\n",i*25,(i*25)%50000+1);
  }


}
