#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1005

int arr[MAX_N];

void calculate(){
    int i, j;
    for(i = 1; i <= 1000; i++) {
        int sum = 0;
        for(j = 1; j*j <= i; j++) {
            if(i%j == 0) {
                sum += j;
                if(j*j != i)
                    sum += i/j;
            }
        }
        if(sum <= 1000)
            arr[sum] = i;
    }
}

main(){
	for(int i=0;i<MAX_N;i++)
		arr[i] = -1;
	
	calculate();

    int S,cases=0;
    while(scanf("%d", &S),S) {
        printf("Case %d: %d\n", ++cases, arr[S]);
    }
    return 0;
}
