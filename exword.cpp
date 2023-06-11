#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

bool canSpellWord(const string& word, const unordered_set<char>& blocks) {
    unordered_set<char> usedBlocks;

    for (char ch : word) {
        ch = tolower(ch);  

        if (blocks.count(ch) == 0) {
            return false;  
        }

        if (usedBlocks.count(ch) > 0) {
            return false;  
        }

        usedBlocks.insert(ch);
    }

    return true;
}

int main() {
    unordered_set<char> blocks;
    for (char ch : {'b', 'o', 'x', 'k', 'd', 'q', 'c', 'p', 'n', 'a', 'g', 't', 'r', 'e', 'f', 's', 'j', 'w', 'h', 'u', 'v', 'i', 'l', 'y', 'z', 'm'}) {
        blocks.insert(ch);
    }

    string word;
    cout << "Введите слово: ";
    cin >> word;

    if (canSpellWord(word, blocks)) {
        cout << "Можно составить слово." << endl;
    } else {
        cout << "Невозможно составить слово." << endl;
    }

    return 0;
}
//Введите слово: block
//Можно составить слово.

//Введите слово: door
//Невозможно составить слово.