#include <iostream>
#include <cstdio>
using namespace std;
int a[14] = {0,0,1,7,4,5,6,8,10,18,23,20,28,68};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	long long T,n;
	cin >> T;
	for(int i = 1;i <= T;i++){
		cin >> n;
		if(n < 2){
			cout << "-1";
			cout << endl;
		}else if(n % 7 == 0){
			for(int i = 1;i <= n / 7;i++){
				cout << "8";
			}
			cout << endl;
		}else if(n % 7 == 1){
			cout << "1" << "0";
			for(int i = 1;i <= n / 7 - 1;i++){
				cout << "8";
			}
			cout << endl;
		}else if(n <= 13){
			cout << a[n];
			cout << endl;
		}else if(n > 13){
			cout << a[n - 7 * (n / 7) + 7];
			for(int i = 1;i <= n / 7 - 1;i++){
				cout << "8";
			}
			cout << endl;
		}
	}
	return 0;
}
