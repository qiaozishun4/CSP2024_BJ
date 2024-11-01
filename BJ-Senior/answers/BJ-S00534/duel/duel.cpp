#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll n, mon[MAXN], ans, cnt;
struct Monster {
    ll amount;
    ll attacked;
    ll dead;
    ll ablt;//ability
}mst[MAXN];
bool attacked[MAXN], dead[MAXN];
bool cmp(int a, int b) {
    return a < b;
}
int main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &mon[i]);
    }
    sort(mon + 1, mon + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        if (mon[i] != mst[cnt].ablt) {
            cnt++;
            mst[cnt].ablt = mon[i];
        }
        mst[cnt].amount++;
    }
    for (int i = 1; i <= cnt; i++) {
        bool flag = true;
        for (int j = i + 1; j <= cnt; j++) {
            int abat = mst[j].amount - mst[j].attacked; //able to attack
            if (abat < mst[i].amount - mst[i].dead) {
                mst[j].attacked = mst[j].amount;
                mst[i].dead += abat;
            }
            else {
                mst[j].attacked += mst[i].amount - mst[i].dead;
                mst[i].dead = mst[i].amount;
                flag = false;
                break;
            }
        }
        if (flag) {
            for (int j = i; j <= cnt; j++) {
                ans += mst[j].amount;
            }
            ans -= mst[i].dead;
            cout << ans << endl;
            break;
        }
    }
    return 0;
}
