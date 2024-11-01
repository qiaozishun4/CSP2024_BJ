#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#include <algorithm>

// #define debug

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 1;
int d[N], v[N], a[N], p[N];
bitset<N> st;  // 0:have  1:no
bitset<N> de, zero;
vector<pii> t;
int n, m;
int res1 = 0, res2 = 0;

void dfs(int idx)
{
	if(idx >= m + 1)
	{
		de = zero;
		for(int i = 1; i <= m; i ++ )
		{
			if(!st[i])
			{
				for(int j = 0; j < t.size(); j ++ )
				{
					auto tt = t[j];
					if(tt.x <= p[i] && p[i] <= tt.y)
					{
						de[j] = true;
					}
				}
			}
		}

		int cnt = 0;
		for(int i = 0; i < t.size(); i ++ )
		{
			if(de[i])
			{
				cnt ++ ;
			}
		}
		if(cnt == res1)
		{
			int cntp = 0;
			for(int i = 1; i <= m; i ++ )
			{
				if(st[i])
				{
					cntp ++ ;
				}
			}
			res2 = max(res2, cntp);
		}
		return ;
	}

	for(int i = 0; i <= 1; i ++ )
	{
		st[idx] = i;
		dfs(idx + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);

	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);

	int T;
	cin>>T;
	while(T--)
	{
		t.clear();

		int L, V;
		bool flagA=true, flagB=true;
		cin>>n>>m>>L>>V;
		for(int i = 1; i <= n; i ++ )
		{
			cin>>d[i]>>v[i]>>a[i];
			if(a[i] != 0)
			{
				flagA=false;
			}
			if(a[i] <= 0)
			{
				flagB=false;
			}
		}
		for(int i = 1; i <= m; i ++ )
		{
			cin>>p[i];
		}

		if(flagA)  // a = 0
		{
			sort(p + 1, p + 1 + m);

			int res = 0;
			for(int i = 1; i <= n; i ++ )
			{
				if(v[i] > V && d[i] <= p[m])
				{
					res ++ ;
				}
			}
			if(res == 0)
			{
				cout<<0<<" "<<m<<endl;
			}
			else
			{
				cout<<res<<" "<<m - 1<<endl;
			}

			continue;
		}
		else if(flagB)  // a > 0
		{
			sort(p + 1, p + 1 + m);

			int res = 0;
			for(int i = 1; i <= n; i ++ )
			{
				if(v[i] > V && d[i] <= p[m])
				{
					res ++ ;
				}
				else if(v[i] <= V)
				{
					ll x = ceil(((ll)V*V - v[i]*v[i]) / (2.0 * a[i]));
					if(d[i] + x + 1 <= p[m])
					{
						res ++ ;
					}
				}
			}
			if(res == 0)
			{
				cout<<0<<" "<<m<<endl;
			}
			else
			{
				cout<<res<<" "<<m - 1<<endl;
			}

			continue;
		}

		for(int i = 1; i <= n; i ++ )
		{
			if(v[i] > V)
			{
				if(a[i] < 0)
				{
					ll x = ceil(((ll)V*V - v[i]*v[i]) / (2.0 * a[i]));
					if(d[i] + x <= L)
					{
						t.push_back({d[i], d[i] + x - 1});
					}
					else
					{
						t.push_back({d[i], L});
					}
				}
				else
				{
					t.push_back({d[i], L});
				}
			}
			else if(v[i] <= V)
			{
				if(a[i] > 0)
				{
					ll x = ceil(((ll)V*V - v[i]*v[i]) / (2.0 * a[i]));
					if(d[i] + x + 1 <= L)
					{
						t.push_back({d[i] + x + 1, L});
					}
				}
			}
		}

		#ifdef debug
		for(auto tt:t)
		{
			cout<<tt.x<<" "<<tt.y<<endl;
		}
		#endif

		res1 = res2 = 0;

		de = zero;
		for(int i = 1; i <= m; i ++ )
		{
			for(int j = 0; j < t.size(); j ++ )
			{
				auto tt = t[j];
				if(tt.x <= p[i] && p[i] <= tt.y)
				{
					de[j] = true;
				}
			}
		}

		int cnt = 0;
		for(int i = 0; i < t.size(); i ++ )
		{
			if(de[i])
			{
				cnt ++ ;
			}
		}
		res1 = cnt;

		dfs(1);
		cout<<res1<<" "<<res2<<endl;
	}

	return 0;
}