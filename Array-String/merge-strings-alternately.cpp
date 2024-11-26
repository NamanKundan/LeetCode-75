#include <iostream>
#include <string>
using namespace std;

string mergeAlternately(string word1, string word2) {
    string merged = "";
    int i = 0, j = 0;

    // Merging letters from both strings alternately
    while (i < word1.size() && j < word2.size()) {
        merged += word1[i++];
        merged += word2[j++];
    }

    // Appending remaining letters from word1 if any
    while (i < word1.size()) {
        merged += word1[i++];
    }

    // Appending remaining letters from word2 if any
    while (j < word2.size()) {
        merged += word2[j++];
    }

    return merged;
}

int main() {
    string word1 = "abc";
    string word2 = "pqr";
    cout << "Merged string: " << mergeAlternately(word1, word2) << endl;
    return 0;
}
