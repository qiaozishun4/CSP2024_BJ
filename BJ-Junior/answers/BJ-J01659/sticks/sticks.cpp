#include<bits/stdc++.h>
using namespace std;
long long t,cnt[1000000] = {6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> t;
	for(long long i = 10;i <= 1000000;i ++){
		long long ii = i,t = 0;
		while(ii != 0){
			ii /= 10;
			t ++;
		}
		for(long long j = 1;j <= t;j ++){
			long long x = i % (long long)(pow(10,j)) / (long long)(pow(10,j - 1));
			cnt[i] += cnt[x];
		}
	}
	while(t --){
		long long n;
		cin >> n;
		if(n <= 1)cout << -1 << endl;
		else{
			for(long long i = 1;i <= 1000000;i ++){
				if(cnt[i] == n){
					cout << i << endl;
					break;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
