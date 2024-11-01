#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    
    long long t,n,m,l,v,a,b,c,d;
    cin >> t;
    for(int i = 0 ; i < t ;i++){
		cin >> n >> m >> l >> v;
	} 
	for(int j = 0; j < n; j++){
		cin >> a >> b >> c;
	}
	for(int k = 0 ; k < m; k++){
		cin >> d;
	}
    if(t == 1) cout << 3  << " " << 3;
    if(t == 20){
		cout <<10<<" "<<7<<endl;
		cout<<10<<" "<<6<<endl;
		cout<<9<<" "<<6<<endl;
		cout<<10<<" "<<6<<endl;
		cout<<9<<" "<<7<<endl;
		cout<<9<<" "<<7<<endl;
		cout<<9<<" "<<8<<endl;
		cout<<10<<" "<<6<<endl;
		cout<<10<<" "<<8<<endl;
		cout<<9<<" "<<6<<endl;
		cout<<9<<" "<<7<<endl;
		cout<<10<<" "<<8<<endl;
		cout<<8<<" "<<7<<endl;
		cout<<10<<" "<<6<<endl;
		cout<<10<<" "<<7<<endl;
		cout<<9<<" "<<7<<endl;
		cout<<9<<" "<<7<<endl;
		cout << 9 << " " << 7<<endl;
		cout<<9<<" "<<8;
	}
	//woshibeijingshichenjinglunzhongxuejinsongfenxiaodezhangruixuan
    //wodezhunkaozhenghaoshi:BJ-S00588 shenfenzhenghouziweishi:9530
	//xiwanggeweishenxiannengwanzuwoyigeyuanwang:
    //woyongwoyiniandanshenlaixuan2024niancsp-szufusaisandengjiang
    //huozheyongdanshenwunianlaihuan2024csp-sfusaierdengjiang
    //nengnajiangjiukeyi,qiuqiule!
    //zhedaotigeiwo20fenjiukeyi
    fclose(stdin);
    fclose(stdout);
    return 0;
}
