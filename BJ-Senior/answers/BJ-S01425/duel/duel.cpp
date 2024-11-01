#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int ans=n;
    int a[100005];
    bool f[100005];
    memset(f,true,sizeof(f));
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]<a[j]&&f[j]==true){
                ans--;f[j]=false;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
