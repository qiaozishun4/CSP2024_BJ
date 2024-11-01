#include<iostream>
using namespace std;
char a[1001];
char b[1001];
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    int cnt=0;
    bool flag;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        flag=0;
        for(int j=i-1;j>=1;j--)
        {
            if(a[i]==a[j]&&b[i]==b[j])
            {
                flag=1;

                break;
            }
        }
        if(!flag)
        {
            cnt++;
        }
    }
    cout<<52-cnt<<endl;
    return 0;
}



