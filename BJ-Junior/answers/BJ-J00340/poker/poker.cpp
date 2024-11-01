#include<bits/stdc++.h>
using namespace std;
bool t[20][10];
int n;
string a;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		int j,k;
		if(a[0]=='C') j=1;
		else if(a[0]=='S')j=2;
		else if(a[0]=='H')j=3;
		else if(a[0]=='D')j=4;
		if(a[1]=='A') k=1;
		else if(a[1]=='T') k=10;
		else if(a[1]=='J') k=11;
		else if(a[1]=='Q') k=12;
		else if(a[1]=='K') k=13;
		else k=a[1]-48;
		t[k][j]=1;
	}
	int sum=0;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(!t[j][i]) sum++;
		}
	}
	cout<<sum;
	return 0;
}