#include <bits/stdc++.h>
using namespace std;
// 0-based indexing
class minHeap
{
public:
    vector<int> arr;
    int size;
    int capacity;
    // Constructor for the class.
    minHeap(int cap)
    {
        arr.resize(cap);
        size = 0;
        capacity = cap;
    }
    // Used to make adjustments in a heap
    void heapify(int ind)
    {
        int j = 2 * ind + 1;
        int item = arr[ind];

        while (j < size)
        {
            if (j + 1 < size && arr[j] > arr[j + 1]) // if the right child is smaller
                j++;
            
            if(arr[j]>=item)
            break;

            arr[(j-1)/2]=arr[j];
            j=2*j+1;
        }
        arr[(j-1)/2]=item;
    }
    // Implement the function to remove minimum element.
    int extractMinElement()
    {
        // check underflow
        if(size==0)
        return -1;
        int val=arr[0];
        arr[0]=arr[size-1];
        size--;
        heapify(0);
        return val;
    }

    // Implement the function to delete an element.
    void deleteElement(int ind)  // index of the element is given
    {
        if(ind>=size)
        return;

        swap(arr[ind],arr[size-1]);
        size--;
        heapify(ind);
    }

    // Implement the function to insert 'val' in the heap.
    void insert(int val)
    {
        // overflow check
        if (size == capacity)
            return;

        int index = size;
        arr[index] = val;
        size = size + 1;
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (arr[parent] > arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
                parent = (index - 1) / 2;
            }
            else
            {
                break;
            }
        }
    }

    void printHeap()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{

    minHeap heap = minHeap(100);
    heap.insert(3);
    heap.insert(4);
    heap.insert(9);
    heap.insert(5);
    heap.insert(2);

    cout << "Max-Heap array: " << endl;
    heap.printHeap();

    // heap.extractMinElement();

    // cout << "After deleting min element: " << endl;

    // heap.printHeap();

    
    // heap.extractMinElement();

    // cout << "After deleting min element: " << endl;

    // heap.printHeap();

    heap.deleteElement(1);
    cout << "After deleting an element: " << endl;

    heap.printHeap();
    return 0;
}

// https://www.codingninjas.com/studio/problems/min-heap-implementation_5480527?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION