#include <bits/stdc++.h>
using namespace std;
long long n,ans;
string str;
long long vis[10001][10001];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(long long i = 1;i <= n;i++){
		cin>>str;
		long long x,y;
		char c = str[0];
		if(c == 'D'){
			x = 1;
		}
		if(c == 'C'){
			x = 2;
		}
		if(c == 'H'){
			x = 3;
		}
		if(c == 'S'){
			x = 4;
		}
		if(str[1] >= '2' && str[1] <= '9'){
			y = str[1] - '0';
		}else{
			if(str[1] == 'A'){
				y = 1;
			}
			if(str[1] == 'T'){
				y = 10;
			}
			if(str[1] == 'J'){
				y = 11;
			}
			if(str[1] == 'Q'){
				y = 12;
			}
			if(str[1] == 'K'){
				y = 13;
			}
		}
		vis[x][y] = 1;
	}
	for(long long i = 1;i <= 4;i++){
		for(long long j = 1;j <= 13;j++){
			if(vis[i][j] == 0){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
