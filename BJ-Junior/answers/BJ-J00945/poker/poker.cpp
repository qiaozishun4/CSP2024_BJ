#include<bits/stdc++.h>
#define int long long
using namespace std;

map <string,int> cards;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);

    int n; cin>>n;

    int ans; ans=52;
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        if(!cards[s]){
            ans--;
        }

        cards[s]=1;
    }

    cout<<ans<<endl;
    return 0;
}

