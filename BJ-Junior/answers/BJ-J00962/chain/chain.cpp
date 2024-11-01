
#include <iostream>
using namespace std;
int main()
{
    freopen("poker.in","r",cin);
    freopen("poker.out","w",cout);
    int l;
    cin>>l;
    int a[52];
    for(int i=0;i<=l-1;i++)
    {
        cin>>a[i];
    }
    int c[52];
    int s=52;
    for(int i=0;i<=52;i++)
    {
       bool b=0;
       for(int k=0;k<=52;k++)
       {
           if(k==i)
           {
               b=0;
           }
       }
       if(b)
       {

       }
       else
       {
           s--;
       }
    }
    fclose(cin);
    fclose(cout);
    cout<<52-l;
    return 0;
}
 







































































































































































































































