#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

typedef std::pair<long long, long long> valueAndindex;

bool cmp(std::pair<long long, long long> a, std::pair<long long, long long> b)
{
	return (a.second < b.second);
}

class min_bheap
{
	std::vector<valueAndindex> heap;

public:
	int heapSize()
	{
		return (heap.size());
	}

	void add(valueAndindex value)
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
				std::swap(heap[index], heap[new_ind]);
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
		std::vector<int> heap(arr, arr + n);
		for (int i = heapSize() / 2; i >= 0; i--)
		{
			heapify(i);
		}
	}

	int pickMin()
	{
		int result = heap[0].first;
		heap[0] = heap[heapSize() - 1];
		heap.erase(heap.begin() + heapSize() - 1);
		heapify(0);
		return result;
	}

	std::vector<valueAndindex> getElement()
	{
		return (heap);
	}
};

min_bheap heap;

int main()
{
	std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
	long long N, M;
	fin >> N >> M;
	for (long long i = 0; i < N; i++)
	{
		long long int k;
		fin >> k;
		heap.add(std::make_pair(k, i));
	}

	for (long long i = 0; i < M; i++)
	{
		long long min1 = heap.pickMin();
		long long min2 = heap.pickMin();
		heap.add(std::make_pair(min1 + min2, N));
	}
	std::vector<valueAndindex> output = heap.getElement();
	sort(output.begin(), output.end(), cmp);
	for (int i = 0; i < heap.heapSize(); i++)
	{
		fout << output[i].first << " ";
	}
}