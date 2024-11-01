#include <bits/stdc++.h>
using namespace std;

int main(){
	int x;
	cin >>x;
	int a[3];
	int b[3];
	int c,d;
	int e = 0;
	for(int i = 0;i < x;i ++){
		e = 0;
		for(int i1 = 0;i1 < 3;i1 ++){
			cin >>a[i1];
		}
		for(int i2 = 0;i2 < 3;i2 ++){
			cin >>b[i2];
		}
		string y[a[0] + 1][a[1] + 1];
		int y1[a[0] + 1][a[1] + 1];
		y1[b[0]][b[1]] = 1;
		for(int j = 1;j <= a[0];j ++){
			for(int j1 = 1;j1 <= a[1];j1 ++){
				cin >>y[j][j1];
			}
		}
		c = b[0];
		d = b[1];
		while(a[2] > 0){
			if(b[2] == 0 && y[c][d + 1] == "." && d + 1 < a[1]){
				d ++;
				y1[c][d] ++;
			}else if(b[2] == 1 && y[c + 1][d] == "." && c + 1 < a[0]){
				c ++;
				y1[c][d] ++;
			}else if(b[2] == 2 && y[c][d - 1] == "." && d - 1 >= 0){
				d --;
				y1[c][d] ++;
			}else if(b[2] == 3 && y[c - 1][d] == "." && c - 1 >= 0){
				c --;
				y1[c][d] ++;
			}else{
				b[2] = (b[2] + 1) % 4;
			}
			a[2] --;
		}
		for(int k = 1;k <= a[0];k ++){
			for(int k1 = 1;k1 <= a[1];k1 ++){
				if(y1[k][k1] > 0){
					e ++;
				}
			}
		}
		cout<<e<<endl;
	}
	return 0;
}
