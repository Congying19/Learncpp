#include<iostream>
#include"sales.h"

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double vals1[12] = {
		1220,1110,1120,1130,7711,1111,
		1211,5555,1231,2000,2010,3020
	};

	double vals2[12] = {
		10,22,33,11,44,25,
		28,29,52,26,24,21
	};

	Sales sales1(2011, vals1, 12);
	LabeledSales sales2("Blogstar", 2012, vals2, 12);

	cout << "First try block:\n";
	try {
		int i;
		cout << "Year = " << sales1.Year() << endl;
		for (i = 0; i < 12; ++i)
		{
			cout << sales1[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "Year = " << sales2.Year() << endl;
		cout << "Label = " << sales2.Label() << endl;
		for (i = 0; i <= 12; i++)
		{
			cout << sales2[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "End of try block 1.\n";
	}
	catch (LabeledSales::nbad_index& bad)
	{
		cout << bad.what();
		cout << "Company: " << bad.label_val() << endl;
		cout << "bad index: " << bad.bi_val() << endl;
	}
	catch (Sales::bad_index& bad)
	{
		cout << bad.what();
		cout << "bad index: " << bad.bi_val() << endl;
	}
	cout << "Next try block:\n";
	try {
		sales2[2] = 37.5;
		sales1[20] = 233345;
		cout << "End of try block 2.\n";
	}
	catch (LabeledSales::nbad_index& bad)
	{
		cout << bad.what();
		cout << "Company: " << bad.label_val() << endl;
		cout << "bad index: " << bad.bi_val() << endl;
	}
	catch (Sales::bad_index& bad)
	{
		cout << bad.what();
		cout << "bad index: " << bad.bi_val() << endl;
	}
	cout << "done\n";
	return 0;
}