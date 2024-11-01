/*
    author: honglan0301
    Goodbye OI~~~~~
    2022.7~2024.7

    BJ jiayou!!!
    RDFZ jiayou!!!
    sexy_goodier,didi123,mc123456,xsap,HYX1124,wuyouka,flying,bunH2O,whdywjd,Max_s_xaM,wzc_IOI_czw,fast_photon,mysterious_cat... jiayou!!!

    accelerate.

    //freopen
    duel1.in duel1.out
    detect1.in detect1.out
    color1.in color1.out
    arena1.in arena1.out
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
mt19937 rnd(time(0));
mt19937_64 rndl(time(0));

int n,a[100005];
map <int,int> ss;

signed main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n; for(int i=1;i<=n;i++) cin>>a[i],ss[a[i]]++;
    int ans=0; for(auto i:ss) ans=max(ans,i.se);
    cout<<ans<<endl;
}
