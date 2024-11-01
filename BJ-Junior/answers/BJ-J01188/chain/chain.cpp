#include <iostream>
using namespace std;
typedef long long LL;
LL t,n[10],k[10],q[10],l,r;
string c;
char cmp;
string a[1000000]="";
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;++i)
    {
        cin>>n[i]>>k[i]>>q[i];
        for(int j=0;j<n;++j)
        {
            cin>>l;
            a[j]="";
            for(int kj=0;kj<l;++kj)
            {
                cin>>cmp;
                a[j]+=cmp;
            }
        }
        for(int iq=0;iq<q;++iq)
        {
            cin>>r;
            cin>>c;
            for(int l=0;l<n;++l)
                if(a[l].find(c)!=string::npos)
            {   cout<<1<<endl;break;}
            cout<<0<<endl;
            
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
