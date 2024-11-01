#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	long long t;
	cin >> t;
	while(t--){
		long long n,m,l,vs;
		cin >> n >> m >> l >> vs;
		bool ash = true;
		long long mlc = -1;
		long long d[n + 1],v[n + 1],a[n + 1],p[m + 1];
		for(int i = 1;i <= n;i++){
			cin >> d[i] >> v[i] >> a[i];
			if(a[i] != 0){
				ash = false;
			}
		}
		for(int i = 1;i <= m;i++){
			cin >> p[i];
			mlc = max(mlc,p[i]);
		}
		sort(p + 1,p + m + 1);
		if(ash){
			long long left = -1;
			long long tp1 = 0;
			for(int i = 1;i <= n;i++){
				if(v[i] > vs){
					if(d[i] <= mlc){
						tp1++;
						left = max(left,d[i]);
					}
				}
			}
			cout << tp1 << " ";
			if(tp1 == 0){
				cout << m << endl;
			}
			else{
				cout << m - 1 << endl;
			}
		}
		else{
			long long speed[1000][1000];
			memset(speed,0,sizeof(speed));
			for(int i = 1;i <= n;i++){
				if(a[i] != 0){
					for(int j = d[i];j <= l;j++){
						long long c = ceil(sqrt(pow(v[i],2) * 1.0 + 1.0 * 2 * a[i] * (j - d[i])));
						speed[i][j] = max(c,0ll);
					}
				}
				else{
					for(int o = d[i];o <= l;o++){
						speed[i][o] = v[i];
					}
				}
			}
			bool bcar[n + 1];
			memset(bcar,false,sizeof(bcar));
			bool high[n + 1];
			memset(high,false,sizeof(high));
			set <int> ccar;
			ccar.clear();
			for(int i = 1;i <= n;i++){
				for(int j = 0;j <= l;j++){
					bool tp = false;
					if(speed[i][j] > vs){
						for(int k = 1;k <= m;k++){
							if(p[k] == j){
								ccar.insert(p[k]);
								bcar[i] = true;
								tp = true;
								break;
							}
						}
						if(tp){
							break;
						}
					}
				}
			}
			long long sum1 = 0;
			for(int i = 1;i <= n;i++){
				if(bcar[i]){
					sum1++;
				}
			}
			cout << sum1 << " " << n - (int)ccar.size() << endl;
		}
	}
	return 0;
}
