#include <bits/stdc++.h>
#define int long long
using namespace std;


int T,n,m,l,V;


signed main(){


	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	
	cin >> T;
	while(T--){
		cin >> n >> m >> l >> V;
		int res1 = 0;
		vector<int> p (m+1,0);
		vector<int> d (n+1,0);
		vector<int> v (n+1,0);
		vector<int> a (n+1,0);
		vector<int> cs;
		set<int> st;
		
		for(int i = 1; i <= n; i++){
			cin >> d[i] >> v[i] >> a[i];
		}
		
		for(int j = 1; j <= m; j++){
			cin >> p[j];
		}
		
		for(int i = 1; i <= n; i++){
			
			if(a[i] == 0){
				if(v[i] > V){
					res1++;
					st.insert(1);
					cs.push_back(i);
				}
				continue;
			}
			
			int l = 1,r = m,cc = 0;
			while(l <= r){
				int mid = l + (r-l)/2;
				if(p[mid] < d[i]){
					cc = mid;
					l = mid+1;
				}else{
					r = mid-1;
				}
				
			}
			cc++;
			int xxx = sqrt(v[i] * v[i] + 2ll * a[i] * (p[cc] - d[i]+1));
			st.insert(cc);
			//cout << cc << " <- ";
			if(xxx > V){
				res1++;
				//cout << i << " ";
				cs.push_back(i);
			}
				
			
			
			
		}
		//int sz = cs.size();
		//for(int i = 0; i < sz; i++){
		//	cout << cs[i] << " ";
		//}
		
		cout << res1 << " " << st.size() << endl;
		
	}
	
	
	return 0;
}
