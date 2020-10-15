#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

int numbers[10] = {0, 1, 2 ,3, 4, 5, 6, 7, 8, 9};
char operators[4] = {'+', '-', '*', '/'};
double num;

vector<string> getInput(string a) {
	vector<string> exp;
	string tmp = "";
	// parse the input line and convert into parts
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != ' ') {
			tmp += a[i];
		} else {
			exp.push_back(tmp);
			tmp = "";
		}
	}
	exp.push_back(tmp);
	return exp;
}

bool checkInt(string &a) {
	// check if the given string is number or a not
	for (int j = 0; j < a.size(); j++) {
		if (a[j] == '.')
			continue;
		if (a[j] - '0' >= 0 && a[j] - '0' <= 9) {
			continue;
		} else {
			cout << "Error: " << a << " is invalid\n";
			return false;
		}
	}
	return true;
}

bool checkErrors(vector<string> a) {
	if (a.size() < 3) {
		// cout << "size of a is: " << a.size() << " ";
		// cout << "printing a: " << a[0] << ", " << a[1] << "\n";
		return false;
	}

	for (int i = 0; i < a.size(); i++) {
		if (i % 2 == 0) {
			if (a[i].size() > 15) {
				cout << "Error: " << a[i] << " too long\n";
				return false;
			}
			if (!checkInt(a[i])) return false;
		} else {
			if (a[i].size() > 1) {
				cout << "Error: Invalid operator " << a[i] << "\n";
				return false;
			}
			// if (checkInt(a[i])) return false;
			bool ok = false;
			for (int j = 0; j < 4; j++) {
				char tmp = a[i][0];

				if (tmp == operators[j]) {
					ok = true;
					break;
				}
			}

			if (!ok) {
				cout << "Error: " << a[i][1] << " Not defined\n";
			}
		}
	}
	return true;
}

int main() {
	freopen("lol.kai", "r", stdin);
	string x;
	getline(cin, x);
	if (x != "BEGIN") {
		cout << "Parse Error: Unexpected " << x << "\n";
		return 0;
	}

	while (x != "END") {
		string a;
		getline(cin, a);
		// cout << "Printing A.. " << a << "\n";
		if (a == "BEGIN")
			continue;
		if (a == "END")
			break;

		vector<string> exp = getInput(a); // splits the input string

		// cout << "Printing exp...\n";

/* 		for (auto x: exp) {
			cout << x << ", ";
		} */

		// cout << "\n";	

		bool ok = checkErrors(exp);
		if (!ok) {
			cout << "Terminating program\n";
			x = "END";
		}

		string before = " ";
		for (int i = 0; i < exp.size()-1; i++) {
			string current = exp[i];

			if (i == 0) {
				num = stod(exp[i]);
				current = exp[i+1];
				continue;
			}

			if (i % 2 != 0) {
				if (current == "+") {
					double curr = stod(exp[i+1]);
					num += curr;
				} else if (current == "-") {
					double curr = stod(exp[i+1]);
					num -= curr;
				} else if (current == "*") {
					double curr = stod(exp[i+1]);
					num *= curr;
				} else {
					double curr = stod(exp[i+1]);
					num /= curr;
				}
			}

		}

	}

	cout << num << "\n";
	return 0;

}
