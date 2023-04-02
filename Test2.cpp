#include <bits/stdc++.h>

#define maxn 200005
#define fo(i,a,b) for(int i=a;i<=(int)b;i++)
#define fr(i,a,b) for(int i=b;i>=(int)a;i--)
#define F first
#define S second
#define pii pair < int,int>
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define Task ""

using namespace std;
mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());

int n;

bool check(int x, vector<int> d)
{
    if( x < 2) return 0;
    return !d[x];
}

void b1()
{
    // voi n <= 1e5, a[i] <= 2e5
    cin >> n;
    vector < int > a(n), b, p(maxn, 0);

    // Sang nt
    for(int i = 2; i * i < maxn; i++){
        for(int j = i*i; j < maxn; j+=i){
            p[j] = 1;
        }
    }
    // tinh
    fo(i,0,n-1)
    {
        cin >> a[i];
        if(check(a[i], p)) b.pb(a[i]);
    }
    sort(b.begin(), b.end());
    a = b;
    fo(i, 0, a.size() -1) cout << a[i] <<' ';
    cout << endl;
}

void b2()
{
    // n<=
    cin >> n;
    if(n < 3)
    {
        cout << 1 ;
        return ;
    }
    long long f0 = 1, f1 = 1, dem = 2;
    while(dem!=n)
    {
        dem++;
        f1+=f0;
        f0 = f1 - f0;
    }
    cout << f1;
     cout << endl;
}

void b3()
{
    // n, len <= 20
    int len;
    cin >> len >> n;
    vector < int > a(len), b, c;
    fo(i,0,len-1) cin >> a[i];
    fo(x, 0, (1 << len) -1)
    {
        fo(i,0,len-1)
        {
            if((x>>i)&1)
                b.pb(a[i]);
        }
        if(b.size()== n)
            {
                c = b;
                sort(b.begin(), b.end());
                bool ok = 1;
                fo(i,1,n-1)
                {
                    if(b[i] == b[i-1])
                    {
                        ok = 0;
                        break;
                    }
                }
                if(ok)
                {
                    fo(i,0,n-1) cout << c[i] <<' ';
                    cout << endl;
                }
            }
           b.clear();
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//   freopen(Task".inp","r",stdin);
//    freopen(Task".out","w",stdout);
    bool ok = true;
     char ch;
    while(ok)
    {
        cout << "1. Bai 1\n2. Bai 2\n3. Bai 3\n4. Thoat" << endl;

        cin >> ch;

        switch (ch)
        {
        case '1':
            b1();
            break;
        case '2':
            b2();
            break;
        case '3':
        {
            b3();
            break;
        }
        case '4':
        {
            ok = false;
            break;
        }
        default:
            continue;
        }

    }
    return 0;
}
