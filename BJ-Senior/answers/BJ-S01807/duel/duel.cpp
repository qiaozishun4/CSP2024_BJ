#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i ++)
#define nrep(i, a, b) for(int i = (a); i >= (b); i --)
using namespace std;

void print() { cerr << endl; }
template<typename T, typename ...Ts>
void print(T v, Ts ...vs) { cerr << v << " "; print(vs...); }


typedef long long ll;
ll read() {
    ll x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
    while(isdigit(ch)) { x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar(); }
    return x * f;
}

const int N = 1e6 + 10;

int a[N];

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    
    int n = read();
    rep(i, 1, n) a[i] = read();
    sort(a + 1, a + n + 1);
    queue<int> q;
    rep(i, 1, n) {
        if(!q.empty() && a[i] > q.front()) q.pop();
        q.push(a[i]);
    }
    cout << q.size() << endl;
}