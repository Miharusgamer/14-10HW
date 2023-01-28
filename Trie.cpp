#include <iostream>
#include "Trie.h"
using namespace std;

TrieNode* getNewNode(void)
{
    struct TrieNode* pNode = new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}

void insert(TrieNode* root, string key)
{
    TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';

        if (!node->children[index])
            node->children[index] = getNewNode();

        node = node->children[index];
    }
    node->isEndOfWord = true;
}

bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}

void find_end(TrieNode* root, char buf[], int ind, string& res, string key) {
    TrieNode* node = root;
    ind++;
    if (node->isEndOfWord == true && isEmpty(node)) {
        cout << key;
        for (int i = 0; i < ind; i++) {

            cout << buf[i];
        }
        cout << endl;
    }
    if (node->isEndOfWord == true && !isEmpty(node)) {
        {cout << key;
        for (int i = 0; i < ind; i++) {
            cout << buf[i];
        }
        cout << endl;
        }
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                char b = 'a' + i;
                buf[ind] = b;
                find_end(node->children[i], buf, ind, res, key);
                continue;
            }
        }
    }

    if (node->isEndOfWord == false) {
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                char b = 'a' + i;

                buf[ind] = b;

                find_end(node->children[i], buf, ind, res, key);
                continue;
            }
        }
    }
}

void find_words(TrieNode* root, string key) {
    struct TrieNode* node = root;
    int y = 0;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (node->children[index] == nullptr) {
            cout << "В словаре нет слова с таким ключем!" << endl;
            break;
        }
        if (node->children[index]) {
            node = node->children[index];
            y++;
        }
    }
    if (y == key.length()) {
        char buf[10];
        int ind = -1;
        string res;
        find_end(node, buf, ind, res, key);
    }
}
