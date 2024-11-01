#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXLen = 1e5 + 5;
int T;
int n;
int itab[55];
int imp[8] = {0, 108, 188, 200, 208, 288, 688, 888};
int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	scanf("%d", &T);
	itab[1] = -1;
	itab[2] = 1;
	itab[3] = 7;
	itab[4] = 4;
	itab[5] = 2;
	itab[6] = 6;
	itab[7] = 8;
	
	itab[8] = 10;
	itab[9] = 18;
	itab[10] = 22;
	itab[11] = 20;
	itab[12] = 28;
	itab[13] = 68;
	itab[14] = 88;
	
	itab[15] = 108;
	itab[16] = 188;
	itab[17] = 200;
	itab[18] = 208;
	itab[19] = 288;
	itab[20] = 688;
	itab[21] = 888;
	for(int asdf = 1; asdf <= T; asdf++){
		scanf("%d", &n);
		if(n <= 20){                    //tiny sample
			printf("%d\n", itab[n]);
			continue;
		} else if(n % 7 == 0){          //A sample
			int k = n / 7;
			for(int i = 1; i <= k; i++){
				printf("8");
			}
			printf("\n");
		} else if(n % 7 == 1 && n != 1){//B sample
			int k = (n-1)/7-1;
			printf("10");
			for(int i = 1; i <= k; i++){
				printf("8");
			}
			printf("\n");
		} else {                        //normal sample
			int tmp1 = n % 7;
			if(tmp1 == 0) tmp1 = 7;
			int tmp2 = (n-1) / 7 + 1;
			printf("%d", imp[tmp1]);
			int iend = tmp2 - 3;
			for(int i = 1; i <= iend; i++){
				printf("8");
			}
			printf("\n");
		}
	}
	return 0;
}
