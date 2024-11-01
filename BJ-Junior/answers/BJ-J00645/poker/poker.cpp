#include<bits/stdc++.h>
using namespace std;
int h[5][15];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,x,ans=0;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c;
		if(c=='D'){
			x=1;
		}else if(c=='C'){
			x=2;
		}else if(c=='H'){
			x=3;
		}else if(c=='S'){
			x=4;
		}
		cin>>c;
		if(c>='0'&&c<='9'){
			h[x][(int)(c-'0')]++;
		}else if(c=='A'){
			h[x][1]++;
		}else if(c=='T'){
			h[x][10]++;
		}else if(c=='J'){
			h[x][11]++;
		}else if(c=='Q'){
			h[x][12]++;
		}else if(c=='K'){
			h[x][13]++;
		}
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(h[i][j]==0){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}