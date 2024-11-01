#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
char a[100];
int main () {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int flag = 1;
		if(n == 1) {
			cout << "-1" << endl;
			flag = 0;
		}
		if (n == 2) {
			cout << "1" << endl;
			flag = 0;
		}
		if (n == 3) {
			cout << "7" << endl;
		}
		if (flag == 1) {
				for (int i = 2;; i++) {
				int ii = i;
				int sum = 0;
				while (ii / 10) {
					int inr = ii % 10;
					if (inr == 0) sum += 6;
					if (inr == 1) sum += 2;
					if (inr == 2) sum += 5;
					if (inr == 3) sum += 5;
					if (inr == 4) sum += 4;
					if (inr == 5) sum += 5;
					if (inr == 6) sum += 6;
					if (inr == 7) sum += 3;
					if (inr == 8) sum += 7;
					if (inr == 9) sum += 6;
					ii /= 10;
				}
				int inr = ii % 10;
				if (inr == 0) sum += 6;
				if (inr == 1) sum += 2;
				if (inr == 2) sum += 5;
				if (inr == 3) sum += 5;
				if (inr == 4) sum += 4;
				if (inr == 5) sum += 5;
				if (inr == 6) sum += 6;
				if (inr == 7) sum += 3;
				if (inr == 8) sum += 7;
				if (inr == 9) sum += 6;
				if (sum == n) {
					cout << i << endl;
					break;
				}
				if (sum > n) {
					break;
				}
			}
		}
	}
	return 0;
}
