#include<bits/stdc++.h>
using namespace std;
int n,a[100005],tb,ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    ans=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n && tb<=n;i++){
        while(a[tb]<=a[i] && tb<=n)tb++;
        if(tb>n)break;
        ans--;
        tb++;
    }
    cout<<ans<<endl;
    return 0;
}
