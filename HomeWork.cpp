#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <random>
using namespace std;



//Supporting homework functions

string file_to_string(string l) {
	string txt = "";
	if (l[l.length() - 4] == '.') {
		ifstream f(l);

		for (; ;) {
			if (!f.eof()) {
				string s;
				getline(f, s);
				for (int i = 0; i < s.length(); i++) {
					txt += s[i];
				}
			}
			else {
				break;
			}
		}
	}
	else {
		txt = l;
	}

	return txt;
}

string random_text_fragment_generator(string l) {
	string text = file_to_string(l);

	int k = 0;
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == ' ') {
			k += 1;
		}
	}

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 100 * k);
	int spaces = dis(gen) % k;

	int index = 0;

	for (int i = 0; i < text.length(); i++) {
		if (i != text.length() - 1) {
			if (text[i] == ' ') {
				spaces -= 1;
				if (spaces == 0) {
					index = i + 1;
					break;
				}
			}
		}
	}

	string txt_fragment = "";

	for (int i = index; i < text.length(); i++) {
		if (text[i] == ' ') {
			spaces += 1;
		}

		if (spaces < 4 && txt_fragment.length() < 20) {
			txt_fragment += text[i];
		}
		else {
			break;
		}
	}

	return txt_fragment;
}

int is_there_equal_elements(vector <unsigned long long> arr) {
	int ans = 0;
	for (int i = 0; i < arr.size() - 1; i++) {
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[i] == arr[j]) {
				ans += 1;
			}
		}
	}

	return ans;
}

char encoder(char a, int i) {
	char b;
	if ((int)a >= 65 && (int)a <= 90) {
		b = (char)((int(a) + i - 65) % 26 + 65);
	}
	else if ((int)a >= 97 && (int)a <= 122) {
		b = (char)((int(a) + i - 97) % 26 + 97);
	}
	//Encoder shifts the element by i

	return b;
}

char decoder(char b, int i) {
	char a;
	if ((int)b >= 65 && (int)b <= 90) {
		a = (char)(90 - abs(90 - int(b) + i) % 26);
	}
	else if ((int)b >= 97 && (int)b <= 122) {
		a = (char)(122 - abs(122 - int(b) + i) % 26);
	}

	return a;
}



//Main homework functions

unsigned long long first_a(string txt) {
	unsigned long long num = 1;

	for (int i = 0; i < txt.length(); i++) {
		num *= (unsigned long long)txt[i];
	}

	return num;
}

unsigned long long first_b(string txt, bool a = false) {
	map <char, int> matches;

	for (int i = 0; i < txt.length(); i++) {
		if (isalpha(txt[i])) {
			matches[txt[i]] += 1;
		}
	}

	string num = "";
	for (map <char, int>::iterator it = matches.begin(); it != matches.end(); it++) {
		num += to_string(it->second);
	}


	if (a == true) {
		for (map <char, int>::iterator it = matches.begin(); it != matches.end(); it++) {
			cout << it->first << " " << it->second << endl;
		}
	}


	return stoull(num);
}

void first_c(string file) {
	vector <unsigned long long> a_arr, b_arr;
	int k = 50;

	for (int i = 0; i < k; i++) {
		string txt = random_text_fragment_generator(file);
		a_arr.push_back(first_a(txt));
		b_arr.push_back(first_b(txt));
	}

	cout << (double)is_there_equal_elements(a_arr) / k * 100 << "% " << (double)is_there_equal_elements(b_arr) / k * 100 << "%" << " - first c task" << endl;
}

string second_a(string l) {
	string txt = file_to_string(l);

	for (int i = 0; i < txt.length(); i++) {
		if (isalpha(txt[i])) {
			txt[i] = encoder(txt[i], i + 1);
		}
	}

	return txt;
}

string second_b(string l) {
	string txt = file_to_string(l);

	for (int i = 0; i < txt.length(); i++) {
		if (isalpha(txt[i])) {
			txt[i] = decoder(txt[i], i + 1);
		}
	}

	return txt;
}

int main()
{
	setlocale(LC_ALL, "rus");



	string random_fragment = random_text_fragment_generator("text.txt");
	cout << random_fragment << " - random fragment" << endl << endl;

	//First A Task
	unsigned long long a = first_a(random_fragment);
	cout << a << " - first a task" << endl;

	//First B Task
	unsigned long long b = first_b(random_fragment);
	cout << b << " - first b task" << endl;

	//First C Task
	first_c("text.txt");


	cout << endl;

	//Second A Task(only for Eng)
	string changed_txt = second_a(random_fragment);
	cout << changed_txt << " - second a task" << endl;

	//Second B Task
	string returned_txt = second_b(changed_txt);
	cout << returned_txt << " - second b task" << endl;

	//Second C Task
	cout << first_b(changed_txt) << " - second ñ task" << endl;
}
