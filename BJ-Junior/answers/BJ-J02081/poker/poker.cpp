/*
	1. 输入
	2.二维数组  flag  记录 每张牌出现的次数，如果是第一次出现则cnt++
	3.输出 52 - cnt
 */

#include<bits/stdc++.h>
using namespace std;
int n, cnt, flag[600][100];
char col, num; 
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n ; i++){
		int co, nu;
		cin >> col >> num;
		co = int(col);
		nu = int(num);
		flag[nu][co]++;
		if(flag[nu][co] == 1)
			cnt++;
	}
	cout << 52 - cnt;

	return 0;
}
