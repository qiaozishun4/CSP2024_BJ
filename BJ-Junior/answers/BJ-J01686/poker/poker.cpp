#include<iostream>
#include<set>
#include<string>
using namespace std;
set<string> s;
int n;
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out". "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i ++){
        string str;
        cin >> str;
        s.insert(str);
    }
    cout << 52 - s.size();
    return 0;
}
