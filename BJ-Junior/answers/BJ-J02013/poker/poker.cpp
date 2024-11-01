#include <bits/stdc++.h>

using namespace std;

int n;
int book[7][15];
int ans;

int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin >> n;
	char hs, bh;
	int wzhs, wzbh;
	for(int i = 1;i <= n;i++){
		cin >> hs >> bh;
		if(hs == 'D') wzhs = 1;
		else if(hs == 'C') wzhs = 2;
		else if(hs == 'H') wzhs = 3;
		else if(hs == 'S') wzhs = 4;
		if(bh == 'A') wzbh = 1;
		else if(bh == '2') wzbh = 2;
		else if(bh == '3') wzbh = 3;
		else if(bh == '4') wzbh = 4;
		else if(bh == '5') wzbh = 5;
		else if(bh == '6') wzbh = 6;
		else if(bh == '7') wzbh = 7;
		else if(bh == '8') wzbh = 8;
		else if(bh == '9') wzbh = 9;
		else if(bh == 'T') wzbh = 10;
		else if(bh == 'J') wzbh = 11;
		else if(bh == 'Q') wzbh = 12;
		else if(bh == 'K') wzbh = 13;
		book[wzhs][wzbh]++;
	}
	for(int i = 1;i <= 4;i++)
		for(int j = 1;j <= 13;j++)
			if(book[i][j] == 0)
				ans++;
	cout << ans << endl;
	return 0;
}