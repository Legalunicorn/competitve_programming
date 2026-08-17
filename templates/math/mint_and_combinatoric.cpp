#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
Created: 2025-12-30 03:38:38
File: mint_and_combinatoric
Author: taken from tinle 
Test status: 
Description: 
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/
*/


//SNIPPET_ID:mint_and_combinatoric
// TEMPLATE FROM TIN_LE 
template <int MOD>
struct mod_int {
    int value;
    
    mod_int(ll v = 0) { value = int(v % MOD); if (value < 0) value += MOD; }
    
    mod_int& operator+=(const mod_int &other) { value += other.value; if (value >= MOD) value -= MOD; return *this; }
    mod_int& operator-=(const mod_int &other) { value -= other.value; if (value < 0) value += MOD; return *this; }
    mod_int& operator*=(const mod_int &other) { value = int((ll)value * other.value % MOD); return *this; }
    mod_int pow(ll p) const { mod_int ans(1), a(*this); while (p) { if (p & 1) ans *= a; a *= a; p /= 2; } return ans; }
    
    mod_int inv() const { return pow(MOD - 2); }
    mod_int& operator/=(const mod_int &other) { return *this *= other.inv(); }
    
    friend mod_int operator+(mod_int a, const mod_int &b) { a += b; return a; }
    friend mod_int operator-(mod_int a, const mod_int &b) { a -= b; return a; }
    friend mod_int operator*(mod_int a, const mod_int &b) { a *= b; return a; }
    friend mod_int operator/(mod_int a, const mod_int &b) { a /= b; return a; }
    
    bool operator==(const mod_int &other) const { return value == other.value; }
    bool operator!=(const mod_int &other) const { return value != other.value; }
    bool operator<(const mod_int &other) const { return value < other.value; }
    bool operator>(const mod_int &other) const { return value > other.value; }
    bool operator<=(const mod_int &other) const { return value <= other.value; }
    bool operator>=(const mod_int &other) const { return value >= other.value; }
    
    mod_int operator&(const mod_int &other) const { return mod_int((ll)value & other.value); }
    mod_int& operator&=(const mod_int &other) { value &= other.value; return *this; }
    mod_int operator|(const mod_int &other) const { return mod_int((ll)value | other.value); }
    mod_int& operator|=(const mod_int &other) { value |= other.value; return *this; }
    mod_int operator^(const mod_int &other) const { return mod_int((ll)value ^ other.value); }
    mod_int& operator^=(const mod_int &other) { value ^= other.value; return *this; }
    mod_int operator<<(int shift) const { return mod_int(((ll)value << shift) % MOD); }
    mod_int& operator<<=(int shift) { value = int(((ll)value << shift) % MOD); return *this; }
    mod_int operator>>(int shift) const { return mod_int(value >> shift); }
    mod_int& operator>>=(int shift) { value >>= shift; return *this; }
 
    mod_int& operator++() { ++value; if (value >= MOD) value = 0; return *this; }
    mod_int operator++(int) { mod_int temp = *this; ++(*this); return temp; }
    mod_int& operator--() { if (value == 0) value = MOD - 1; else --value; return *this; }
    mod_int operator--(int) { mod_int temp = *this; --(*this); return temp; }
 
    explicit operator ll() const { return (ll)value; }
    explicit operator int() const { return value; }
	explicit operator double() const { return (double)value; }
 
    friend mod_int operator-(const mod_int &a) { return mod_int(0) - a; }
    friend std::ostream& operator<<(std::ostream &os, const mod_int &a) { os << a.value; return os; }
    friend std::istream& operator>>(std::istream &is, mod_int &a) { ll v; is >> v; a = mod_int(v); return is; }
};
// EDIT
using mint = mod_int<EDIT_HERE>;


// CHECK
const int MX = 1e5+5;
template<class T>
class Combinatoric {
    public: 
    int N;  
    vector<T> fact, inv;
    Combinatoric(int _N) : N(_N) {
        fact.resize(N + 1), inv.resize(N + 1);
        init();
    }

    void init() {
        fact[0] = 1;
        for(int i = 1; i <= N; i++) {
            fact[i] = fact[i - 1] * i;
        }
        inv[N] = fact[N].inv();
        for(int i = N - 1; i >= 0; i--) {
            inv[i] = inv[i + 1] * (i + 1);
        }
    }

    T nCk(int a, int b) {
        if(a < b) return 0;
        return fact[a] * inv[b] * inv[a - b];
    }
 
    T nPk(int n, int k) {
        if (k < 0 || k > n) return 0; 
        return fact[n] * inv[n - k];
    }
 
}; 
Combinatoric<mint> comb(MX-1);
//END_SNIPPET:mint_and_combinatoric


// FOR TESTING 
void solve(){
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T =1;
    // cin >> T; 
    while(T--){
        solve();
    }
    return 0;
}



