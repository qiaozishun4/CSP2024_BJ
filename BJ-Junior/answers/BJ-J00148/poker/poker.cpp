#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int ans=52;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    cout<<ans-n;
    return 0;
}
