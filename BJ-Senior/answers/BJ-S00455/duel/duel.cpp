#include <iostream>
#include <algorithm>
using namespace std;

int r[100010], b[100010], c[100010]; // b = attack, c = survive

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> r[i];

	sort(r + 1, r + n + 1);

	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		if(r[i] != r[i - 1])
            cnt++;
        b[cnt]++;
	}
	for(int i = 1; i <= cnt; i++)
		c[i] = b[i];

	int pos = 1;
	for(int i = 2; i <= cnt; i++)
    {
        for(int j = pos; j < i && c[i] > 0; j++)
        {
            if(c[j] == 0)
                continue;
            if(b[i] >= c[j])
            {
                b[i] -= c[j];
                b[j] = c[j] = 0;
                pos++;
                continue;
            }
            else
            {
                c[j] -= b[i];
                b[i] = 0;
                break;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= cnt; i++)
        ans += c[i];
    cout << ans << endl;
    return 0;
}
