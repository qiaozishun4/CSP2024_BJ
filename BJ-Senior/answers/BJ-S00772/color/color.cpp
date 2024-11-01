# include<iostream>
# include<algorithm>
# include<cmath>
# include<vector>
# define endl "\n"
using namespace std;
const int maxn=2e5+5;
int t, n, a[maxn], l, r, mmax;
signed main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        mmax=-1;
        for(int i=0; i<pow(2, n)-1; i++) {
            int t=i, ans=0;
            l=-1, r=-1;
            for(int j=1; j<=n; j++) {
                int now=t%2; t/=2;
                if(now==0) {
                    if(a[j]==l) ans+=l;
                    l=a[j];
                } else {
                    if(a[j]==r) ans+=r;
                    r=a[j];
                }
            }
            mmax=max(mmax, ans);
        }
        cout << mmax << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
