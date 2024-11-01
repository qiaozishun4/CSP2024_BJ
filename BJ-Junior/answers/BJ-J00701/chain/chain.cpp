#include<bits/stdc++.h>
using namespace std;
int l[2005];
map<int,map<int,int> > mp;
int s[2005][2005];
struct st{
	int r,c;
	bool operator<(const st& other) const{
		return r<other.r;
	}
}qu[100005];
set<int> chars;
void fun(){
	map<int,map<int,int> >().swap(mp);
	int n,k,q;
	cin>>n>>k>>q;
	for(int i=1;i<=n;i++){
		cin>>l[i];
		for(int j=1;j<=l[i];j++){
			cin>>s[i][j];
			chars.insert(s[i][j]);
			for(int o=1;o<j;o++){
				if(o+k-1<j) continue;
				if(mp[s[i][o]].count(s[i][j])&&mp[s[i][o]][s[i][j]]!=i){
					mp[s[i][o]][s[i][j]]=0;
				}
				else{
					mp[s[i][o]][s[i][j]]=i;
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>qu[i].r>>qu[i].c;
	}
	sort(qu+1,qu+q+1);
	for(int i=1;i<=q;i++){
		cout<<mp[1].count(qu[i].c)<<endl;
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t;
	cin>>t;
	while(t--) fun();
	return 0;
}
