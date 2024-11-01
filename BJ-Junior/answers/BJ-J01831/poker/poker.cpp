#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vl=vector<ll>;
const int inf=0x3f3f3f3f;
const string c="DCHS";
const string d="A23456789TJQK";
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int n;
	cin>>n;
	vector<vi>bt(4,vi(13));
	char a,b;
	int x=0,y=0;
	int ans=52;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=0;j<4;j++){
			if(a==c[j]){
				x=j;
				break;
			}
		}
		for(int j=0;j<13;j++){
			if(b==d[j]){
				y=j;
				break;
			}
		}
		if(bt[x][y])continue;
		ans--;
		bt[x][y]=1;
	}
	cout<<ans<<endl;
	return 0;
}
