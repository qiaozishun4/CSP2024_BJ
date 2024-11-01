#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
int lenght[200005];
vector <int> dictionp[100005];

int n,k,q,c;

bool dfs(int perq,int numberq,int r){
	if(r==-1)return 0;
	for(int i=0;i<n;i++){
		if(i==perq)continue;
		int have1=-1;
		for(int j=0;j<lenght[i];j++){
			if(have1!=-1 && j-have1>=k)break;
			if(r==0 && have1!=-1 && dictionp[i].at(j)==c)return 1;
			else if(have1!=-1 && dfs(i,dictionp[i].at(j),r-1)==1)return 1;
			if(dictionp[i].at(j)==numberq)have1=j;
		}
	}
	return 0;
}

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		vector<int>swapp[100005];
		swap(swapp,dictionp);
		cin>>n>>k>>q;
		for(int i=0;i<n;i++){
			cin>>lenght[i];
			for(int j=0;j<lenght[i];j++){
				int chainpiece;
				cin>>chainpiece;
				dictionp[i].push_back(chainpiece);
			}
		}
		
		while(q--){
			int r;
			cin>>r>>c;
			cout<<dfs(-1,1,r-1)<<endl;
		}
	}
	return 0;
}
		
