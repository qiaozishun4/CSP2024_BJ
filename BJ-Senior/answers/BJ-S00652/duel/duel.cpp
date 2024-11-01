#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int a[200005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    queue <int> q;
    q.push(a[1]);
    for (int i = 2;i <= n;i++)
    {
    	if (!q.empty() && q.front() < a[i])
    		q.pop();
    	q.push(a[i]);
    }

    cout << int(q.size()) << endl;
	return 0;
}