#include <bits/stdc++.h>
using namespace std;

int n;
int c_ptr = 1;
int rec[100005];
int n_tot;
int s,b;
int ans = 0;
struct card_tot
{
    int v;
    int cnt;
    int cnt_dueled;
};
struct card_tot c[100005];

void print()
{
    cout << endl;
    cout << "n_tot : " << n_tot << endl;;
    cout << "c" <<endl;
    cout << "v ";
    for (int i = 1 ; i <= n_tot; i ++)
    {
        cout << c[i].v <<" ";
    }
    cout << endl << "cnt ";
    for (int i = 1 ; i <= n_tot; i ++)
    {
        cout << c[i].cnt <<"  ";
    }
    cout << endl << "cnt_d";
    for (int i = 1 ; i <= n_tot; i ++)
    {
        cout << c[i].cnt_dueled <<"  ";
    }
    cout << endl;
    cout << endl;
}

void print_rec()
{
    for (int i = 1 ; i <= n ; i ++)
    {
        cout << rec[i] << " ";
    }
    cout << endl;
}

void print_mx()
{
    cout << "c" <<endl;
    cout << "v ";
    for (int i = 1 ; i <= n_tot; i ++)
    {
        cout << c[i].v <<" ";
    }
    cout << endl << "cnt ";
    for (int i = 1 ; i <= n_tot; i ++)
    {
        cout << c[i].cnt <<"  ";
    }
    cout << endl << "cnt_d ";
    for (int i = 1 ; i <= n_tot; i ++)
    {
        cout << c[i].cnt_dueled <<"  ";
    }
    cout << endl;
}


int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    cin >> n;
    if(n == 1)
    {
        cout << 1;
        return 0;
    }
    for (int i = 1 ; i <= n ; i ++)
    {
        cin >> rec[i];
    }
    sort(rec + 1,rec + n + 1);
    //print_rec();

    if (rec[1] == rec[n])
    {
        cout << n;
        return 0;
    }


    for (int i = 1 ; i <= n ; i ++)
    {
        if (i == 1)
        {
            c[1].v = rec[i];
            c[1].cnt = 1;
        }
        else
        {
            if(rec[i] == c[c_ptr].v)
            {
                c[c_ptr].cnt ++;
            }
            else
            {
                c_ptr++;
                c[c_ptr].v = rec[i];
                c[c_ptr].cnt = 1;
            }
        }
        //print_2()
    }
    n_tot = c_ptr;


    //print_mx();



    for (int s = 1 ; s <= n_tot ; s ++)
    {
        for (int b = s + 1 ; (b <= n_tot) && ( (c[s].cnt != 0) || (c[s].cnt_dueled != 0) ); b ++)
        {
            int cur = min(c[s].cnt + c[s].cnt_dueled,c[b].cnt);

            c[b].cnt -= cur;
            c[b].cnt_dueled += cur;

            if(c[s].cnt_dueled >= cur)
            {
                c[s].cnt_dueled -= cur;
            }
            else
            {
                c[s].cnt = c[s].cnt + c[s].cnt_dueled - cur;
                c[s].cnt_dueled = 0;
            }
            //print_mx();
        }
    }

    //print();

    for (int i = 1 ; i <= n_tot ; i++)
    {
        ans += c[i].cnt_dueled;
        ans += c[i].cnt;
    }

    cout << ans;

    return 0;
}
