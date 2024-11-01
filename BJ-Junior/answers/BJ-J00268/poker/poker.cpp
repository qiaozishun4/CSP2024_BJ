#include<bits/stdc++.h>
using namespace std;
int b[20][20];
int main (){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    long long n;
    cin>>n;
    string a;

    for(int i=0;i<n;i++){
        cin>>a;
        if(a[0]=='C'){
            if(a[1]<='9'&&a[1]>='0'){
                b[1][a[1]-'0']++;
            }else if(a[1]=='A')b[1][1]++;
            else if(a[1]=='T')b[1][10]++;
            else if(a[1]=='J')b[1][11]++;
            else if(a[1]=='Q')b[1][12]++;
            else if(a[1]=='K')b[1][13]++;
        }else if(a[0]=='D'){
            if(a[1]<='9'&&a[1]>='0'){
                b[0][a[1]-'0']++;
            }else if(a[1]=='A')b[0][1]++;
            else if(a[1]=='T')b[0][10]++;
            else if(a[1]=='J')b[0][11]++;
            else if(a[1]=='Q')b[0][12]++;
            else if(a[1]=='K')b[0][13]++;
        }else if(a[0]=='H'){
            if(a[1]<='9'&&a[1]>='0'){
                b[2][a[1]-'0']++;
            }else if(a[1]=='A')b[2][1]++;
            else if(a[1]=='T')b[2][10]++;
            else if(a[1]=='J')b[2][11]++;
            else if(a[1]=='Q')b[2][12]++;
            else if(a[1]=='K')b[2][13]++;
        }else if(a[0]=='S'){
            if(a[1]<='9'&&a[1]>='0'){
                b[3][a[1]-'0']++;
            }else if(a[1]=='A')b[3][1]++;
            else if(a[1]=='T')b[3][10]++;
            else if(a[1]=='J')b[3][11]++;
            else if(a[1]=='Q')b[3][12]++;
            else if(a[1]=='K')b[3][13]++;
        }
    }
    for(int i=0;i<=3;i++){
        for(int j=1;j<=13;j++){
            if(b[i][j]>=2)n--;
        }
    }
    cout<<52-n;
    fcloce(stdin);
    fclose(stdout);
    return 0;
}