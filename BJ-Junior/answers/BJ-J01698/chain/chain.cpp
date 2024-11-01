#include<bits/stdc++.h>
using namespace std;

struct abc{
    int len;
    int a[200005];
};
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;

    while(T--){
        int n,k,q;int cnt[200005]={0};
        cin>>n>>k>>q;
        abc l[100005];
        for(int i=1;i<=n;i++){
            cin>>l[i].len;
            for(int j=1;j<=l;j++){
                cin>>l[i].a[j];
                cnt[l[i].a[j]]++;
            }
        }
        int r,c;
        for(int i=1;i<=q;i++){
            cin>>r>>c;
            if(cnt[c]==0)cout<<'0'<<endl;
            else cout<<'1'<<endl;
        }
    }
    return 0;
}
