#include<bits/stdc++.h>
using namespace std;
const int N=100010;
char c[N];
int n,t;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1||n==0){
            cout<<-1<<endl;
            continue;
        }
        if(n<=7){
            if(n==2) cout<<1<<endl;
            else if(n==3) cout<<7<<endl;
            else if(n==4) cout<<4<<endl;
            else if(n==5) cout<<2<<endl;
            else if(n==6) cout<<6<<endl;
            else if(n==7) cout<<8<<endl;
            continue;
        }
        if(n%7==0){
            while(n!=0){
                n-=7;
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==1){
            n-=8;
            cout<<10;
            while(n!=0){
                n-=7;
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==2){
            cout<<24;
            n-=9;
            while(n!=0){
                n-=7;
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==3){
            cout<<22;
            n-=10;
            while(n!=0){
                n-=7;
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==4){
            cout<<20;
            n-=11;
            while(n!=0){
                n-=7;
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==5){
            cout<<28;
            n-=12;
            while(n!=0){
                n-=7;
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n%7==6){
            cout<<68;
            n-=13;
            while(n!=0){
                n-=7;
                cout<<8;
            }
            cout<<endl;
            continue;
        }
    }
    cout.flush();
    return 0;
}