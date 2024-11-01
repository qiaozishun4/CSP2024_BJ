#include<bits/stdc++.h>
#define Maxn 2*10^5+4
#define Max 10^5+4
using namespace std;
int n,k,q;
int L[Maxn];
short S[Maxn][Maxn];
bool pd(int from,int to,int r,short last){
    if(r==1){
        for(short i=1;i<=n;i++){
            if(i==last) continue;
            for(short j=0;j<=L[i]-2;j++) if(S[i][j]==from) for(short p=j+1;p<L[i]-1&&p-j<k;p++) if(S[i][p]==to) return true;
        }
    }
    for(short i=1;i<=n;i++){
        if(i==last) continue;
        for(short j=0;j<=L[i]-2;j++) if(S[i][j]==from) for(short p=j+1;p<L[i]-1&&p-j<k;p++) if(pd(S[i][p],to,r-1,i)) return true;
    }
    return false;
}

int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    short T;
    cin>>T;
    for(int t=0;t<T;t++){
        short i,j,p;
        cin>>n>>k>>q;
        for(i=1;i<=n;i++){
            cin>>L[i];
            for(j=0;j<L[i];j++){
                cin>>p;
                S[i][j]=p;
            }
        }
        for(i=0;i<q;i++){
            int c,r;
            cin>>r>>c;
            if(pd(1,c,r,-1)) cout<<"1"<<endl;
            else cout<<"0"<<endl;
        }
    }
    return 0;
}
