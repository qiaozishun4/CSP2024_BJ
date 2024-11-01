#include<bits/stdc++.h>
using namespace std;
int n;
int a[20] = {0};
int b[20] = {0};
int t[20] = {0};
int d[20] = {0};
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    char s,c;
    /*cout <<n <<endl;
    for(int i= 1;i <= 13;i++){
        cout <<d[i] <<' ';
    }
    cout <<endl;*/
    for(int i = 1;i <= n;i++){
        cin >> s >> c;
        if(s == 'D'){
            if(c == 'A'){
                a[1] = 1;
                continue;
            }
            if(c == 'T'){
                a[10] = 1;
                continue;
            }
            if(c == 'J'){
                a[11] = 1;
                continue;
            }
            if(c == 'Q'){
                a[12] = 1;
                continue;
            }
            if(c == 'K'){
                a[13] = 1;
                continue;
            }
            a[c-'0'] = 1;
        }
        if(s == 'C'){
            if(c == 'A'){
                b[1] = 1;
                continue;
            }
            if(c == 'T'){
                b[10] = 1;
                continue;
            }
            if(c == 'J'){
                b[11] = 1;
                continue;
            }
            if(c == 'Q'){
                b[12] = 1;
                continue;
            }
            if(c == 'K'){
                b[13] = 1;
                continue;
            }
            b[c-'0'] = 1;
        }
        if(s == 'H'){
            if(c == 'A'){
                t[1] = 1;
                continue;
            }
            if(c == 'T'){
                t[10] = 1;
                continue;
            }
            if(c == 'J'){
                t[11] = 1;
                continue;
            }
            if(c == 'Q'){
                t[12] = 1;
                continue;
            }
            if(c == 'K'){
                t[13] = 1;
                continue;
            }
            t[c-'0'] = 1;
        }
        /*for(int i= 1;i <= 13;i++){
            cout <<d[i] <<' ';
        }
        cout <<endl;*/
        if(s == 'S'){
                //cout << "s" <<endl;
            if(c == 'A'){
                d[1] = 1;
                continue;
            }
            if(c == 'T'){
                d[10] = 1;
                continue;
            }
            if(c == 'J'){
                d[11] = 1;
                continue;
            }
            if(c == 'Q'){
                d[12] = 1;
                continue;
            }
            if(c == 'K'){
                d[13] = 1;
                continue;
            }
            d[c-'0'] = 1;
        }

    }
    /*for(int i= 1;i <= 13;i++){
        cout <<d[i] <<' ';
    }*/
    //cout <<endl;
    int cnt = 0;
    for(int i = 1;i <= 13;i++){
        if(a[i] == 0){
            cnt++;
        }
        if(b[i] == 0){
            cnt++;
        }
        if(t[i] == 0){
            cnt++;
        }
        if(d[i] == 0){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
