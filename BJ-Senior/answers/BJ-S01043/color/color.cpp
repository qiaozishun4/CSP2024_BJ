#include <iostream>
using namespace std;
const int maxn = 1e5;

int a[maxn + 5],n,t;

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1;i <= n; i++) cin >> a[i];
		int ans = 0;
		int front = clock();
		for(int i = 0;i < (1<<n); i++){
			long long lst0 = 0,lst1 = 0,sum = 0;
			for(int j = 1;j <= n; j++){
				if(i & (1 << j - 1)){
					if(a[lst1] == a[j]) sum += a[j];
					lst1 = j;
				}
				else{
					if(a[lst0] == a[j]) sum += a[j];
					lst0 = j;
				}
			}
			ans = max(ans,sum);
			if((clock()-front)/CLOCKS_PER_SEC >= 0.9 / t){
				cout << ans << endl;
				continue;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}