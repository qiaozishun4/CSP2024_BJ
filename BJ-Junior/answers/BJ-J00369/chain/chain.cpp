#include <bits/stdc++.h>
using namespace std;
int c[10000005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int n,m,k,q,ma=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m>>k>>q;
        for(int i=1;i<=ma;i++){
            c[i]=0;
        }
        for(int j=1;j<=m;j++){
            int x;
            cin>>x;
            c[x]++;
            ma=max(ma,x);
        }
        for(int j=1;j<=q;j++){
            int a,b;
            cin>>a>>b;
            if(c[b]==0)cout<<0<<endl;
            else cout<<1<<endl;
        }
    }
    return 0;
}

