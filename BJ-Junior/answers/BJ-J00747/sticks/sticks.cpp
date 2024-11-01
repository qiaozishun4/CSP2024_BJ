#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
char sticks_num_sort[10][2]={{'8','7'},{'0','6'},{'6','6'},{'9','6'},{'2','5'},{'3','5'},{'5','5'},{'4','4'},{'7','3'},{'1','2'}};
int num[N];
int cnt=1,n;
long long min_num=1e9;
string min_num1="99999999999999999999999999999999";

void dfs(int x,string sum_num,int sum_sticks)
{
	if(sum_sticks>=n)
	{
		if(x<min_num)
		{
			min_num1=sum_num;
		}
		else
		{
			min_num1=min(min_num1,sum_num);
		}
		return;
	}
	for(int i=0;i<10;i++)
	{
		if(n-sum_sticks>=sticks_num_sort[i][1]-'0')
		{
			sum_sticks+=sticks_num_sort[i][1]-'0';
			sum_num=sum_num+sticks_num_sort[i][0];
			dfs(x+1,sum_num,sum_sticks);
			break;
		}
	}
}
int main()
{
	freopen("sticks.in","r",stdin);
  freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		memset(num,0,sizeof(num));
		cin>>n;
		if(n%7==0)
		{
			n/=7;
			for(int i=1;i<=n;i++)
			{
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		dfs(1,"0",0);
		if(min_num1!="99999999999999999999999999999999")
		{
			if(min_num1=="0") cout<<"6"<<endl;
			else 
			{
				for(int i=0;i<=min_num1.size();i++)
				{
					if(min_num1[i]!='0')
					{
						break;
					}
					min_num1.erase(i,1);
					i--;
				}
				cout<<min_num1<<endl;
			}
		}
		else cout<<-1<<endl;
		min_num=1e9;
		min_num1="99999999999999999999999999999999";
	}
	return 0;
}

