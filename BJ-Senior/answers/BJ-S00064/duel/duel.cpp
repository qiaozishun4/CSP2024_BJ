#include<bits/stdc++.h>
using namespace std;
int a[100001],n;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	queue<int> ds;
	ds.push(a[1]);
	int ans=0;
	for(int i=2;i<=n;i++){
		if(a[i]>ds.front()){
			ds.pop();
			ds.push(a[i]);
			ans++;
		}
		else{
			ds.push(a[i]);
		}
	}
	printf("%d",n-ans);
	fclose(stdin);
	fclose(stdout);
}
