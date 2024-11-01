#include <bits/stdc++.h>
using namespace std;

int n,ans;
char a1[4]={'D','C','H','S'},a2[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
bool a[5][14];

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--){
        char x,y;
        cin>>x>>y;
        for(int i=0;i<4;i++){
            if(x==a1[i]){
                for(int j=0;j<13;j++){
                    if(y==a2[j]){
                        a[i][j]=1;
                    }
                }
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            if(a[i][j]){
                ans++;
            }
        }
    }
    cout<<52-ans;
    return 0;
}
