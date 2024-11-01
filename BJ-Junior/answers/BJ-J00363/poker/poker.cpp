#include<bits/stdc++.h>
using namespace std;
int x[4][14];
int main(){
	//freopen("poker.in","r",stdin);
	//freopen("poker.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		string a;
		cin>>a;
		if(a[0]=='S'){
			if(a[1]>='0'&&a[1]<='9'){
				x[4][a[1]-'0'+1]=1;
			}else{
				x[4][a[1]-'A'+1]=1;
			}
		}else if(a[0]=='H'){
			if(a[1]>='0'&&a[1]<='9'){
				x[3][a[1]-'0'+1]=1;
			}else{
				x[3][a[1]-'A'+1]=1;
			}
		}else if(a[0]=='C'){
			if(a[1]>='0'&&a[1]<='9'){
				x[2][a[1]-'0'+1]=1;
			}else{
				x[2][a[1]-'A'+1]=1;
			}
		}else{
			if(a[1]>='0'&&a[1]<='9'){
				x[1][a[1]-'0'+1]=1;
			}else{
				x[1][a[1]-'A'+1]=1;
			}
		}
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(x[i][j]==0){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}

