#include<bits/stdc++.h>
using namespace std;
vector<int> v1;
vector<int> v2;
int n, a[100010];
int maxn = 0;
void dfs(int step)
{
	if(step > n)
	{
		int sum = 0;
		for(int i = 1; i < v1.size(); i++)
		if(v1[i] == v1[i - 1])sum += v1[i];
		for(int i = 1; i < v2.size(); i++)
		if(v2[i] == v2[i - 1])sum += v2[i];
		maxn = max(maxn, sum);
		return;
	}
	v1.push_back(a[step]);
	dfs(step + 1);
	v1.pop_back();
	v2.push_back(a[step]);
	dfs(step + 1);
	v2.pop_back();
}
int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int TT;
	cin >> TT;
	while(TT--)
    {
        maxn = 0;
        v1.clear();
        v2.clear();
        cin >> n;
        for(int i = 1; i <= n; i++)cin >> a[i];
        dfs(1);
        cout << maxn << "\n";
    }
    return 0;
}
