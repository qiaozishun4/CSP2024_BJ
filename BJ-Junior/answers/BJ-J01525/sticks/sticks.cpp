#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int ans[N];

int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        if(n < 7){
			if(n < 2){
			cout << -1 << endl;
		}else if(n == 3) cout << 7 << endl;
		else if(n == 4) cout << 4 << endl;
		else if(n == 5) cout << 2 << endl;
		else if(n == 6) cout << 6 << endl;
		else cout << 1 << endl;
		continue;
		}
        
        if(n % 7 == 0 && n >= 100){
            for(int i = 1; i <= n / 7; i++) cout << 8;
            cout << endl; continue;
        }
        int t1 = n / 7, t2 = n % 7;
        if(t2 == 0){
            for(int i = 1; i <= t1; i++) cout << 8;
            cout << endl;
        }else{
            if(t2 == 1){
                cout << "10";
                for(int i = 1; i <= t1 - 1; i++) cout << 8;
                cout << endl;
            }else if(t2 == 2){
                cout << "1";
                for(int i = 1; i <= t1; i++) cout << 8;
                cout << endl;
            }else if(t2 == 3){
				if(t1 < 2){
					cout << "22";
                    for(int i = 1; i <= t1 - 1; i++) cout << 8;
                    cout << endl;
				}else{
					cout << "200";
					for(int i = 1; i <= t1 - 2; i++) cout << 8;
					cout << endl;
				}
                
            }else if(t2 == 4){
                cout << "20";
                for(int i = 1; i <= t1 - 1; i++) cout << 8;
                cout << endl;
            }else if(t2 == 5){
                cout << "2";
                for(int i = 1; i <= t1; i++) cout << 8;
                cout << endl;
            }else{
                cout << 6;
                for(int i = 1; i <= t1; i++) cout << 8;
                cout << endl;
            }
        }
    }
}
