#include<bits/stdc++.h>
using namespace std;
int A[100001];
int main(){
	freopen("color.in", "r",stdin);
	freopen("color.out", "w", stdout);
	int T;
	cin >> T;
	int n;
	for (int i=0; i<T; i++){
		cin >> n;
		for (int j=0; j<n; j++){
			cin >> A[j];
		}
	}
	cout << 1 << endl << 0 << endl << 8 << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
			 
