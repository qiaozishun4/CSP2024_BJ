#include <iostream>
#include <algorithm>
#include <cmath>


using namespace std;

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    int T;
    cin >> T;

    for (int i=0;i<T;i++)
    {
        int n,m,l,v;
        cin >> n >> m >> l >> v;
        //cerr << "飙车速度："<<v<<endl;
        int maxjuli=0;
        int chaochecnt=0;
        for (int i=0;i<n;i++)
        {
            
            int d,lyx,a;
            cin >> d >> lyx >> a;
            if(lyx<=v)
            {
                //cerr <<"当前车速"<<lyx<<"c"<<chaochecnt<<endl;
                continue;
            }
            else
            {
                
                chaochecnt++;
                //cerr <<"当前车速"<<lyx<<"c"<<chaochecnt<<endl;
                maxjuli=max(maxjuli,d);
            }
                       
        }
        maxjuli++;
        int kill=0;
        for (int i=0;i<kill;i++)
        {
            int lyx;
            cin >> lyx;
            if(lyx>maxjuli)
            kill++;
        }
        cout << chaochecnt << " " << kill << endl;
    }
}