#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N];
struct node{
	int id,t;
};
queue<node>q;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(q.front().t<a[i] && !q.empty()){
			a[q.front().id]=1;
			q.pop();
		}
		q.push((node){i,a[i]});
	}
	printf("%d\n",q.size());
	fclose(stdin);
	fclose(stdout);
	return 0;
}