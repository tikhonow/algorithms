#include <vector>
#include <iostream>
#include <fstream>

class bheap
{
	std::vector<int> heap;

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
			std::swap(heap[i], heap[parent]);
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

			auto new_ind = (leftChild<heapSize() && heap[leftChild] > heap[rightChild]) ? leftChild : rightChild;

			if (new_ind < heapSize() && heap[index]<heap[new_ind])
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

	int pickMax()
	{
		int result = heap[0];
		heap[0] = heap[heapSize() - 1];
		heap.erase(heap.end() - 1);
		heapify(0);
		//cout << result;
		return result;
	}

	int getElement(int i)
	{
		return(heap[i]);
	}
};

bheap heap;

int main() {
	std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    long long int N, M;
    fin >> N >> M;
    for (long long int i = 0; i < N; i++) {
        long long k;
        fin >> k;
        heap.add(k);
    }

    for (int i =0; i< M; i++) {
        long long max_thirst = heap.pickMax();
        max_thirst /= 10;
        heap.add(max_thirst);
    }

    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += heap.getElement(i);
    }
    fout << sum;
}