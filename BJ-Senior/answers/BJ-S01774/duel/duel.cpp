#include <bits/stdc++.h>
/*help me with lxm to back to real l*/
using namespace std;
const int MAXN = 100005;

int n, cnt = 0, m;
//int r[MAXN];
int t, dui[MAXN], aatk[MAXN];
//bool change, f;

//youhua
int dn = MAXN, sj = 0;

int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    m = n;
    for (int i = 1; i <= n; ++i) {
        cin >> t;
        dui[t]++;
        if (t > sj) sj = t;
        if (t < dn) dn = t;
    }
    //cout <<"arr::" << dn << " ~ " << sj << endl;
    for (int i = dn; i <= sj; ++i) {
        if (dui[i] > 0) {
            for (int j = i + 1; j <= sj; ++j) {
                //change = false;
                while (dui[j] > 0 && dui[i] > 0) {
                    //change = true;
                    //cout << "## " << j << "[" << dui[j] << "] atk " << i << "[" << dui[i] << "] for once" << endl;
                    --dui[i];
                    --dui[j];
                    aatk[j]++;
                    cnt++;
                    m--;
                }
            }
        }
        if (dui[i] == 0 && aatk[i] > 0) {
            for (int j = i + 1; j <= sj; ++j) {
                while (dui[j] > 0 && aatk[i] > 0) {
                    //cout << "## " << j << "[" << dui[j] << "] atk ar-atked " << i << "[" << aatk[i] << "] for once" << endl;
                    --aatk[i];
                    --dui[j];
                    ++aatk[j];
                    cnt++;
                    m--;
                }
            }
        }
    }
    cout << m;
    return 0;
}
