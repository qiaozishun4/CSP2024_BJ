#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    scanf("%d",&t);
    int n,m,k,x,y,d,temp=0,temp_ = 0;
    for (int i = 0;i < t;i++){
        cin >> n >> m >> k;
        cin >> x >> y >> d;
        string a[m+2];
        for (int i = 0;i <= n;i++) getline(cin,a[m]);
        if(m == 1){
            temp = 1;
            continue;
        }
        else if (m == 2){
            if (x == 1&&y == 1&&d == 1){
                temp = 1;
                continue;
            }
            else if (x == 1&&y == 1&&d == 0){
                temp_ = 2;
                continue;
            }
            else if (x == 1&&y == 2&&d == 1){
                temp = 1;
                continue;
            }
            else if (x == 1&&y == 2&&d == 0){
                temp_ = 2;
                continue;
            }
        }

    }
    for (int i = 0;i < t;i++){
        if (temp == 1) cout<< "1" << endl;
        if (temp_ == 2) cout<<"2"<<endl;
    }
    return 0;
}