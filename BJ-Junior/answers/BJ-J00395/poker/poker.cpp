#include<bits/stdc++.h>
using namespace std;

bool a[5][14]={};
int n,ans=0;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		char x,y;
		int f,s;
		cin>>x>>y;
		if(x=='D') f=1;
		else if(x=='C') f=2;
		else if(x=='H') f=3;
		else f=4;
		if(y>='2'&&y<='9') s=y-'0';
		else{
			if(y=='A') s=1;
			else if(y=='T') s=10;
			else if(y=='J') s=11;
			else if(y=='Q') s=12;
			else s=13;
		}
		a[f][s]=true;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(a[i][j]==false){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
