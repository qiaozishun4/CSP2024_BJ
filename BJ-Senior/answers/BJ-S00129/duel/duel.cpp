#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,r[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)cin>>r[i];
    sort(r,r+n);
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
        if(r[i]==0||r[j]==0)continue;
            ans--;
            r[i]=0;
        }
    }
    cout<<ans;
    return 0;
}