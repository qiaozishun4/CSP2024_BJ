#include<bits/stdc++.h>
using namespace std;
int k[10]={6,2,5,5,4,5,6,3,7,6};
int cnt=-1;
void f(int a){
	int ans=0;
	int min=10000000;
	int minn=0;
	int s;
	for(int i=1;i<=1e5;++i){
		s=i;
		ans=0;
		while(s>0){
			ans+=k[s%10];
			minn=i;
			s/=10;
		}
		if(minn<min&&ans==a){
			min=minn;
		}
	}
	if(min==10000000){
		cout<<-1<<endl;
	}else{
		cout<<min<<endl;
	}
	return;
}
int main(){
	freopen("sticks1.in","r",stdin);
	freopen("sticks1.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;++i){
		cin>>n;
		f(n);
		cnt=-1;
	}
	return 0;
}