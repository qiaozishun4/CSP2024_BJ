#include<iostream>
using namespace std;
const int N = 1e3+5;
int a[] = {6,2,5,5,4,5,6,3,7,6};
int num[100] = {0,-1,1,7,4,2,6,8,10,18,22,20,66,68,88,108,188,
	202,208,288,688,888,1088,1888,2008,2088,2888,688,8888,10888,
	18888,20088,20888,28888,68888,88888,108888,188888,200888,208888,
	288888,688888,888888,1088888,1888888,2008888,2088888,2888888,
	6888888,8888888,10888888};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n%7 == 0){
			for(int i=1;i<=n/7;i++) cout<<8;
			cout<<"\n";
		}else if(n%7 == 1){
			cout<<10;
			for(int i=1;i<=n/7-1;i++){
				cout<<8;
			}
			cout<<"\n";
		}else cout<<num[n]<<"\n";
	}
	return 0;
}
/*
 
*/
	
