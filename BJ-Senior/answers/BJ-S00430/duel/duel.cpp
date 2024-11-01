#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int r[maxn],m[maxn],n,ans;
    cin>>n;
    ans=2;
    for(int i=1;i<=n;i++){
        cin>>r[i];
        if(r[i]<r[i-1]){
            swap(r[i],r[i-1]);
        }
    }
    for(int i=1;i<=n;i++){
        if(r[i]==r[i-1]){
            ans = ans+1;
        }
    }
    cout<<ans;
}
