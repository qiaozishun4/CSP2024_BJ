#include<bits/stdc++.h>
using namespace std;
long long n,r[100005],flag,cnt,ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>r[i];
    }
    sort(r+1,r+n+1);
    for(long long i=1;i<=n;i++){
        if(flag==r[i])cnt++;
        else {
            flag=r[i];
            cnt=1;
        }
        ans=max(cnt,ans);
    }
    cout<<ans;

    return 0;
}
