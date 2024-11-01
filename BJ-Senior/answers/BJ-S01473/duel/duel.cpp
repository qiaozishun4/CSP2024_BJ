#include<bits/stdc++.h>
using namespace std;

int zhanli[100001];

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	int result;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> zhanli[i];
	}
	for (int i=1; i<n; i++){
		if (zhanli[i] > zhanli[i-1]){
			 zhanli[i-1] = 0;
		 }
	 }
	 for (int i=0; i<n; i++){
		 if (zhanli[i] != 0){
			result += 1;
		}
	}
	cout << result;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
		 