#include<iostream>
#include<algorithm>
using namespace std;
bool a[10010] = {0};
int r[10010],cc;
int n;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> r[i];
	}
	sort(r+1,r+n+1);
	for(int i = 1;i <= n;i++){
		for(int j = i;j > 0;j--){
			if(a[i] == 1){
				j--;
			}
			if(r[i] > r[j]){
				a[j] = 1;
			}
		}
	}
	for(int i = 1;i <= n;i++){
			if(a[i] == 0) cc ++;
	}
	cout  << (n - cc);
	return 0;
}
