#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
const int cnt[12]={6,2,5,5,4,5,6,3,7,6};
const string tab[12]={" ","07","1","7 ","4","2","0","8","10"};
string dp[N],op[10];
int T,n;
inline bool cmp(string A,string B)
{
    if(A.length()!=B.length())return A.length()<B.length();
    if(A[0]!=B[0])return A[0]<B[0];
    return A[1]<B[1];
}
inline void Init()
{
    if(n==1)
    {
        cout<<"-1"<<endl;
        return;
    }
    dp[1]="x";
    for(int i=2;i<=8;i++)dp[i]=tab[i];
    dp[6]="6";
    for(int i=9;i<=n;i++)
    {
        op[1]="1"+dp[i-2];
        op[2]="7"+dp[i-3];
        op[3]="4"+dp[i-4];
        op[4]="2"+dp[i-5];
        if(i!=n)op[5]="0"+dp[i-6];
        else op[5]="6"+dp[i-6];
        op[6]="8"+dp[i-7];
        sort(op+1,op+7,cmp);
        dp[i]=op[1];
    }
    cout<<dp[n]<<endl;
    return;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> n;
        Init();
    }
    return 0;
}