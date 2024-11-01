#include <bits/stdc++.h>
using namespace std;
int n,r[100005],a,b,c;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&r[i]);
	sort(r+1,r+1+n);
	a=n;
	for(int i=1;i<=n;i++){
		if(r[i]!=r[i-1]){
			b+=c;
			c=0;
		}
		c++;
		if(b){
			a--;
			b--;
		}
	}
	printf("%d",a);
	fclose(stdin);
	fclose(stdout);
	return 0;
}