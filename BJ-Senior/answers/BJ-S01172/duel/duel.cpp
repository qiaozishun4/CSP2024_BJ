#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
multiset<int>s;
int ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    //cout<<n<<endl;
    ans=n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s.insert(a[i]);
    for(int i=1;i<=n;i++){
        int x=a[i];
        if(s.empty())continue;
        auto it=s.end();
        it--;
        if(*it<=a[i])continue;
        it=s.upper_bound(x);
        ans--;
        s.erase(it);
    }
    cout<<ans;
    return 0;
}
