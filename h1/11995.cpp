#include <bits/stdc++.h>
using namespace std;
main(){
	int N,opcion,val,aux;
  int a,b,c;
  stack<int> s;
  queue<int> q;
  priority_queue<int> pq;
  while(scanf("%d",&N)!=EOF){
    while(!s.empty())s.pop();
    while(!q.empty())q.pop();
    while(!pq.empty())pq.pop();
    a=1;
    b=1;
    c=1;
    while(N--){
      scanf("%d%d",&opcion,&val);
      if(opcion==1){
        s.push(val);
        q.push(val);
        pq.push(val);
      }
      else{
        if(s.empty()){a=b=c=0;continue;}
        if(val!=s.top())a=0;
        if(val!=q.front())b=0;
        if(val!=pq.top())c=0;
        s.pop();
        q.pop();
        pq.pop();
      }
    }
    if(a+b+c>1)
      printf("not sure\n");
    else if(a+b+c==0)
      printf("impossible\n");
    else if(a)
      printf("stack\n");
    else if(b)
      printf("queue\n");
    else
      printf("priority queue\n");
      
  }

}
