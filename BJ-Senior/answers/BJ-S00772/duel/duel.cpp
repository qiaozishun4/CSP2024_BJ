# include<iostream>
# include<algorithm>
# include<cmath>
# define int long long
# define endl "\n"
using namespace std;
const int maxn=1e6+5;
int n, a[maxn], num, lnum, last;
signed main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n; last=n;
    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    for(int i=1; i<=n; i++) {
        if(a[i]>a[i-1]) {
            if(lnum>=num) {
                last-=num;
            } else {
                last-=lnum;
                lnum=num;
            }
            num=1;
        } else {
            num++;
        }
    }
    if(lnum>=num) last-=num;
    else last-=lnum;
    cout << last << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
