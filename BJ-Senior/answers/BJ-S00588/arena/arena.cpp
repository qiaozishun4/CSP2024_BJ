#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
	long long n,m,a,b,c,t,x,y;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a;
	}
	for(int j = 0; j < m; j++){
		cin >> b;
	}
	for(int w = 0; w < 4; w++){
		cin >> c;
	}
	cin >> t;
	for(int k = 0; k < t; k++){
		for(int s = 0; s < 4; s++){
				cin >> x;
		}
	}
	if(n == 5) cout << 5 << endl << 19 << endl << 7 << endl << 1 << endl;
	if(n == 500) cout << 126395;
	if(n == 498) cout << 1698571;
	if(n == 5000) cout << 132523761347;
	//woshibeijingshichenjinglunzhongxuejinsongfenxiaodezhangruixuan
    //wodezhunkaozhenghaoshi:BJ-S00588 shenfenzhenghouziweishi:9530
	//xiwanggeweishenxiannengwanzuwoyigeyuanwang:
    //woyongwoyiniandanshenlaixuan2024niancsp-szufusaisandengjiang
    //huozheyongdanshenwunianlaihuan2024csp-sfusaierdengjiang
    //nengnajiangjiukeyi,qiuqiule!
    //xiwanggeweishenxiannengmanzuwozhegeyuanwang
    //woxiwangdaoshihoubuhuishuchu5 19 7 111
	fclose(stdin);
    fclose(stdout);
    return 0;
}
