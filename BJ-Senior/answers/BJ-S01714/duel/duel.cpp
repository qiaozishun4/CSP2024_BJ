#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,a[N],ans;
bool vis1[N],vis2[N];
signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=n-1,r=n;
    sort(a+1,a+n+1);
    while(l>=1&&r>=1){
        while(a[l]==a[r]){
            l--;
        }
        vis1[l]=1,vis2[l]=1;
        l--,r--;
    }
    for(int i=1;i<=n;i++) if(vis1[i]==0) ans++;
    //cout<<endl;
    //for(int i=1;i<=n;i++) cout<<vis2[i]<<" ";
    //cout<<endl;
    cout<<ans;
    return 0;
}
