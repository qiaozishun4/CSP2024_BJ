#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;
const int N = 1e5+5;
int T; // [1,20]
int n,m; // [1,1e5]
int L,V; // [1,1e6] [1,1e3]
int p[N],d[N],v[N],a[N];
//[1,L] [1,L] [1,1e3] |a|<=1e3
int first[N],last[N];
int cnt1 = 0,cnt2 = 0;
struct node{
	int val,cnt;
}c[N];
bool cmp(node a,node b){
	return a.cnt > b.cnt;
}
bool cmp2(node a,node b){
	return a.val < b.val;
}
bool vis[N];
bool fA = 1;
bool fB = 1;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i=1;i<=n;i++)first[i] = last[i] = 0,vis[i] = 1;
		for(int i=1;i<=m;i++)c[i].cnt = 0;
		cnt1 = cnt2 = 0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
			fA = (fA && a[i]==0);
			fB = (fB && a[i]>0);
		}
		for(int i=1;i<=m;i++)scanf("%d",&p[i]);
		sort(p+1,p+1+m);
		for(int i=1;i<=n;i++){
			int s1,s2;
			if(a[i] > 0){
				if(v[i] > V){
					s1 = d[i];
					first[i] = lower_bound(p+1,p+1+m,s1)-p;	
				}else if(v[i] == V){
					s1 = d[i];
					first[i] = upper_bound(p+1,p+1+m,s1)-p;	
				}else{
					if((V*V-v[i]*v[i])%(2*a[i]) == 0){
						s1 = d[i]+ceil(1.0*(V*V-v[i]*v[i])/2/a[i]);
						first[i] = upper_bound(p+1,p+1+m,s1)-p;
					}else{
						s1 = d[i]+ceil(1.0*(V*V-v[i]*v[i])/2/a[i]);
						first[i] = lower_bound(p+1,p+1+m,s1)-p;
					}
				}
				
				if(first[i] > m)last[i] = m+1;
				else last[i] = m;
			}else if(a[i] == 0){
				if(v[i] > V){
					s1 = d[i];
					first[i] = lower_bound(p+1,p+1+m,s1)-p;
					if(first[i] > m)last[i] = m+1;
					else last[i] = m;
				}else{
					first[i] = last[i] = m+1;
				}
			}else{
				if(v[i] >= V){
					s1 = d[i];
					first[i] = lower_bound(p+1,p+1+m,s1)-p;
					s2 = d[i]+ceil(1.0*(V*V-v[i]*v[i])/2/a[i]);
					last[i] = lower_bound(p+1,p+1+m,s2)-p-1;
					if(first[i] > last[i])first[i] = last[i] = m+1;
				}else{
					first[i] = last[i] = m+1;
				}
			}
			//cout<<s1<<" "<<s2<<" "<<first[i]<<" "<<last[i]<<endl;	
			if(first[i]<=m && last[i]<=m)cnt1++;
		}
		//
		c[0].val = 0;
		c[0].cnt = 0;
		for(int i=1;i<=n;i++){
			c[first[i]].cnt++;
			c[last[i]+1].cnt--;
		}
		for(int i=1;i<=m;i++){
			c[i].val = i;
			c[i].cnt += c[i-1].cnt;
		}
		printf("%d ",cnt1);
		if(fA || fB){
			if(cnt1 == 0)cnt2 = 0;
			else cnt2 = 1;
		}else{
			while(1){
				//for(int i=1;i<=n;i++)cout<<c[i].cnt<<" ";
				//cout<<endl;
				sort(c+1,c+1+m,cmp);
				int v = c[1].val;
				if(c[1].cnt == 0)break;
				cnt2++;
				//cout<<"---"<<v<<endl;
				sort(c+1,c+1+m,cmp2);
				for(int i=1;i<=n;i++){
					if(!vis[i])continue;
					if(first[i]<=v && last[i]>=v){
						vis[i] = 0;
						for(int j=first[i];j<=last[i];j++)c[j].cnt--;
					}
				}
			}	
		}
		printf("%d\n",m-cnt2);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
