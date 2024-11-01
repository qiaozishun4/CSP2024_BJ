#include <bits/stdc++.h>
using namespace std;
long long n,r[100010],ans,mn,cnt;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    sort(r+1,r+1+n);
    mn=r[1];
    cnt=1;
    ans=n;
    for(int i=1;i<=n;i++){
        if(r[i]>mn){
            cnt++;
            mn=r[cnt];
            ans--;
        }
    }
    cout<<ans;
    return 0;
}
