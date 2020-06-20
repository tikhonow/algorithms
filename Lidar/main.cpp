#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <functional>

using namespace std;

//Filter object containing range and temporal median filter functions
class filters
{
private:
	float min = -90.03;
	float max = 50000.0;
	/*
	float min = 0.03;
	float max = 50.0;
*/
public:
	filters() {}
	vector<float> update(vector<float> &scan);
	vector<float> median(vector<float> &data, int q);
	~filters() {}
};

//Update function
//Takes in an array of float values and returns a filtered output with values within the range of [0.03, 50.0]
vector<float> filters::update(vector<float> &scan)
{
	vector<float> updated_scan(scan.size(), 0);
	for (int i = 0; i < scan.size(); i++)
	{
		if (scan[i] < min)
			updated_scan[i] = min;
		else if (scan[i] > max)
			updated_scan[i] = max;
		else
			updated_scan[i] = scan[i];
	}

	return updated_scan;
}

//Median function
//Takes in an array of float values and returns the median of the array
vector<float> filters::median(vector<float> &data, int q)
{
	vector<float> updated_scan(data.size(), 0);
	for (int i = 0; i < data.size(); i++)
	{
		const auto median_it = data.begin() + data.size() / 2.0;
		nth_element(data.begin(), median_it, data.end());
		auto median = *median_it;

		if (data.size() % 2 == 0)
		{
			const auto median_it1 = data.begin() + data.size() / 2.0 - 1.0;
			const auto median_it2 = data.begin() + data.size() / 2.0;

			std::nth_element(data.begin(), median_it1, data.end());
			const auto e1 = *median_it1;

			std::nth_element(data.begin(), median_it2, data.end());
			const auto e2 = *median_it2;

			updated_scan[i] = (e1 + e2) / 2.0;
		}
		else
		{
			const auto median_it = data.begin() + data.size() / 2.0;
			std::nth_element(data.begin(), median_it, data.end());
			updated_scan[i] = *median_it;
		}
	}

	return updated_scan;
}

//Println function
//Prints a line
void println()
{
	for (int i = 0; i < 50; i++)
	{
		cout << "-";
	}
	cout << endl;
}

int main()
{

	//Init variables
	filters test;
	vector<float> scan;
	vector<float> range_output;
	vector<float> med_data;
	vector<float> temp;
	vector<vector<float>> med_output;
	vector<vector<float>> twod_vector;
	twod_vector.resize(5, vector<float>(5, 0));
	med_output.resize(5, vector<float>(5, 0));

	fstream f;
	int row = 0;
	int col = 0;
	float num = 0;
	int count = 0; //generic counter
	int n = 5;	   //temporal median n variable
	int D = 5;	   //temporal median D variable
	int a = 5;
	int b = 3;
	int q = 5;

	//TEMPORAL MEDIAN DEMO
	cout << endl
		 << endl;
	cout << "Temporal Median Filter Demo" << endl;
	println();

	scan.clear(); //Clean up scan vector

	//Read in file for testing temporal median function
	f.open("input.txt", ios::in);
	while (!f.eof())
	{
		f >> num;
		scan.push_back(num);
	}
	f.close();

	count = 0; //Reset counter
	scan = test.update(scan);
	//Place scanned float input values into a 2-D vector
	for (int i = 0; i < a * b; i++)
	{

		if (count == 0)
		{
			twod_vector[row][col] = scan[i];
		}
		else if ((count % b) == 0)
		{
			col = 0;
			row++;
			twod_vector[row][col] = scan[i];
		}
		else
		{
			twod_vector[row][col] = scan[i];
		}
		col++;
		count++;
	}

	//Print 2-D vector
	cout << left << setw(10) << "Num  | " << left << setw(10) << "Scan" << endl;
	println();
	for (int i = 0; i < a; i++)
	{
		cout << left << setw(5) << i << "|";
		for (int j = 0; j < b; j++)
		{
			cout << right << setw(5) << twod_vector[i][j] << "|";
		}
		cout << endl;
	}

	count = 0; //Reset counter

	//Median function is called to find the temporal median of the data set
	for (int i = 0; i < D; i++)
	{
		for (int j = 0; j < D; j++)
		{
			med_data.push_back(twod_vector[j][i]);
			temp = test.median(med_data, q);
			med_output[j][i] = (i < q) ? temp[j] : twod_vector[j][i];
			count++;
		}
		med_data.clear();
		temp.clear();
	}

	//Print an updated vector containing the temporal median of the data set
	cout << endl
		 << endl;
	cout << left << setw(10) << "Num  | " << left << setw(10) << "Update" << endl;
	println();
	for (int i = 0; i < a; i++)
	{
		cout << left << setw(5) << i << "|";
		for (int j = 0; j < b; j++)
		{
			cout << right << setw(5) << med_output[i][j] << "|";
		}
		cout << endl;
	}

	test.~filters(); //Deconstructor
	system("PAUSE");

	return 0;
}