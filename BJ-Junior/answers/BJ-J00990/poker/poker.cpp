#include<bits/stdc++.h>
using namespace std;
int N,c,cards[4][13],n,m;
char sa[5]="DCHS",sb[14]="A23456789TJQK",s[3];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		cin>>s;
		for(int j=0;j<4;j++) if(s[0]==sa[j]) n=j;
		for(int j=0;j<13;j++) if(s[1]==sb[j]) m=j;
		cards[n][m]=1;
	}
	for(int i=0;i<4;i++) for(int j=0;j<13;j++) c+=cards[i][j];
	cout<<52-c;
	return 0;
}
