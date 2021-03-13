
#include <stdio.h>
#include <math.h>
using namespace std;
int esPrimo(int n){
    int a=2;
    while(a<=sqrt(n)){
        if(n%a==0){
            return 0;
        }
    }
    return 1;
}
int main() {
	char c;
	int sum=0;
	while((c=getchar()) != EOF){
		printf("%d",c=='\n');
	   if(c!='\n'){
	       
	       if(c>='a' && c<='z'){
	           
	           sum+=(c-'a'+1);
	       }
	       if(c>='A' && c<='Z'){
	           sum+=(c-'A'+27);
	           printf("%d ",sum);
	       }
	     
	   }
	   else{
	       if(esPrimo(sum))
	           printf("It is a prime word.\n");
	       else
	        printf("It is not a prime word.\n");
	    
	  
            sum=0;
	   }
	    
	}
}
