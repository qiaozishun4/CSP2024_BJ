#include<bits/stdc++.h>
using namespace std;
const int N=1e5+114;
const int inf=0x3f;
int n;
int a[N];
map<int ,int >mp;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }

    sort(a+1,a+n+1);

    int size=0;
    int maxn=-1;
    for(auto it : mp){
        size++;
        maxn=max(maxn,it.second);
    }
    int ans=0;
    if(size==2)
        if(mp[a[n]]>=mp[a[1]]) ans=mp[a[n]];
        else ans=n-mp[a[n]];
    else if(size==3){
        if(mp[a[n]]>mp[a[n-mp[a[n]]]]){
            ans=n-mp[a[n]];
        }
        else if(mp[a[n]]<mp[a[n-mp[a[n]]]]){
            ans=n-(mp[a[n]]+mp[a[n-mp[a[n]]]])-(mp[a[n-mp[a[n]]]]-mp[a[n]]-1);
        }else{
            ans=mp[a[n]];
        }
    }else{
        if(mp[a[n]]<mp[a[n-mp[a[n]]]]) ans=mp[a[n-mp[a[n]]]]+1;
        else if(mp[a[n]]==mp[a[n-mp[a[n]]]]) ans=mp[a[n]]+mp[a[n-mp[a[n]]]]-1;
        else ans=mp[a[n]];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
