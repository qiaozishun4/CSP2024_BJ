#include<iostream>
using namespace std;
short sticks[10]={6,2,5,5,4,5,6,3,7,6};
long long mxnum(int n)//the max one,which is like 1111111111111111 or 1111111111111111111117
{
    long long res=0;
    for(int i=0;i<(n>>1);i++)res=res*10+1;
    return n&1?res+6:res;
}
long long cnt(long long num)
{
    long long res=0;
    for(;num;num/=10)res+=sticks[num%10];
    return res;
}
int main(void)
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    for(cin>>T;T;T--)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            cout<<-1<<endl;
            continue;
        }
        for(long long i=1;i<=mxnum(n);i++)
            if(cnt(i)==n)
            {
                cout<<i<<endl;
                break;
            }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
