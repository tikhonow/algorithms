#include <vector>
#include <iostream>
#include <fstream>
#include <iostream>

using namespace std;

class bheap
{
	vector<int> heap;

public:
	int heapSize()
	{
		return (heap.size());
	}

	void add(int value)
	{
		heap.push_back(value);
		int i = heapSize() - 1;
		int parent = (i - 1) / 2;

		while (i > 0 && heap[parent] < heap[i])
		{
			//cout << heap[i];
			swap(heap[i], heap[parent]);
			i = parent;
			parent = (i - 1) / 2;
		}
	}

	void heapify(int index)
	{
		int leftChild;
		int rightChild;
		auto working = true;

		do
		{
			leftChild = 2 * index + 1;
			rightChild = 2 * index + 2;

			auto new_ind = (leftChild < heapSize() && heap[leftChild] > heap[rightChild]) ? leftChild : rightChild;

			if (new_ind < heapSize() && heap[index] < heap[new_ind])
			{
				swap(heap[index], heap[new_ind]);
				index = new_ind;
			}
			else
			{
				working = false;
			}

		} while (working);
	}

	void buildHeap(int arr[], int n)
	{
		vector<int> heap(arr, arr + n);
		for (int i = heapSize() / 2; i >= 0; i--)
		{
			heapify(i);
		}
	}

	int pickMax()
	{
		int result = heap[0];
		heap[0] = heap[heapSize() - 1];
		heap.pop_back();
		heapify(0);
		//cout << result;
		return result;
	}

	int getElement(int i)
	{
		return (heap[i]);
	}
};

bheap maxheap;

class min_bheap
{
	vector<int> heap;

public:
	int heapSize()
	{
		return (heap.size());
	}

	void add(int value)
	{
		heap.push_back(value);
		int i = heapSize() - 1;
		int parent = (i - 1) / 2;

		while (i > 0 && heap[parent] > heap[i])
		{
			swap(heap[i], heap[parent]);
			i = parent;
			parent = (i - 1) / 2;
		}
	}

	void heapify(int index)
	{
		int leftChild;
		int rightChild;
		auto working = true;

		do
		{
			leftChild = 2 * index + 1;
			rightChild = 2 * index + 2;

			auto new_ind = (leftChild < heapSize() && heap[leftChild] < heap[rightChild]) ? leftChild : rightChild;

			if (new_ind < heapSize() && heap[index] > heap[new_ind])
			{
				swap(heap[index], heap[new_ind]);
				index = new_ind;
			}
			else
			{
				working = false;
			}

		} while (working);
	}

	void buildHeap(int arr[], int n)
	{
		vector<int> heap(arr, arr + n);
		for (int i = heapSize() / 2; i >= 0; i--)
		{
			heapify(i);
		}
	}

	int pickMin()
	{
		int result = heap[0];
		heap[0] = heap[heapSize() - 1];
		heap.erase(heap.begin() + heapSize() - 1);
		heapify(0);
		return result;
	}

	int getElement(int i)
	{
		return (heap[i]);
	}
};

min_bheap minheap;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n;
	fin >> n;
	int tmp;
	vector<int> sort_array;

	for (int index = 0; index < n; index++)
	{
		fin >> tmp;
		if (index == 0)
			maxheap.add(tmp);
		else
		{
			if (index % 2 != 0)
			{
				if (tmp < maxheap.getElement(0))
				{
					minheap.add(maxheap.pickMax());
					maxheap.add(tmp);
				}
				else
					minheap.add(tmp);
			}
			if (index % 2 == 0)
			{
				if (tmp > minheap.getElement(0))
				{
					maxheap.add(minheap.getElement(0));
					minheap.add(tmp);
				}
				else
					maxheap.add(tmp);
			}
		}
		sort_array.push_back(maxheap.getElement(0));
	}

	for (int i = 0; i < n; i++)
	{
		fout << sort_array[i] << " ";
	}
}