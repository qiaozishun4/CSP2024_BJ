#include <bits/stdc++.h>
using namespace std;
char b[53][2],c[53][2];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int a;
    cin>>a;
    bool th=false;
    for(int i=0;i<a;i++){
        cin>>b[i][0]>>b[i][1];
        for(int j=0;j<53;j++){
            if(c[j][0]==b[i][0]&&c[j][1]==b[i][1]){
                th=true;
            }
        }
        if(!th){
            c[j][0]=b[i][0];
            c[j][0]=b[i][0];
            sum++;
        }
    }
    cout<<52-sum;
    return 0;
}

