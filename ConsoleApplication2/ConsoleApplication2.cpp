

#include <iostream>
#include <string>

using namespace std;

string encrypt(string plaintext, string key) {
	string cyphertext;

	int pmodk = plaintext.size() % key.size();

	if (pmodk != 0) //padding
	{
		for (size_t i = pmodk; i < key.size(); i++)
		{
			plaintext.push_back('x');
		}
	}

	for (size_t i = 0; i < plaintext.size(); i += key.size()) //encrypting
	{
		for (size_t j = 0; j < key.size(); j++)
		{
			cyphertext.push_back(plaintext[i + (int)key[j] - 49]);
		}
	}

	return cyphertext;
}

string decrypt(string cyphertext, string key) {

	cyphertext.shrink_to_fit();

	string plaintext;
	plaintext.resize(cyphertext.size());

	for (size_t i = 0; i < cyphertext.size(); i += key.size()) //decrypting
	{
		for (size_t j = 0; j < key.size(); j++)
		{
			plaintext[i + (int)key[j] - 49] = cyphertext[i + j];
		}
	}

	while (plaintext.back() == 'x')
	{
		plaintext.pop_back();
	}

	return plaintext;
}

string generate_dkey(string ekey) {
	string dkey;

	ekey.shrink_to_fit();

	for (size_t i = 1; i < ekey.length() + 1; i++)
	{
		for (size_t j = 0; j < ekey.length(); j++)
		{
			if (ekey[j] - 48 == i) //find position of digit
			{
				dkey.push_back(j + 49);
			}
		}
	}

	return dkey;
}

int main()
{
    char menuSelect = ' ';
	while (menuSelect != 'q')
	{
		cout << "(e)ncrpyt" << endl;
		cout << "(d)ecrypt" << endl;
		cout << "(g)enerate decryption key | use encrypt to reencrypt your text, decrypt does the decrypting using the original key" << endl;
		cout << "(q)uit" << endl;
		cin >> menuSelect;

		if (menuSelect == 'e')
		{
			string plaintext;
			string key;
			cout << "plaintext: ";
			cin >> plaintext;
			cout << endl << "key: ";
			cin >> key;
			cout << endl << "encryptet: " << encrypt(plaintext, key) << endl;
		}
		else if (menuSelect == 'd')
		{
			string cyphertext;
			string key;
			cout << "cyphertext: ";
			cin >> cyphertext;
			cout << endl << "key: ";
			cin >> key;
			cout << endl << "decryptet: " << decrypt(cyphertext, key) << endl;
		}
		else if (menuSelect == 'g')
		{
			string key;
			cout << endl << "key: ";
			cin >> key;
			cout << endl << "decryption key: " << generate_dkey(key) << endl;
		}
		else if (menuSelect == 'q')
		{
			cout << "Good Bye!" << endl;
			return 0;
		}
		else
		{
			cout << "you failed, try again" << endl;
		}
	}
}

