/*I will only use 30 minutes to do this t3 and t4, then back to t2.*/

#include <bits/stdc++.h>

using namespace std;

int T;
int n;
int arr[209];
int C[209];
int res;
int colors[109];
int cc;
int twopow[30] = {1 , 2 , 4 , 8 , 16 , 32 , 64 , 128 , 256 , 512 , 1024 , 2048 , 4096 , 8192 , 16384 , 32768 , 65536 , 131072 , 262144 , 524288 , 1048576 , 2097152 , 4194304 , 8388608};

int Deal(int way){
	cc = 0;
	while(way > 0){
		cc ++;
		if(way & 1){
			colors[cc] = 1;
		}else{
			colors[cc] = 0;
		}
		way /= 2;
	}
	int ret = 0;
	for(int i = 2 ; i <= cc ; i ++){
		for(int j = i - 1; j >= 0; j --){
			if(colors[i] == colors[j] && arr[i] == arr[j]){
				ret += arr[i];
				break;
			}else if(colors[i] == colors[j] && arr[i] != arr[j]){
				break;
			}
		}
	}
	return ret;
}

int main(){
	freopen("color.in" , "r" , stdin);
	freopen("color.out" , "w" , stdout);
	
	cin >> T;
	while(T --){
		res = 0;
		cin >> n;
		for(int i = 1; i <= n; i ++){
			cin >> arr[i];
		}
		
		for(int i = 0; i < min(5000000, twopow[n]); i ++){
			res = max(res , Deal(i));
		}
		cout << res << endl;
	}
	return 0;
}