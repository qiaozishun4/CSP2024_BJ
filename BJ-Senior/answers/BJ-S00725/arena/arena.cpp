#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=8e5+5;
int T,n,m,iniA[N],a[N],qy[N],maxK,minVal[N],maxVal[N],iniCnt[20],dOnTree[N],purged[N];
int ans[N];
bool d[20][N];
bitset<20> canBe[N];
inline int ls(int p){return p<<1;}
inline int rs(int p){return p<<1|1;}
inline void purge(int p,int dep,int l,int r) {
}
inline void pushUp(int p,int dep,int l,int r) {
    int mid=l+r>>1;
    if (!dOnTree[p] && minVal[ls(p)] < dep && maxVal[ls(p)] >= dep) {
        auto tmp = canBe[ls(p)] << dep >> dep;
        canBe[p] = canBe[rs(p)] | tmp;
        for (int i = 0; i <= 18; i++)
            if (canBe[p][i]) {
                minVal[p] = i;
                break;
            }
        for (int i = 18; ~i; i--)
            if (canBe[p][i]) {
                maxVal[p] = i;
                break;
            }
    }
    else if (!dOnTree[p] && maxVal[ls(p)] < dep)
    {

    }
    else if (!dOnTree[p] && minVal[ls(p)] >= dep && !purged[rs(p)])
        purge(rs(p),dep-1,mid+1,r);
    else if(dOnTree[p] && minVal[rs(p)] < dep)
        canBe[p] |= canBe[ls(p)];
    else if(dOnTree[p] && minVal[rs(p)] >= dep && !purged[ls(p)])
        purge(ls(p),dep-1,l,mid);
}
inline void init(int p,int dep,int l,int r){
    dOnTree[p] = d[dep][++iniCnt[dep]];
    if (l == r) {
        for (int i=0;i<=18;i++)
            canBe[p][i] = 1;
        return;
    }
    int mid=l+r>>1;
    init(ls(p),dep-1,l,mid);
    init(rs(p),dep-1,mid+1,r);
}
int main()
{
    //freopen("detect.in","r",stdin);
    //freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>iniA[i];
    for(int i=1;i<=m;i++)
        cin>>qy[i];
    sort(qy+1,qy+1+m);
    maxK=ceil(log2(n));
    for(int i=1;i<=maxK;i++)
        for(int j=1;j<=1<<(maxK-i);j++)
            cin>>d[i][j];

    cin>>T;
    while(T--) {
        int decodeX[4];
        for(int i=0;i<4;i++)
            cin>>decodeX[i];
        for(int i=1;i<=n;i++)
            a[i]=min(iniA[i]^decodeX[i%4], 18);
        init(1, 1, 1<<maxK);
    }
    return 0;
}
/*
i,j,k -> i+1,i,k: +a[j]==a[i+1]
i,j,k -> i+1,j,i: +a[k]==a[i+1]
*/
