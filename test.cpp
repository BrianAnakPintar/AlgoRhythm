#include <bits/stdc++.h>
using namespace std;

typedef __int128_t i128;
typedef int64_t i64;

#define int int64_t
#define all(a) a.begin(),a.end()
#define pb push_back
#define sz(a) ((int)a.size())

std::ostream& operator<<(std::ostream& os, i128 n) {
    std::string s;
    while (n) {
        s += '0' + n % 10;
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, vector<T>& a) {
    for (T i : a) os << i << " ";
    return os << "\n";
}

template <typename T>
std::istream& operator>>(std::istream& is, vector<T>& a) {
    for (T& i : a) is >> i;
    return is;
}

void no() {
    cout << "NO\n";
}

void yes() {
    cout << "YES\n";
}

template<class T>
constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

constexpr i64 mul(i64 a, i64 b, i64 p) {
    i64 res = a * b - i64(1.L * a * b / p) * p;
    res %= p;
    if (res < 0) {
        res += p;
    }
    return res;
}

template<i64 P>
struct MLong {
    i64 x;
    constexpr MLong() : x{} {}
    constexpr MLong(i64 x) : x{ norm(x % getMod()) } {}

    static i64 Mod;
    constexpr static i64 getMod() {
        if (P > 0) {
            return P;
        }
        else {
            return Mod;
        }
    }
    constexpr static void setMod(i64 Mod_) {
        Mod = Mod_;
    }
    constexpr i64 norm(i64 x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }
    constexpr i64 val() const {
        return x;
    }
    explicit constexpr operator i64() const {
        return x;
    }
    constexpr MLong operator-() const {
        MLong res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MLong inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr MLong& operator*=(MLong rhs)& {
        x = mul(x, rhs.x, getMod());
        return *this;
    }
    constexpr MLong& operator+=(MLong rhs)& {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MLong& operator-=(MLong rhs)& {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MLong& operator/=(MLong rhs)& {
        return *this *= rhs.inv();
    }
    friend constexpr MLong operator*(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MLong operator+(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MLong operator-(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MLong operator/(MLong lhs, MLong rhs) {
        MLong res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream& operator>>(std::istream& is, MLong& a) {
        i64 v;
        is >> v;
        a = MLong(v);
        return is;
    }
    friend constexpr std::ostream& operator<<(std::ostream& os, const MLong& a) {
        return os << a.val();
    }
    friend constexpr bool operator==(MLong lhs, MLong rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MLong lhs, MLong rhs) {
        return lhs.val() != rhs.val();
    }
};

template<>
i64 MLong<0LL>::Mod = i64(1E18) + 9;

template<int P>
struct MInt {
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(i64 x) : x{ norm(x % getMod()) } {}

    static int Mod;
    constexpr static int getMod() {
        if (P > 0) {
            return P;
        }
        else {
            return Mod;
        }
    }
    constexpr static void setMod(int Mod_) {
        Mod = Mod_;
    }
    constexpr int norm(int x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }
    constexpr int val() const {
        return x;
    }
    explicit constexpr operator int() const {
        return x;
    }
    constexpr MInt operator-() const {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MInt inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr MInt& operator*=(MInt rhs)& {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }
    constexpr MInt& operator+=(MInt rhs)& {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt& operator-=(MInt rhs)& {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt& operator/=(MInt rhs)& {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream& operator>>(std::istream& is, MInt& a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream& operator<<(std::ostream& os, const MInt& a) {
        return os << a.val();
    }
    friend constexpr bool operator==(MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
};

template<>
int MInt<0>::Mod = 1000000007;

template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();

constexpr int P = 1000000007;
using Z = MInt<P>;

double ES;
double EX;

double y(int n, int k) {
    if (k == 0) {
        return (n + 1) / 2 * EX;
    }
    if (n == 0) {
        return 0;
    }
    double ret = (double(k) / n) * (EX + y(n - 1, k - 1)) + (double(1) - (double(k) / n)) * (k * ES + (n - k) * EX - y(n - 1, k));
    return ret;
}

vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31;
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T));
    p_pow[0] = 1;
    for (int i = 1; i < (int)p_pow.size(); i++)
        p_pow[i] = (p_pow[i - 1] * p) % m;

    vector<long long> h(T + 1, 0);
    for (int i = 0; i < T; i++)
        h[i + 1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
    long long h_s = 0;
    for (int i = 0; i < S; i++)
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;

    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++) {
        long long cur_h = (h[i + S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurrences.push_back(i);
    }
    return occurrences;
}

int p = 31;
int mod = 1e9 + 9;

int myHash(string s) {
    int n = s.size();

    int ret = 0;
    int pow = 1;
    for (int i = 0; i < n; i++) {
        ret += (s[i] - 'a' + 1) * pow % mod;
        pow = (pow * p) % mod;
    }

    return ret;
}

vector<int> myHashPreFix(string s) {


    int n = s.size();

    vector<int> ret(n + 1);
    int sum = 0;
    int pow = 1;
    for (int i = 0; i < n; i++) {
        sum += (s[i] - 'a' + 1) * pow % mod;
        pow = (pow * p) % mod;
        ret[i + 1] = sum;
    }

    return ret;
}

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

vector<int> rabin_karp2(string const& s, string const& t) {
    int n = s.size();
    int m = t.size();

    if (n > m) return {};

    int hashOfS = myHash(s);
    vector<int> hashOfT = myHashPreFix(t);

    cout << hashOfT << "\n";

    int ppow = 1;
    for (int i = 1; i <= m; i++) {
        ppow = (ppow * p) % mod;
    }
    int pinvn = binpow(ppow, mod - 2);

    vector<int> pinvpow(m + 1);
    pinvpow[m] = pinvn;
    for (int i = m - 1; i >= 0; i--) {
        pinvpow[i] = (pinvpow[i + 1] * p) % mod;
    }

    vector<int> pos = {};
    for (int i = 0; i + n < m; i++) {
        int subHash = ((hashOfT[i + n] - hashOfT[i]) * pinvpow[i]) % mod;
        if (subHash == hashOfS) {
            pos.push_back(i);
        }
        cout << "hashes: " << subHash << " " << hashOfS << "\n";
    }
    return pos;
}

void solve() {
    // s is needle, t is haystack
    string s, t; cin >> s >> t;
    auto ret = rabin_karp(s, t);
    cout << ret << "\n";
    ret = rabin_karp2(s, t);
    cout << ret << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
        // cout << "\n";
    }
}