#include <bits/stdc++.h>
using namespace std;

bool vis[100001];
int t, num[5] = {1, 7, 4, 2, 8}, us[5] = {2, 3, 4, 5, 7}, ans = INT_MAX;

int change(vector<int> use){
    int m = INT_MAX;
    for (int i = 1 ; i < 9; i++)
        m = min(m, use[i] ? i : INT_MAX);
    if (m == INT_MAX)
        return INT_MAX;
    int a = m;
    use[m]--;
    for (int i = 0; i < use[0]; i++)
        a *= 10;
    for (int i = m; i < 10; i++)
        for (int j = 0; j < use[i]; j++)
            a = a * 10 + i;
    return a;
}

class path{
public:
    int amount, cnt = 0;
    vector<int> use;
    path(int a){
        amount = a, cnt = 0;
        use = vector<int>(10);
    }
    path(int a, int c, vector<int> u){
        use = u, amount = a, cnt = c;
    }
};

void h(int n){
    for (int i = 0; i <= n; i++)
        vis[i] = false;
    queue<path> q;
    q.push(path(n));
    int l = INT_MAX;
    while (!q.empty()){
        path p = q.front();
        q.pop();
        if (p.amount == 0){
            ans = min(ans, change(p.use));
            if (ans != INT_MAX)
                l = min(l, p.cnt);
            continue;
        }

        if (p.amount >= 6)
            if ((n == 6 || ((p.use[7] || p.use[8]) && !(p.use[1] || p.use[2] || p.use[4] || p.use[6]))) && p.cnt < l)
                p.use[6]++, q.push(path(p.amount - 6, p.cnt + 1, p.use)), vis[p.amount - 6] = true;
            else if (p.cnt < l)
                p.use[0]++, q.push(path(p.amount - 6, p.cnt + 1, p.use)), vis[p.amount - 6] = true;
        for (int i = 0; i < 5 && p.amount >= us[i]; i++){
            p.use[num[i]]++;
            if (p.cnt < l)
                q.push(path(p.amount - us[i], p.cnt + 1, p.use)), vis[p.amount - us[i]] = true;
            p.use[num[i]]--;
        }
    }
}


int main(){
    freopen("stick.in", "r", stdin);
    freopen("stick.out", "w", stdout);
    int n;
    cin >> t;
    while (t--){
        cin >> n;
        if (n % 7 == 0)
            for (int i = 0; i < n; i += 7)
                cout << 8;
        else if (n % 7 == 1 && n > 7){
            cout << 10;
            for (int i = 8; i < n; i += 7)
                cout << 8;
        }
        else{
            ans = INT_MAX, h(n);
            cout << (ans == INT_MAX ? -1 : ans);
        }
        cout << endl;
    }
    return 0;
}
