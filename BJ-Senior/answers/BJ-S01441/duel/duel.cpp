#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100001],b[100001];
signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i]<a[j]&&b[i]!=1&&b[j]==0){
                b[i]=1;
                b[j]=2;
                continue;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(b[i]!=1){
            ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
