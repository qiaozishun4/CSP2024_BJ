#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb emplace_back
#define pii pair<int,int>
ll n,a[100005],cnt1,cnt2;
multiset<int>s;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]==a[1])s.insert(a[i]),cnt1++;
    }
    for(int i=cnt1+1;i<=n;i++){
        if(a[i]>(*(s.begin())))s.erase(s.begin());
        s.insert(a[i]);
    }
    cout<<s.size();
    return 0;
}
