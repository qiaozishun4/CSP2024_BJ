#include<bits/stdc++.h>
using namespace std;
struct a{
	char a,b;
}p[52];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,j,count=52,top=0;
	char poker[2];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>poker;
		for(j=0;j<=top;j++){
			if(p[j].a==poker[0]&&p[j].b==poker[1]) break;
		}
		if(j==top+1){
			count--;
			p[top].a=poker[0];
			p[top].b=poker[1];
			top++;
		}
	}
	cout<<count;
	return 0;
}
