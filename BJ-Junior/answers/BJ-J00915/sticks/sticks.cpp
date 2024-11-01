#include <bits/stdc++.h>
using namespace std;
const int m[15]={6,2,5,5,4,5,6,3,7,6},ord[15]={8,0,6,9,2,3,5,4,7,1};
int t,n,stop,minlen;
string ans,fin;
string minint(string x,string y){
	if(x.size()<y.size()) return x;
	else if(x.size()>y.size()) return y;
	else return min(x,y);
	return 0;
}
void dfs(int x){
	if(stop) return ;
	if(x==0){
		fin=ans,stop=1;
		return ;
	}
	if((int)ans.size()>minlen||x<=1) return ;
	for(int i=0;i<10;++i){
		if(ans.size()==0&&ord[i]==0) continue;
		ans.push_back('0'+ord[i]);
		dfs(x-m[ord[i]]);
		ans.pop_back();
	}
	return ;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t,++t;
	while(--t){
		cin>>n,fin=ans="",minlen=INT_MAX,stop=0;
		dfs(n);
		if(fin==""){
			if(n==6) cout<<"0\n";
			else cout<<"-1\n";
		}
		else{
			int zer=0;
			sort(fin.begin(),fin.end());
			for(;zer<(int)fin.size();++zer) if(fin[zer]!='0') break;
			cout<<fin[zer];
			for(int i=1;i<=zer;++i) cout<<"0";
			for(int i=zer+1;i<(int)fin.size();++i) cout<<fin[i];
			cout<<"\n";
		}
	}
    return 0;
}