#include <stdio.h>                                                                                                                                             
#include <cstring>                                                                                                                                             
#include <cmath>                                                                                                                                               
#include <stdlib.h>                                                                                                                                            
#include <algorithm>                                                                                                                                           
#include <math.h>                                                                                                                                              
                                                                                                                                                               
main(){                                                                                                                                                        
        int n,i,j=0;                                                                                                                                               
        scanf("%d",&n);                                                                                                                                 
        int x[n*n];                                                                                                                                          
      
        for(i=0;i<n*n;i++){                                                                                                                                  
                scanf("%d",&x[i]);                                                                                                                   
        }            
      
        std::sort(x,x+sizeof(x)/sizeof(int));
       
         int var = x[n*n-1];
         printf("%d ",var);
         int c=1;
         int rep=1;
        for(i=n*n-1;i>=0;i--){
            
            if(x[i]!=var && c<n){
                rep++;
                var=x[i];
                printf("%d ",var);
                c++;
            }
        }
        int repetidosi[rep];
        int repetidoscount[rep];
        memset(&repetidosi,0,sizeof(int)*rep);
        memset(&repetidoscount,0,sizeof(int)*rep);
        var=0;
        j=-1;
        for(i=n*n-1;i>=0;i--){
            
            if(x[i]!=var){
                var=x[i];
               
                j++;
                repetidosi[j]=x[i];
                repetidoscount[j]=1;


            
            }
            else{
                repetidoscount[j]+=1;
              
            }
            
        }
        int a;
        j=0;
        while(c<n &&j<=rep){
            
            a=(int)sqrt(repetidoscount[j])-1;
            //printf("%d ",c);
            for(i=0;i<a && c<n;i++){
                printf("%d ",repetidosi[j]);
                c++;
            }
            j++;
            
        }
                                                                                                                                              
                                                                                                                                                               
                                                                                                                                                               
}               