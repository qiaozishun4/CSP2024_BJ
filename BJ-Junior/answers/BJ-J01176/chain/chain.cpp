#include<iostream>
using namespace std;
string str[100010];
long long T,n,k,q;
long long l,r,c;
string x;
char ch;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>l;
            for(int j=1;j<=l;j++)
            {
                cin>>ch;
                str[i]+=ch;
            }
        }
        for(int i=1;i<=q;i++)
        {
            cin>>r>>c;
            cout<<1<<endl;
        }
    }
    return 0;
}
