#include<bits/stdc++.h>
using namespace std;
int n,t;
int sk[10005]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
		cin>>n;
		if(n==1){
			cout<<"-1";
		}else{
			int w=(n+6)/7;
			for(int j=w;j>=1;j--){
				for(int k=0;k<=9;k++){
					if(k==0 and j==w){
						continue;
					}
					if((n-sk[k]+6)/7==j-1){
						cout<<k;
						n-=sk[k];
						break;
					}
				}
			}
		}
		cout<<"\n";
	}
    return 0;
}