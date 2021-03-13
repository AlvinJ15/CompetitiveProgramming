
#include <bits/stdc++.h>
using namespace std;
	 int  arbol[4000000];
    
   int built(int a [],int n,int d){
	    for (int i = 0; i < d; i++) {
	    	arbol[i+n]=a[i]; 
    	}
	   for(int i =n-1; i > 0; i--) arbol[i] = arbol[2*i] * arbol[2*i+1];
     return 0;

    }
    int query(int l, int r,int n) {  
	      int res = 1;
	     for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
	    if (l & 1) res =res *arbol[l++];
	    if (r & 1)  res =res *arbol[--r];
	  }
	  return res;
	}
	void modify(int a, int value , int n  ){
  arbol[a+n]= value ;
  for(int i =(a+n )/2; i>0; i/=2 ){
  arbol[i]=arbol[i*2]* arbol[i*2+1];
  
  }}
  int main() {
    int a=0 ;
    int b=0;
    scanf(" %d", &a) ;
    scanf( " %d", &b); 

  	int arr [a] ;
  	for (int i = 0; i <a; i++) {
	  	scanf("%d ", &arr[i]); 
	  }
	  int logi;
  	logi=ceil(log2(a));
  	logi=1<<logi;
  	memset(arbol,1,sizeof arbol);
  	built(arr,logi,a);
    int we[b];
    int consultas  =0;
  
  	for (int i = 0; i < b; i++) {
      char op=0;
	  	int l=0 ;
	  	int h=0;
	  	scanf("%c \n", &op); 
	  	scanf("%d ", &l); 
      scanf("%d ", &h);
	    if(op=='P'){
	    	l--;
        we[consultas]=query( l,  h, logi);
	     	consultas++;
	   }
	    if(op=='C'){
	    	l--;
    
    
        if(h>0)
         h=1;
         if(h<0)
         h=-1;
         modify(l, h,logi );
	  }
	}
    string y ="";
    for(int i =0;i<consultas;i++){

        if(we[i]==0)
        y+='0';
        if(we[i]>0)
       y+='+';
        if(we[i]<0)
        y+='-';
        }
cout<<"\n"<<y<<endl;
	return 0;

}