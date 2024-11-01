#include <bits/stdc++.h>
using namespace std;
int bita[10001];
void add(int n){
	bita[n] += 1;
	for(int i = n;i >= 1;i--){
		if(bita[i] >= 2){
			bita[i] = 0;
			bita[i - 1] += 1;
		}
	}
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	long long t;
	cin >> t;
	while(t--){
		long long n;
		cin >> n;
		int a[1000];
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		long long maxf = 0;
		memset(bita,0,sizeof(bita));
		for(int i = 1;i <= pow(2,n);i++){
			long long ci = 0;
			for(int j = 1;j <= n;j++){
				long long tp = 0;
				for(int k = j - 1;k >= 1;k--){
					if(a[k] == a[j]){
						if(bita[j] == bita[k]){
							tp = a[k];
							break;
						}
					}
				}
				ci += tp;
			}
			maxf = max(maxf,ci);
			add(n);
		}
		cout << maxf << endl;
	}
	return 0;
}
