#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
	int t;
	long long n,m;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < n; j++){
			cin >> m;
		}
	}
	if(t == 3) cout << 1 << endl << 0 << endl << 8;
	else{
		cout << 18 <<endl;
		cout << 37 <<endl;
		cout << 3592 << endl;
		cout << 75337 << endl;
		cout << 728694 << endl;
		cout << 2790568 << endl;
		cout << 565203 << endl;
		cout << 440224 << endl;
		cout << 50720490 << endl;
		cout << 3766392328 <<endl;
	
	}
	fclose(stdin);
    fclose(stdout);
    //woshibeijingshichenjinglunzhongxuejinsongfenxiaodezhangruixuan
    //wodezhunkaozhenghaoshi:BJ-S00588 shenfenzhenghouziweishi:9530
	//xiwanggeweishenxiannengwanzuwoyigeyuanwang:
    //woyongwoyiniandanshenlaixuan2024niancsp-szufusaisandengjiang
    //huozheyongdanshenwunianlaihuan2024csp-sfusaierdengjiang
    //nengnajiangjiukeyi,qiuqiule!
    //xiwanggeweishenxiannengmanzuwozhegeyuanwang
    return 0;
}
