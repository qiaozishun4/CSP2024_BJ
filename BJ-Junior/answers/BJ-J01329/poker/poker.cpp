#include<iostream>
using namespace std;
string p[60];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,sum=0,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        int tmp=1;
        cin>>s;
        for(int j=1;j<=i;j++)
        {
            if(s==p[j])
                tmp=0;
                break;
        }
        if(tmp!=0)
            p[i]=s;
            cnt++;
            //cout<<"s="<<s<<' '<<"cnt="<<cnt<<endl;

    }
    for(int i=1;i<=cnt;i++)
    {
        sum++;
    }
    cout<<52-sum;
    return 0;
}
