#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main (){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int p=1;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]<=a[p]) ans++;
        else p++;
    }
    cout<<ans;
    return 0;
}
