#include <bits/stdc++.h>
using namespace std;
int num[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
long long t, n, ans;
bool flag_1, flag;
vector<long long> vi;
void dfs(int n) {
    if(n==1)
        return;
    if(n==0) {
        vi.push_back(ans);
        flag = true;
        return;
    }
    if(flag_1==false) {
        for(int i=1;i<=9;i++) {
            if(n>=num[i]) {
                n-=num[i];
                flag_1 = true;
                ans = ans*10+i;
                dfs(n);
                ans = (ans-i)/10;
                flag_1 = false;
                n+=num[i];
            }
        }
    }
    else {
        for(int i=0;i<=9;i++) {
            if(n>=num[i]) {
                n-=num[i];
                ans = ans*10+i;
                dfs(n);
                ans = (ans-i)/10;
                n+=num[i];
            }
        }
    }
}
bool cmp(int a, int b) {
    return a<b;
}
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> t;
    while(t--) {
        cin >> n;
        if(n==1) {
            cout << -1;
            continue;
        }
        if(n%7==0) {
            for(int i=1;i<=n/7;i++)
                cout << 8;
            cout << '\n';
            continue;
        }
        else if(n%7==1) {
            if(n==8) {
                cout << 10 << '\n';
                continue;
            }
            cout << 10;
            for(int i=1;i<=n/7-1;i++)
                cout << 8;
            cout << '\n';
            continue;
        }
        ans = 0;
        flag_1 = false;
        flag = false;
        dfs(n);
        if(flag==false)
            cout << -1 << '\n';
        else {
            sort(vi.begin(), vi.end(), cmp);
            cout << vi[0] << '\n';
            vi.clear();
        }
    }
    return 0;
}
