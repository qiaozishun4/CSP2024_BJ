#include<bits/stdc++.h>
using namespace std;
int a[50][50];
int n;
string s;
int ans=0;
int x,y;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(s[1]>='2'&&s[1]<='9'){
			x=s[1]-'1'+1;
		}else if(s[1]=='A'){
			x=1;
		}else if(s[1]=='T'){
			x=10;
		}else if(s[1]=='J'){
			x=11;
		}else if(s[1]=='Q'){
			x=12;
		}else if(s[1]=='K'){
			x=13;
		}
		if(s[0]=='D'){
			y=1;
		}else if(s[0]=='C'){
			y=2;
		}else if(s[0]=='H'){
			y=3;
		}else if(s[0]=='S'){
			y=4;
		}
		a[y][x]++;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(a[i][j]==0){
				ans++;
			}
			//cout<<a[i][j]<<" ";
		}
		//cout<<endl;
	}
	cout<<ans;
	return 0;
}
//我
