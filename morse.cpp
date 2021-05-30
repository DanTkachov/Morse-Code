#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <regex>
#include <vector>
using namespace std;
void translate();
void decoder();
void menu() {
	cout << "Menu: type \\help for help \nType 1 to translate (English --> Morse)\nType 2 to decode (Morse --> English) \n -->:";
	string test;
	cin >> test;
	regex i("\\help", regex_constants::icase);
	smatch match;

	if (regex_search(test, match, i) == true)
	{
		cout << "help worked!";
	}
	else if (test == "1") {
		translate();
	}
	else if (test == "2") {
		decoder();
	}
}
map<char, string> keyTranslate() {
	map<char, string> key;
	key['A'] = ".-";
	key['B'] = "-...";
	key['C'] = "-.-.";
	key['D'] = "-..";
	key['E'] = ".";
	key['F'] = "..-.";
	key['G'] = "--.";
	key['H'] = "....";
	key['I'] = "..";
	key['J'] = ".---";
	key['K'] = "-.-";
	key['L'] = ".-..";
	key['M'] = "--";
	key['N'] = "-.";
	key['O'] = "---";
	key['P'] = ".--.";
	key['Q'] = "--.-";
	key['R'] = ".-.";
	key['S'] = "...";
	key['T'] = "-";
	key['U'] = "..-";
	key['V'] = "...-";
	key['W'] = ".--";
	key['X'] = "-..-";
	key['Y'] = "-.--";
	key['Z'] = "--..";
	key['1'] = ".----";
	key['2'] = "..---";
	key['3'] = "...--";
	key['4'] = "....-";
	key['5'] = ".....";
	key['6'] = "-....";
	key['7'] = "--...";
	key['8'] = "---..";
	key['9'] = "----.";
	key['0'] = "-----";
	key['.'] = ".-.-.-";
	key[','] = "--..--";
	key['?'] = "..--..";
	return key;
}
void translate() {
	map<char, string> key = keyTranslate();
	string input;
	cin.ignore();
	cout << "Input English Phrase: ";
	getline(cin, input);
	for (int i = 0; i < input.length(); i++)
	{
		if (key.find(toupper(input[i])) != key.end())
		{
			cout << key.find(toupper(input[i]))->second << " ";
		}
		else if (input[i] == ' ') {
			cout << " / ";
		}
	}
}
map<string, char> keyDecode() {
	map<string, char> key;
	key[".-"] = 'A';
	key["-..."] = 'B';
	key["-.-."] = 'C';
	key["-.."] = 'D';
	key["."] = 'E';
	key["..-."] = 'F';
	key["--."] = 'G';
	key["...."] = 'H';
	key[".."] = 'I';
	key[".---"] = 'J';
	key["-.-"] = 'K';
	key[".-.."] = 'L';
	key["--"] = 'M';
	key["-."] = 'N';
	key["---"] = 'O';
	key[".--."] = 'P';
	key["--.-"] = 'Q';
	key[".-."] = 'R';
	key["..."] = 'S';
	key["-"] = 'T';
	key["..-"] = 'U';
	key["...-"] = 'V';
	key[".--"] = 'W';
	key["-..-"] = 'X';
	key["-.--"] = 'Y';
	key["--.."] = 'Z';
	key[".----"] = '1';
	key["..---"] = '2';
	key["...--"] = '3';
	key["....-"] = '4';
	key["....."] = '5';
	key["-...."] = '6';
	key["--..."] = '7';
	key["---.."] = '8';
	key["----."] = '9';
	key["-----"] = '0';
	key[".-.-.-"] = '.';
	key["--..--"] = ',';
	key["..--.."] = '?';
	return key;
}
void decoder() {
	map<string, char> key = keyDecode();
	string input;
	cin.ignore();
	getline(cin, input);
	input += ' '; // else if will now read every char
	string let;
	for (int i = 0; i < input.length() + 1; i++)
	{
		if (input[i] == '.' || input[i] == '-') {
			let += input[i];
		}
		else if (input[i] == ' ' && !let.empty())
		{
			if (key.find(let) != key.end()) {
				cout << key.find(let)->second;
			}
			else {
				cout << endl << "Following character: \"" << let << "\" not recognized as morse code." << endl;
			}
			let.clear();
		}
		else if (input[i] == '/') {
			cout << " ";
		}
	}
}
int main() {
	menu();
}
