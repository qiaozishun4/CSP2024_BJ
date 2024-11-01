#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m,ans=1,cnt=0;
    cin>>n>>m;
    while(1){
        ans*=2;
        cnt++;
        if(ans>=n)break;
    }
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
    }
    for(int j=1;j<=m;j++){
        int y;
        cin>>y;
    }
    for(int i=1;i<=cnt;i++){
        string z;
        cin>>z;
    }
    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        int x,y,z,w;
        cin>>x>>y>>z>>w;
        cout<<abs(10*y-1-x*2+2*z-18*w+(10*y-1-x*2+2*z-18*w<=0)*i)<<endl;
    }
    return 0;
}

