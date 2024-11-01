#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int r,ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    r=1;
    ans=n;
    for(int i=1;i<=n;i++){
        while(r<=n&&a[r]<=a[i])r++;
        if(r>n)break;
        ans--,r++;
    }
    cout<<ans<<endl;
    return 0;
}
