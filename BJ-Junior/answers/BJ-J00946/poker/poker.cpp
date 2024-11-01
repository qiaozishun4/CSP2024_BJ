#include<map>
#include<iostream>
using namespace std;
#define endl '\n'

bool a[60];
int n;

int get1(char a){
    if(a == 'D') return 0;
    if(a == 'C') return 1;
    if(a == 'H') return 2;
    if(a == 'S') return 3;
}

int get2(char a){
    if(a == 'A') return 1;
    if(isdigit(a)) return a - '0';
    if(a == 'T') return 10;
    if(a == 'J') return 11;
    if(a == 'Q') return 12;
    if(a == 'K') return 13;
}

int get(char a,char b){
    return get1(a) * 13 + get2(b);
}

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n;++i){
        char p,f;
        cin >> p >> f;
        int id = get(p,f);
        a[id] = 1;
    }
    int cnt = 0;
    for(int i = 1;i <= 52;++i)
        if(!a[i]) cnt++;
    cout << cnt << endl;
    return 0;
}
