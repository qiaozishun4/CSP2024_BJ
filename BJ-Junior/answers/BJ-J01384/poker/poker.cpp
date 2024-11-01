#include <bits/stdc++.h>

using namespace std;
int n,a[15][5];
char s;
int main()
{

    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> s;
        int j,k;
        if(s == 'D'){
            j = 1;
        }else if(s == 'C'){
            j = 2;
        }else if(s == 'H'){
            j = 3;
        }else if(s == 'S'){
            j = 4;
        }
        cin >>s;
        if(s == 'T'){
            k = 10;
        }else if(s == 'J'){
            k = 11;
        }else if(s == 'Q'){
            k = 12;
        }else if(s == 'K'){
            k = 13;
        }else if(s == 'A'){
            k = 1;
        }else{
            k = s - '0';
        }
        a[k][j] = 1;
    }
    int p = 0;
    for(int i = 1;i <= 13;i++){
        for(int j = 1;j <= 4;j++){
            if(!a[i][j]) p++;
        }
    }
    cout <<p;
    return 0;
}
