#include <bits/stdc++.h>
using namespace std;

void Merge(float array[], int start, int mid, int end)
{

    int length_n1 = mid - start + 1;
    int length_n2 = end - mid;
    auto *n1_array = new float[length_n1];
    auto *n2_array = new float[length_n2];
    for (int i = 0 ; i < length_n1 ; i++)
    {
        n1_array[i] = array[start + i];
    }
    for (int i = 0 ; i < length_n2 ; i++)
    {
        n2_array[i] = array[mid + i + 1];
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = start;

    while (i < length_n1 && j < length_n2)
    {
        if (n1_array[i] <= n2_array[j])
        {
            array[k] = n1_array[i];
            ++i;
        }
        else
        {
            array[k] = n2_array[j];
            ++j;
        }
        ++k;
    }

    while (i < length_n1)
    {
        array[k] = n1_array[i];
        ++i;
        ++k;
    }

    while (j < length_n2)
    {
        array[k] = n2_array[j];
        ++j;
        ++k;
    }
}

void MergeSort(float array[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        MergeSort(array, start, mid);
        MergeSort(array, mid + 1, end);

        Merge(array, start, mid, end);
    }
}

const int NMAX=1000000;

char file_name[200];


int main()
{
        auto *a = new float[NMAX+1];
        for (unsigned int i = 0; i < 10; i++)
        {
		memset(file_name, 0, sizeof(file_name));
		sprintf(file_name, "testcase%u.txt", i + 1);
		ifstream File(file_name);

		for (unsigned int i = 0; i < NMAX && (!File.eof()); i++) File >> a[i];
		File.close();

		auto begin = std::chrono::high_resolution_clock::now();
		MergeSort(a, 0, NMAX-1);
		auto end = std::chrono::high_resolution_clock::now();
		auto duration =  std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

		cout << file_name << " runs in " << duration.count() << " microseconds\n";
        }
    return 0;
}

