#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
int ap[N], a[N], c[N], ord[N];
char s[N];
int lim[N << 2], Tg[N << 2], dep[N << 2];
int dir[N << 2];
int S[N << 2];
ll sum[N << 2], ans[N];
bool cmp(int x, int y)
{
	return c[x] < c[y];
}
void init(int n)
{
	int i;
	for(i = (1 << n) - 1; i >= 1; i--)
		dep[i] = dep[i << 1] + 1;
	Tg[1] = 2 << n;
	for(i = 1; i < (1 << n); i++)
	{
		Tg[i << 1] |= Tg[i];
		Tg[i << 1 | 1] |= Tg[i];
		Tg[i << 1 | dir[i]] |= (1 << dep[i]);
	}
}
void build(int n)
{
	int i, x, y;
	for(i = 0; i < (1 << n); i++)
	{
		S[i + (1 << n)] = (2 << n) - 1;
		sum[i + (1 << n)] = i + 1;
	}
	for(i = (1 << n) - 1; i >= 1; i--)
	{
		x = i << 1 | dir[i];
		y = i << 1 | (dir[i] ^ 1);
		sum[i] = sum[x];
		S[i] = S[x] >> 1;
		if(S[x] & 1)
		{
			sum[i] += sum[y];
			S[i] |= S[y] >> 1 | (S[y] & 1);
		}
	}
}
void upd(int n, int p, int v, int qwq)
{
	int i, x, y;
	S[p + (1 << n)] = (1 << v);
	sum[p + (1 << n)] = qwq;
	i = (p + (1 << n)) >> 1;
	while(i)
	{
		x = i << 1 | dir[i];
		y = i << 1 | (dir[i] ^ 1);
		sum[i] = sum[x];
		S[i] = S[x] >> 1;
		if(S[x] & 1)
		{
			sum[i] += sum[y];
			S[i] |= S[y] >> 1 | (S[y] & 1);
		}
		i >>= 1;
	}
}
int xr[4], tp[N], lg[N], pos[N];
vector<int> awa[20];

int main()
{
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	int T, n, m, i, j, p, k = 0, t;
	ll qwq;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; i++)
		scanf("%d", ap + i);
	for(i = 1; i <= m; i++)
		scanf("%d", c + i);
	for(i = 1; i <= m; i++)
		ord[i] = i;
	sort(ord + 1, ord + m + 1, cmp);
	while((n - 1) >> k)
		k++;
	for(i = 1; i <= k; i++)
	{
		scanf("%s", s);
		for(j = 0; j < (1 << (k - i)); j++)
			dir[j + (1 << (k - i))] = s[j] - '0';
	}
	init(k);
	lg[0] = -1;
	for(i = 1; i <= n; i++)
		lg[i] = lg[i >> 1] + 1;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d%d", xr, xr + 1, xr + 2, xr + 3);
		for(i = 0; i < 20; i++)
			awa[i].clear();
		for(i = 1; i <= n; i++)
		{
			a[i] = min(ap[i] ^ xr[i & 3], k);
			// printf("TAG%d\n", Tg[i + (1 << k) - 1]);
			pos[i] = (Tg[i + (1 << k) - 1] >> (a[i] + 1));
			pos[i] = lg[pos[i] & -pos[i]] + a[i] + 1;
			// printf("EE%d %d\n", i, a[i]);
			if(pos[i] > lg[i - 1] + 1)
			{
				awa[pos[i]].emplace_back(i);
				// printf("haha %d %d\n", pos[i], i);
			}
		}
		build(k);
		t = 0;
		p = 0;
		for(i = 1; i <= m; i++)
		{
			while(t < c[ord[i]])
			{
				++t;
				upd(k, t - 1, a[t], (pos[t] <= lg[t - 1] + 1 ? 0 : t));
			}
			while((c[ord[i]] - 1) >> p)
			{
				p++;
				for(auto o: awa[p])
				{
					// printf("GG%d %d\n", p, o);
					upd(k, o - 1, a[o], 0);
				}
			}
			// printf("!!%d\n", c[ord[i]]);
			ans[ord[i]] = sum[1 << (k - p)];
		}
		qwq = 0;
		for(i = 1; i <= m; i++)
		{
			// printf("#%d: %lld\n", c[i], ans[i]);
			qwq ^= i * ans[i];
		}
		printf("%lld\n", qwq);
	}
	return 0;
}