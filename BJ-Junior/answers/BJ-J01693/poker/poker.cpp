#include<iostream>
using namespace std;
char a[53][3];

bool q(int n)
{
	for(int i=1;i<n;i++)
	{
		if(a[1][i]==a[1][n]&&a[2][i]==a[2][n]) return false;
	}
	return true;
}

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin >> n ;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=2;j++)
		{
			cin >> a[i][j] ;
			if(q(i)) ans++;
		}
	}
	cout << 52-ans ;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
