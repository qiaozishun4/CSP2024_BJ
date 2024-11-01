#include<bits/stdc++.h>
using namespace std;
const int table[]={6,2,5,5,4,5,6,3,7,6};
int sum=INT_MAX;
int box[100005];
bool dfs(int n,int stp,int lst){
	//cout<<n<<' '<<stp<<' '<<lst<<'\n';
	if(n==0){
		int ans=0;
		//cout<<"@@@@@@@@@@@@@@@@@@@@@ ";
		for(int i=0;i<=stp-1;i++){
			ans=box[i]+ans*10;
			//cout<<box[i]<<' ';
		}
		//cout<<"\n";
		if(ans!=0)sum=min(sum,ans);
		return 1;
	}
	if(n<0) return 0;
	bool flag=0;
	for(int i=0;i<=9;i++){
		box[stp]=i;
		bool f=dfs(n-table[i],stp+1,i);
		flag=flag||f;
	}
	if(flag) return 1;
	else {
		return 0;
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		if(n%7==0){
			int t=n/7;
			for(int i=1;i<=t;i++){
				cout<<1;
			}
			for(int i=1;i<=t;i++){
				cout<<2;
			}
			cout<<'\n';
		}
		else if (n%7==1){
			int t=n/7;
			for(int i=1;i<=t;i++){
				cout<<1;
			}
			cout<<0;
			for(int i=1;i<=t-1;i++){
				cout<<2;
			}
			cout<<'\n';
		}
		else {
			sum=INT_MAX;
			bool f=dfs(n,0,0);
			//cout<<"#############################\n";
			if(f)cout<</*n<<' '<<*/sum<<'\n';
			else cout<<"-1\n";
		}
	}
	return 0;
}
