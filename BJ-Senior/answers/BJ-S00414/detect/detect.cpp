#include<bits/stdc++.h>
using namespace std;
int r[100001];
int s[100001];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin >> T;
    for(int I=1;I<=T;I++){
        long long a,b,c;
        cin >> a >> b >> c;
        cin >> c;
        for(int i=1;i<=a;i++){
            int x;
            cin >> r[i] >> s[i] >> x;
        }
        int y;
        for(int i=1;i<=b;i++){
            cin >> y;
        }
        long long da=0;
        for(int i=1;i<=a;i++){
            if(r[i]<=y && s[i]>c){
                da++;
            }
        }
        cout <<da << ' ' << b-1 << "\n";
    }
    return 0;
}
