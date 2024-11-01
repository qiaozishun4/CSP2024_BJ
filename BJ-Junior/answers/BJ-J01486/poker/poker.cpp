#include<bits/stdc++.h>
using namespace std;
#define int long long
bool v[1000009];
signed main(){
    std::ios::sync_with_stdio(0);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int ans;
    ans=52;
    for(int i=1;i<=n;i++){
        char a,b;
        cin>>a>>b;
        int p;
        p=a*1000+b;
        if(!v[p]){
          ans--;
        }
        v[p]=1;
    }
    cout<<ans;
    return 0;
}
