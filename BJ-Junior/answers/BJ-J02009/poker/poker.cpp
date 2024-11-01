#include<bits/stdc++.h>
using namespace std;
int n,p,ans;
bool t[7][25];
char str[7];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str);
		if(str[0]=='D') p=1;
		if(str[0]=='C') p=2;
		if(str[0]=='H') p=3;
		if(str[0]=='S') p=4;
		if(str[1]>='2'&&str[1]<='9') t[p][str[1]-'0']=1;
		else if(str[1]=='A') t[p][1]=1;
		else if(str[1]=='T') t[p][10]=1;
		else if(str[1]=='J') t[p][11]=1;
		else if(str[1]=='Q') t[p][12]=1;
		else if(str[1]=='K') t[p][13]=1;
	}
	for(int i=1;i<=4;i++)
		for(int j=1;j<=13;j++) if(!t[i][j]) ans++;
	printf("%d",ans);
	return 0;
}