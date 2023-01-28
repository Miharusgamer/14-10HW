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
		cout << "-----������� ������ �������-----" << endl;
		cout << "1 - ����� ����" << endl;
		cout << "0 - �����" << endl;
		cin >> operation;
		if (operation != 1 && operation != 0)
		{
			cout << "����� �������� ���!" << endl;
			continue;
		}
		if (operation == 0) 
		{ 
			break; 
		}
		if (operation == 1)
		{
			cout << endl;
			cout << "������� ����� ����� ��� ������: " << endl;
			getline(cin, d, '\n');
			getline(cin, key, '\n');
			find_words(root, key);
		}
	}
	return 0;
}