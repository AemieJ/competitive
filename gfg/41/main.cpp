// HIGHLY IMPORTANT QUEUE(DOUBLE LINKED LIST) + HASHMAP QUES
#include<bits/stdc++.h>

using namespace std;

class Cache {
    private:
        list<pair<string, int>> l;
        unordered_map<string, list<pair<string, int>>::iterator> m;
        int capacity;
    public:
        Cache(int c);
        void insert(const string &a, int val);
        int get(const string &a);
        void set(const string &a, int val);
        void erase(const string &a);
        void print();
};

Cache::Cache(int c): capacity(c) {};

void Cache::insert(const string &a, int val) {
    l.push_back({a, val});
    m[a] = (--l.end());

    if (l.size() > capacity) {
        auto i = l.front();
        l.pop_front();
        m.erase(i.first);
    }
}

int Cache::get(const string &a) {
    if (m.find(a) == m.end()) return -1;
    auto itr = m[a];
    l.erase(itr);
    insert(a, itr->second);
    return itr->second;
}

void Cache::set(const string &a, int val) {
    if (m.find(a) == m.end()) {
        insert(a, val);
        return;
    }
    auto itr = m[a];
    l.erase(itr);
    m.erase(a);
    insert(a, val);
}

void Cache::erase(const string &a) {
    if (m.find(a) == m.end()) return;
    auto itr = m[a];
    m.erase(a);
    l.erase(itr);
}

void Cache::print() {
    for(auto it = l.rbegin(); it != l.rend(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
}

int main() {
    Cache c(3);
    c.set("User1", 22);
    c.set("User2", 20);
    c.set("User3", 21);
    c.set("User4", 19);
    c.print();
    cout << c.get("User1") << endl;
    cout << c.get("User2") << endl;
    c.erase("User2");
    c.print();
    return 0;
}