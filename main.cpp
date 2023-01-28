#include <iostream>
#include "Trie.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	TrieNode* root = getNewNode();

	insert(root, "hello");
	insert(root, "car");
	insert(root, "cool");
	insert(root, "cold");
	insert(root, "good");
	insert(root, "water");
	insert(root, "fire");
	insert(root, "house");
	insert(root, "ball");
	insert(root, "cola");
	insert(root, "weather");
	insert(root, "bus");
	insert(root, "ice");
	insert(root, "telephone");
	while (true)
	{
		string key;
		string d;
		int operation = 0;
		cout << "-----Введите нужную операцю-----" << endl;
		cout << "1 - Поиск слов" << endl;
		cout << "0 - Выход" << endl;
		cin >> operation;
		if (operation != 1 && operation != 0)
		{
			cout << "Такой операции нет!" << endl;
			continue;
		}
		if (operation == 0) 
		{ 
			break; 
		}
		if (operation == 1)
		{
			cout << endl;
			cout << "Введите часть слова для поиска: " << endl;
			getline(cin, d, '\n');
			getline(cin, key, '\n');
			find_words(root, key);
		}
	}
	return 0;
}