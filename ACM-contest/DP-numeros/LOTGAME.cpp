#include <bits/stdc++.h>
using namespace std;
int nA[32],nB[32],nK[32];
string DecimalToBinaryString(int a)
{
    string binary = "";
    int mask = 1;
    for(int i = 0; i < 31; i++)
    {
        if((mask&a) >= 1)
            binary = "1"+binary;
        else
            binary = "0"+binary;
        mask<<=1;
    }
    cout<<binary<<endl;
    return binary;
}
main(){
	
  int A,B,K;
  cin>>A>>B>>K;
  

}
