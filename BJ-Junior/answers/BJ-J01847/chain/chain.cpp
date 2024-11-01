#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
struct node{
    int l;
    int a[2001];
}a[1001];
int ans[200001];
signed main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(a,0,sizeof(a));
        memset(ans,0,sizeof(ans));
        int n,k,q,maxx=0;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>a[i].l;
            for(int j=1;j<=a[i].l;j++){
                cin>>a[i].a[j];
                maxx=max(maxx,a[i].a[j]);
            }
        }
        // for(int i=1;i<=n;i++){
        //     cout<<a[i].l<<' ';
        //     for(int j=1;j<=a[i].l;j++){
        //         cout<<a[i].a[j]<<' ';
        //     }
        // }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=a[i].l;j++){
                if(a[i].a[j]==1){
                    for(int p=1;p<k;p++){
                        // cout<<1<<endl;
                        ans[a[i].a[j+p]]=1;
                    }
                }
                else continue;
            }
        }
        while(q--){
            int r,x;
            cin>>r>>x;
            cout<<ans[x]<<endl;
        }
        // for(auto i:ans) cout<<i<<endl;
    }
    return 0;
}