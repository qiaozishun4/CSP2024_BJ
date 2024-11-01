#include<bits/stdc++.h>
using namespace std;
const int MAXN = 60;

int n, tot;
bool vis[MAXN];
string s;

int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> s;	
		int res = 0;
		if (s[0] == 'D') res = 0;
		else if (s[0] == 'C') res = 13;
		else if (s[0] == 'H') res = 26;
		else res = 39;
		
		if (s[1] == 'A') res += 1;
		else if (s[1] == 'T') res += 10;
		else if (s[1] == 'J') res += 11;
		else if (s[1] == 'Q') res += 12;
		else if (s[1] == 'K') res += 13;
		else res += (s[1]-'0');
		
		if (vis[res] == false){
			vis[res] = true;
			tot++;
		}
	}
	cout << 52-tot;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}