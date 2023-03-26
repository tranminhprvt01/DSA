#include <bits/stdc++.h>

using namespace std;

const int M = 1e6+13;

long long sqr(long long x) {
    return (x%M*x%M)%M;
}

int pow(int a, int b, int MOD) {
    if (b == 0) return 1 % MOD;
    else
        if (b % 2 == 0)
            return sqr(pow(a, b/2, MOD)) % MOD;
        else
            return a * (sqr(pow(a, b/2, MOD)) % MOD) % MOD;
}


class HashTable {
private:
    list<string> table[M];

    //Hashing Function
    int hash(string key) {
        int res = 0;
        for (int i = 0; i < key.length(); i++) {
            if (key[i] == '1') {
                res += pow(2, 99 - i, M);
        }
    }
    return res % M;
}

public:

    //Handle hash collision by chaining
    void insert(string key) {
        int index = hash(key);
        table[index].push_back(key);
    }

    //Look up for value in HashTable
    bool search(string key) {
        int index = hash(key);
        for (string k : table[index]) {
            if (k == key) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    HashTable ht;

    ht.insert("101010");
    ht.insert("110011");
    ht.insert("111000");
    ht.insert("011001");

    cout << ht.search("101010") << endl; //expected value : 1
    cout << ht.search("110010") << endl; //expected value : 0

    return 0;
}
