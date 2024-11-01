#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int val,vis=0;
} a[N];
deque<node> q;
bool cmp(node x,node y){
	return x.val<y.val;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].val;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		q.push_back({a[i].val,0});
	}
	int cnt=0,f=0;
	while(!q.empty()){
		if(q.size()==1) break;
		node x=q.front();
		q.pop_front();
		node y=q.front();
		q.pop_front();
		if(x.val>y.val&&x.vis==1){
			if(q.size()==2){
				cout<<q.size();
				f=1;
				break;
			}else{
				cnt++;
				node a=q.front();
				if(a.val==y.val){
					break;
				}
			}
		}else if(x.val>y.val&&x.vis==0){
			q.push_back(x);
		}else if(x.val==y.val){
			q.push_back(y);
			q.push_front(x);
		}else{
			y.vis=1;
			q.push_front(y);
		}
	}
	if(f==0) cout<<cnt+q.size();
	return 0;
}
