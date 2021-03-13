  #include<bits/stdc++.h>
  using namespace std;
  main(){
    int T;
    cin>>T;
    int A,B,cases=1;
    double arr[2000][501];
    double candidatos[501];
    double var;
    while(T--){
      if(cases!=1)printf("\n");
      cases++;
      memset(arr,0,sizeof arr);
      memset(candidatos,0,sizeof candidatos);
      scanf("%d%d",&A,&B);
      for(int i=0;i<B;i++){
        for(int j=0;j<A+1;j++){
          scanf("%lf",&arr[i][j]);
          if(j!=A)arr[i][j]/=100.0;
        }
      }
                                                                                         /* for(int i=0;i<B;i++){
                                                                                                        for(int j=0;j<A+1;j++){
                                                                                                                        cout<<arr[i][j]<<" ";
                                                                                                                                    }
                                                                                                                                                cout<<endl;
                                                                                                                                                        }*/
                                                                                                                                                double total=0;
                                                                                                                                                for(int i=0;i<B;i++){
                                                                                                                                                  total+=arr[i][A];
                                                                                                                                                }
                                                                                                                                                for(int i=0;i<A;i++){
                                                                                                                       // cout<<candidatos[i]<<endl;
                                                                                                                                                 for(int j=0;j<B;j++){
                                                                                                                                           // cout<<"R:"<<arr[j][A]*arr[j][i]<<endl;
                                                                                                                                                   candidatos[i]+=(arr[j][A]*arr[j][i]);
                                                                                                                                                 }
                                                                                                                                //     cout<<candidatos[i]<<endl;
                                                                                                                                //     cout<<endl;
                                                                                                                                               }
                                                                                                                 // for(int i=0;i<A;i++)
                                                                                                                //  cout<<"C:"<<candidatos[i]<<endl;
                                                                                                                                               long long max1=0,max2=0;
                                                                                                                                               int i1,i2;
                                                                                                                                               for(int i=0;i<A;i++){
                                                                                                                                             //   cout<<candidatos[i]<<endl;
                                                                                                                                                if(max1<candidatos[i]){
                                                                                                                                                  max1=candidatos[i];
                                                                                                                                                  i1=i;
                                                                                                                                                }
                                                                                                                                              }

                                                                                                                                              candidatos[i1]=0;
                                                                                                                                              for(int i=0;i<A;i++){
                                                                                                                                               if(max2<candidatos[i]){
                                                                                                                                                 max2=candidatos[i];
                                                                                                                                                 i2=i;
                                                                                                                                               }
                                                                                                                                             }
                                                                                                                                                          // cout<<max1<<" "<<max2<<endl;
                                                                                                                                             if(max1*1000>=501*total){
                                                                                                                                              printf("%d %lld\n",i1+1,max1);
                                                                                                                                            }
                                                                                                                                            else{
                                                                                                                                              printf("%d %lld\n",i1+1,max1);
                                                                                                                                              printf("%d %lld\n",i2+1,max2);
                                                                                                                                            }
                                                                                                                                            

                                                                                                                                          }

                                                                                                                                        }

