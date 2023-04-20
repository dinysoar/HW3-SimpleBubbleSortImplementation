#include <vector>
#include <iostream>
#include <cctype>
#include <string>
#include <cstring>
using namespace std;


struct MONTHLYTEMPNUMS
{
	double TOTALRAINFALL;
	double HIGHTEMP;
	double LOWTEMP;
};

void sortArray(MONTHLYTEMPNUMS array[], int size, string arr[]);
void sortArrayLow(MONTHLYTEMPNUMS array[], int size, string arr1[]);

int main()
{
	MONTHLYTEMPNUMS temp[12];
	const int SIZE = 12;
	string MONTHS[SIZE] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	//string MONTHS1[SIZE] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	double TOTAL = 0;
	double MHIMLO = 0;
	double TOTML = 0;
	cout << "Enter the following information: " << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Month " << (i + 1) << endl;
		cout << "	Total Rainfall: ";
		cin >> temp[i].TOTALRAINFALL;
		while (temp[i].TOTALRAINFALL < 0 || temp[i].TOTALRAINFALL > 10000)
		{
			cout << "	Please enter a number between 0 & 10000: ";
			cin >> temp[i].TOTALRAINFALL;
		}
		cout << "	High Temperature: ";
		cin >> temp[i].HIGHTEMP;
		while (temp[i].HIGHTEMP < -100 || temp[i].HIGHTEMP > 140)
		{
			cout << "	Please enter a number between -100 & 140: ";
			cin >> temp[i].HIGHTEMP;
		}
		cout << "	Low Temperature: ";
		cin >> temp[i].LOWTEMP;
		while (temp[i].LOWTEMP < -100 || temp[i].LOWTEMP > 140)
		{
			cout << "	Please enter a number between -100 & 140: ";
			cin >> temp[i].LOWTEMP;
		}
		TOTAL += temp[i].TOTALRAINFALL;
		MHIMLO = (temp[i].LOWTEMP + temp[i].HIGHTEMP) / 2;
		TOTML = TOTML + MHIMLO;

	}
	cout << "Total Rainfall: " << TOTAL << endl;
	cout << "Average Monthly Rain: " << (int(TOTAL / SIZE)) << endl;
	cout << "Average monthly average temperature: " << TOTML / 12 << endl;
	sortArray(temp, SIZE, MONTHS);
	cout << "Highest Temperature: " << temp[SIZE - 1].HIGHTEMP << " <" + MONTHS[SIZE - 1] + ">" << endl;
	sortArrayLow(temp, SIZE, MONTHS);
	cout << "Lowest temperature: " << temp[0].LOWTEMP << " <" + MONTHS[0] + ">" << endl;


	return 0;
}

void sortArray(MONTHLYTEMPNUMS array[], int size, string arr[])
{
	bool swap;
	MONTHLYTEMPNUMS temp;
	string MONTHS;
	do
	{
		swap = false;
		for (int count = 0; count < (size - 1); count++)
		{
			if (array[count].HIGHTEMP > array[count + 1].HIGHTEMP)
			{
				temp = array[count];
				MONTHS = arr[count];
				array[count] = array[count + 1];
				arr[count] = arr[count + 1];
				array[count + 1] = temp;
				arr[count + 1] = MONTHS;
				swap = true;
			}
		}
	} while (swap);
}

void sortArrayLow(MONTHLYTEMPNUMS array[], int size, string arr1[])
{
	bool swap;
	MONTHLYTEMPNUMS temp;
	string MONTHS;
	do
	{
		swap = false;
		for (int count = 0; count < (size - 1); count++)
		{
			if (array[count].LOWTEMP > array[count + 1].LOWTEMP)
			{
				temp = array[count];
				MONTHS = arr1[count];
				array[count] = array[count + 1];
				arr1[count] = arr1[count + 1];
				array[count + 1] = temp;
				arr1[count + 1] = MONTHS;
				swap = true;
			}
		}
	} while (swap);
}