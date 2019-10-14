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

int tree[4 * N];
int a[N];

void build(int pos, int left, int right) {
    if (left == right) {
        if (left == 1) tree[pos] = 0;
        else tree[pos] = 1e6;
        return;
    }
    int mid = (left + right) >> 1;
    build(pos * 2, left, mid);
    build(pos * 2 + 1, mid + 1, right);
    tree[pos] = 1e6;
}

void update(int pos, int left, int right, int x, int y, int val) {
    if (left > y || right < x) return;
    if (left >= x && right <= y) {
        tree[pos] = min(tree[pos], val);
        return;
    }
    int mid = (left + right) >> 1;
    update(pos * 2, left, mid, x, y, val);
    update(pos * 2 + 1, mid + 1, right, x, y, val);
}

void propagate(int pos) {
    tree[pos * 2] = min(tree[pos * 2], tree[pos]);
    tree[pos * 2 + 1] = min(tree[pos * 2 + 1], tree[pos]);
    tree[pos] = 1e6;
}

int query(int pos, int left, int right, int x) {
    if (left > x || right < x) return 1e6;
    if (left == right) return tree[pos];
    if (tree[pos] < 1e6) propagate(pos);
    int mid = (left + right) >> 1;
    int m = query(pos * 2, left, mid, x);
    int n = query(pos * 2 + 1, mid + 1, right, x);
    return min(m, n);
}

int solve() {
    int n = in();
    for (int i = 1; i <= n; i++) {
        a[i] = in();
    }
    build(1, 1, n);
    for (int i = 1; i < n; i++) {
        if (a[i] == 0) continue;
        int mn = query(1, 1, n, i);
        int x = i + 1, y = min(n, i + a[i]);
        update(1, 1, n, x, y, mn + 1);
    }
    int ans = query(1, 1, n, n);
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



