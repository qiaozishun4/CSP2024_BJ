#include <bits/stdc++.h>
using namespace std;
int n,a[100005],res;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n ;
	res = n;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int j = 1;
	for(int i = 2;i<=n;i++)
	{
		if(a[i] > a[j]) res --,j++; 
	}
	cout << res << "\n";
}
//1 1 2 2 3