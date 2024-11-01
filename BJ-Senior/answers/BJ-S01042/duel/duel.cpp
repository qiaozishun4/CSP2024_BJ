#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int r[N],n,ans,used[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>r[i];
    sort(r+1,r+n+1);
    int i=1,j=1;
    while(j<=n){
        if(r[j]>r[i]){
            used[i]=1;
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    for(int i=1;i<=n;i++) if(!used[i]) ans++;
    cout<<ans;
    return 0;
}