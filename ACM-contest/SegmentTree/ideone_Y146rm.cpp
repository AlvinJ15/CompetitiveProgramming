#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;

#define MAXN 250002
int n;
int L;
int A[MAXN];
int Q[600];
vector<int> QS[600];
int BIT[50002];

inline int query( int x ){
  int ans = 0;
  for( ; x > 0 ; x -= ( x & -x) )
    ans += BIT[x];
  return ans;
}
inline void update( int x ){
  for( ; x <= 50000 ; x += ( x & -x) )
    ++BIT[x];
}
long long count ( ){
  memset( BIT , 0 , sizeof BIT );
  long long ans = 0;
  for( int i = 0 ; i < n ; ++i ){
    int tmp = 50000 - A[i] + 1;
    ans += query( tmp - 1 );
    update( tmp );
  }
  return ans;
}



void construct(){
  int sg = 0;
  for( int i = 0 ; i < n ; i += L ){
    QS[sg].clear();
    for( int j = i ; j < min( n , i + L  ) ; ++j )
      QS[sg].push_back( A[ j ] );
    sort( QS[sg].begin() , QS[sg].end() );
    ++sg;
  }
}
inline int update( int pos , int val ){
  int ans = 0;
  int oldv = A[pos];
  int cs = pos / L ;
  int ini = cs * L , lim = min( n , ( cs + 1) * L  );
  for( int st = cs  - 1 ; st >= 0 ; --st ){
    ans -= (int)( QS[st].end() -  upper_bound( QS[st].begin(), QS[st].end() , oldv) );
    ans += (int)( QS[st].end() -  upper_bound( QS[st].begin(), QS[st].end() , val) );
  }
  for( int i = ini ; i < pos ; ++i  ){
    ans -= ( A[i] > oldv ? 1 : 0 ) ;
    ans += ( A[i] > val ? 1 : 0 ) ;
  }
  A[pos] = val;
  //QS[cs].clear();
  int k =  -1; 
  //put
  // menores :V
  for( int st = cs  + 1 ; QS[st].size() > 0  ; ++st ){
    ans -= (int)( lower_bound( QS[st].begin(), QS[st].end() , oldv) - QS[st].begin() )  ;
    ans += (int)( lower_bound( QS[st].begin(), QS[st].end() , val) -  QS[st].begin()  )  ;
  }
  for( int i = pos + 1 ; i < lim  ; ++i  ){
    ans -= ( A[i] < oldv ? 1 : 0 ) ;
    ans += ( A[i] < val ? 1 : 0 ) ;
  }
  // put in place
  A[ pos ] = val ;
  for( int i = QS[ cs ].size() - 1    ; i >= 0 ; --i  )
    if( QS[ cs ][ i ] == oldv ){
      QS[ cs ][ i ] = val;
      break;
    }
  vector<int> & tmp = QS[cs];
  for( int i = 0   ; i < tmp.size() ; ++i  ){
    int j = i - 1;
    int val = tmp[i];
    while( j >= 0 and tmp[ j ] > val ){
      tmp[ j + 1 ] = tmp[ j ];
      --j;
    }
    tmp[ j + 1 ] = val;
  }
  return ans;
}
inline bool get( int &n ){
  char c;
  do{
    c = getchar_unlocked();
    if( c == EOF ) return false;
  }while( c < '0' || c > '9' );  

  n = 0;
  do{
    n = 10 * n + c - '0';
    c = getchar_unlocked();
  }while( c >= '0' && c <= '9' );  
  return true;
}

int main(){
  get(n);
  for(int i = 0 ; i < n ; ++i ){
    get(A[i]);
  }
  L = sqrt( n );
  long long ans = count();
  construct();
  int m , a , b ;
  cin >> m;
  while( m-- ){
    get(a);get(b);
    --a;
    ans += update( a  , b );
    printf("%lld\n",ans);
  }
  return 0;
}