#include<bits/stdc++.h>
using namespace std;
map<string,bool>mp;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans;
    cin>>n;
    ans=52-n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(mp[s])ans++;
        mp[s]=true;
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
