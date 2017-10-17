#include <iostream>
#include <cassert>

using namespace std;

       // s = start of range to sort
       // e = end of range to sort
void msort(int a[], int x[], int s, int e) {
  
        int mid;
	if (s >= e)
	{
	return;
	    
	}

	 mid=(s+e)/2;
	 msort(a, x, s, mid);
	 msort(a, x, mid+1, e);
	 
	// We put mid+1 because we want to get to 4 and to end in order to sort.

	int i;
	int j;
	int k;
	i = s;
	k = 0;
	j = mid + 1;
	// Merge the two parts into x[].
	while (i <= mid && j <= e)
	  {
	 if (a[i] < a[j])
		{
			x[k] = a[i];
			k++;
			i++;
		}
	else
		{
			x[k] = a[j];
			k++;
			j++;
		}
	}
 
	// We have put all remaining values from i to mid into x[].
	while (i <= mid)
	{
		x[k] = a[i];
		k++;
		i++;
	}
 
	// We have put all remaining values from j to high into x[].
	while (j <= e)
	{
		x[k] = a[j];
		k++;
		j++;
       
	}
	
	for (int i = s; i <= e; i++)
	{
		a[i] = x[i-s];
	}
     
}
 

void mergesort(int a[], int n) {
        int * x = new int[n];
	msort (a, x, 0, n-1);
	delete [] x;
}

bool sorted(int a[], int n) {
        for (int i = 0; i < n - 1; ++i)
    {
        if (a[i] > a[i + 1])
	 return false;
    }
         return true;
}

int main(int argc, char * args[]) {
	int a[1000];
	for (int i = 0; i < 1000; ++i) a[i] = -50 + rand() % 100;
	mergesort(a, 1000);
	assert(sorted(a, 1000));
	/*
	int b[1001];
	for (int i = 0; i < 1001; ++i) b[i] = -50 + rand() % 100;
	mergesort(b, 1001);
	assert(sorted(b, 1001));
	
	int c[] = { 2 };
	mergesort(c, 1);
	assert(sorted(c, 1));
	
	int d[] = { 1, 2, 3, 4, 5 };
	mergesort(d, 5);
	assert(sorted(d, 5));
	*/
	cout << "All tests passed." << endl;	
}
