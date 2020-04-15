#include <vector>
#include <fstream>

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

    int getElement(int i)
    {
        return (heap[i]);
    }
};

bheap heap;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    long long int N;
    fin >> N;
    for (long long int i = 2; i <= N; i++)
    {
        long long k = i;
        heap.add(k);
    }
    heap.add(1);
    for (int i = 0; i < heap.heapSize(); i++)
	{
		fout << heap.getElement(i) << " ";
	}
}