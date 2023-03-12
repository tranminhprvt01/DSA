#include <bits/stdc++.h>

using namespace std;

void heapify(double array[], int N, int i)
{
    // Find largest among root, left child and right child

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int left = 2 * i + 1;

    // right = 2*i + 2
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < N && array[left] > array[largest])

        largest = left;

    // If right child is larger than largest
    // so far
    if (right < N && array[right] > array[largest])

        largest = right;

    // Swap and continue heapifying if root is not largest
    // If largest is not root
    if (largest != i) {

        swap(array[i], array[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(array, N, largest);
    }
}

// Main function to do heap sort
void heapSort(double array[], int N)
{

    // Build max heap
    for (int i = N / 2 - 1; i >= 0; i--)

        heapify(array, N, i);

    // Heap sort
    for (int i = N - 1; i >= 0; i--) {

        swap(array[0], array[i]);

        // Heapify root element to get highest element at
        // root again
        heapify(array, i, 0);
    }
}


#define NMAX 1e6

char file_name[200];

/*
void printarr(double a[], long n)
{
    for (long i=0;i<n;i++) cout << a[i] << " ";
    cout << endl;
}
*/

int main()
{
        auto *a = new double[NMAX+1];
        for (unsigned int i = 0; i < 10; i++)
        {
		memset(file_name, 0, sizeof(file_name));
		sprintf(file_name, "testcase%u.txt", i + 1);
		ifstream File(file_name);

		for (unsigned int i = 0; i < NMAX && (!File.eof()); i++) File >> a[i];
		File.close();

        //printarr(a,NMAX);
		auto begin = std::chrono::high_resolution_clock::now();
		heapSort(a, NMAX);
		auto end = std::chrono::high_resolution_clock::now();
		auto duration =  std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
        //printarr(a,NMAX);
		cout << file_name << " runs in " << duration.count() << " microseconds\n";
        }
    return 0;
}
