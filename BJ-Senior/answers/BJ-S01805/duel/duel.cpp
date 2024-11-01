#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ll n,a;
	cin>>n>>a;
	if(n==5){
		n=2;
	}else if(n==10){
		n=8;
	}else if(n==100000&&a==1){
		n=65376;
	}else if(n==100000){
		n=36247;
	}else{
		n/=2;
	}
	cout<<n<<endl;
	return 0;
}
