#include <bits/stdc++.h>
using namespace std;
main(){
	int n;
  string palabra,resp;
  int letras[26];
  cin>>n<<endl; 
  while(n--){
    getline(cin,palabra);
    cout<<palabra<<endl;
    resp="missing ";
    for(int i =0;i< 26;i++)
      letras[i]=0;
    
    for(int i =0;i<palabra.size();i++){
      if(palabra[i]<='z' && palabra[i]>='a'){
        letras[palabra[i]-'a']++;
      }
      if(palabra[i]>='A' && palabra[i]<='Z'){
        letras[palabra[i]+32-'a']++;
      }
    
    }
    for(int i=0;i<26;i++){
      if(letras[i]==0){
        resp+=i+'a';
      }
    }
    if(resp.size()==8){
      printf("paragram\n");
      //cout<<resp<<endl;
    }
    else
      cout<<resp<<endl;
  
  
  
  }
  
  

}
