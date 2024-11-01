#include <bits/stdc++.h>

using namespace std;

bool is(string c)
{
	if ((c[0]=='D'||c[0]=='C'||c[0] =='S'||c[0] =='H')&&((c[1]>='2'&&c[1]<='9')||(c[1]=='A'||c[1]=='T'||c[1]=='J'||c[1]=='Q'||c[1]=='K')))
		return true;
	else
		return false;
}

int main()
{
	//1 SA
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=52;
	set<string> s;
	cin >> n;
	while(n --)
	{
		string c;
		cin >> c;
		if (!s.count(c))
			if (is(c))
			{
				s.insert(c);
				ans --;
			}
	}
	cout << ans;
	return 0;
}
