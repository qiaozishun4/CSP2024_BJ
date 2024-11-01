#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5+5;

int t;
int a[N];
int min_ = 1e5;

void dfs(int now,int sum,int n) {
    int num = 0;
    int tmp = ceil(((double)n/7));
    if (now>tmp+1) return;

    if (sum>n) return;

    if (sum==n) {
        if (a[1]==0) return;
        for (int i=1;i<now;i++) {
            num+=a[i];
            num*=10;
        }
        num/=10;
//        cout << num << endl;
        min_ = min(min_, num);
//        if (num == 66)
//        {
//            for (int i=1;i<n+1;i++) {
//                cout << a[i] <<' ';
//            }
//            cout << endl;
//            return ;
//        }
    }
    a[now] = 1;
    dfs(now+1, sum+2, n);
    a[now] = 7;
    dfs(now+1, sum+3, n);
    a[now] = 4;
    dfs(now+1, sum+4, n);
    a[now] = 2;
    dfs(now+1, sum+5, n);
    a[now] = 0;
    dfs(now+1, sum+6, n);
    a[now] = 6;
    dfs(now+1, sum+6, n);
    a[now] = 8;
    dfs(now+1, sum+7, n);

}

void work() {

    int n;
    cin >> n;

    if (n==1) {
        cout << -1 << endl;
        return;

    }
    dfs(1, 0, n);
    cout << min_ <<endl;



}


signed main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    while (t--) {
        min_ = 1e17;
        work();
    }



    return 0;
}
