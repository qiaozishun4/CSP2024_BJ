#include<bits/stdc++.h>
using namespace std;
string s[53];
int n;
int ans;
//rp++
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    ans=52-n;
    for (int i=1;i<=n;i++){
        cin>>s[i];
        for (int j=i-1;j>0;j--)
            if (s[i]==s[j])
            ans++;
    }
    cout<<ans;
    return 0;
}
