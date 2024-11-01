#include "bits/stdc++.h"
using namespace std;
string f[20], s[20], ans;
int n, t;
void init()
{
	f[2] = s[2] = "1";
	f[3] = s[3] = "7";
	f[4] = s[4] = "4";
	f[5] = s[5] = "2";
	f[6] = "6";
	s[6] = "0";
	f[7] = s[7] = "8";
	f[8] = "16";
	s[8] = "01";
	f[9] = "18";
	s[9] = "03";
	f[10] = "23";
	s[10] = "04";
	f[11] = "20";
	s[11] = "02";
	f[12] = "28";
	s[12] = "06";
	f[13] = "68";
	s[13] = "08";
	f[14] = s[14] = "88";
}

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	init();
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	while(n--)
	{
		ans.clear();
		cin >> t;
		if(t < 2)
		{
			cout << "-1" << endl;
			continue;
		}
		while(t >= 14)	ans += "8",t -= 7;
		ans = f[t] + ans;
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
