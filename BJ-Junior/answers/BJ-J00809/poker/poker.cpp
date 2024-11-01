#include <iostream>
#include <cstring>
#include <map>
using namespace std;

string s;
map<int, int> m;
int n, ans, num;

int fid(string s)
{
	
	switch (s[0]){
		case 'D' : num = 0; break;
		case 'C' : num = 13; break;
		case 'H' : num = 26; break;
		case 'S' : num = 39; break;
	}
	switch (s[1]){
		case 'A' : num += 1; break;
		case '2' : num += 2; break;
		case '3' : num += 3; break;
		case '4' : num += 4; break;
		case '5' : num += 5; break;
		case '6' : num += 6; break;
		case '7' : num += 7; break;
		case '8' : num += 8; break;
		case '9' : num += 9; break;
		case 'T' : num += 10; break;
		case 'J' : num += 11; break;
		case 'Q' : num += 12; break;
		case 'K' : num += 13; break;
	}
	return num;
}

int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		m[fid(s)]++;
	}
	for (int i = 1; i <= 52; i++) ans += (m[i] == 0) ? 1 : 0;
	cout << ans << endl;
	return 0;
}