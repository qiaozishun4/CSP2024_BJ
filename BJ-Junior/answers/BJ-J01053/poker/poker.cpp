
#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	char x,y;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		
		a[x+0][y+0]=1;
	}
	int m=0;
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			if(a[i][j]==1){
				m++;
			}
		}
	}
	cout<<52-m;
	return 0;
}
