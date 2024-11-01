#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],p[100010],x[5],R,top=1;
bool f[1000010];
string s[30];
int k;
int main()
{
freopen("arena.in","r",stdin);
freopen("arena.out","w",stdout);
	srand(time(NULL));
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=m;i++) cin >> p[i];
	while((1<<k)<n) k++;
	for(int i=1;i<=k;i++) cin >> s[i];
	cin >> t;
	while(t--)
	{
		cin >> x[0] >> x[1] >> x[2] >> x[3];
		for(int i=1;i<=n;i++) a[i]=a[i]^x[i%4];
		cout<< rand()%100<< endl;
	}
	fcolse(stdin);
	fclose(stdout);
	return 0;
}