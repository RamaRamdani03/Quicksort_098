#include <iostream>
using namespace std;

int arr[20];
int cmp_count = 0; // Number of comprasion 
int mov_count = 0; // Number of data movements 
int n; 

void input() {
	while (true)
	{
		cout << "Masukan panjang element array: ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMaxsimum panjang array adalah 20" << endl;
	}


	cout << "\n===================" << endl;
	cout << "\nEnter array element" << endl;
	cout << "\n===================" << endl;

	for (int i = 0; 1 < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> arr[i];
	}
}
// Swap the element st index x with the element at index y
void swap(int x, int y)
{
	int temp;

	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}
void q_short(int low, int hight)
{
	int pivot, i, j;
    if (low > hight)                                             // Langkah Algoritma No.1
        return;

    // Partition the list into two parts:
    // One containing elements less that or equal to pivot
    // Outher containing elements greater than pivot

    pivot = arr[low];                                           // Langkah Algoritma No.2

    i = low + 1;                                                // Langkah Algoritma No.3
    j = hight;                                                   // Langkah Algoritma No.4


    while (i <= j)                                              // Langkah Algoritma No.10
    {
        // Search for an element greater than pivot
        while ((arr[i] <= pivot) && (i <= hight))                // Langkah Algoritma No.5
        {
            i++;                                                // Langkah Algoritma No.6
            cmp_count++;
        }
        cmp_count++;

        // Search for an element less than or equal to pivot
        while ((arr[j] > pivot) && (j >= low))                  // Langkah Algoritma No.7
        {
            j--;                                                // Langkah Algoritma No.8
            cmp_count++;
        }
        cmp_count++;

        // If the greater element is on the left of the element
        if (i < j)                                              // Langkah Algoritma No.9
        {
            // Swap the element at index i with the element at index j
            swap(i, j);
            mov_count++;
        }
    }
    // J now containt the index of the last element in the sorted list
    if (low < j);                                               // Langkah Algoritma No.11
    {
        // Move the pivot to its correct position in the list
        swap(low, j);
        mov_count++;
    }
    // Sort the list on the left of pivot using quick sort
    q_short(low, j - 1);                                        // Langkah Algoritma No.12

    // Sort the list on the right of pivot using quick sort
    q_short(j + 1, hight);                                       // Langkah Algoritma No.13

}

void display() {
    cout << "\n-----------------" << endl;
    cout << "Sorted Array" << endl;
    cout << "-------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\nNumber of comparisions: " << cmp_count << endl;
    cout << "Number of data movements: " << mov_count << endl;
}

int main()
{
    input();
    q_short(0, n - 1);                      // Sort the array using quick sort
    display();
    system("pause");

    return 0;
}

