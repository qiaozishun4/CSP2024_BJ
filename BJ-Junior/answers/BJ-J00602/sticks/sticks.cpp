#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int a[10]={6,2,5,5,4,5,6,3,7,6};
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<100000;i++){
			int count=0,t=i;
			while(t>0){
				count+=a[t%10];
				t/=10;
			}
			if(count==n){
				cout<<i<<endl;;
				break;
			}
			if(i==99999) cout<<-1<<endl;
		}
	}
	return 0;
}
