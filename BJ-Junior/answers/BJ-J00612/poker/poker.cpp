#include <bits/stdc++.h>
using namespace std;
int po[53],n;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		string tmp;
		cin >> tmp;
		char s1 = tmp[0];
		char s2 = tmp[1];
		int k = 0;
		if (s1 == 'D') k += 13;
		if (s1 == 'H') k += 26;
		if (s1 == 'S') k += 39;
		if (s2 == 'A') k++;
		else if (s2 == 'T') k += 10;
		else if (s2 == 'J') k += 11;
		else if (s2 == 'Q') k += 12;
		else if (s2 == 'K') k += 13;
		else k += (s2 - '0');
		po[k]++; 
	}
	int cnt = 0;
	for (int i = 1;i <= 52;i++) if (po[i] == 0) cnt++;
	cout << cnt << endl;
    return 0;
}