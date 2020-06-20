#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include "filter.h"

void println()
{
	for (int i = 0; i < 50; i++)
	{
		std::cout << "-";
	}
	std::cout << std::endl;
}


int main(int argc, char *argv[])
{
	int row = 0;
	int col = 0;
	float num = 0;
	int count = 0; //generic counter
	int D = 5;	   //temporal median D variable
	int a = 5;	   //строки
	int b = 3;	   //столбцы
	int q = 5;

	//Init variables
	filters test;
	float min1, min2;
	for (int count=0; count < argc; ++count)
	{
		if (strcmp(argv[count], "-limit") == 0)
		{
			std::cout << "Enter parameters for the threshold filter" << std::endl;
			std::cin >> min1 >> min2;
			test.set_min(min1);
			test.set_max(min2);
		}
		if (strcmp(argv[count], "-size") == 0)
		{
			std::cout << "Input size" << std::endl;
			std::cin >> a >> b;

		}
	}
	std::vector<float> scan;
	std::vector<float> range_output;
	std::vector<float> med_data;
	std::vector<float> temp;
	std::vector<std::vector<float>> med_output;
	std::vector<std::vector<float>> twod_vector;
	twod_vector.resize(5, std::vector<float>(5, 0));
	med_output.resize(5, std::vector<float>(5, 0));

	std::fstream f;


	//TEMPORAL MEDIAN DEMO
	std::cout << std::endl
		 << std::endl;
	std::cout << "Median Filter" << std::endl;
	println();

	scan.clear(); //Clean up scan vector

	//Read in file for testing temporal median function
	f.open("scans.txt", std::ios::in);
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
	std::cout << std::left << std::setw(10) << "Num  | " << std::left << std::setw(10) << "Scan" << std::endl;
	println();
	for (int i = 0; i < a; i++)
	{
		std::cout << std::left << std::setw(5) << i << "|";
		for (int j = 0; j < b; j++)
		{
			std::cout << std::right << std::setw(5) << twod_vector[i][j] << "|";
		}
		std::cout << std::endl;
	}

	count = 0; //Reset counter

	//Median function is called to find the temporal median of the data set
	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < a; j++)
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
	std::cout << std::endl
		 << std::endl;
	std::cout << std::left << std::setw(10) << "Num  | " << std::left << std::setw(10) << "Update" << std::endl;
	println();
	for (int i = 0; i < a; i++)
	{
		std::cout << std::left << std::setw(5) << i << "|";
		for (int j = 0; j < b; j++)
		{
			std::cout << std::right << std::setw(5) << med_output[i][j] << "|";
		}
		std::cout << std::endl;
	}

	test.~filters(); //Deconstructor
	system("PAUSE");

	return 0;
}