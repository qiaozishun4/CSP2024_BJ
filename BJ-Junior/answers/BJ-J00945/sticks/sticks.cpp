#include<bits/stdc++.h>
#define int long long
using namespace std;

int num[15]={6,2,5,5,4,5,6,3,7,6};
int f[10]={-1,-1,1,7,4,2,0,8};
int tb[50]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108};

void work(int n){
    if(n<=14){
        cout<<tb[n]<<endl;
        return;
    }

    int cnt1; cnt1=n/7;
    int p; p=n%7;

    if(p==0){
        for(int i=1;i<=n/7;i++){
            cout<<8;
        }
    }
    else if(p==1){
        cout<<10;
        for(int i=1;i<n/7;i++){
            cout<<8;
        }
    }
    else if(p==2){
        cout<<1;
        for(int i=1;i<=n/7;i++){
            cout<<8;
        }
    }
    else if(p==3){
        cout<<200;
        for(int i=1;i<=n/7-2;i++){
            cout<<8;
        }
    }
    else if(p==4){
        cout<<20;
        for(int i=1;i<=n/7-1;i++){
            cout<<8;
        }
    }
    else if(p==5){
        cout<<2;
        for(int i=1;i<=n/7;i++){
            cout<<8;
        }
    }
    else{
        cout<<6;
        for(int i=1;i<=n/7;i++){
            cout<<8;
        }
    }

    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        work(n);
    }
    return 0;
}

