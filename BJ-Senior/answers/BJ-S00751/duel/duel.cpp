#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n,dead,r[N];
int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
		scanf("%d",&r[i]);
	sort(r+1,r+n+1);
	for(int i=2;i<=n;i++)
		if(r[dead+1]<r[i])
			dead++;
	printf("%d",n-dead);
	fclose(stdin);
	fclose(stdout);
	return 0;
}