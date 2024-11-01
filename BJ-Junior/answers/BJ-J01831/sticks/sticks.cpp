#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vl=vector<ll>;
const int inf=0x3f3f3f3f;
const int sk[]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
			continue;
		}
		int x=(n+6)/7;
		int y=x*7-n;
		if(x==1){
			for(int i=1;i<=9;i++){
				if(7-sk[i]==y){
					cout<<i;
					break;
				}
			}
			cout<<endl;
			continue;
		}
		int cnt=0;
		for(int i=1;i<=x-2;i++){
			for(int j=0;j<=9;j++){
				if(i==1&&j==0)continue;
				if(y-(7-sk[j])>=0){
					cout<<j;
					cnt++;
					y-=7-sk[j];
					break;
				}
			}
		}
		if(y==0){
			for(int i=cnt+1;i<=x;i++)cout<<8;
			cout<<endl;
			continue;
		}
		for(int i=(x==2?1:0),sf=false;i<=9;i++){
			for(int j=0;j<=9;j++){
				if(7-sk[i]+7-sk[j]==y){
					cout<<i<<j;
					sf=true;
					break;
				}
			}
			if(sf)break;
		}
		cout<<endl;
	}
	return 0;
}
