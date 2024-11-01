#include<bits/stdc++.h>
using namespace std;

int t,n,ans;
int num[220000];
int c[1000001];
bool vis[220000];
int lis1[220000],lis2[220000];
const int maxn = 1e5;

int score(){
	ans = 0;
	bool f = 1;
	for(int i = 1; i <= maxn; i++){
		if(c[i] > 1){
			vis[i] = f;
			if(f){
				f = 0;
			}else{
				f = 1;
			}
		}
	}
	
	int p1 = 1,p2 = 1;
	for(int i = 1; i <= n; i++){
		if(vis[num[i]] == 0){
			lis1[p1++] = num[i];
		}else{
			lis2[p2++] = num[i];
		}
	}
	
	for(int i = 1; i <= max(p1,p2)-1; i++){
		if(lis1[i+1] == lis1[i]){
			ans += lis1[i+1];
		}
		if(lis2[i+1] == lis2[i]){
			ans  += lis2[i+1];
		}
	}
	return ans;
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);

	cin >> t;
	for(int i = 1; i <= t; i++){
		memset(c,0,sizeof(c));
		memset(num,0,sizeof(num));
		memset(vis,0,sizeof(vis));
		memset(lis1,0,sizeof(lis1));
		memset(lis2,0,sizeof(lis2));
		
		cin >> n;
		for(int j = 1; j <= n; j++){
			cin >> num[j];
			c[num[j]]++;
		}
		cout << score() << endl;
	}
	return 0;
}
