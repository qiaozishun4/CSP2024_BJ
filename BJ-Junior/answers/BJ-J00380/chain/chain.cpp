#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
typedef long long ll;
int n,s[1005][2005],l[1005],q,k,r,c,t;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++)cin>>s[i][j];
        }
        while(q--){
            cin>>r>>c;
            bool f=0;
            for(int i=1;i<=n;i++){
                for(int j=2;j<=l[i];j++){
                    if(s[i][j]==c&&j<=k){
                        f=1;
                        break;
                    }
                }
            }
            cout<<f<<endl;
        }
    }
    return 0;
}
