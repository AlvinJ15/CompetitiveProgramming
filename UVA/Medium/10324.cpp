#include <stdio.h>
#define gc getchar_unlocked
#define pc putchar_unlocked
#define MAX_N 1000003

int sumas[MAX_N];
int valores[20];
main(){
    int i=1,R,cases=1,C,Q,a,b,var,rev;
    char c;
    sumas[0]=0;
    while((c=gc()),c!=EOF){
      if(c!='\n'){
        sumas[i]=sumas[i-1]+c-'0';
        i++;
      }
      else{
        printf("Case %d:\n",cases++);
        var=0;
        while((c=gc()),c!='\n'&&c!=EOF){
          var=((var<<3)+(var<<1))+c-'0';
        }
        Q=var;
        for(int j=0;j<Q;j++){
          var=0;
          while((c=gc()),c!='\n'&&c!=EOF&&c!=' '){
            var=((var<<3)+(var<<1))+c-'0';
          }
          a=var;
          var=0;
          while((c=gc()),c!='\n'&&c!=EOF&&c!=' '){
            var=((var<<3)+(var<<1))+c-'0';
          }
          b=var;
          a++,b++;
          R=sumas[a>b?a:b]-sumas[(a<b?a:b)-1];
          if(R==0||R==(a>b?a:b)-(a<b?a:b)+1){
            pc('Y');
            pc('e');
            pc('s');
            pc('\n');
          }
          else{
            pc('N');
            pc('o');
            pc('\n');
          }
        }
        i=1;
        scanf("\n");
      }
    }
}
