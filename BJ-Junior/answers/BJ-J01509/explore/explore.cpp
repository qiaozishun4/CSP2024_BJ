#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
char a[N][N];
bool b[N][N];

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		int x,y,d;
		scanf("%d%d%d",&x,&y,&d);
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				cin >> a[i][j];			
			}
		}
		b[x][y] = 1;
		for(int i = 1;i <= k;i++){
			if(d == 0){
				if(y + 1 <= m && a[x][y + 1] == '.'){
					y = y + 1;
					b[x][y] = 1;
				}else{
					d = (d + 1) % 4;
				}
			}else if(d == 1){
				if(x + 1 <= n && a[x + 1][y] == '.'){
					x = x + 1;
					b[x][y] = 1;
				}else{
					d = (d + 1) % 4;
				}
			}else if(d == 2){
				if(y - 1 >= 1 && a[x][y - 1] == '.'){
					y = y - 1;
					b[x][y] = 1;
				}else{
					d = (d + 1) % 4;
				}
			}else if(d == 3){
				if(x - 1 >= 1 && a[x - 1][y] == '.'){
					x = x - 1;
					b[x][y] = 1;
				}else{
					d = (d + 1) % 4;
				}
			}
		}
		
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				if(b[i][j] == 1){
					cnt++;
				}
			}
		}
		
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= m;j++){
				b[i][j] = 0;
			}
		}
		cout << cnt << endl;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
