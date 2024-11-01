#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int n,a[N];
priority_queue<int,vector<int>,greater<int>> heap;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;++i) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;++i)
	{
		if(heap.size())
		{
			int x = heap.top();
			if(a[i] > heap.top()) heap.pop();
		}
		heap.push(a[i]);
	}
	cout << heap.size() << '\n';
	return 0;
}
