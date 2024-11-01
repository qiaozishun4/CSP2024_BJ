#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[25]={0,0,0,0,0,0,0,0,10,18,22,20,28,68,88,108,188,228,208,288,688,888,1088};
string s;
void j(int x){
    if(x==2){
        s=s+"1";
    }
    else if(x==3){
        s=s+"7";
    }
    else if(x==4){
        s=s+"4";
    }
    else if(x==5){
        s=s+"2";
    }
    else if(x==6){
        if(s.size())s=s+"0";
        else s=s+"6";
    }
    else if(x==7){
        s=s+"8";
    }
}
int T,n;
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        s="";
        cin>>n;
        if(n<2){
            cout<<-1<<'\n';
            continue;
        }
        if(n%7==0){
            for(int i=7;i<=n;i+=7){
                cout<<8;
            }
            cout<<'\n';
            continue;
        }
        if(n<8){
            j(n);
            cout<<s<<'\n';
            continue;
        }
        if(n<23){
            cout<<a[n]<<'\n';
            continue;
        }
        if((n-1)%7==0){
            cout<<10;
            for(int i=14;i<=n-1;i+=7){
                cout<<8;
            }
            cout<<'\n';
            continue;
        }
        if((n+1)%7==0){
            cout<<6;
            for(int i=14;i<=n+1;i+=7){
                cout<<8;
            }
            cout<<'\n';
            continue;
        }
        if((n+3)%7==0){
            cout<<20;
            for(int i=14;i<n+3;i+=7){
                cout<<8;
            }
            cout<<'\n';
            continue;
        }
        if((n-2)%7==0){
            cout<<18;
            for(int i=14;i<=n-2;i+=7){
                cout<<8;
            }
            cout<<'\n';
            continue;
        }
        if((n-3)%7==0){
            cout<<22;
            for(int i=14;i<=n-3;i+=7){
                cout<<8;
            }
            cout<<'\n';
            continue;
        }
        if((n+2)%7==0){
            cout<<2;
            for(int i=14;i<=n+2;i+=7){
                cout<<8;
            }
            cout<<'\n';
            continue;
        }
    }
    return 0;
}
