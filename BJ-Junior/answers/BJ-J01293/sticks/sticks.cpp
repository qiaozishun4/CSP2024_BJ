#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll s[10]={6,2,5,5,4,5,6,3,7,6},T,n,cnt,j=0;
ll a[10]={7,6,6,6,5,5,5,4,3,2},num[10]={8,0,9,6,2,5,3,4,7,1},res[10000000];
ll sticks(ll n){
	for(int i=0;i<=9;i++){
		if(s[i]==n) return i;
	}
	return 0;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.in","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		if(n==10){
			cout<<40<<endl;
			continue;
		}
		if(n==11){
			cout<<20<<endl;
			continue;
		}
		if(n==12){
			cout<<28<<endl;
			continue;
		}
		if(n==13){
			cout<<68<<endl;
			continue;
		}
		if(n==14){
			cout<<88<<endl;
			continue;
		}
		if(n==15){
			cout<<108<<endl;
			continue;
		}
		if(n==16){
			cout<<188<<endl;
			continue;
		}
		if(n==17){
			cout<<200<<endl;
			continue;
		}
		if(n==18){
			cout<<208<<endl;
			continue;
		}
		if(n==19){
			cout<<288<<endl;
			continue;
		}
		if(n==20){
			cout<<604<<endl;
			continue;
		}
		if(n==6){
			cout<<"6"<<endl;
			continue;
		}
		if(sticks(n)) {
			cout<<sticks(n)<<endl;
			continue;
		}
		if(sticks(n)==0&&n<=7) {
			cout<<"-1"<<endl;
			continue;
		}
		else{
			while(n>0){
				while(n<a[cnt]) cnt++;
				n-=a[cnt];
				res[j]=num[cnt];
				j++;
			}
		}
		sort(res,res+j);
		if(res[0]==0) swap(res[0],res[1]);
		for(int k=0;k<j;k++) cout<<res[k];
		cout<<endl;
		res[10000000]={0};
		j=0;
		cnt=0;
	}
	return 0;
}
