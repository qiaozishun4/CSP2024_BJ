#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> pii;

const int N = 1e5 + 10;
struct node{
    int cnt , can = 0;
}a[N] , t[N];
int main(){
    freopen("duel.in" , "r" , stdin);
    freopen("duel.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i <= 1e5; i++)t[i].cnt = t[i].can = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        t[x].cnt++;
        t[x].can++;
    }
    int sz = 0;
    for (int i = 1; i <= 1e5; i++)
        if (t[i].cnt)
            a[++sz] = t[i];
    int l = 1 , r = 2;
    while (r <= sz){
        while (a[r].can == 0)r++;
        while (a[l].cnt == 0)l++;
        while (l >= r)r++;
        if (r > sz)break;
        if (a[l].cnt < a[r].can){
            a[r].can -= a[l].cnt;
            a[l].cnt = a[l].can = 0;
        }
        else{
            if (a[l].cnt == a[r].can)a[l].can = 0;
            a[l].cnt -= a[r].can;
            a[r].can = 0;
        }
    }
    int ans = 0;
    for (int i = 1; i <= sz; i++)ans += a[i].cnt;
    cout << ans << '\n';
    return 0;
}
//15.40
