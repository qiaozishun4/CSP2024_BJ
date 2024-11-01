#include<iostream>
using namespace std;
const int N = 100;
int a[5][N];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	char c,c1;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>c1>>c;
		if(c == 'A') x = 1;
		else if(c>='2'&& c <= '9') x = c-'0';
		else if(c == 'T') x = 10;//DCHS
		else if(c == 'J') x = 11;
		else if(c == 'Q')  x = 12;
		else x = 13;
		if(c1 == 'D'){
			a[1][x] = 1;
		}else if(c1 == 'C'){
			a[2][x] = 1;
		}else if(c1 == 'H'){
			a[3][x] = 1;
		}else a[4][x] = 1;
	}
	int cnt=0;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(!a[i][j]){
				cnt ++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
/*
4
DQ
H3
DQ
DT
*/
	
