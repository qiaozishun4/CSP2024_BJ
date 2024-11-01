#include<bits/stdc++.h>
using namespace std;

map<int, int> mp = {{0, 6}, {1, 2}, {2, 5}, {3, 5}, {4, 4}, {5, 5}, {6, 6}, {7, 3}, {8, 7}, {9, 6}};

int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		
		if(n <= 35){
			int ans = -1;
			for(int i = 1; i <= 100000; i++){
				string s = to_string(i);
				int sum = 0;
				for(auto c : s) sum += mp[c - '0'];
				if(sum == n){
					ans = i;
					break;
				}
			}
			printf("%d\n", ans);
		}
		else{
			if(n % 7 == 0){
				int step = n / 7;
				while(step--) printf("8");
				printf("\n");
			}
			else if(n % 7 == 1){
				printf("10");
				int step = n / 7 - 1;
				while(step--) printf("8");
				printf("\n");
			}
		}
	}
	return 0;
}