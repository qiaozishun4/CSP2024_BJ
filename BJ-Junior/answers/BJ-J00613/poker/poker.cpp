#include<iostream>
#include<string>
using namespace std;
string str[1001];
string tmp[1001];
int tmp1=52;
void checkopen(string str,int cnt)
{
    for(int i=0;i<cnt;i++)
    {
        if(str.compare(tmp[i])==0)
        {
            return;
        }
    }
    tmp[cnt++]+=str;
    tmp1--;
}
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
        if(i==0)
        {
            tmp1--;
            tmp[cnt]=str[i];
            cnt++;
            continue;
        }
       checkopen(str[i],cnt);
    }
    cout<<tmp1<<endl;
    return 0;
}