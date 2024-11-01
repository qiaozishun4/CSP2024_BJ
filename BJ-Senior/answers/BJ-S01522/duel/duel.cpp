#include<iostream>

using namespace std;

int	a[100010];

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,num,max = 0,min = 100010,ans = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> num;
		a[num]++;
		if(num > max)
			max = num;
		if(num < min)
			min = num;
	}
	for(int i = min; i <= max; i++)
		if(a[i] == 0)
			continue;
		else if(ans == 0)
		{
			ans += a[i];
			continue;
		}
		else if(a[i] >= ans)
			ans = a[i];
	cout << ans;
	return 0;
}	
