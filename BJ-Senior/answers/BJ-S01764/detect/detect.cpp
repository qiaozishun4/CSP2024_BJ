#include<bits/stdc++.h>
using namespace std;
long long T ;	
float n , m , l , V , d[100005] , v[100005] , a[100005] , p[100005] , q[100005] , h[100005] , ans1 = 0 , ans2 = 0;
long long sum[100005];
bool flag[3005][3005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
	ans1 = ans2 = 0;
	    memset(flag,false,sizeof(flag));
	    memset(sum,0,sizeof(flag));
		memset(q,-1,sizeof(q));
		memset(h,-1,sizeof(h));
		cin>>n>>m>>l>>V;
		for(int i = 1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(v[i]<=V&&a[i]>0){
				float cnt = ((V * V) - (v[i] * v[i]))/(2 * a[i]);
				if(cnt == (int)cnt){
					cnt++;
				}
				cnt = ceil(cnt);
				
				if(d[i] + cnt<=l){
					q[i] = d[i] + cnt;
					h[i] = l;
				}
			}
			else if(v[i]>V&&a[i]<0){
				float cnt = ((V * V) - (v[i] * v[i]))/(2 * a[i]);
				
				cnt = ceil(cnt) - 1;
				if(d[i] + cnt<=l){
					h[i] = d[i] + cnt;
					q[i] = d[i];
				}
				else{
					h[i] = l;
					q[i] = d[i];
				}
				
			}
			else if(v[i]>V){
				q[i] = d[i];
				h[i] = l;
			
			}
		}
		for(int i = 1;i<=m;i++){
			cin>>p[i];
			for(int j = 1;j<=n;j++){
				if(p[i]<= h[j]&&p[i] >= q[j]){
					if(sum[j] == 0) ans1++;
					sum[j]++;
					flag[i][j] = true;
				}
			}
	    }
	    bool flag2 = false;
	    for(int i = 1;i<=m;i++){
			flag2 = false;
			for(int j = 1;j<=n;j++){
				if(sum[j] == 1&&flag[i][j] == true){
					flag2 = true;
				}
			}
			if(flag2 == false){
				for(int j = 1;j<=n;j++){
					if(flag[i][j] == true){
						sum[j]--;
						flag[i][j] = false;
					}
				}
				ans2++;
				}
		}
		cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 ‐2
6 4 ‐4
2 5 8 9 15
*/
