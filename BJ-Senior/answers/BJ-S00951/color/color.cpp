#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb emplace_back
#define pii pair<int,int>
int a[200005],n,ans,s2[200005],len;
map<int,int>cnt;
set<int>s,r,b;
void dfs(int x,int r,int b,int sum){
    if(x==n+1){
        ans=max(sum,ans);
        return;
    }
    dfs(x+1,a[x],b,sum+(a[x]==r?a[x]:0));
    dfs(x+1,r,a[x],sum+(a[x]==b?a[x]:0));
}
void dfs2(int x){
    if(x==n+1){
        int sum=0,lr=0,lb=0;
        for(int i=1;i<=n;i++){
            if(r.count(a[i])){
                if(lr==0)lr=i;
                else {
                    if(a[lr]==a[i])sum+=a[lr];
                    lr=i;
                }
            }
            else {
                if(lb==0)lb=i;
                else {
                    if(a[lb]==a[i])sum+=a[lb];
                    lb=i;
                }
            }
        }
        ans=max(sum,ans);
        return;
    }
    r.insert(s2[x]);
    dfs2(x+1);
    r.erase(s2[x]);
    b.insert(s2[x]);
    dfs2(x+1);
    b.erase(s2[x]);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        ans=0;
        memset(a,0,sizeof a);
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            cnt[a[i]]++;
            s.insert(a[i]);
        }
        if(n<=15){
            dfs(1,0,0,0);
            cout<<ans<<'\n';
            continue;
        }
        for(int i:s)s2[++len]=i;
        dfs2(1);
        cout<<ans<<'\n';
    }
    return 0;
}
