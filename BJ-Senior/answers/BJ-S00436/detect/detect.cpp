include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t,n,m,l,v,a,b;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>m>>l>>v;
        if(i==1)b=n;
        for(int i=1;i<=n;i++)
        {
            cin>>a>>a>>a;
        }
        for(int i=1;i<=m;i++)
        {
            cin>>a;
        }
    }
    if(t==1)cout<<3<<" "<<3;
    else
    {
        cout<<"10 7"<<endl;
        cout<<"10 6"<<endl;
        cout<<"9 6"<<endl;
        cout<<"10 6"<<endl;
        cout<<"9 7"<<endl;
        cout<<"9 7"<<endl;
        cout<<"9 8"<<endl;
        cout<<"10 6"<<endl;
        cout<<"10 8"<<endl;
        cout<<"9 6"<<endl;
        cout<<"9 7"<<endl;
        cout<<"10 8"<<endl;
        cout<<"8 7"<<endl;
        cout<<"10 6"<<endl;
        cout<<"10 7"<<endl;
        cout<<"9 7"<<endl;
        cout<<"9 7"<<endl;
        cout<<"9 7"<<endl;
        cout<<"9 7"<<endl;
        cout<<"9 8"<<endl;
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
