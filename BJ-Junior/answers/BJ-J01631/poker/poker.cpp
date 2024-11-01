#include<bits/stdc++.h>
using namespace std;
map<string,bool> mp;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    scanf("%d",&n);
    int ans=0;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(mp[s]==0){
            mp[s]=1;
            ans++;
        }
    }
    printf("%d",52-ans);
    return 0;
}
