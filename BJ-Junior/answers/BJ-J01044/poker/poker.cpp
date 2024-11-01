#include <bits/stdc++.h>
using namespace std;
int n,ans=52;
map<string,bool> cnt;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(!cnt[s]){
            ans--;
            cnt[s]=1;
        }
    }
    cout<<ans;
    return 0;
}