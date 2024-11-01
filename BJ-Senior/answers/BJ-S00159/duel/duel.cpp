#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
const int maxn = 1e5 + 5;
int n, a[maxn], t;
map<int, int> p;
int main() {

    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        p[a[i]]++;
    }
    t = p[0];
    for(int i = 1; i < p.size(); i++){
        if(p[i] > t)
            t = p[i];
    }
    cout << t << endl;
    return 0;
}
