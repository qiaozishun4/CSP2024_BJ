#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e5+5;
int n,r[N],c[N],cnt = 0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&r[i]);
		c[r[i]]++;
	}
	sort(r+1,r+1+n);
	for(int i=1;i<=r[n];i++){
		cnt = max(cnt-c[i],0) + c[i];
	}
	printf("%d\n",cnt);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
