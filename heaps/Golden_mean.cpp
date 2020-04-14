#include <vector>
#include <iostream>
#include <fstream>
#include <iostream>

using namespace std;

class heap_max
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
heap_max left_max;

class heap_min
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
heap_min right_min;


int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    fin >> n;
    int tmp;
    vector<int> sort_array;
    for (int index = 0; index < n; index++) {
        fin >> tmp;
        if (index == 0)
            left_max.add(tmp);
        else {
            if (index % 2 != 0) {
                if (tmp < left_max.getElement(0)) {
                    right_min.add(left_max.pickMax());
                    left_max.add(tmp);
                } else
                    right_min.add(tmp);
            }
            if (index % 2 == 0) {
                if (tmp > right_min.getElement(0)) {
                    left_max.add(right_min.pickMin());
                    right_min.add(tmp);
                } else
                    left_max.add(tmp);
            }
        }
        sort_array.push_back(left_max.getElement(0));
    }
    for (int i = 0; i < n; i++) {
        fout << sort_array[i] << " ";
    }
}