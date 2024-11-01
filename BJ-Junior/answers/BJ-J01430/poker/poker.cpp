#include<iostream>
#define MAXN 55
using namespace std;

int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	scanf("%d", &n);
	char p[MAXN][2];
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		bool same = 0;
		cin >> p[i][0] >> p[i][1];
		for(int j = 1; j <= i; j++)
		{
			if(i != j && p[i][0] == p[j][0] && p[i][1] == p[j][1]) 
			{
				same = 1;
				break;
			}
		}
		if(!same) cnt++;
	}
	int ans = 52 - cnt;
	printf("%d\n", ans);
	return 0;
}
