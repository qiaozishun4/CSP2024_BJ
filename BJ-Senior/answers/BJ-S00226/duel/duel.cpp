#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int NR = 1e5 + 10;
int A[NR];
int n;

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    sort(A+1, A+n+1);
    int i = 1, j = 2;
    while (j <= n)
    {

        if (A[j] > A[i])
        {
            i++;
        }
        j++;
    }
    cout << n - i + 1 << endl;
    return 0;
}
