#include<bits/stdc++.h>
using namespace std;
int n,f[105],ans;
string s[105];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        if(f[i])continue;
        ans++;
        for(int j=1;j<=n;j++){
            if(s[i]==s[j])f[j]=1;
        }
    }
    cout<<52-ans;
    return 0;
}
