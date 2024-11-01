#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	scanf("%d",&n);
	int guaishou[100001];
	char zhuangtai[100001];   //1---zhengchang;2---beichile;3---chilebierenle
	for(int i=0;i<n;i++)
	{
		zhuangtai[i]='1';
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&guaishou[i]);
	}
	sort(guaishou,guaishou+n);
	for(int i=1;i<n;i++)
	{  
		for(int j=i-1;j>=0;j--)
		{
			if(guaishou[j]<guaishou[i] && zhuangtai[j]!='2'&& zhuangtai[i]=='1')
			{
				zhuangtai[j]='2';
				zhuangtai[i]='3';
				
			}
		}
	}
	int ct=0;
	for(int i=0;i<n;i++)
	{
		//printf("%c ",zhuangtai[i]);
		if(zhuangtai[i]=='1' || zhuangtai[i]=='3')
		    ct++;
	}
	printf("%d",ct);
	return 0;
}
