#include<bits/stdc++.h>
using namespace std;
int t[20][20];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		string s;
		cin>>s;
		int a,b;
		if(s[0]=='D'){
			a=1;
		}
		if(s[0]=='C'){
			a=2;
		}
		if(s[0]=='H'){
			a=3;
		}
		if(s[0]=='S'){
			a=4;
		}
		if(s[1]=='A'){
			b=1;
		}
		if(s[1]=='T'){
			b=10;
		}
		if(s[1]=='J'){
			b=11;
		}
		if(s[1]=='Q'){
			b=12;
		}
		if(s[1]=='K'){
			b=13;
		}
		if(s[1]>='2'&&s[1]<='9'){
			b=s[1]-'0';
		}
		t[a][b]=1;
	}
	int sum=0;
	for(int i=1; i<=4; i++){
		for(int j=1; j<=13; j++){
			if(t[i][j]==0){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}