#include <iostream>
#include <algorithm>

using namespace std;


struct Node {
	char left;
	char right;
};

Node tree[26];

void Pre(char node) {
	if (node == '.') return;

	cout << node;
	Pre(tree[node - 'A'].left);
	Pre(tree[node - 'A'].right);
}

void Mid(char node) {
	if (node == '.') return;

	Mid(tree[node - 'A'].left);
	cout << node;
	Mid(tree[node - 'A'].right);
}

void Back(char node) {
	if (node == '.') return;

	Back(tree[node - 'A'].left);
	Back(tree[node - 'A'].right);
	cout << node;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		char x, y, z;
		cin >> x >> y >> z;

		tree[x - 'A'].left = y;
		tree[x - 'A'].right = z;
	}
	Pre('A');
	cout << "\n";
	Mid('A');
	cout << "\n";
	Back('A');
	cout << "\n";
}