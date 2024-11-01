#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	
	bool a[60] = {false};
	string s;
	int n, h, sh, ans = 0;
	cin >> n;
	
	for (int i = 0; i < n; i ++ )
	{
		cin >> s;
		
		if (s[0] == 'D') h = 0;
		else if (s[0] == 'C') h = 13;
		else if (s[0] == 'H') h = 26;
		else if (s[0] == 'S') h = 39;
		
		if (s[1] == 'A') sh = 1;
		else if (s[1] == '2') sh = 2;
		else if (s[1] == '3') sh = 3;
		else if (s[1] == '4') sh = 4;
		else if (s[1] == '5') sh = 5;
		else if (s[1] == '6') sh = 6;
		else if (s[1] == '7') sh = 7;
		else if (s[1] == '8') sh = 8;
		else if (s[1] == '9') sh = 9;
		else if (s[1] == 'T') sh = 10;
		else if (s[1] == 'J') sh = 11;
		else if (s[1] == 'Q') sh = 12;
		else if (s[1] == 'K') sh = 13;
		
		a[h + sh] = true;
	}
	
	for (int i = 0; i < 52; i ++ )
	{
		if (a[i] == false) ans ++ ;
	}
	
	cout << ans << endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
