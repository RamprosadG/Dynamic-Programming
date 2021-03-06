#include<bits/stdc++.h>
using namespace std;

#define ll             long long
#define LL             long long
#define gcd(a,b)       __gcd(a, b)
#define lcm(a,b)       a * (b / gcd(a, b))
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
#define all(v)         v.begin(), v.end()
#define fill(a, b)     memset(a, b, sizeof a)
#define smax(a, b)     a = max(a, b)
#define smin(a, b)     a = min(a, b)
#define sqr(x)         x * x
#define cube(x)        x * x * x
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

const ll inf = (ll)1e17;
const ll mod = (ll)1e9 + 7;
const int N = 2e5 + 5;

int a[N], dp[N];
vii tem;
vi mn;

int bs(int x) {
    int low = 0, high = tem.size() - 1, ans = 1e6;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (tem[mid].ff >= x) ans = mn[mid], low = mid + 1;
        else high = mid - 1;
    }
    return ans;
}

void call(int left, int right) {
    tem.clear(), mn.clear();
    int mid = (left + right) >> 1;
    for (int i = left; i <= mid; i++) {
        tem.pb({a[i] + i - mid, dp[i]});
    }
    sort(all(tem));
    reverse(all(tem));
    for (int i = 0; i < tem.size(); i++) {
        if (i == 0) mn.pb(tem[i].ss);
        else mn.pb(min(mn.back(), tem[i].ss));
    }
    for (int i = mid + 1; i <= right; i++) {
        dp[i] = min(dp[i], bs(i - mid) + 1);
    }
}

void divide(int left, int right) {
    if (left == right) return;
    int mid = (left + right) >> 1;
    divide(left, mid);
    call(left, right);
    divide(mid + 1, right);
}

int solve() {
    int n = in();
    for (int i = 1; i <= n; i++) {
        a[i] = in();
        dp[i] = 1e6;
    }
    dp[1] = 0;
    divide(1, n);
    printf("%d\n", dp[n]);
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


