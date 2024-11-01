#include<bits/stdc++.h>
using namespace std;
int r[100005],visa[100005],visd[100005];

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int ans=n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    sort(r+1,r+n+1);
    for(int i=1;i<=n;i++){
        if(visd[i]==1) continue;
        for(int j=i;j<=n;j++){
            if(visa[j]==1||visd[j]==1||visd[i]==1) continue;
            if(r[i]<r[j]){
                ans--;
                visd[i]=1,visa[j]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}
