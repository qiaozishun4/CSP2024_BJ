#include<iostream>
using namespace std;
int d[100005];
int c[100005];
int h[100005];
int s[100005];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    string a;
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 0;i < n;i++){
        cin >> a;
        if(a[0] == 'D'){
            d[a[1]]++;
        }
        if(a[0] == 'C'){
            c[a[1]]++;
        }
        if(a[0] == 'H'){
            h[a[1]]++;
        }
        if(a[0] == 'S'){
            s[a[1]]++;
        }
    }
    for(int i = 0;i < 1000;i++){
        if(d[i] != 0){
            cnt++;
        }
        if(c[i] != 0){
            cnt++;
        }
        if(h[i] != 0){
            cnt++;
        }
        if(s[i] != 0){
            cnt++;
        }

    }
    cout << 52-cnt;
    return 0;
}

