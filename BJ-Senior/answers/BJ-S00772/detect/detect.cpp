# include<iostream>
# include<algorithm>
# include<cmath>
# include<vector>
# define endl "\n"
using namespace std;
const int maxn=1e5+5, maxm=1e5+5, maxl=1e6+5;
struct Node{
    int l, r;
}b[maxn];
int t, n, m, l, V, p[maxm], d[maxn], v[maxn], a[maxn], s[maxn], pmax=-1;
bool flag;
double up(double a) {
    if(double(int(a))==a) return a;
    else return int(a)+1;
}
signed main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> t;
    while(t--) {
        cin >> n >> m >> l >> V;
        l++;
        for(int i=1; i<=n; i++) {
            cin >> d[i] >> v[i] >> a[i];
            d[i]++;
            if(a[i]==0) flag=false;
            else flag=true;
        }
        for(int i=1; i<=m; i++) cin >> p[i], pmax=max(pmax, p[i]+1);
        if(!flag) {
            int ans=0;
            for(int i=1; i<=n; i++) {
                if(v[i]<=V || d[i]>pmax) {
                    ans++;
                }
            }
            cout << n-ans << " " << 1 << endl;
        } else {
            int ans=0;
            for(int i=1; i<=n; i++) {
                int t=d[i]+up((V*V-v[i]*v[i])*1.0/(a[i]*1.0)/2.0);
                if(t>pmax) {
                    ans++;
                }
            }
            cout << n-ans << " " << 1 << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}