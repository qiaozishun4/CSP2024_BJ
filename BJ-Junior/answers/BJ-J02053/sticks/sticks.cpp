#include<iostream>
using namespace std;
int stick[10]={6,2,5,5,4,5,6,3,7,6};
int T,ans;
int n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		for(long long i=0;i<=1000000000000000;i++){
			ans=0;
			while(i){
				ans+=stick[i%10];
				i/=10;
			}
		}
		if(ans==n)
			cout<<i;
		else
			cout<<-1;
	}
	return 0;
}