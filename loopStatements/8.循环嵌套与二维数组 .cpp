#include<iostream>
using namespace std;
const int Cities = 5;
const int Years = 4;

int main() {
	const char* cities[Cities] = {
		"Beijing",
		"Nanjing",
		"Shandong",
		"Henan",
		"Dalian"
	};//�������Ϊ��ά���� cities[1]��ʾchar����һά���飬���ַ���
	int maxtemps[Years][Cities] = {
		{90,81,78,99,51},
		{98,89,99,85,88},
		{101,111,18,88,95},
		{48,59,89,99,87}
	};

	cout << "Maximum temperatures for 2008-2011\n\n";
	for (int city = 0; city < Cities; ++city) {
		cout << cities[city] << ":\t";
		for (int year = 0; year < Years; ++year) {
			cout << maxtemps[year][city] << "\t";
		}
		cout << endl;
	}
	return 0;
}