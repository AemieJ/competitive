#include<bits/stdc++.h>
#include <type_traits>

using namespace std;

template <typename T>
class Data {
    private:
        vector<T> data;        
    public:
        Data();
        void add(T val); 
        int generateRandom(int upperRange);
        void popRandom();
        void print();
};

template <typename T>
Data<T>::Data() {};

template <typename T>
void Data<T>::add(T val) {
    constexpr bool isEmpty = is_empty<T>::value;
    if (isEmpty) {
        cout << "Access Denied - Value can't be empty" << endl;
        return;
    }
    data.push_back(val);
    print();
}

template <typename T>
int Data<T>::generateRandom(int upperRange) {
    // random_device rd;
    // mt19937 gen(rd());
    // uniform_int_distribution<int> generateRand(0, upperRange);
    return rand() % (upperRange - 0 + 1);
}

template <typename T>
void Data<T>::popRandom() {
    if (data.size() == 0) {
        cout << "Acess Denied - No value in data structure" << endl;
        return;
    }
    int randVal = generateRandom(data.size()-1);
    T val = data[randVal];
    data.erase(data.begin() + randVal);
    print();
}

template <typename T>
void Data<T>::print() {
    for(auto x: data) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    Data<int> d;
    d.add(3);
    d.add(5);
    d.add(-1);
    d.popRandom();
    d.add(8);
    d.popRandom();
    d.add(1);
    d.add(2);
    d.add(7);
    d.add(6);
    d.popRandom();
    return 0;
}