#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 2e5+5;
int T,n,a[N];
int c[N],maxx = -1,ans = 0;
void dfs(int x){
	if(x > n){
		int lr = 0,lb = 0;
		ans = 0;
		for(int i=1;i<=n;i++){
			if(c[i] == 1){ // red
				if(lr == 0){
					lr = i;
					continue;
				}
				if(a[lr] == a[i]){
					ans += a[i];
					lr = i;
				}else{
					lr = i;
					continue;
				}
			}else if(c[i] == 2){ // blue
				if(lb == 0){
					lb = i;
					continue;
				}
				if(a[lb] == a[i]){
					ans += a[i];
					lb = i;
				}else{
					lb = i;
					continue;
				}
			}
		}
		maxx = max(maxx,ans);
		return;
	}
	for(int i=1;i<=2;i++){
		c[x] = i;
		dfs(x+1);
		c[x] = 0;
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		maxx = -1;
		dfs(1);
		printf("%d\n",maxx);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
