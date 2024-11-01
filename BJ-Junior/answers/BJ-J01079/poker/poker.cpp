#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,s[5][14]={0},sum=0;
    cin>>n;
    string a;
    int x,y;
    for(int i=1;i<=n;i++){
		cin>>a;
		
		if(a[0]=='S')x=1;
		if(a[0]=='H')x=2;
		if(a[0]=='C')x=3;
		if(a[0]=='D')x=4;
		if(a[1]=='A')y=1;
		if(a[1]=='2')y=2;
		if(a[1]=='3')y=3;
		if(a[1]=='4')y=4;
		if(a[1]=='5')y=5;
		if(a[1]=='6')y=6;
		if(a[1]=='7')y=7;
		if(a[1]=='8')y=8;
		if(a[1]=='9')y=9;
		if(a[1]=='T')y=10;
		if(a[1]=='J')y=11;
		if(a[1]=='Q')y=12;
		if(a[1]=='K')y=13;
		s[x][y]=1;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(s[i][j]!=1)sum++;
		}
	}
	cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
