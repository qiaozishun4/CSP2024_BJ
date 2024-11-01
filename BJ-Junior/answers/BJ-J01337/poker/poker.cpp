#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,ans=52;
    string a;
    map<string,bool> m;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(!m[a]){
            ans--;
            m[a]=1;
        }
    }
    cout<<ans;
}
