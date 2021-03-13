#include <bits/stdc++.h>
using namespace std;
main(){
	vector<string> palabra;
  palabra.push_back("Happy");
  palabra.push_back("birthday");
  palabra.push_back("to");
  palabra.push_back("you");
  palabra.push_back("Happy");
  palabra.push_back("birthday");
  palabra.push_back("to");
  palabra.push_back("you");
  palabra.push_back("Happy");
  palabra.push_back("birthday");
  palabra.push_back("to");
  palabra.push_back("Rujia");
  palabra.push_back("Happy");
  palabra.push_back("birthday"),
  palabra.push_back("to");
  palabra.push_back("you");
  int N;
  string persona;
  scanf("%d",&N);
  vector<string> personas;
  for(int i=0;i<N;i++){
    cin>>persona;
    personas.push_back(persona);
  }
  if(N>palabra.size()){
    for(int i=0;i<palabra.size()*2;i++){
      cout<<personas[i%N]<<": "<<palabra[i%palabra.size()]<<endl;
    }
  }
  else
    for(int i=0;i<palabra.size();i++){
      cout<<personas[i%N]<<": "<<palabra[i]<<endl;
    }

}
