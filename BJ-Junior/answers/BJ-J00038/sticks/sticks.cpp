#include<bits/stdc++.h>
using namespace std;

int T,n,m,cnt,x,mn,ci,y,k,f;
int a[100]={-1,-1,1,7,4,2,6,8};
int b[100]={-1,-1,1,7,4,2,0,8};


int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> T;
	while(T--){
		mn=1e9;
		cin >> n;
		if(n<=7){
			cout << a[n] << endl;
			continue;
		}
		x=n%7;
		k=n/7;
		if(x!=0)k--;
		if(x!=0)x+=7;
		for(int i=2;i<=7;i++){
			if(x-i>7||x-i<2){
				continue;
			}
			if(a[i]<mn){
				mn=a[i];
				ci=i;
			}
		}
		if(x!=0)cout << a[ci] << b[x-ci];
		for(int i=1;i<=k;i++){
			cout << 8;
		}
		cout << endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
