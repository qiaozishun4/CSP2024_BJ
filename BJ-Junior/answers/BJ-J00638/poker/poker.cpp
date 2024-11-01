

#include <bits/stdc++.h>

using namespace std;

int a[10][20];

int main () {

    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int num;
    cin >> num;
    for (int i = 1; i <= num; i++) {
		char huase, dianshu;
		cin >> huase >> dianshu;
		//fang pian
		if (huase == 'D') {
			if (dianshu == 'A') a[1][1] = 1;
			if (dianshu == '2') a[1][2] = 1;
			if (dianshu == '3') a[1][3] = 1;
			if (dianshu == '4') a[1][4] = 1;
			if (dianshu == '5') a[1][5] = 1;
			if (dianshu == '6') a[1][6] = 1;
			if (dianshu == '7') a[1][7] = 1;
			if (dianshu == '8') a[1][8] = 1;
			if (dianshu == '9') a[1][9] = 1;
			if (dianshu == 'T') a[1][10] = 1;
			if (dianshu == 'J') a[1][11] = 1;
			if (dianshu == 'Q') a[1][12] = 1;
			if (dianshu == 'K') a[1][13] = 1;
		}
		//cao hua
		if (huase == 'C') {
			if (dianshu == 'A') a[2][1] = 1;
			if (dianshu == '2') a[2][2] = 1;
			if (dianshu == '3') a[2][3] = 1;
			if (dianshu == '4') a[2][4] = 1;
			if (dianshu == '5') a[2][5] = 1;
			if (dianshu == '6') a[2][6] = 1;
			if (dianshu == '7') a[2][7] = 1;
			if (dianshu == '8') a[2][8] = 1;
			if (dianshu == '9') a[2][9] = 1;
			if (dianshu == 'T') a[2][10] = 1;
			if (dianshu == 'J') a[2][11] = 1;
			if (dianshu == 'Q') a[2][12] = 1;
			if (dianshu == 'K') a[2][13] = 1;
		}
		//hong tao
		if (huase == 'H') {
			if (dianshu == 'A') a[3][1] = 1;
			if (dianshu == '2') a[3][2] = 1;
			if (dianshu == '3') a[3][3] = 1;
			if (dianshu == '4') a[3][4] = 1;
			if (dianshu == '5') a[3][5] = 1;
			if (dianshu == '6') a[3][6] = 1;
			if (dianshu == '7') a[3][7] = 1;
			if (dianshu == '8') a[3][8] = 1;
			if (dianshu == '9') a[3][9] = 1;
			if (dianshu == 'T') a[3][10] = 1;
			if (dianshu == 'J') a[3][11] = 1;
			if (dianshu == 'Q') a[3][12] = 1;
			if (dianshu == 'K') a[3][13] = 1;
		}
		//hei tao
		if (huase == 'S') {
			if (dianshu == 'A') a[4][1] = 1;
			if (dianshu == '2') a[4][2] = 1;
			if (dianshu == '3') a[4][3] = 1;
			if (dianshu == '4') a[4][4] = 1;
			if (dianshu == '5') a[4][5] = 1;
			if (dianshu == '6') a[4][6] = 1;
			if (dianshu == '7') a[4][7] = 1;
			if (dianshu == '8') a[4][8] = 1;
			if (dianshu == '9') a[4][9] = 1;
			if (dianshu == 'T') a[4][10] = 1;
			if (dianshu == 'J') a[4][11] = 1;
			if (dianshu == 'Q') a[4][12] = 1;
			if (dianshu == 'K') a[4][13] = 1;
		}
	}
	int res = 0;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 13;j++) {
			if (a[i][j] == 0) {
				res++;
			}
		//	cout << a[i][j] << " ";
		}
		//cout << endl;
	}
	cout << res << endl;
    
    return 0;
}

