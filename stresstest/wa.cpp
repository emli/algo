/*
    code was
    created by
    Bayel
    Abdikarimov
*/

# include <bits/stdc++.h>
# define frein freopen("input.in","r", stdin)
# define freout freopen("output.out","w", stdout)
# define fr first
# define sc second
# define pb push_back
# define ll long long
# define mk make_pair

const int N = 1e5 + 5;
const int INF = 1e9 + 10;
const int mod = 1e9;
const int prime = 271;

using namespace std;

int e, f, p[N], w[N], n, mxdp[N], mndp[N];

int main ()
{
    scanf("%d %d %d", &e, &f, &n);

    for (int i = 0; i < n; i++)
        scanf("%d %d", &p[i], &w[i]);

    int o = f - e;

     for (int i = 0; i <= o; i++)
            mndp[i] = -1;

    for (int i = 0; i <= o; i++)
            mxdp[i] = -1;

    mxdp[0] = 0;
    mndp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= o; j++)
        {
            if ((j % w[i]) == 0)
            {
                mxdp[j] = max(mxdp[j], (j / w[i]) * p[i]);
                if (mndp[j] == -1)
                    mndp[j] = (j / w[i]) * p[i];
                else
                    mndp[j] = min(mndp[j], (j / w[i]) * p[i]);
            }
            for (int k = 1; k < j; k++)
            {
                if (mxdp[j - k] > -1 && mxdp[k] > -1)
                    mxdp[j] = max(mxdp[j], mxdp[j - k] + mxdp[k]);
                if (mndp[j - k] > -1 && mndp[k] > -1)
                {
                    if (mndp[j] == -1)
                        mndp[j] = mndp[j - k] + mndp[k];
                    else
                        mndp[j] = min(mndp[j], mndp[j - k] + mndp[k]);
                }
            }
        }
    }

    /*for (int i = 0; i <= o; i++)
        printf("%d ", mndp[i]);
    puts("");
    for (int i = 0; i <= o; i++)
        printf("%d ", mxdp[i]);
    puts("");*/


    if (mndp[o] == -1)
        puts("This is impossible");
    else
        printf("%d %d", mndp[o], mxdp[o]);

    return 0;
}
