

#include <bits/stdc++.h>

using namespace std;

int a[10];

int main () {
	
	freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int Ti = 0;
    cin >> Ti;
    a[2] = 1;
    a[3] = 7;
    a[4] = 4;
    a[5] = 2;
    a[6] = 6;
    
    while (Ti--) {
		int num = 0;
		cin >> num;
		
		if (num %7==0) {
		//3 4 5
			for (int i = 1; i <= num/7; i++) {
				cout << 8;
			}
			cout << endl;
			continue;
		}
		if (num == 6) {
			cout << 0 << endl;
			continue;
		}
		int t8 = num/7;
		num%=7;
		if (num == 1) {
			cout << -1 << endl;
			continue;
		}
		cout << a[num];
		for (int i = 1; i <= t8; i++) {
			cout << 8;
		}
		cout << endl;
	}
	
	return 0;
}
