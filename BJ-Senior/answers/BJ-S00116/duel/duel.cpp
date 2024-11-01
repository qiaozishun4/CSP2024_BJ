#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define REV(i,a,b) for(int i=a;i>=b;i--)
#define mkp make_pair
#define pb push_back
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int N=1e5+5;
int n,r[N],ans;
map<int,int>mp;
int main(){
    //freopen("/home/csp-s-2024/duel/duel4.in","r",stdin);
    freopen("duel.in","r",stdin);freopen("duel.out","w",stdout);
    cin>>n;
    FOR(i,1,n){
        cin>>r[i];
        ++mp[r[i]];
    }
    sort(r+1,r+n+1);
    ans=n;
    unique(r+1,r+n+1);
    n=mp.size();
    FOR(i,2,n){
        int j=i-1;
        while(mp[r[i]]){
            to:
            if(j<1)break;
            if(mp[r[j]]>=mp[r[i]]){
                ans-=mp[r[i]],mp[r[i]]=0;
            }
            else{
                ans-=mp[r[j]],mp[r[j]]=0;
            }
            --j;goto to;
        }
    }
    cout<<ans;
    return 0;
}
