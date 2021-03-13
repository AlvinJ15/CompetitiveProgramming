#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
main(){
	int rarity,k;
  ll twilight = 1;
  scanf("%d%d",&rarity,&k);
  ll div = rarity/k;
  ll pinkiePie[div], flutterShy[div];
  for(int i =0;i< div;i++){
    scanf("%lld",&pinkiePie[i]);
  }
  for(int i =0;i<div;i++){
    scanf("%lld",&flutterShy[i]);
  }
  for(int i =0;i<div;i++){
    twilight%=1000000007;
    twilight*=((ll)floor((pow(10,k)-1)/pinkiePie[i])+1   -  ( (ll) floor(  ( pow(10,k-1)*(flutterShy[i]+1) -1) /pinkiePie[i] )    - (ll) ceil((pow(10,k-1)*flutterShy[i])/pinkiePie[i])  +1))  % 1000000007;
  twilight%=1000000007;
  }
  printf("%lld\n",twilight%1000000007);
  

}
