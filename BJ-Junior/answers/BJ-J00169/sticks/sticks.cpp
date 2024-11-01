#include<bits/stdc++.h>
using namespace std;
int t,n,p;
int sz[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        p=0;
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        if(n<=7){
            for(int i=1;i<10;i++){
                if(sz[i]==n){
                    cout<<i<<endl;
                    break;
                }
            }
        }else if(n<=20){
            for(int i=1;i<10;i++){
                for(int j=0;j<10;j++){
                    if(sz[i]+sz[j]==n){
                        cout<<i*10+j*1<<endl;
                        p=1;
                        break;
                    }
                }
                if(p==1) break;
            }
            if(p==1) continue;
            for(int i=1;i<10;i++){
                for(int j=0;j<10;j++){
                    for(int k=0;k<10;k++){
                        if(sz[i]+sz[j]+sz[k]==n){
                            cout<<i*100+j*10+k<<endl;
                            p=1;
                            break;
                        }
                    }
                    if(p==1) break;
                }
                if(p==1) break;
            }
        }else if(n%7==0){
            while(n>0){
                cout<<8;
                n/=7;
            }
            cout<<endl;
        }else if(n%7==1){
            while(n>14){
                cout<<8;
                n/=7;
            }
            cout<<0<<1<<endl;
        }
    }
    return 0;
}
