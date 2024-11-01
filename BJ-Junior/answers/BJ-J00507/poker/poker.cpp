#include<bits/stdc++.h>
bool biao[20][10];
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int a;
    cin >> a;
    for(int i=1;i<=a;i++){
        char h,d;
        int hs,dsh;
        cin >> h >> d;
        if(h=='D'){
            hs=1;
        }
        else if(h=='C'){
            hs=2;
        }
        else if(h=='H'){
            hs=3;
        }
        else {
            hs=4;
        }
        if(d>'1' && d<='9'){
            dsh=d-'0';
        }
        else if(d=='A'){
            dsh=1;
        }
        else if(d=='T'){
            dsh=10;
        }
        else if(d=='J'){
            dsh=11;
        }
        else if(d=='Q'){
            dsh=12;
        }
        else {
            dsh=13;
        }
        biao[dsh][hs]=1;
    }
    int da=0;
    for(int i=1;i<=13;i++){
        for(int j=1;j<=4;j++){
            if(!biao[i][j]) da++;
        }
    }
    cout << da;
    return 0;
}
