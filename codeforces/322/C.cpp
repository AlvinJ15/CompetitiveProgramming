#include <cstring>
#include <cstdio>
#include <cmath>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
main(){
    int n,k,i,suma=0,a,b;
    scanf("%d%d",&n,&k);
    int skill[n];
    for(i=0;i<n;i++)
        scanf("%d",&skill[i]);
    std::sort(skill, skill+sizeof(skill)/sizeof(int));

    for(i=n-1;i>=0 &&k>0;i--){

        if(skill[i]<100){
            
                b=10-skill[i]%10;
                b+=skill[i];
        
                a=b-skill[i];
                if(a<=k){
                    skill[i]+=a;
                    k-=a;
                }
                else{
                    skill[i]+=k;
                    k=0;
                }
            
        }

    }
    for(i=n-1;i>=0;i--){
    	if(skill[i]<100){
    		a=100-skill[i];
    		if(k>=a){
	    		skill[i]+=a;
	    		k-=a;
    		}
    		else{
    			skill[i]+=k;
    			k=0;
    		}
    	}
    	suma+=skill[i]/10;
    }
    printf("%d\n",suma);
}