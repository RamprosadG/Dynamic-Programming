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

const ll inf = 1e17;
const ll mod = (ll)1e9 + 7;
const int N = 1e5 + 5;

int l[N], r[N];
int dp[N];

int tree[N];

void compress(int n) {
    vii A, B;
    for (int i = 1; i <= n; i++) {
        A.pb({l[i], i});
        B.pb({r[i], i});
    }
    sort(all(A)), sort(all(B));
    int num_a = 1, num_b = 1;
    for (int i = 0; i < n; i++) {
        if (i > 0 && A[i].ff != A[i - 1].ff) num_a++;
        if (i > 0 && B[i].ff != B[i - 1].ff) num_b++;
        l[A[i].ss] = num_a, r[B[i].ss] = num_b;
    }
}

void update(int n, int x, int val) {
    while (x <= n) {
        tree[x] = max(tree[x], val);
        x += (x & -x);
    }
}

void update2(int n, int x) {
    while (x <= n) {
        tree[x] = 0;
        x += (x & -x);
    }
}

int query(int x) {
    int mx = 0;
    while (x > 0) {
        mx = max(mx, tree[x]);
        x -= (x & -x);
    }
    return mx;
}

int n;
vector<pair<pii, int > > tem, seg;

void calc(int left, int right) {
    int mid = (left + right) >> 1;
    tem.clear(), seg.clear();
    for (int i = left; i <= mid; i++) {
        tem.pb({{l[i], r[i]}, dp[i]});
    }
    sort(all(tem));
    for (int i = mid + 1; i <= right ; i++) {
        seg.pb({{l[i], r[i]}, i});
    }
    sort(all(seg));
    for (int i = 0, j = 0; i < (int)seg.size(); i++) {
        while (j < (int)tem.size() && tem[j].ff.ff < seg[i].ff.ff) {
            update(n, tem[j].ff.ss, tem[j].ss);
            j++;
        }
        dp[seg[i].ss] = max(dp[seg[i].ss], query(seg[i].ff.ss - 1) + 1);
    }
    for (int i = 0; i < tem.size(); i++) {
        update2(n, tem[i].ff.ss);
    }
}

void divide(int left, int right) {
    if (left == right) return;
    int mid = (left + right) >> 1;
    divide(left, mid);
    calc(left, right);
    divide(mid + 1, right);
}

int solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &l[i], &r[i]);
        dp[i] = 1;
    }
    compress(n);
    divide(1, n);
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
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