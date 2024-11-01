#include<bits/stdc++.h>
#define int long long
using namespace std;
map<string,int>s;
signed main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    int n;cin>>n;
    int ans=52-n;
    for(int i=1;i<=n;i++){
        string a;cin>>a;
        if(s[a])ans++;
        s[a]++;
    }
    cout<<ans;
    return 0;
}
