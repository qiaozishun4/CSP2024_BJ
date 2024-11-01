#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int>vec;
void solve(){
	int a;cin>>a;
	if(a==1) cout<<-1<<'\n';
	else if(a==2) cout<<1<<'\n';
	else if(a==3) cout<<7<<'\n';
	else if(a==4) cout<<4<<'\n';
	else if(a==5) cout<<2<<'\n';
	else if(a==6) cout<<6<<'\n';
	else if(a==7) cout<<8<<'\n';
	else{
		vec.clear();
		while(a>14) a-=7,vec.pb(8);
		if(a==8) {vec.pb(1);vec.pb(0);}
		else if(a==9) {vec.pb(1);vec.pb(8);}
		else if(a==10) {vec.pb(2);vec.pb(5);}
		else if(a==11) {vec.pb(2);vec.pb(0);}
		else if(a==12) {vec.pb(2);vec.pb(7);}
		else if(a==13) {vec.pb(6);vec.pb(8);}
		else {vec.pb(8);vec.pb(8);}
		sort(vec.begin(),vec.end());
		int sum=0,it;
		for(int i=0;i<(int)vec.size();i++)
			if(vec[i]!=0){
				sum+=vec[i];
				it=i;
				break;
			}
		for(int i=0;i<(int)vec.size();i++)
			if(i!=it) sum=sum*10+vec[i];
		cout<<sum<<'\n';
	}
}
int main(){
	freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
	int n;cin>>n;
	while(n--) solve();
	return 0;
}
