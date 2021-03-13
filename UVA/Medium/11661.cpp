#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pc(x) putchar_unlocked(x);
inline void writeInt (long long n)
  {
                long long N = n, rev, count = 0;
                        rev = N;
                                if (N == 0) { pc('0'); return ;}
                                        while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
                                                rev = 0;
                                                        while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
                                                                while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
                                                                        while (count--) pc('0');
                                                                            }
main(){
  int var2=sizeof(int)*CHAR_BIT-1;
	int R,L,N,minimo,var;
  char c;
  while(true){
    var=0;
    while((c=gc()),c!='\n'&&c!=EOF){
      var=(var<<3)+(var<<1)+c-'0';
    }
    N=var;
    if(!N)break;
    R=L=-100000000;
    minimo=100000000;
    for(int i=0;i<N;i++){
      c=gc();
      if(c=='D'){
        var=i-R+1;
        minimo=var+((minimo-var)&((minimo-var)>>(var2)));
        //  minimo<var?minimo:var;
        L=i;
      }
      if(c=='R'){
        var=i-L+1;
        minimo=var+((minimo-var)&((minimo-var)>>(var2)));
        //minimo=minimo<var?minimo:var;
        R=i;
      }
      if(c=='Z')
        minimo=1;
    }
    gc();
    writeInt(minimo-1);
    pc('\n');
  }


}
