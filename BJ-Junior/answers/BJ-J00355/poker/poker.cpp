#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	int n;
	char g[19]={0,'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
	char g2[6]={'D','C','H','S'};
	int l[20][8]={};
	cin>>n;
	int num,num2;
	for(int i=0;i<n;i++){
		
		char x,y;
		cin>>y>>x;
		for(int j=1;j<=13;j++){
			if(x==g[j]){
				num=j;
			}
		}
		for(int j=0;j<4;j++){
			if(y==g2[j]){
				num2=j;
			}
			
		}

		l[num][num2]=1;
	}
	int ans;
	for(int i=1;i<=13;i++){
		for(int j=0;j<4;j++){
			if(l[i][j]==0){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
