#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int ans=n,mn=0,tong=0;
    for(int i=1;i<=n;i++){
        if(mn>0){
            mn--;
            ans--;
        }
        tong++;
        if(a[i]!=a[i+1]) mn+=tong,tong=0;
    }
    cout<<ans;
    return 0;
}
