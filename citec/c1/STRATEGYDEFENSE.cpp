#include <bits/stdc++.h>
using namespace std;
int N;
int memo[3005][3005];
int arr[3005];
int dp(int pos,int act){
  if(pos==N)return 0;
  if(memo[pos][act]!=-1)return memo[pos][act];
  if(arr[pos]>arr[act]){
    return memo[pos][act]=max(1+dp(pos+1,pos),dp(pos+1,act));
  }
  else{
    return memo[pos][act]=dp(pos+1,act);
  }
}
main(){
  int test;
  cin>>test;
  vector<int> resp;
  scanf("\n");
  scanf("\n");
  char c;
  int flag=0;
  int pos,act,var=0;
  int cases=0;
  while(test--){
     flag=1;
     pos=1;
     arr[0]=-1;
     memset(memo,-1,sizeof memo);
     while(scanf("%c",&c),c!=EOF){
       if(c=='\n'&&flag ==1){
         flag=0;
         N=pos;
         if(pos==1){printf("Max hits : 0\n");
          break;
         }
         else{
         printf("Max hits: %d\n",dp(0,0));
         pos=0;
         act=0;
         resp.clear();
         int ant=memo[0][0];
         while(true){
           if(pos==N)break;

           if(max(memo[pos+1][pos],memo[pos+1][act])==ant){
           }
           else{
             if(memo[pos+1][pos]>=memo[pos+1][act]){
               resp.push_back(arr[pos]);
               act=pos;
             }
           }
           pos++;
         }
         for(int i=0;i<resp.size();i++)
           printf("%d\n",resp[i]);
         break;
         }
       }
       if(c=='\n'&& flag==0){
          arr[pos]=var;
          pos++;
          var=0;
          flag=1;
          continue;
       }
          flag=0; 
          var=var*10+c-'0';
     }
     if(cases!=0)printf("\n");
  cases++;
  }
}
