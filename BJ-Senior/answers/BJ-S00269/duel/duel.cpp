#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);  
    long long n,ans=0;
    cin>>n;
    long long r[n+5][2]={0};
    for(int i=0;i<n;i++){
		cin>>r[i][0];
		if(r[i][0]>r[i-1][0]&&r[i][1]==0){
			r[i-1][0]=0;
			r[i][1]=1;
		}
	}
	for(int i=0;i<n;i++){
		if(r[i][0]>0){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
    return 0;
}