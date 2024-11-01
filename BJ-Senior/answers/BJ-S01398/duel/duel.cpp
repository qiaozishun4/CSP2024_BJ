#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, a[N];

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.ans", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, cmp);
    int l = n - 2, r = n - 1;
    while(l >= 0)
    {
        if(a[l] > a[r]) r--;
        l--;
    }
    cout << r + 1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
