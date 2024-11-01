#include<bits/stdc++.h>
using namespace std;
int n,a,b,f[5][15],ans=52;
char c,d;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c>>d;
		if(c=='D'){
			a=1;
		}else if(c=='C'){
			a=2;
		}else if(c=='H'){
			a=3;
		}else a=4;
		if(d=='A'){
			b=1;
		}else if(d=='T')b=10;
		else if(d=='J')b=11;
		else if(d=='Q')b=12;
		else if(d=='K')b=13;
		else b=d-'0';
		f[a][b]=1;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			ans-=f[i][j];
		}
	}
	cout<<ans;
	return 0;
}
