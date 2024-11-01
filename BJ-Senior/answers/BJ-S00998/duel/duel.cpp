// #define debug
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+3 ;

int n,a[N+N],l,r,res;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	l=r=1;
	while(true){
		if(a[r]>a[l]){
			l++;
			r++;
		}else if(r<n){
			r++;
		}else{
			break;
		}
	}
	cout<<res+min(n,r)-l+1<<endl;
	return 0;
}
