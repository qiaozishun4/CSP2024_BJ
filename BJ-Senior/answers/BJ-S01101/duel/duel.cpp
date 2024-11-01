#include <iostream>
#include <queue>
using namespace std;
const int N = 1e5+5;
int a[N];
int main()
{

	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1;i <= n;++i)
	{
		cin >> a[i];
	}
	priority_queue<int> q;
	for (int i = 1;i <= n;++i)
	{
		if (!q.empty() && q.top() > a[i])
		{
			q.pop();
		}
        q.push(a[i]);
	}
	cout << q.size()-1 << endl;
	return 0;
}
