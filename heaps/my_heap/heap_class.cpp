#include <bits/stdc++.h>
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
            int temp = heap[i];
            cout << temp;
            heap[i] = heap[parent];
            heap[parent] = temp;

            i = parent;
            parent = (i - 1) / 2;
        }
        
    }
    void heapify(int i)
    {
        int leftChild;
        int rightChild;
        int largestChild;

        for (;;)
        {
            leftChild = 2 * i + 1;
            rightChild = 2 * i + 2;
            largestChild = i;

            if (leftChild < heapSize() && heap[leftChild] > heap[largestChild])
            {
                largestChild = leftChild;
            }

            if (rightChild < heapSize() && heap[rightChild] > heap[largestChild])
            {
                largestChild = rightChild;
            }

            if (largestChild == i)
            {
                break;
            }

            int temp = heap[i];
            heap[i] = heap[largestChild];
            heap[largestChild] = temp;
            i = largestChild;
        }
    }
    void buildHeap(int arr[], int n)
    {
        vector<int> heap(arr, arr + n);
        for (int i = heapSize() / 2; i >= 0; i--)
        {
            heapify(i);
        }
    }
    int getMax()
    {
        int result = heap[0];
        heap[0] = heap[heapSize() - 1];
        heap.erase(heap.begin() + (heapSize() - 1));
        ;
        cout << result;
        return result;
    }
    int out(int i)
    {
        return(heap[i]);
        for(long long i = 0; i < heap.size(); i++) 
    {
        cout << heap[i] << ' ';
    }
        
    }
};
int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    int N, M;
    fin >> N >> M;
    for (int i = 0; i < N; i++) {
        int k;
        fin >> k;
        bheap add(int k);
    }
}
