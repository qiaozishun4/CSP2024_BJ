#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,a[maxn],ans=0,b[maxn];
    set<int> s;
    map<int,int> mp;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        mp[a[i]]++;
        s.insert(a[i]);
    }
    int cnt=1;
    for(auto it:s){
        b[cnt]=it;
        cnt++;
    }
    for(int i=1;i<=cnt-1-1;i++){
        int cmt=mp[b[i]]-mp[b[i+1]];
        if(cmt<0) cmt=0;
        ans+=cmt;
    }
    ans+=mp[b[cnt-1]];
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}