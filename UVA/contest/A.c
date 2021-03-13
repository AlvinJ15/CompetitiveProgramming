
#include <stdio.h>
/*int esPrimo(int n){
    int a=2;
    while(a*a<=n){
        if(n%a==0){
            return 0;
        }
        a++;
    }
    return 1;
}*/
    int esPrimo(int n){
    	int i;
    	if(n==2)return 1;
	 if(!(n&1))return 0;
	 for(i = 3 ; i*i <= n ; i += 2)
	     if(!(n % i))return 0;
	 return 1;

    }
int main() {
	char c;
	int sum=0;
	while((c=getchar())!=EOF){
		
	   if(c!='\n'){
	       
	       if(c>='a' && c<='z'){
	           
	           sum+=(c-'a'+1);
	       }
	       if(c>='A' && c<='Z'){
	           sum+=(c-'A'+27);
	          
	       }
	     
	   }
	   else{
	   		if(sum==0)continue;
	       if(esPrimo(sum))
	           printf("It is a prime word.\n");
	       else
	        printf("It is not a prime word.\n");
	    
	  
            sum=0;
	   }
	    
	}
	if(sum!=0){
	 if(esPrimo(sum))
	           printf("It is a prime word.\n");
	       else
	        printf("It is not a prime word.\n");
	}
}
