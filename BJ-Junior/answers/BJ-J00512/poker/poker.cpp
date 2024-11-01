#include<bits/stdc++.h>
using namespace std;
long long n,sum=52;
string p,q,s,t;
int main ()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
         cin>>p>>t;
    }
    for(int i=1;i<=n;i++)
    {

         if(p[i]+q[i]==52){
            break;
         }
            if(p[i]<52)
            {
                p+=s;
            }
            if(p[i]<52)
            {
                cout<<sum-p[i];
            }
        }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
