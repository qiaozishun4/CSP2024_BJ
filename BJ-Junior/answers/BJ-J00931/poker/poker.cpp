#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,s;
    bool q;
    string m1;
    char m2[52][2];
    cin>>n;
    for(int i = 0;i < 52;i++){
        m2[i][0] = 0;
        m2[i][1] = 0;
    }
    for(int i = 0;i < n;i++){
        cin>>m1;
        for(int j = 0;j < i;j++){
            if(m1[0] == m2[j][0] && m1[1] == m2[j][1]){
                q == 1;
            }
        }
        if(q == 1){
            q = 0;
            break;
        }
        m2[i][0] = m1[0];
        m2[i][1] = m1[1];
        s+= 1;
    }
    cout<<52 - s;
    return 0;
}
