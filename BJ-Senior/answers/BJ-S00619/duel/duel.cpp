#include<bits/stdc++.h>
using namespace std;
int ans=0,n;
int main(){
    int a[100010],t[100010];
    memset(t,0,sizeof(t));
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t[a[i]]++;
    }
     for(int i=1;i<=n;i++){
        if(t[i]>ans) ans=t[i];
     }
    cout<<ans;
return 0;
}
