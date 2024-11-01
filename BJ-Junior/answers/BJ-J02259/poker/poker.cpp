#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    char c[n],d[n],e[n];
    for(int i=0;i<n;i++){
        cin>>c[i]>>d[i];
    }
    int m=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(c[i]==c[j]){
                if(d[i]==d[j]){
                    m--;
                }
            }
        }
        m++;
    }
    cout<<52-m;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
