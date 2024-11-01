#include<bits/stdc++.h>
using namespace std;
int r[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	int rm=0;
	for(int i=1;i<=n;i++){
		int rr;
		cin>>rr;
		r[rr]++;
		if(rr>rm){
			rm=rr;
		}
	}
	for(int i=1;i<=rm;i++){
		if(r[i]<=n-r[i]){
			n=n-r[i];
		}
		else{
			cout<<r[i];
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}