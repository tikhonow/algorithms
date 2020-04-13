#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

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

			auto new_ind = (leftChild<heapSize() && heap[leftChild] < heap[rightChild]) ? leftChild : rightChild;

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
		heap.erase(heap.begin() + heapSize() -1 );
		heapify(0);
		return result;
	}

	int getElement(int i)
	{
		return(heap[i]);
	}
};

min_bheap heap;

int main() 
{
	ifstream fin("input.txt");
    ofstream fout("output.txt");
    long long int N,M;
    fin >> N >> M;
    for (long long int i = 0; i < N; i++) {
        long long k;
        fin >> k;
        heap.add(k);
    }
/*
    for (long  i =0; i< M; i++)
	{
		long long min1 = heap.pickMin();
		long long min2 = heap.pickMin();
		heap.add(min1 + min2);
	}

	for (long long i =0; i< N - M; i++)
	{
		fout << heap.getElement(i) << " ";
	}
*/
	for (int i = 0; i < N; i++)
	{
		fout << heap.getElement(i) << " ";
	}
	fout << '\n' << heap.pickMin() << '\n';
	fout << '\n' << heap.pickMin() << '\n';
	for (int i = 0; i < N; i++)
	{
		fout << heap.getElement(i) << " ";
	}
}