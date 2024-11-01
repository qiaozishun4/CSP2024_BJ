#include<bits/stdc++.h>
using namespace std;
int h[130][130],n,an=52;
char a,b;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		h[(int)(a)][(int)(b)]=1;
	}
	for(int i=0;i<130;i++){
		for(int j=0;j<130;j++){
			an-=(h[i][j]);
		}
	}
	cout<<an;
	return 0;
}