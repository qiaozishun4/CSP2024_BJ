#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
const int N=2e5+5;
int n,a[N],col[N],ans;
void sol() {
    memset(a,0,sizeof a);
    memset(col,0,sizeof col);
    ans=-1;

    cin>>n;
    forr(i,1,n) cin>>a[i];

    int T=(1<<n) -1;
    forr(i,0,T) {
        int k=i,cnt=0;
        forr(j,1,n) {
            col[j] = k%2;
            //**/ cout<<k%2;
            k/=2;
        }
        //**/ puts("");
        forr(j,2,n) {
            int k=j-1;
            while(k>=1 && col[k] != col[j]) k--;
            if(k==0 || a[j]!=a[k]) continue;
            cnt += a[j];
        }
        ans = max(ans,cnt);
    }
    cout << ans <<endl;
}


int main() {
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T; cin>>T; while(T--) sol();
    return 0;
}
