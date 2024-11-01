#include <bits/stdc++.h>
#define N 100005

using namespace std;
int n, res = 0, a[N], b[N], attack[N], len[N], i;
int curlen, nxt, nxtnxtpos, nxtlen, nxtpos;
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    for (i = 0; i < n; i++) b[i] = a[i];
    int tot = unique(b, b+n) - b;
    i = 0;
    
    curlen = upper_bound(a, a+n, a[0]) - a; // this is also the nxtpos
    nxt = upper_bound(b, b+tot, a[0]) - b; // find the first number greater than a[i] in a
    nxtnxtpos = upper_bound(a, a+n, b[nxt]) - a;
    nxtlen = nxtnxtpos - curlen;
    while (i < n) {
        //int range = min(curlen, nxtlen);
        if (curlen <= nxtlen) { // nxt covered cur, 
            i = curlen;
            // for (int j = i; j <= nxtpos-1; j++)
            res += curlen;
        }
        else { // part of cur was covered
            i += curlen;
            res += curlen; // then we'll use nxtnxt and nxtnxtnxt to cover so on
            nxtpos = curlen + curlen;
        }
        for (int j = lower_bound(a, a+n, b[nxt]) - a; j < n; j++) {
            if (!attack[j]) {
                attack[j] = 1;
                res++;
                break;
            }
        }
    }
    cout << n-res;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
