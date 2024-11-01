#include<iostream>
using namespace std;

int main(){
	int n;
	string p[55];
	cin>>n;
	for(int i=1;i<=n;i++){cin>>p[i];}
	string p2[55];
	int len=0;
	for(int i=1;i<=n;i++){
		int f=0;
		for(int j=1;j<i;j++){
			if(i==j){
				f=1;
				break;
			}
		}
		if(f==0){
			p2[i]=i;
			len++;
		}
	}
	cout<<n-len;
	return 0;
}
