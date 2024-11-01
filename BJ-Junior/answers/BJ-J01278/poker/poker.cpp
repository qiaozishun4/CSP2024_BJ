#include<iostream>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,aa=0,cnt=0,cnt1=0;
    char s[55],s1[55];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i]>>s1[i];
    }
    if(n==1)
    {
        cout<<"51";
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(s[i]==s[j]&&s1[i]==s1[j])
            {
                cnt1++;
            }
            else
                cnt++;
        }

    }
    if(cnt==n)
    {
        cout<<52-cnt;
    }
    else
        cout<<52-(n-cnt1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
