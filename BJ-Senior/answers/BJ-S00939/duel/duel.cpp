#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int n,a[N],sum[N];
map<int,int> mp;

int main(){
    //freopen("duel.in","w",stdout);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    cin>>n;
    int tot=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(!mp[a[i]]) mp[a[i]]=++tot;
        sum[tot]++;
    }
    int ans=0;
    for(int i=1;i<=tot;i++){
        if(ans < sum[i]) ans=0;
        else ans-=sum[i];
        ans+=sum[i];
    }
    cout<<ans;
    return 0;
}
/*
5
1 2 3 1 2
*/
