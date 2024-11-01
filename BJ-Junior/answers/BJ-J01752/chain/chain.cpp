// By Pr_159
// 2024.10.26
// Sugar_Pigeon & 159 rp++!

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

//TODO
const int N = 1e3 + 5;
const int L = 2e3 + 5;

int T, n, k, q, l[N], r, c;
int S[N][L];

void solve1() {
    for(int i = 1; i <= n; ++i) {
        queue<int> lst;
        for(int j = 1; j <= l[i]; ++j) {
            if(S[i][j] == 1) {
                lst.push(j);
            }
            if(!lst.empty() && j - lst.front() + 1 > k) {
                lst.pop();
            }
            if(S[i][j] == c) {
                if(!lst.empty() && j - lst.front() + 1 >= 2) {
                    cout << "1\n";
                    return;
                }
            }
        }
    }
    cout << "0\n";
    return;
}

int main() {
    //subtask1 10 pts
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while(T--) {
        cin >> n >> k >> q;
        for(int i = 1; i <= n; ++i) {
            cin >> l[i];
            for(int j = 1; j <= l[i]; ++j) {
                cin >> S[i][j];
            }
        }
        while(q--) {
            cin >> r >> c;
            if(r == 1) {
                solve1();
            }
        }
    }
    return 0;
}
/*
    310pts, enough for me (haha, please don't let me down)
    already in grade nine, should study for school-cources currently
    confidence (perhaps it's equals to mine happiness now) -> others' apperciation -> time management & strong will
    *the north sea is far, still can arrive by swirling wind*
    *the past has gone, still not too late to seize the day*

    maybe I'll never be
    all the things I wanna be
    but now's not the time to cry
    now's the time to find out why
    maybe you're the same as me
    we'll see thing they never see
    YOU & I ARE GONNA LIVE FOREVER!

    please wait for me my friends, we are going to standing at the peak together one day.
    come on Pr_159, come on please!

    -> bad at English *laugh out loud*
*/
