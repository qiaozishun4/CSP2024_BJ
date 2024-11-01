#include<bits/stdc++.h>
using namespace std;
int n;
int visit[60];
int ans;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	ans=52-n;
	for(int i=1;i<=n;i++){
		char A[5];
		int A2;
		int E;
		cin>>A;
		if(A[0]=='D'){
			A2=0;
		}
		if(A[0]=='C'){
			A2=1;
		}
		if(A[0]=='H'){
			A2=2;
		}
		if(A[0]=='S'){
			A2=3;
		}
		if(A[1]>='2'&&A[1]<='9'){
			E=A[1]-'0';
		}
		else{
			switch(A[1]){
				case 'A':E=1;break;
				case 'T':E=10;break;
				case 'J':E=11;break;
				case 'Q':E=12;break;
				case 'K':E=13;break;
			}
		}
		int xi=A2*13+E;
		if(visit[xi]==1){
				ans+=1;
			}
		visit[xi]=1;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
