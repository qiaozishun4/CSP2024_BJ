#include<bits/stdc++.h>
using namespace std;
int n;
const int MAX_N=1e5+10;
/*bool cmp(int a,int b)
{
    return a > b;
}*/
bool is_find=false;
int a[MAX_N];
int kil=0;
//bool is_die[MAX_N]={false};
bool is_faqi[MAX_N]={false};
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++)
    {

        for(int j=i;j<=n;j++)
        {
            if(a[i]<a[j] && !is_faqi[j])
                //!is_die[i] && !is_die[j] &&
            //证明攻击成功了，有攻击对象，可以攻击 ,J kill I
            {
                kil++;
                //is_die[i]=true;
                is_faqi[j]=true;

                //cout << j<<" "<<i<<endl;
                break;
            }
        }
    }
    //cout <<endl;
    cout << n-kil;
    //for (int i=1;i<=n;i++)
    //{
    //    cout << a[i];
    //}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
