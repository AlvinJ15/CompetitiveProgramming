#include <bits/stdc++.h>
using namespace std;
#define II *2+1
#define DD *2+2
#define mid (R+L)>>1
int STF[2][2][1000][4000];
char grid[1000][1000];
int F,C;
struct node{
  int v,index,L,R,P,D,T;
  node(int _v,int _index,int _L,int _R,int _P,int _D,int _T):v(_v),index(_index),L(_L),R(_R),P(_P),D(_D),T(_T){}
};
vector<node> vectorcito;
int aumentarF(int index,int L,int R,int l,int r,int val,int P,int D,int T){
  if(L>=l&&R<=r)return STF[P][T][D][index]+=val;
  if(L>r || R<l)return STF[P][T][D][index];
  return STF[P][T][D][index]=aumentarF(index II,L,mid,l,r,val,P,D,T)+aumentarF(index DD,mid+1,R,l,r,val,P,D,T);
}
int consultarF(int index,int L,int R,int l,int r,int P,int D,int T){
  if(L>=l&&R<=r){
    vectorcito.push_back(node(STF[P][T][D][index],index,L,R,P,D,T));
    return STF[P][T][D][index];
  }

  if(L>r || R<l)return 0;
  return consultarF(index II,L,mid,l,r,P,D,T)+consultarF(index DD,mid+1,R,l,r,P,D,T);
}
int x4[]={-1,0,1,0};
int y4[]={0,1,0,-1};
bool visitedM[1000][1000];
bool visitedG[1000][1000];
/*int buscar(int f,int c,int P,int D,int E){
  //cout<<f<<c<<endl;
      if(f==c)return f;
      if(!E){
        if(consultarF(0,0,(P?C:F)-1,(f+c)/2,c,P,D,0)){
          return buscar((f+c)/2,c,P,D,E);
        }
        else{
          return buscar(f,(f+c)/2-1,P,D,E);
        }
      }
      else{
    //      cout<<"A"<<endl;
        if(consultarF(0,0,(P?C:F)-1,f,(f+c)/2,P,D,0)){
          return buscar(f,(f+c)/2,P,D,E);
        }
        else{
          return buscar((f+c)/2+1,c,P,D,E);
        }
      }
}*/
int buscar(int f,int c,int P,int D,int E){
  //cout <<f<<c<<endl;
  int L,R,index;
  node aux(0,0,0,0,0,0,0);
   //   if(f==c)return f;
      if(!E){

        for(int i=vectorcito.size()-1;i>=0;i--){
          if(vectorcito[i].v){
            aux=vectorcito[i];
            break;
          }
        }
        L=aux.L;
        R=aux.R;
        index=aux.index;
        while(L!=R){
          if(STF[P][aux.T][D][index DD]){
            L=mid+1;
            index=index DD;
          }
          else{
            R=mid;
            index=index II;
          }
        }
      }
      else{
        for(int i=0;i<vectorcito.size();i++){
          if(vectorcito[i].v){
            aux=vectorcito[i];
            break;
          }
        }
        L=aux.L;
        R=aux.R;
        index=aux.index;
        while(L!=R){
          if(STF[P][aux.T][D][index II]){
            R=mid;
            index=index II;
          }
          else{
            L=mid+1;
            index=index DD;
          }
        }
      }
      return L;
}
bool muerto(pair<int,int> var){
  
  bool up=false;
  vectorcito.clear();
  int f=var.first;
  int c=var.second;
  //cout<<f<<"-"<<c<<endl;
  int l,r;
  if(consultarF(0,0,F-1,0,f,0,c,0)==0){
    l=-1;
  }
  else{
    l=buscar(0,f,0,c,0);
  }
  //cout<<"UP:"<<l<<endl;
  if(consultarF(0,0,F-1,l+1,f,0,c,1)){
    up=true;
   // cout<<"up"<<endl;
    return true;
  }
  bool down=false;
  vectorcito.clear();
  if(consultarF(0,0,F-1,f,F-1,0,c,0)==0){
    r=F;
  }
  else{
    r=buscar(f,F-1,0,c,1);
  }
  //cout<<"DOWN:"<<r<<endl;
  if(consultarF(0,0,F-1,f,r-1,0,c,1)){
    down=true;
   // cout<<"down"<<endl;
    return true;
  }

  bool left=false;
  vectorcito.clear();
  if(consultarF(0,0,C-1,0,c,1,f,0)==0){
    l=-1;
  }
  else{
    l=buscar(0,c,1,f,0);
  }
  //cout<<"LEFT:"<<l<<endl;
  if(consultarF(0,0,C-1,l+1,c,1,f,1)){
    left=true;
    //cout<<"left"<<endl;
    return true;
  }

  bool rigth=false;
  vectorcito.clear();
  if(consultarF(0,0,C-1,c,C-1,1,f,0)==0){
    r=C;
  }
  else{
    r=buscar(c,C-1,1,f,1);
  }
  //cout<<"RIGTH:"<<r<<endl;
  if(consultarF(0,0,C-1,c,r-1,1,f,1)){
    rigth=true;
   // cout<<"rigth"<<endl;
    return true;
  }
  
  return false;
}
main(){
  int T;
  int contador;
  int numM;
  cin>>T;
  queue<pair<int,int> > colita;
  pair<int,int> god;
  pair<int,int> pos;
  memset(STF,0,sizeof STF);
  while(T--){
    contador=0;
    numM=0;
    while(!colita.empty())colita.pop();
    scanf("%d%d",&C,&F);
    int ax;
   for(int i=0;i<2;i++){
     for(int j=0;j<F;j++){
        ax=4*C;
        for(int h=0;h<ax;h++){
          STF[0][i][j][h]=0;
        }
     }
   }
   for(int i=0;i<2;i++){
     for(int j=0;j<C;j++){
        ax=4*F;
        for(int h=0;h<ax;h++){
          STF[1][i][j][h]=0;
        }
     }
   }
    for(int i=0;i<F;i++){
      scanf("\n");
      for(int j=0;j<C;j++){
        visitedG[i][j]=false;
        visitedM[i][j]=false;
        scanf("%c",&grid[i][j]);
        if(grid[i][j]=='R'){
          aumentarF(0,0,F-1,i,i,1,0,j,0);
          aumentarF(0,0,C-1,j,j,1,1,i,0);
        }
        if(grid[i][j]=='M'){
          visitedM[i][j]=true;
          numM++;
          aumentarF(0,0,F-1,i,i,1,0,j,1);
          aumentarF(0,0,C-1,j,j,1,1,i,1);
          colita.push(make_pair(i,j));
        }
        if(grid[i][j]=='G'){
          visitedG[i][j]=true;
          god.first=i;
          god.second=j;
        }
      }
    }
  /*  for(int i=0;i<F;i++){
      for(int j=0;j<C;j++){
        printf("%c",grid[i][j]);
      }
      cout<<endl;
    }*/
    bool bucle=true;
    bool ady=false;
    int temp;
    pos.first=god.first;
    pos.second=god.second;
    while(bucle){
      int i;
      bucle =false;
      for(i=0;i<4;i++){
        int ff=pos.first+x4[i];
        int cc=pos.second+y4[i];
        if(ff>=0&&cc>=0&&ff<F&&cc<C&&!visitedG[ff][cc]){
          if(grid[ff][cc]=='R'){
            bucle=true;
            visitedG[ff][cc]=true;
            contador++;
            grid[ff][cc]='.';
            aumentarF(0,0,F-1,ff,ff,-1,0,cc,0);
            aumentarF(0,0,C-1,cc,cc,-1,1,ff,0);
            pos.first=ff;
            pos.second=cc;
            break;
          }
        }
      }
      if(i==4){
        for(int j=0;j<4;j++){
          int ff=pos.first+x4[j];
          int cc=pos.second+y4[j];
          if(ff>=0 && cc>=0 && ff<F&&cc<C&&!visitedG[ff][cc]){
            bucle=true;
            visitedG[ff][cc]=true;
            pos.first=ff;
            pos.second=cc;
            break;
          }
        }
      }
      

      if(visitedM[pos.first][pos.second]){
        break;
      }


      temp=0;
  //    cout<<numM<<endl;
      for(i=0;i<numM;i++){
        pair<int,int> aux = colita.front();colita.pop();
        for(int j=0;j<4;j++){
          int ff=aux.first+x4[j];
          int cc=aux.second+y4[j];
    //      cout<<ff<<" "<<cc<<endl;
          if(ff>=0 && cc>=0 && ff<F&&cc<C && grid[ff][cc]!='R'&& !visitedM[ff][cc]){
            visitedM[ff][cc]=true;
         //   cout<<"M"<<ff<<"-"<<cc<<endl;
            aumentarF(0,0,F-1,ff,ff,1,0,cc,1);
            aumentarF(0,0,C-1,cc,cc,1,1,ff,1);
            colita.push(make_pair(ff,cc));
            temp++;
          }
        }
      }
      numM=temp;
      //verificacion
      if(muerto(pos)){
        bucle=false;
      }
    }
    printf("%d\n",contador);
  }


}
