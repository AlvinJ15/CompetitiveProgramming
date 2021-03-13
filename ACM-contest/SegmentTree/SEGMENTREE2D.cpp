#include <bits/stdc++.h>
using namespace std;
#define II *2+1
#define DD *2+2
#define midF (U+D)/2
#define midC (R+L)/2
int ST[2000][2000];
int lazy[2000][2000];

void push(int index1,int index2,int U,int D,int L,int R,int l,int r);
int aumentarCol(int index1,int index2,int U,int D,int L,int R,int l,int r,int val);
void pushCol(int index1,int index2,int U,int D,int L,int R,int l,int r){
  if(L>=l && R<=r){
    return ;
  }
  if(R<l||L>r)return;
  push(index1,index2,U,D,L,R,l,r);
  pushCol(index1,index2 II,U,D,L,midC,l,r);
  pushCol(index1,index2 DD,U,D,midC+1,R,l,r);
}
void pushFilas(int index1,int index2,int U,int D,int L,int R,int l,int r){
  if(L>=l && R<=r){
    aumentarCol(index1 II,index2,U,midF,L,R,L,R,lazy[index1][index2]);
    aumentarCol(index1 DD,index2,midF+1,D,L,R,L,R,lazy[index1][index2]);
    lazy[index1][index2]=0;
    return ;
  }
  if(R<l || L>r)return ;
  push(index1, index2, U, D, L, R, l, r);
  pushFilas(index1,index2 II,U,D,L,midC,l,r);
  pushFilas(index1,index2 DD,U,D,midC+1,R,l,r);
}
void push(int index1,int index2,int U,int D,int L,int R,int l,int r){
  aumentarCol(index1,index2 II,U,D,L,midC,L,midC,lazy[index1][index2]);
  aumentarCol(index1,index2 DD,U,D,midC+1,R,midC+1,R,lazy[index1][index2]);
  lazy[index1][index2]=0;
}
int aumentarCol(int index1,int index2,int U,int D,int L,int R,int l,int r,int val){
  if(L>=l && R<=r){
    lazy[index1][index2]+=val;
   // cout<<"RES:"<<(D-U+1)*(R-L+1)*val<<endl;
    return ST[index1][index2]+=(D-U+1)*(R-L+1)*val;
  }
  if(R<l||L>r)return ST[index1][index2];
  push(index1, index2, U, D, L, R, l, r);
  return ST[index1][index2]=aumentarCol(index1,index2 II,U,D,L,midC,l,r,val)+aumentarCol(index1,index2 DD,U,D,midC+1,R,l,r,val);
}
int actualizar(int index1,int index2,int U,int D,int L,int R,int u,int d,int l,int r){
//  cout<<"ACT:"<<ST[index1 II][index2]+ST[index1 DD][index2]<<endl;
  if(L>=l && R<=r)
    return ST[index1][index2]=ST[index1 II][index2]+ST[index1 DD][index2];
  if(R<l || L>r)return ST[index1][index2]=ST[index1 II][index2]+ST[index1 DD][index2];
  return ST[index1][index2]=actualizar(index1,index2 II,U,D,L,midC,u,d,l,r)+actualizar(index1,index2 DD,U,D,midC+1,R,u,d,l,r);
}
void aumentar(int index1,int index2,int U,int D,int L,int R,int u,int d,int l,int r,int val){
  if(U>=u && D<=d){
    aumentarCol(index1,index2,U,D,L,R,l,r,val);
    return;
  }
  if(U>d || D<u)return;
  
  pushFilas(index1,index2,U,D,L,R,l,r);
  aumentar(index1 II,index2,U,midF,L,R,u,d,l,r,val);
  aumentar(index1 DD,index2,midF+1,D,L,R,u,d,l,r,val);
  //cout<<"SEParacion"<<endl;
  actualizar(index1,index2,U,D,L,R,u,d,l,r);
  

}
int consultarCol(int index1,int index2,int U,int D,int L,int R,int l,int r){
  if(L>=l && R<=r){
   // cout<<ST[index1][index2]<<endl;
    return ST[index1][index2];
  
  }
  if(R<l || L>r)return 0;
  push(index1,index2,U,D,L,R,l,r);
  return consultarCol(index1,index2 II,U,D,L,midC,l,r)+consultarCol(index1,index2 DD,U,D,midC+1,R,l,r);
}
int consultar(int index1,int index2,int U,int D,int L,int R,int u,int d,int l,int r){
  if(U>=u && D<=d){
    return consultarCol(index1,index2,U,D,L,R,l,r);
  }
  if(U>d || D<u)return 0;
  pushFilas(index1,index2,U,D,L,R,l,r);
  return consultar(index1 II,index2,U,midF,L,R,u,d,l,r)+consultar(index1 DD,index2,midF+1,D,L,R,u,d,l,r);
}
char grid[500][500];
void imprimir(){
  for(int i=0;i<3;i++){
      printf("[%d]: ",i);
    for(int j=0;j<3;j++){
      printf("%d:%d  ",ST[i][j],lazy[i][j]);
    }
    cout<<endl;

  }
  cout<<endl;
}
main(){
  int T,a,b,c,d,F,C,Q,nR,nB;
  scanf("%d",&T);
  while(T--){
    nR=nB=0;
    memset(ST,0,sizeof ST);
    memset(lazy,0,sizeof lazy);
    scanf("%d%d%d",&F,&C,&Q);
    for(int i=0;i<F;i++){
      scanf("\n");
      for(int j=0;j<C;j++){
        scanf("%c",&grid[i][j]);
      }
    }
    F=C=500;
    aumentar(0,0,0,F-1,0,C-1,255,256,255,256,1);
  /*  aumentar(0,0,0,F-1,0,C-1,1,4,1,2,1);
    aumentar(0,0,0,F-1,0,C-1,1,9,1,2,1);
    aumentar(0,0,0,F-1,0,C-1,4,4,0,2,1);
    aumentar(0,0,0,F-1,0,C-1,4,8,1,1,1);
    aumentar(0,0,0,F-1,0,C-1,3,7,7,9,1);
    aumentar(0,0,0,F-1,0,C-1,7,8,2,7,1);
    aumentar(0,0,0,F-1,0,C-1,2,8,4,8,1);
    aumentar(0,0,0,F-1,0,C-1,0,0,0,1,1);
    imprimir();
    aumentar(0,0,0,F-1,0,C-1,1,1,0,0,1);
    
    imprimir();
    cout<<"QHER"<<endl;*/
 //   printf("%d\n",consultar(0,0,0,F-1,0,C-1,0,1,0,0));
  //  printf("%d\n",consultar(0,0,0,F-1,0,C-1,1,1,0,0));
   // printf("%d\n",consultar(0,0,0,F-1,0,C-1,0,1,0,1));
   // printf("%d\n",consultar(0,0,0,F-1,0,C-1,6,6,2,2));
    //printf("%d\n",consultar(0,0,0,F-1,0,C-1,6,6,3,3));
   // printf("%d\n",consultar(0,0,0,F-1,0,C-1,6,6,4,4));
   // printf("%d\n",consultar(0,0,0,F-1,0,C-1,6,6,5,5));
   // printf("%d\n",consultar(0,0,0,F-1,0,C-1,6,6,6,6));
   // printf("%d\n",consultar(0,0,0,F-1,0,C-1,6,6,7,7));
   // printf("%d\n",consultar(0,0,0,F-1,0,C-1,6,6,2,7));
   // printf("%d\n",consultar(0,0,0,F-1,0,C-1,6,6,2,7));
   // printf("%d\n",consultar(0,0,0,F-1,0,C-1,6,6,2,7));
    //cout<<"-----------------"<<endl;
    /*printf("%d\n",consultar(0,0,0,F-1,0,C-1,0,2,0,3));
    aumentar(0,0,0,F-1,0,C-1,5,5,3,3,1);
    cout<<ST[0][0]<<endl;
    printf("%d\n",consultar(0,0,0,F-1,0,C-1,0,2,0,3));
    aumentar(0,0,0,F-1,0,C-1,1,4,1,2,1);
    aumentar(0,0,0,F-1,0,C-1,1,1,2,3,10);
    printf("%d\n",consultar(0,0,0,F-1,0,C-1,0,5,0,3));
    printf("%d\n",consultar(0,0,0,F-1,0,C-1,0,2,0,3));
    cout<<"-----------------"<<endl;*/
    while(Q--){
    //  cout<<F<<" "<<C<<endl;

      scanf("%d%d%d%d",&a,&b,&c,&d);
      swap(a,b);
      swap(c,d);
     // cout<<a<<b<<" "<<c<<d<<endl;
      a=F-a+1;
      c=F-c+1;
     // cout<<a<<b<<" "<<c<<d<<endl;
      a--;b--;c--;d--;
      //cout<<c<<a<<" "<<b<<d<<endl;
      aumentar(0,0,0,F-1,0,C-1,c,a,b,d,1);

      //printf("VAL: %d\n",consultar(0,0,0,F-1,0,C-1,c,a,b,d));       
    
    }
    for(int i=0;i<F;i++){
      for(int j=0;j<C;j++){
  //      cout<<"a"<<endl;
     //   cout<<(consultar(0,0,0,F-1,0,C-1,i,i,j,j))<<" ";
        if(consultar(0,0,0,F-1,0,C-1,i,i,j,j))
          if(grid[i][j]=='B')
            nB++;
          else
            nR++;
      }
    //  cout<<endl;
    }
   // printf("%d\n",consultar(0,0,0,F-1,0,C-1,0,2,0,2));       
    printf("%d %d\n",nB,nR);
  }

}
