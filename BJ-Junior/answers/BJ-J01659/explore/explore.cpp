#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	while(t --){
		int n,m,k,x,y,d,cnt[1100][1100] = {0},ans = 0;
		char mp[1100][1100];
		cin >> n >> m >> k >> x >> y >> d;
		cnt[x][y] = 1;
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= m;j ++){
				cin >> mp[i][j];
			}
		}
		while(k --){
			switch(d){
				case 0:if((y + 1) <= m && mp[x][y + 1] == '.'){cnt[x][y + 1] = 1;y ++;}else d = (d + 1) % 4;break;
				case 1:if((x + 1) <= n && mp[x + 1][y] == '.'){cnt[x + 1][y] = 1;x ++;}else d = (d + 1) % 4;break;
				case 2:if((y - 1) >= 1 && mp[x][y - 1] == '.'){cnt[x][y - 1] = 1;y --;}else d = (d + 1) % 4;break;
				case 3:if((x - 1) >= 1 && mp[x - 1][y] == '.'){cnt[x - 1][y] = 1;x --;}else d = (d + 1) % 4;break;
			}
		}
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= m;j ++){
				if(cnt[i][j] == 1)ans ++;
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
