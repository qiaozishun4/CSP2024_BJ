#include<bits/stdc++.h>
using namespace std;
struct node{
	char a;
	char b;
};
int n,ans;
node a[100];
bool cnt[5][15] = {0};
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++){
		cin >> a[i].a >> a[i].b;
		if(a[i].a == 'D'){
			switch(a[i].b){
				case 'A':cnt[1][1] = 1;break;
				case '2':cnt[1][2] = 1;break;
				case '3':cnt[1][3] = 1;break;
				case '4':cnt[1][4] = 1;break;
				case '5':cnt[1][5] = 1;break;
				case '6':cnt[1][6] = 1;break;
				case '7':cnt[1][7] = 1;break;
				case '8':cnt[1][8] = 1;break;
				case '9':cnt[1][9] = 1;break;
				case 'T':cnt[1][10] = 1;break;
				case 'J':cnt[1][11] = 1;break;
				case 'Q':cnt[1][12] = 1;break;
				case 'K':cnt[1][13] = 1;break;
			}
		}else if(a[i].a == 'C'){
			switch(a[i].b){
				case 'A':cnt[2][1] = 1;break;
				case '2':cnt[2][2] = 1;break;
				case '3':cnt[2][3] = 1;break;
				case '4':cnt[2][4] = 1;break;
				case '5':cnt[2][5] = 1;break;
				case '6':cnt[2][6] = 1;break;
				case '7':cnt[2][7] = 1;break;
				case '8':cnt[2][8] = 1;break;
				case '9':cnt[2][9] = 1;break;
				case 'T':cnt[2][10] = 1;break;
				case 'J':cnt[2][11] = 1;break;
				case 'Q':cnt[2][12] = 1;break;
				case 'K':cnt[2][13] = 1;break;
			}
		}else if(a[i].a == 'H'){
			switch(a[i].b){
				case 'A':cnt[3][1] = 1;break;
				case '2':cnt[3][2] = 1;break;
				case '3':cnt[3][3] = 1;break;
				case '4':cnt[3][4] = 1;break;
				case '5':cnt[3][5] = 1;break;
				case '6':cnt[3][6] = 1;break;
				case '7':cnt[3][7] = 1;break;
				case '8':cnt[3][8] = 1;break;
				case '9':cnt[3][9] = 1;break;
				case 'T':cnt[3][10] = 1;break;
				case 'J':cnt[3][11] = 1;break;
				case 'Q':cnt[3][12] = 1;break;
				case 'K':cnt[3][13] = 1;break;
			}
		}else if(a[i].a == 'S'){
		switch(a[i].b){
				case 'A':cnt[4][1] = 1;break;
				case '2':cnt[4][2] = 1;break;
				case '3':cnt[4][3] = 1;break;
				case '4':cnt[4][4] = 1;break;
				case '5':cnt[4][5] = 1;break;
				case '6':cnt[4][6] = 1;break;
				case '7':cnt[4][7] = 1;break;
				case '8':cnt[4][8] = 1;break;
				case '9':cnt[4][9] = 1;break;
				case 'T':cnt[4][10] = 1;break;
				case 'J':cnt[4][11] = 1;break;
				case 'Q':cnt[4][12] = 1;break;
				case 'K':cnt[4][13] = 1;break;
			}	
		}
	}
	for(int i = 1;i <= 4;i ++){
		for(int j = 1;j <= 13;j ++){
			if(cnt[i][j] == 0){
				ans ++;
			}
		}
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
