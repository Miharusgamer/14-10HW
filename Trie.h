#pragma once
#ifndef TRIE_H
#define TRIE_H
#include <string>
using namespace std;

const int ALPHABET_SIZE = 26;
 
struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};

TrieNode* getNewNode(void);
void insert(TrieNode*, string);
void find_words(TrieNode* root, string key);
#endif