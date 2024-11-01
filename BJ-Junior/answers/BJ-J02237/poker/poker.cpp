#include<bits/stdc++.h>
using namespace std;

const string c1="DCHS",c2="A23456789TJQK";
const int l1=4,l2=13;

int n;
string s;
int cnt[105],ans=52;

void add(){
	int rt=0;
	for(int i=0;i<l1;++i){
		if(s[0]==c1[i]){
			break;
		}
		rt+=13;
	}
	for(int i=0;i<l2;++i){
		if(s[1]==c2[i]){
			break;
		}
		++rt;
	}
	if(cnt[rt]==0){
		cnt[rt]=1;
		--ans;
	}
	return;
}

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>s;
		add();
	}
	cout<<ans;
	return 0;
}
//DCHS
//A23456789TJQK
