#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define REV(i,a,b) for(int i=a;i>=b;i--)
#define mkp make_pair
#define pb push_back
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int N=2e5+5;
int T,n,a[N];
int main(){
    freopen("color.in","r",stdin);freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        FOR(i,1,n)cin>>a[i];
        ll ans=0;
        FOR(i,0,(1<<n)-1){
            ll sum=0;
            int l1=-1,l0=-1;
            FOR(j,0,n-1){
                if(i>>j&1){
                    if(a[n-j]==a[n-l1])sum+=a[n-j];
                    l1=j;
                }
                else{
                    if(a[n-j]==a[n-l0])sum+=a[n-j];
                    l0=j;
                }
            }
            ans=max(sum,ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}
