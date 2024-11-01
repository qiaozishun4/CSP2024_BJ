#include<iostream>
using namespace std;
void fre(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
}
int main(){
    fre();
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		long long ans=0;
		for(int i=1;i<=n;i++){
			int a;
			cin>>a;
			ans+=a;
		}
		cout<<(ans>>1)<<endl;
	}
}
