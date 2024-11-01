#include<bits/stdc++.h>
using namespace std;
int a[15]={6,2,5,5,4,5,6,3,7,6};

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int cnt=1000000;
           for(int i=1;i<=9;i++){
                if(a[i]==n){
                    cnt=min(cnt,i);
                }
           }
           if(cnt==1000000){
               for(int i=1;i<=9;i++){
                    for(int j=0;j<=9;j++){
                        if(a[i]+a[j]==n){
                            cnt=min(i*10+j,cnt);
                        }
                    }
               }
            }
            if(cnt==1000000){
                for(int i=1;i<=9;i++){
                    for(int j=0;j<=9;j++){
                        for(int k=0;k<=9;k++){
                            if(a[i]+a[j]+a[k]==n){
                                cnt=min(i*100+j*10+k,cnt);
                            }
                        }
                    }
               }
            }
             if(cnt==1000000){
                for(int i=1;i<=9;i++){
                    for(int j=0;j<=9;j++){
                        for(int k=0;k<=9;k++){
                            for(int o=0;o<=9;o++){
                                if(a[i]+a[j]+a[k]+a[o]==n){
                                    cnt=min(i*1000+j*100+k*10+o,cnt);
                                }
                            }
                        }
                    }
               }
            }

            if(cnt==1000000){
                cout<<-1<<endl;
            }else{
                cout<<cnt<<endl;
            }

    }











    return 0;
}
