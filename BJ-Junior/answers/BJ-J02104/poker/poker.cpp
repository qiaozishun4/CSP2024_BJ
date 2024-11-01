#include <bits/stdc++.h>
using namespace std;

int n, ans;
char poker[64];

int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);

	scanf("%d",&n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%s",&poker[i]);
	}

	ans=unique(poker,poker+n)-poker;
	printf("%d\n",52-ans);
	return 0;
}
