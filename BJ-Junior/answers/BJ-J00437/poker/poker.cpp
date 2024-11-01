#include<bits/stdc++.h>
using namespace std;
int h[60][60];
int n;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=15;i++){
		for(int j=1;j<=15;j++){
			h[i][j]=0;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		int sum=0;
		if(s[0]=='D'){
			if(s[1]=='T'){
				sum=10;
			}else if(s[1]=='J'){
				sum=11;
			}else if(s[1]=='Q'){
				sum=12;
			}else if(s[1]=='K'){
				sum=13;
			}else if(s[1]=='A'){
				sum=1;
			}
			if(h[1][sum]==0){
				ans++;
				h[1][sum]=1;
			}
		}
		if(s[0]=='C'){
			if(s[1]=='T'){
				sum=10;
			}else if(s[1]=='J'){
				sum=11;
			}else if(s[1]=='Q'){
				sum=12;
			}else if(s[1]=='K'){
				sum=13;
			}else if(s[1]=='A'){
				sum=1;
			}
			if(h[2][sum]==0){
				ans++;
				h[2][sum]=1;
			}
		}
		if(s[0]=='H'){
			if(s[1]=='T'){
				sum=10;
			}else if(s[1]=='J'){
				sum=11;
			}else if(s[1]=='Q'){
				sum=12;
			}else if(s[1]=='K'){
				sum=13;
			}else if(s[1]=='A'){
				sum=1;
			}
			if(h[3][sum]==0){
				ans++;
				h[3][sum]=1;
			}
		}
		if(s[0]=='S'){
			if(s[1]=='T'){
				sum=10;
			}else if(s[1]=='J'){
				sum=11;
			}else if(s[1]=='Q'){
				sum=12;
			}else if(s[1]=='K'){
				sum=13;
			}else if(s[1]=='A'){
				sum=1;
			}
			if(h[4][sum]==0){
				ans++;
				h[4][sum]=1;
			}
		}
	}
	cout<<52-ans;
	return 0;
}
