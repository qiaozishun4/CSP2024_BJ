#include<bits/stdc++.h>
using namespace std;
int n;
int a[100010];
bool book[100010];
priority_queue<int> pq;
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];;
    sort(a+1, a+n+1);
    for(int i=1, j=0; i<=n; i=j+1) {
        while(a[j+1]==a[i]) {
            ++j;
            if(!pq.empty()) pq.pop();
        }
        for(int k=i; k<=j; ++k) pq.push(a[k]);
    }
    cout << pq.size();
    return 0;  
}