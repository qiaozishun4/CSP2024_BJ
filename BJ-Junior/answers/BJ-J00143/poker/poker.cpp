#include <bits/stdc++.h>
using namespace std;
int n,a[60];
string s[60];
int main () {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n; i ++){
		cin >> s[i];
		int lsa, lsb;//
		if(s[i][0]=='D'){
			lsa = 0;
		}else if (s[i][0] == 'C') {
			lsa = 13;
		}else if (s[i][0] == 'H') {
			lsa = 26;
		}else if (s[i][0] == 'S') {
			lsa = 39;
		}//color
		if(s[i][1] == 'T'){
			lsb = 10;
		}else if (s[i][1] == 'J'){
			lsb = 11;
		}else if (s[i][1] == 'Q'){
			lsb = 12;
		}else if (s[i][1] == 'K'){
			lsb = 13;
        }else if (s[i][1] == 'A'){
			lsb = 1;
		}else {
			lsb = s[i][1]-'0';
		}
		a[lsa + lsb] = 1;
	}//number
	int tong=0;
	for(int i = 1; i <= 52 ; i ++ ) {
		if (a[i] == 0){
			tong ++;
		}
	}//count how many poker he doesn't have
	cout << tong << endl;
	return 0;
}
