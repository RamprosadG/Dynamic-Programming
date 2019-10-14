#include<bits/stdc++.h>
using namespace std;

#define ll             long long
#define LL             long long
#define gcd(a,b)       __gcd(a,b)
#define lcm(a,b)       a*(b/gcd(a,b))
#define pii            pair<int, int>
#define pll            pair<ll, ll>
#define pil            pair<int, ll>
#define pli            pair<ll, int>
#define vi             vector<int>
#define vl             vector<ll>
#define vii            vector<pii>
#define vll            vector<pll>
#define vil            vector<pil>
#define vli            vector<pli>
#define pb             push_back
#define ppb            pop_back
#define mp             make_pair
#define ff             first
#define ss             second
#define all(v)         v.begin(),v.end()
#define fill(a,b)      memset(a,b,sizeof a)
#define smax(a, b)     a=max(a, b)
#define smin(a, b)     a=min(a, b)
#define sqr(x)         x*x
#define cube(x)        x*x*x
#define endl           '\n'

int in() {
    int n;
    scanf("%d", &n);
    return n;
}

ll Lin() {
    ll n;
    scanf("%lld", &n);
    return n;
}

double Din() {
    double n;
    scanf("%lf", &n);
    return n;
}

const ll inf = 1e17;
const ll mod = (ll)1e9 + 7;
const int N = 2e5 + 5;

int Set(int mask, int pos) {
    return mask = (mask | (1 << pos));
}

int Reset(int mask, int pos) {
    return mask = (mask & ~ (1 << pos));
}

bool Check(int mask, int pos) {
    return (bool)(mask & (1 << pos));
}

int n, dis[20][20];
ll dp[1 << 20 + 2][20];

ll tsp(int mask, int at) {
    if (mask == (1 << n) - 1) return (ll)dis[at][0];
    if (dp[mask][at] != -1) return dp[mask][at];
    ll res = inf;
    for (int i = 0; i < n; i++) {
        if (Check(mask, i) == 0) {
            res = min(res, tsp(Set(mask, i), i) + dis[at][i]);
        }
    }
    return dp[mask][at] = res;
}

int solve() {
    n = in();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dis[i][j] = in();
        }
    }
    fill(dp, -1);
    printf("%lld\n", tsp(1, 0));
    return 0;
}

int main() {
    int test = 1, tc = 0;
    while (test--) {
        //printf("Case %d: ", ++tc);
        solve();
    }
    return 0;
}
