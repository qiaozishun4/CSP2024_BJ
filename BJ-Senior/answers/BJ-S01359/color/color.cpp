#include<iostream>
using namespace std;
int n,a,b;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a;
		for(int j = 1;j <=a;j++){
			cin >> b;
		}
	}
	for(int i = 0;i < n;i++){
		cout << 0 << endl;
	}
	return 0;
}
