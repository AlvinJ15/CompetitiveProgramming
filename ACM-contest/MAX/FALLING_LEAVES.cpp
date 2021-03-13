#include <bits/stdc++.h>
#define DD *2+2
#define II *2+1
#define mid (R+L)/2
using namespace std;
char TREE[100000];
void insertar(int index,char val){
  if(TREE[index]=='$')TREE[index]=val;
  else
  if(val>TREE[index])insertar(index DD,val);
  else insertar(index II,val);
}
void imprimir(int index){
  if(TREE[index]=='$')return;
  else printf("%c",TREE[index]);
  imprimir(index II);imprimir(index DD);
}
vector<string> arr;
main(){
	string p;
  while(true){
    cin>>p;
    if(p[0]!='*'&&p[0]!='$'){
      arr.push_back(p);
    }
    else{
      for(int i=0;i<1000;i++)
        TREE[i]='$';
      for(int i=arr.size()-1;i>=0;i--){
        for(int j=0;j<arr[i].size();j++){
          insertar(0,arr[i][j]);
        }
      }
      imprimir(0);
      printf("\n");
      if(p[0]=='$')break;
      arr.clear();
    }

  }


}
