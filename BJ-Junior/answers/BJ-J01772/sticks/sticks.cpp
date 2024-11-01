#include<bits/stdc++.h>
using namespace std;
const long long w[8]={0,-1,1,7,4,2,6,8};
long long t,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=7)cout<<w[n];
        else if(n==10)cout<<22;
        else if(n%7==0){
            while(n){
                cout<<8;
                n-=7;
            }
        }
        else if(n%7==1){
            cout<<10;
            n-=8;
            while(n){
                cout<<8;
                n-=7;
            }
        }
        else if(n%7==2){
            cout<<1;
            n-=2;
            while(n){
                cout<<8;
                n-=7;
            }
        }
        else if(n%7==3){
            cout<<200;
            n-=17;
            while(n){
                cout<<8;
                n-=7;
            }
        }
        else if(n%7==4){
            cout<<20;
            n-=11;
            while(n){
                cout<<8;
                n-=7;
            }
        }
        else if(n%7==5){
            cout<<2;
            n-=5;
            while(n){
                cout<<8;
                n-=7;
            }
        }
        else{
            cout<<6;
            n-=6;
            while(n){
                cout<<8;
                n-=7;
            }
        }
        cout<<"\n";
    }
    return 0;
}
