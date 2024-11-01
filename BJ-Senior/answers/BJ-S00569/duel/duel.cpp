#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge{
	int ener;
	bool att,con;
};
const int N=1e5+5;
int n;
int sum;
edge a[N];
int find(edge x){
	for(int i=1;i<=n;i++){
		if(!a[i].con){
			if(a[i].ener<x.ener){
				return i;
			}
		}
	}
	return -1;
}
bool cmp(edge x,edge y){
	return x.ener<y.ener;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].ener);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(!a[i].con){
			int k=find(a[i]);
			if(k!=-1){
				a[k].con=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!a[i].con) sum++;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}