#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;

int n,a[N];
bool tag[N];
priority_queue<pair<int,int>>q;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(!q.empty()){
			//寻找最小的数字,mambaout
			pair<int,int>t=q.top();
			if(-t.first<a[i])q.pop();//mambaout
		}
		q.push({-a[i],i});
	}
	cout<<q.size()<<endl;
	return 0;
}
