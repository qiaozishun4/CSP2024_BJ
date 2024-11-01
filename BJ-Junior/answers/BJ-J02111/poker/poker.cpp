#include <iostream>
#include <cstdio>
using namespace std;
int d[60],c[60],h[60],s[60];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		char a,b;
		cin >> a >> b;
		if(a == 'D'){
			if(b <= '9' && b >= '2'){
				d[b - 48]++;
			}else if(b == 'A'){
				d[1]++;
			}else if(b == 'T'){
				d[10]++;
			}else if(b == 'J'){
				d[11]++;
			}else if(b == 'Q'){
				d[12]++;
			}else if(b == 'K'){
				d[13]++;
			}
		}else if(a == 'C'){
			if(b <= '9' && b >= '2'){
				c[b - 48]++;
			}else if(b == 'A'){
				c[1]++;
			}else if(b == 'T'){
				c[10]++;
			}else if(b == 'J'){
				c[11]++;
			}else if(b == 'Q'){
				c[12]++;
			}else if(b == 'K'){
				c[13]++;
			}
		}else if(a == 'H'){
			if(b <= '9' && b >= '2'){
				h[b - 48]++;
			}else if(b == 'A'){
				h[1]++;
			}else if(b == 'T'){
				h[10]++;
			}else if(b == 'J'){
				h[11]++;
			}else if(b == 'Q'){
				h[12]++;
			}else if(b == 'K'){
				h[13]++;
			}
		}else if(a == 'S'){
			if(b <= '9' && b >= '2'){
				s[b - 48]++;
			}else if(b == 'A'){
				s[1]++;
			}else if(b == 'T'){
				s[10]++;
			}else if(b == 'J'){
				s[11]++;
			}else if(b == 'Q'){
				s[12]++;
			}else if(b == 'K'){
				s[13]++;
			}
		}
	}
	int cnt = 0;
	for(int i = 1;i <= 13;i++){
		if(d[i] < 1){
			cnt++;
		}
		if(c[i] < 1){
			cnt++;
		}
		if(h[i] < 1){
			cnt++;
		}
		if(s[i] < 1){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
