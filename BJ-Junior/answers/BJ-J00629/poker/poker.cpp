#include<bits/stdc++.h>
using namespace std;
bool a[10][20];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	char s0,s1;
	for(int i=1;i<=n;i++){
		cin>>s0>>s1;
		if(s0=='D'){
			if(s1>'1'&&s1<='9'){
				a[1][s1-'0']=1;
			}
			else if(s1=='A'){
				a[1][1]=1;
			}
			else if(s1=='T'){
				a[1][10]=1;
			}
			else if(s1=='J'){
				a[1][11]=1;
			}
			else if(s1=='Q'){
				a[1][12]=1;
			}
			else if(s1=='K'){
				a[1][13]=1;
			}
		}
		else if(s0=='C'){
			if(s1>'1'&&s1<='9'){
				a[2][s1-'0']=1;
			}
			else if(s1=='A'){
				a[2][1]=1;
			}
			else if(s1=='T'){
				a[2][10]=1;
			}
			else if(s1=='J'){
				a[2][11]=1;
			}
			else if(s1=='Q'){
				a[2][12]=1;
			}
			else if(s1=='K'){
				a[2][13]=1;
			}
		}
		else if(s0=='H'){
			if(s1>'1'&&s1<='9'){
				a[3][s1-'0']=1;
			}
			else if(s1=='A'){
				a[3][1]=1;
			}
			else if(s1=='T'){
				a[3][10]=1;
			}
			else if(s1=='J'){
				a[3][11]=1;
			}
			else if(s1=='Q'){
				a[3][12]=1;
			}
			else if(s1=='K'){
				a[3][13]=1;
			}
		}
		else if(s0=='S'){
			if(s1>'1'&&s1<='9'){
				a[4][s1-'0']=1;
			}
			else if(s1=='A'){
				a[4][1]=1;
			}
			else if(s1=='T'){
				a[4][10]=1;
			}
			else if(s1=='J'){
				a[4][11]=1;
			}
			else if(s1=='Q'){
				a[4][12]=1;
			}
			else if(s1=='K'){
				a[4][13]=1;
			}
		}
	}
	int sum=0;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(a[i][j]) sum++;
		}
	}
	cout<<52-sum;
	return 0;
}
