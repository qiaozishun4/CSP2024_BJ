#include<bits/stdc++.h>
using namespace std;
int n,a[100005],ans;
queue<int>q;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;ans=n;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	q.push(a[1]);
	for(int i=2;i<=n;++i){
		if(a[i]>q.front()){
			ans--;
			q.pop();
			q.push(a[i]);
		}else{
			q.push(a[i]);
		}
	}cout<<ans<<endl;
    return 0;
}