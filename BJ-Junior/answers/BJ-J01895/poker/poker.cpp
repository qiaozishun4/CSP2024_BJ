#include <bits/stdc++.h>
using namespace std;
int n,t[66][66];
char cnt;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        char s[4];
        cin>>s[1]>>s[2];
        t[s[1]-'A'][s[2]-'A'+1]++;
        if(t[s[1]-'A'][s[2]-'A'+1]<=1) cnt++;
        else continue;
    }
    int ans=52-cnt;
    cout<<ans;
    return 0;
}
