#include<bits/stdc++.h>
using namespace std;
char poke[55][2];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int sum=n;
    for(int i=1;i<=n;i++){
        cin>>poke[i][0]>>poke[i][1];
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
        if(poke[j][0]==poke[i][0]&&poke[j][1]==poke[i][1])sum--;
    }
    }

    cout<<52-sum;
    fclose(stdin);
    fclose(stdout);

return 0;}
