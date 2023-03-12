#include <bits/stdc++.h>

using namespace std;

const int NMAX=1e6;

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

		FILE *f=fopen(file_name,"r");
		for (int i=0;i<NMAX;i++) {
            fscanf(f, "%lf\n", &a[i]);
		}
		fclose(f);

		//printarr(a,NMAX);
		auto begin = std::chrono::high_resolution_clock::now();

		sort(a, a + NMAX);

		auto end = std::chrono::high_resolution_clock::now();
		auto duration =  std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
		//printarr(a,NMAX);
		cout << file_name << " runs in " << duration.count() << " microseconds\n";
        }
    return 0;
}
