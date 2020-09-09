#include<bits/stdc++.h>

using namespace std;

/*Complete the function below 
Which contains 2 arguments 
1) root of the tree formed while encoding
2) Encoded String*/
string decode_file(struct MinHeapNode* root, string s) {
    string res;
    struct MinHeapNode* curr = root;
    for(int i = 0; i < s.length(); ++i) {
        if (s[i] == '0') curr = curr->left;
        if (s[i] == '1') curr= curr->right;
        if (curr->left == NULL && curr->right == NULL) {
            res += curr->data;
            curr = root;
        }
    }
    return res;
}

int main() {
    return 0;
}