#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

bool cmp(pair<long long, long long> a, pair<long long, long long> b)
{
	return (a.second < b.second);
}

class min_bheap
{
	vector<pair<long long, long long>> heap;

public:
	int heapSize()
	{
		return (heap.size());
	}

	void add(pair<long long, long long> value)
	{
		heap.push_back(value);
		int i = heapSize() - 1;
		int parent = (i - 1) / 2;

		while ((i > 0) && (heap[parent].first > heap[i].first) || ((heap[parent].first==heap[i].first)&& (heap[parent].second>heap[i].second)))
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
		int result = heap[0].first;
		heap[0] = heap[heapSize() - 1];
		heap.erase(heap.begin() + heapSize() - 1);
		heapify(0);
		return result;
	}

	int getElement(int i)
	{
		return (heap[i].first);
	}
};

min_bheap heap_sequence;

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");

	long long N, M;
	fin >> N >> M;
	for (long long i = 0; i < N; i++)
	{
		long long k;
		fin >> k;
		heap_sequence.add(make_pair(k, i));
	}
	for (long long int i = 0; i < M; i++)
	{
		long long min1 = heap_sequence.pickMin();
		long long min2 = heap_sequence.pickMin();
		heap_sequence.add(make_pair(min1 + min2, N + i));
	}
	vector<pair<long long, long long>> output;
	for (int i = 0; i < heap_sequence.heapSize(); i++)
	{
		output[i] = make_pair(heap_sequence.getElement(i), i);
	}
	sort(output.begin(), output.end(), cmp);
	for (int i = 0; i < output.size(); i++)
	{
		fout << output[i].first;
	}
}