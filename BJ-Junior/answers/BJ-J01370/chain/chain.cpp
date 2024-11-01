#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool flag=0;
ll n,k,q;
ll l[100005];
ll s[1005][2005];
void dfs(ll cnt,ll last_person,ll r,ll c,ll last){
    if(cnt==r+1){
        if(last==c){
            flag=1;
        }
        return ;
    }
    for(int p=1;p<=n;p++){
        if(p==last_person) continue;
        for(int i=1;i<=l[p];i++){
            if(to_string(s[p][i])[0]==last&&to_string(s[p][i]).size()<=k){
                dfs(cnt+1,p,r,c,s[p][i]%10);
            }
        }
    }

}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);

    ll T;
    cin>>T;
    while(T--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                cin>>s[i][j];
            }
        }
        for(int i=1;i<=q;i++){
            flag=0;
            ll r,c;
            cin>>r>>c;
            for(int j=1;j<=n;j++){
                dfs(1,j,r,c,1);
                if(flag){
                    break;
                }
            }
            cout<<flag<<'\n';
        }
    }
    return 0;
}
