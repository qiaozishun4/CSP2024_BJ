#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int N = 1e5+5;
int a[N];
int h[N];

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);

	int n;
	cin>>n;
	for(int i = 1; i <= n; i ++ )
	{
		cin>>a[i];
		h[a[i]] ++ ;
	}

	int res = 0;
	for(int i = 1; i <= n; i ++ )
	{
		res = max(res, h[a[i]]);
	}

	cout<<res<<endl;

	return 0;
}