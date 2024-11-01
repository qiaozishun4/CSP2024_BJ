#include<bits/stdc++.h>
using namespace std;
int n,s[5][14];//1D 2C 3H 4S
int d[30],e[30],ans;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    d['D'-'A']=1;
    d['C'-'A']=2;
    d['H'-'A']=3;
    d['S'-'A']=4;
    e[0]=1;
    e['T'-'A']=10;
    e['J'-'A']=11;
    e['Q'-'A']=12;
    e['K'-'A']=13;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        string str;
        cin>>str;
        int tmp1=d[str[0]-'A'],tmp2;
        if(str[1]<='9'&&str[1]>='1'){
            tmp2=str[1]-'0';
        }
        else{
            tmp2=e[str[1]-'A'];
        }
  //      printf("%d %d\n",tmp1,tmp2);
        s[tmp1][tmp2]++;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!s[i][j]){
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
