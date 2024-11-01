#include <bits/stdc++.h>
using namespace std;

map<string,int> m;

int main (){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int ans=52-n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(m[s]>0) ans++;
        m[s]=1;
    }
    cout<<ans;
    return 0;
}