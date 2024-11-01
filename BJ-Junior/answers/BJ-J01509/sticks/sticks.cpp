#include<bits/stdc++.h>
using namespace std;



int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		cin >> n;
		int k = n / 7;
		for(int i = 1;i <= k;i++){
			cout << 8;
		}
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
