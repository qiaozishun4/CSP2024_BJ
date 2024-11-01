#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[10][20];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        char f,m;
        cin>>f>>m;
        if(f=='D'){
            if('2'<=m&&m<='9')a[1][m-'0']++;
            else if(m=='A')a[1][1]++;
            else if(m=='T')a[1][10]++;
            else if(m=='J')a[1][11]++;
            else if(m=='Q')a[1][12]++;
            else a[1][13]++;
        }else if(f=='C'){
            if('2'<=m&&m<='9')a[2][m-'0']++;
            else if(m=='A')a[2][1]++;
            else if(m=='T')a[2][10]++;
            else if(m=='J')a[2][11]++;
            else if(m=='Q')a[2][12]++;
            else a[2][13]++;
        }else if(f=='H'){
            if('2'<=m&&m<='9')a[3][m-'0']++;
			else if(m=='A')a[3][1]++;
            else if(m=='T')a[3][10]++;
            else if(m=='J')a[3][11]++;
            else if(m=='Q')a[3][12]++;
            else a[3][13]++;
        }else{
            if('2'<=m&&m<='9')a[4][m-'0']++;
            else if(m=='A')a[4][1]++;
            else if(m=='T')a[4][10]++;
            else if(m=='J')a[4][11]++;
            else if(m=='Q')a[4][12]++;
            else a[4][13]++;
        }
    }
    ll ans=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!a[i][j])ans++;
        }
    }
    printf("%lld",ans);
    return 0;
}

