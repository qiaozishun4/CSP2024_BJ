#include<bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int z[100005];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		if(n%7 == 0){
			int m=n/7;
			for(int i=1;i<=m;i++){
				cout<<8;
			}
		}
		else if((n-1)%7 == 0 && n>=8){
			cout<<10;
			n-=8;
			int m=n/7;
			for(int i=1;i<=m;i++){
				cout<<8;
			}
		}
		else if(z[n] != 0){
			cout<<z[n];
		}
		else{
			int i=1;
			bool f=1;
			while(true){
				int sum=0,j=i,w=0;
				while(j>0){
					w++;
					sum+=a[j%10];
					j/=10;
				}
				if(sum == n){
					cout<<i;
					z[n]=i;
					f=0;
					break;
				}
				if(w>n/2){
					break;
				}
				i++;
			}
			if(f){
				cout<<-1;
			}
		}
		cout<<"\n";
	}
	return 0;
}
