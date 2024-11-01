#include<bits/stdc++.h>
using namespace std;
long long n,s=52,B=0;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	bool f[53];
	string a[100];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		f[i]=1;
		B++;
		
	}

	s-=B;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			
			if(a[i]==a[j]&&f[i]!=false){
					f[j]=false;
					s++;
				}
			
			
		}
	}
	cout<<s;
	return 0;
}
