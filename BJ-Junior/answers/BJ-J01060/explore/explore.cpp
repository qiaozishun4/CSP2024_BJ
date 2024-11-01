#include<bits/stdc++.h>
#define int long long
using namespace std;

int t,n,m,k,a[1010][1010];


signed main(){
	
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	cin >> t;
	while(t--){
		
		cin >> n >> m >> k;
		int res = 1,si = 0,sj = 0,d = 0;
		cin >> si >> sj >> d;
		memset(a,0,sizeof(a));
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				char c;
				cin >> c;
				if(c == '.'){
					a[i][j] = 0;					
				}else{
					a[i][j] = -1;			
				}
			}
		}
		a[si][sj] = 1;
		for(int i = 1; i <= k; i++){
		
			if(d == 0){
				if(sj+1 <= m && sj+1 >= 1 && a[si][sj+1] != -1){
					sj++;
					if(a[si][sj] == 0)res++;
					a[si][sj] = 1;
					
				}else{
					d = (d+1)%4;
				}
			}
			else if(d == 1){
				if(si+1 <= n && si+1 >= 1 && a[si+1][sj] != -1){
					si++;
					if(a[si][sj] == 0)res++;
					a[si][sj] = 1;
				}else{
					d = (d+1)%4;
				}
			}
			else if(d == 2){
				if(sj-1 <= m && sj-1 >= 1 && a[si][sj-1] != -1){
					sj--;
					if(a[si][sj] == 0)res++;
					a[si][sj] = 1;
				}else{
					d = (d+1)%4;
				}
			}
			else if(d == 3){
				if(si-1 <= n && si-1 >= 1 && a[si-1][sj] != -1){
					si--;
					if(a[si][sj] == 0)res++;
					a[si][sj] = 1;
				}else{
					d = (d+1)%4;
				}
			}
			
			
		}
		
		cout << res << endl;
		
		
	}
	
	return 0;
	
}
