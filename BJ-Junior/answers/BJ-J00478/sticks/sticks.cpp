#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
long long p = 1;
long long n,t;
long long a[11] = {6,2,5,5,4,5,6,3,7,6};
int f(long long x){
	long long sum = 0;
	while(x){
		sum += a[x%10];
		x/=10;
	}
	return sum;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		if(n < 2){
			cout << -1 << endl;
			continue;
		}
		p = 1;
		while(1){
			if(f(p) == n){
				cout << p << endl;
				break;
			}
			p++;
		}
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}
