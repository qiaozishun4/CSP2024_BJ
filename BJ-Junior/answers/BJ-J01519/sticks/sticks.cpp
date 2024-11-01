#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	map<int,int> m;
	m.insert(pair<int,int>(6,0));
	m.insert(pair<int,int>(2,1));
	m.insert(pair<int,int>(5,2));
	m.insert(pair<int,int>(5,3));
	m.insert(pair<int,int>(4,4));
	m.insert(pair<int,int>(5,5));
	m.insert(pair<int,int>(6,6));
	m.insert(pair<int,int>(3,7));
	m.insert(pair<int,int>(7,8));
	m.insert(pair<int,int>(6,9));
	map<int,int> ::iterator it;
	int t;
	cin >> t;
	vector<int> vi(t);
	while(t --)
	{
		int n;
		cin >> n;
		int ans=1e9;
		int temp = 0;
		bool flag = false;
		while(n && it!=m.end())
		{
			if (n-it->first >= 0)
			{
				n -= it->first;
				temp = temp*10+it->second;
				flag = true;
			}
			else
				it ++;
			ans = min(temp,ans);
		}
		if (flag)
			vi.push_back(ans);
		else
			vi.push_back(-1);
	}
	for (int i=0;i<t;i++)
		cout << vi[i] << endl;
	return 0;
}
