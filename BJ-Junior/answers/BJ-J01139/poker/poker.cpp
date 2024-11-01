#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct poker {
	char flower;
	char dian;
}a[55];
char ds[13] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
char fs[4] = {'D','C','H','S'};
int main () {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i].flower >> a[i].dian;
	}
	for (int i = 0; i < n; i++){
		for (int j = i+1; j < n; j++){
			if (a[i].flower == a[j].flower && a[i].dian == a[j].dian){
					a[j].dian = '0';
					a[j].flower = '0';
			}
		}
	}
	int ans = 52;
	for (int i = 0; i < 13; i++){
		for (int j  = 0; j < 4; j++) {
			//cout << fs[j] << " " << ds[i] << endl;
			for (int k = 0; k < n; k++){
				if (a[k].dian == ds[i] && a[k].flower == fs[j]) {
					ans--;
				}
			}
		}
	}
	cout << ans;
	return 0;
} 
