#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n,flag;
	cin>>t;
	while(t--){
		cin>>n;
		flag=0;
		if(n%7==0){
			for(int i=1;i<=n/7;i++){
				cout<<8;
			}
			cout<<'\n';
			continue;
		}else if((n-1)%7==0&&n!=1){
			cout<<10;
			n-=1;
			n-=7;
			for(int i=1;i<=n/7;i++){
				cout<<8;
			}
			cout<<'\n';
			continue;
		}else if(n<8){
			for(int i=1;i<=9;i++){
				if(a[i]==n){
					cout<<i<<'\n';
					flag=1;
					break;
				}
			}
			if(flag==0){
				cout<<-1<<'\n';
			}
		}else{
			for(int i=1;i<=8888888;i++){
				int num=i,sum=0;
				while(num){
					sum+=a[num%10];
					num/=10;
				}
				if(sum==n){
					cout<<i<<'\n';
					flag=1;
					break;
				}
			}
			if(flag==0) cout<<-1<<'\n';
		}
	}
	return 0;
}
