#include <bits/stdc++.h>
using namespace std;
main(){
  map<string,string> mapa;
  mapa["HELLO"]="ENGLISH";
  mapa["HOLA"]="SPANISH";
  mapa["HALLO"]="GERMAN";
  mapa["BONJOUR"]="FRENCH";
  mapa["CIAO"]="ITALIAN";
  mapa["ZDRAVSTVUJTE"]="RUSSIAN";
  string palabra;
  int cases=1;
  map<string,string>::iterator it;
  while(true){
    cin>>palabra;
    
    if(palabra[0]=='#')break;
    it=mapa.find(palabra);
    if(it==mapa.end()){
      printf("Case %d: UNKNOWN\n",cases++);
      continue;
    }
    cout<<"Case "<<cases++<<": "<<mapa[palabra]<<endl;
  }


}
