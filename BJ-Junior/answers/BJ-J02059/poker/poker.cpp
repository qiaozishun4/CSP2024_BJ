#include<bits/stdc++.h>
using namespace std;
int n;
char str[5];
map<char,int>mp;
bool book[10][20];
void pre()
{
	mp['D']=1;
	mp['C']=2;
	mp['H']=3;
	mp['S']=4;
	mp['A']=1;
	for(int i=2;i<=9;i++)
	{
		mp['0'+i]=i;
	}
	mp['T']=10;
	mp['J']=11;
	mp['Q']=12;
	mp['K']=13;
	return;
}
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	pre();
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>str;
		book[mp[str[0]]][mp[str[1]]]=true;
	}
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=13;j++)
		{
			if(book[i][j]==false)
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
