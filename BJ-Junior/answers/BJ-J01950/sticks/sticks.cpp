#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=1) cout<<-1;
        else{
            if(n%7==0){
                for(int i=1;i<=n/7;i++) cout<<8;
            }else if(n%7==1){
                n--;
                cout<<10;
                n-=7;
                for(int i=1;i<=n/7;i++) cout<<8;
            }else if(n%7==2){
                cout<<1;
                n-=2;
                for(int i=1;i<=n/7;i++) cout<<8;
            }else if(n%7==3){
                if(n>=10){
                    cout<<22;
                    n-=10;

                }
                else{
                    cout<<7;
                    n-=3;
                }
                for(int i=1;i<=n/7;i++) cout<<8;
            }else if(n%7==4){
                if(n>=11){
                    cout<<20;
                    n-=11;
                    for(int i=1;i<=n/7;i++) cout<<8;
                }else{
                    cout<<4;
                }
            }else if(n%7==5){
                cout<<2;
                n-=5;
                for(int i=1;i<=n/7;i++) cout<<8;
            }else if(n%7==6){
                cout<<6;
                n-=6;
                for(int i=1;i<=n/7;i++) cout<<8;
            }
        }
        cout<<'\n';
    }
    return 0;
}
