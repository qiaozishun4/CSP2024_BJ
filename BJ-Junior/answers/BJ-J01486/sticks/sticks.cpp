#include<bits/stdc++.h>
using namespace std;
#define int long long
void _main(){
    int n;
    cin>>n;
    if(n==1){
        cout<<-1<<endl;
    }else if(n==2){
        cout<<1<<endl;
    }else if(n==3){
        cout<<7<<endl;
    }else if(n==4){
        cout<<4<<endl;
    }else if(n==5){
        cout<<2<<endl;
    }else if(n==6){
        cout<<6<<endl;
    }else if(n==7){
        cout<<8<<endl;
    }else{
        int s;
        s=n/7;
        n%=7;
        if(n==1){
            s--;
            cout<<10;
            while(s--){
                cout<<8;
            }
            cout<<endl;
        }else if(n==2){
            cout<<1;
            while(s--){
                cout<<8;
            }
            cout<<endl;
        }else if(n==3){
            if(s==1){
                cout<<22<<endl;
            }else{
                s-=2;
                cout<<200;
                while(s--){
                cout<<8;
            }
            cout<<endl;
            }
        }else if(n==4){
            s--;
            cout<<20;
            while(s--){
                cout<<8;
            }
            cout<<endl;
        }else if(n==5){
            cout<<2;
            while(s--){
                cout<<8;
            }
            cout<<endl;
        }else if(n==6){
            cout<<6;
            while(s--){
                cout<<8;
            }
            cout<<endl;
        }else if(n==0){
            while(s--){
                cout<<8;
            }
            cout<<endl;
        }
    }
}
signed main(){
    std::ios::sync_with_stdio(0);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        _main();
    }
    return 0;
}
