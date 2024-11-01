#include <bits/stdc++.h>
using namespace std;
int n,a[13][4],sum;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	char c[14]={"A23456789TJQk"},b[5]={"DCHS"};
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		for(int j=0;j<13;j++){
			if(s[1]==c[j]){
				for(int k=0;k<4;k++){
					if(s[0]==b[k])a[k][j]++;
				}
			}
		}
	}
	for(int i=0;i<13;i++){
		for(int j=0;j<4;j++){
			if(a[i][j]==0)sum++;
		}
	}
	cout<<sum;
}