#include <bits/stdc++.h>
using namespace std;
char a[102][102];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    for(int i = 0;i < 102;i++){
	a[i][0] = 'x';
	}
    int t,cnt = 1;
    cin >>t;
    for(int i = 0;i < t;i++){
        int n,m,k,x,y,d;
        cin >>n>>m>>k>>x>>y>>d;
		for(int j = 1;j <= n;j++){
			for(int k = 1;k <= m;k++){
				cin >>a[j][k];	
			}
		}
		for(int j = 0;j < k;j++){
			if(d == 0){
				if(a[x][y+1] == '.' || a[x][y+1] == ','){
					if(a[x][y+1] == '.'){
						cnt++;	
					}
					y = y+1;
					a[x][y] = ',';
				}
				else{
					d++;
				}
				continue;
			}
			if(d == 1){
				if(a[x-1][y] == '.' || a[x-1][y] == ','){
					if(a[x-1][y] == '.'){
						cnt++;	
					}
					x = x - 1;
					a[x][y] = ',';
				}
				else{
					d++;
				}
				continue;
			}
			if(d == 2){
				if(a[x][y-1] == '.' || a[x][y-1] == ','){
					if(a[x][y-1] == '.'){
						cnt++;	
					}
					y = y-1;
					a[x][y] = ',';
				}
				else{
					d++;
				}
				continue;
			}
			if(d == 3){
				if(a[x+1][y] == '.' || a[x+1][y] == ','){
					if(a[x+1][y] == '.'){
						cnt++;	
					}
					x = x+1;
					a[x][y] = ',';
				}
				else{
					d = 0;
				}
				continue;
			}
		}
		    cout<<cnt;
		    cnt = 0;
		    for(int j = 1;j <= n;j++){
			    for(int k = 1;k <= m;k++){
				    a[j][k] = '0';
		    	}
	    	}
        }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
