#include<bits/stdc++.h>
using namespace std;
int n,a[1000001],ans,m;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1,x;i<=n;i++){
        cin>>x;
        m=max(m,x);
        a[x]++;
    }
    for(int i=1;i<=m;i++)ans=max(ans,a[i]);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
