#include<bits/stdc++.h>
using namespace std;
int h[100000+10];
map<int,int> mp;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,x;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		mp[x]++;
		h[x]++;
	}
	while(1){
		int last=-1,flag=0;
		x=0;
		for(auto it=mp.begin();it!=mp.end();it++){
			if(last!=-1&&h[it->first]>0&&mp[last]>0){
				x=it->first;
				flag=1;
				break;
			}
			if(last==-1&&it->second!=0) last=it->first;
			
		}
		if(x!=0){
			mp[last]--;
			h[x]--;
		}
		if(flag==0) break;
	}
	int ans=0;
	for(auto it=mp.begin();it!=mp.end();it++){
		ans+=it->second;
	}
	cout<<ans;
	return 0;
}
