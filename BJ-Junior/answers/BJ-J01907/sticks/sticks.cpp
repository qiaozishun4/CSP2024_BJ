#include <iostream>
#include <cstring>
using namespace std;

const int N=1e5+10;

int a[114514]={6,2,5,5,4,5,6,3,7,6};
int mem[N];
long long mn=2e9+114514;
bool flag;

void dfs(int n,long long num)
{
	if (n<0||n==1) return ;
      	//if (mem[n]!=-1) return mem[n];
	if (n==0)
	{
		if (mn>num) mn=num;
		flag=true;
		return;
	}

	for (int i=0;i<=9;i++)
		dfs(n-a[i],num*10+i);
	
	return;
}

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);

	memset(mem,-1,sizeof mem);
	int T;
	cin>>T;

	while (T--)
	{
		mn=2e9;
		int n;
		cin>>n;

		for (int i=1;i<=9;i++)
			dfs(n-a[i],i);
		
		if (flag) cout<<mn<<'\n';
		else cout<<-1<<'\n';

	}

	return 0;
}
//what can I say