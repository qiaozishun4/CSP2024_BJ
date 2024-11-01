#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
int ans=0;
//考虑到先让最高的攻击次高的
//那可以利用一下次高的，让他攻击次次高的
//这样可以递归
//虽然我不能证明它的正确性
multiset<int> s;
void solve(multiset<int>::iterator x)//表示当前x攻击
{
    auto wz=s.lower_bound(*x);
    if(wz==s.begin() || wz==s.end()) return;
    wz--;
    solve(wz);
    //cerr<<*x<<":"<<*wz<<endl;
    s.erase(wz);
    ans++;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,tmp;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>tmp;
        s.insert(tmp);
    }
    while(1)
    {
        if(s.size()==0) break;
        auto wz=s.end();
        wz--;
        solve(wz);
        s.erase(wz);
    }
    cout<<n-ans<<endl;
    cout<<flush;
    return 0;
}
