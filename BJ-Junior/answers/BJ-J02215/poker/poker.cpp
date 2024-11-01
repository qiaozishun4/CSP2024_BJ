#include<bits/stdc++.h>
using namespace std;
bool a[10][24];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;cin >> n;
	for(int i=1;i<=n;i++)
	{
		string s;cin >> s;
		int row,cow;
		switch(s[0])
		{
			case('D'):
				row=1;break;
			case('C'):
				row=2;break;
			case('H'):
				row=3;break;
			case('S'):
				row=4;break;
		}
		if(s[1]>='0' && s[1]<='9')
			cow=s[1]-'0';
		else
		{
			switch(s[1])
			{
				case('A'):
					cow=1;break;
				case('T'):
					cow=10;break;
				case('J'):
					cow=11;break;
				case('Q'):
					cow=12;break;			
				case('K'):
					cow=13;break;			
			}
		}
		a[row][cow]=1;
	}
	int sum=0;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=13;j++)
			sum += 1-a[i][j];
	cout << sum;
	return 0;
}
