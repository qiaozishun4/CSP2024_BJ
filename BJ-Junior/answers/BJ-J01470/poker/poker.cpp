#include <bits/stdc++.h>
using namespace std;
bool b[5][15];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{	
		string a;
		cin>>a;
		int x,y;
		if(a[0]=='D'){
			x=1;
		}
		else if(a[0]=='C'){
			x=2;
		}
		else if(a[0]=='H'){
			x=3;
		}
		else{
			x=4;
		}
		if(a[1]>='2'&&a[1]<='9'){
			y=a[1]-'0';
		}
		else if(a[1]=='A'){
			y=1;
		}
		else if(a[1]=='T'){
			y=10;
		}
		else if(a[1]=='J'){
			y=11;
		}
		else if(a[1]=='Q'){
			y=12;
		}
		else{
			y=13;
		}
		b[x][y]=true;
	}
	int cnt=0;
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(b[i][j]==false)
			{
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}