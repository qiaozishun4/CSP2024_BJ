#include<bits/stdc++.h>
using namespace std;

int a[100010];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n, l = 0;
    cin >> n;
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    sort(a, a+n);
    for(int i=0;i<n;i++) if(a[l] < a[i]) l++;
    cout << n - l;
}
