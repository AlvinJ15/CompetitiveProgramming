#include <bits/stdc++.h>
using namespace std;
main(){
  int arr[6][3];
  int perm[]={0,1,2,3,4,5};
  int suma;
  while(true){
    for(int i=0;i<6;i++){
      for(int j=0;j<3;j++){
        scanf("%d",&arr[i][j]);
      }
    }
    sort(perm,perm+6);
      suma=-1;
    do{
        for(int j=0;j<3;j++)
         for(int k=0;k<3;k++)
           for(int l=0;l<3;l++)
             for(int m=0;m<3;m++)
              for(int n=0;n<3;n++)
                for(int o=0;o<3;o++){
                  if(arr[perm[0]][j%3]==arr[perm[5]][(o+1)%3]&&
                     arr[perm[1]][k%3]==arr[perm[0]][(j+1)%3]&&
                     arr[perm[2]][l%3]==arr[perm[1]][(k+1)%3]&&
                     arr[perm[3]][m%3]==arr[perm[2]][(l+1)%3]&&
                     arr[perm[4]][n%3]==arr[perm[3]][(m+1)%3]&&
                     arr[perm[5]][o%3]==arr[perm[4]][(n+1)%3]
                     )
                    suma=max(suma,arr[perm[0]][(j+2)%3]+arr[perm[1]][(k+2)%3]+arr[perm[2]][(l+2)%3]+arr[perm[3]][(m+2)%3]+arr[perm[4]][(n+2)%3]+arr[perm[5]][(o+2)%3]);
                  
                  
                }
        
    }
    while(next_permutation(perm,perm+6));
    if(suma<0){
      printf("none\n");
    }
    else{
      printf("%d\n",suma);
    }











    char c;
    scanf("\n");
    scanf("%c",&c);
    if(c=='$')break;
  }

}
