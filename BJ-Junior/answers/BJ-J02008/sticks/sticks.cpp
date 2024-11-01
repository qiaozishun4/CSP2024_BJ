#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n<2){
            cout<<-1<<endl;
            continue;
        }
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        else if(n%7==1){
            cout<<1<<0;
            for(int i=1;i<=n/7-1;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        else if(n<7){
            if(n==2){
                cout<<1<<endl;
                continue;
            }
            if(n==3){
                cout<<7<<endl;
                continue;
            }
            if(n==4){
                cout<<4<<endl;
                continue;
            }
            if(n==5){
                cout<<2<<endl;
                continue;
            }
            if(n==6){
                cout<<6<<endl;
                continue;
            }
        }
        else if(n<=50){
            int w[10]={6,2,5,5,4,5,6,3,7,6};
            int flag=0;
            if(n/7==1){
                for(int i=1;i<10;i++){
                    for(int j=0;j<10;j++){
                        if(w[i]+w[j]==n){
                            cout<<i<<j<<endl;
                            flag=1;
                            break;
                        }
                    }
                    if(flag) break;
                }
                continue;
            }
            flag=0;
            if(n/7==2){
                for(int i=1;i<10;i++){
                    for(int j=0;j<10;j++){
                        for(int k=0;k<10;k++){
                            if(w[i]+w[j]+w[k]==n){
                                cout<<i<<j<<k<<endl;
                                flag=1;
                                break;
                            }
                        }
                        if(flag) break;
                    }
                    if(flag) break;
                }
                continue;
            }
            flag=0;
            if(n/7==3){
                for(int i=1;i<10;i++){
                    for(int j=0;j<10;j++){
                        for(int k=0;k<10;k++){
                            for(int l=0;l<10;l++){
                                if(w[i]+w[j]+w[k]+w[l]==n){
                                    cout<<i<<j<<k<<l<<endl;
                                    flag=1;
                                    break;
                                }
                            }
                            if(flag) break;
                        }
                        if(flag) break;
                    }
                    if(flag) break;
                }
            }
            flag=0;
            if(n/7==4){
                for(int i=1;i<10;i++){
                    for(int j=0;j<10;j++){
                        for(int k=0;k<10;k++){
                            for(int l=0;l<10;l++){
                                for(int m=0;m<10;m++){
                                    if(w[i]+w[j]+w[k]+w[l]+w[m]==n){
                                        cout<<i<<j<<k<<l<<m<<endl;
                                        flag=1;
                                        break;
                                    }
                                }
                                if(flag) break;
                            }
                            if(flag) break;
                        }
                        if(flag) break;
                    }
                    if(flag) break;
                }
            }
            flag=0;
            if(n/7==5){
                for(int i=1;i<10;i++){
                    for(int j=0;j<10;j++){
                        for(int k=0;k<10;k++){
                            for(int l=0;l<10;l++){
                                for(int m=0;m<10;m++){
                                   for(int p=0;p<10;p++){
                                      if(w[i]+w[j]+w[k]+w[l]+w[m]+w[p]==n){
                                          flag=1;
                                          cout<<i<<j<<k<<l<<m<<p<<endl;
                                        break;
                                      }
                                   }
                                   if(flag) break;
                                }
                                if(flag) break;
                            }
                            if(flag) break;
                        }
                        if(flag) break;
                    }
                    if(flag) break;
                }
            }
            flag=0;
            if(n/7==6){
                for(int i=1;i<10;i++){
                    for(int j=0;j<10;j++){
                        for(int k=0;k<10;k++){
                            for(int l=0;l<10;l++){
                                for(int m=0;m<10;m++){
                                   for(int p=0;p<10;p++){
                                      for(int o=0;o<10;o++){
                                          if(w[i]+w[j]+w[k]+w[l]+w[m]+w[p]+w[o]==n){
                                              cout<<i<<j<<k<<l<<m<<p<<o<<endl;
                                              flag=1;
                                              break;
                                          }
                                      }
                                      if(flag) break;
                                   }
                                   if(flag) break;
                                }
                                if(flag) break;
                            }
                            if(flag) break;
                        }
                        if(flag) break;
                    }
                    if(flag) break;
                }
            }
            flag=0;
            if(n/7==7){
                for(int i=1;i<10;i++){
                    for(int j=0;j<10;j++){
                        for(int k=0;k<10;k++){
                            for(int l=0;l<10;l++){
                                for(int m=0;m<10;m++){
                                   for(int p=0;p<10;p++){
                                      for(int o=0;o<10;o++){
                                         for(int r=0;r<10;r++){
                                            if(w[i]+w[j]+w[k]+w[l]+w[m]+w[p]+w[o]+w[r]==n){
                                                cout<<i<<j<<k<<l<<m<<p<<o<<r<<endl;
                                                flag=1;
                                                break;
                                            }
                                         }
                                         if(flag) break;
                                      }
                                      if(flag) break;
                                   }
                                   if(flag) break;
                                }
                                if(flag) break;
                            }
                            if(flag) break;
                        }
                        if(flag) break;
                    }
                    if(flag) break;
                }
            }
        }
        else if(n%7==2){
            cout<<1;
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        else if(n%7==3){
            cout<<"200";
            for(int i=1;i<=n/7-2;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        else if(n%7==4){
            cout<<"20";
            for(int i=1;i<=n/7-1;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        else if(n%7==5){
            cout<<2;
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else if(n%7==6){
            cout<<6;
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
    }
    return 0;
}
