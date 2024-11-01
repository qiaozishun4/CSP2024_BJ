#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ans=52;
    cin>>n;
    map<string,bool> mp;
    while(n--){
        string s;
        cin>>s;
        if(mp[s]==0){
            ans-=1;
            mp[s]=1;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}