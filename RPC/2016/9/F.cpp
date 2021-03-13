#include <bits/stdc++.h>
using namespace std;
double dlog(double base ,double x){
  return log(x)/log(base);
}
main(){
  int T;
  double digits[3];
  int cases=1;
  int arr2[3];
  int arr[3][3000];
  cin>>T;
  double preCalc[2505];
  double preCalc2[2505];
  for(int i=2;i<2505;i++){
    preCalc[i]=dlog(10,i);
  }
  preCalc2[1]=0;
  for(int i=2;i<2505;i++){
    preCalc2[i]=preCalc[i]+preCalc2[i-1];
  }
  while(T--){
    digits[0]=0;
    digits[1]=0;
    digits[2]=0;
    for(int i=0;i<3;i++)
     scanf("%d",&arr2[i]);
    for(int i=0;i<3;i++){
      for(int j=0;j<arr2[i];j++){
        scanf("%d",&arr[i][j]);
        if(arr[i][j]>1)
          digits[i]+=preCalc2[arr[i][j]];
       /* for(int h=2;h<arr[i][j];h++){
          digits[i]+=dlog(10,h);
        }*/
      }
    }
    double maxi =-1;
    int ind=0;
    for(int i=0;i<3;i++){
      if(maxi<digits[i]){
        maxi=digits[i];
        ind=i;
      }
    }
    double val =0.0001;
    int contadorcito=0;
    for(int i=0;i<3;i++){
    //  cout<<digits[i]<<endl;
      if(maxi-digits[0]<=val)
        contadorcito++;
    }
   // cout<<endl;
    if(contadorcito>1){
      printf("Case #%d: TIE\n",cases++);
    }
    else{
      printf("Case #%d: %c\n",cases++,ind+'A');
    }
  }

}
