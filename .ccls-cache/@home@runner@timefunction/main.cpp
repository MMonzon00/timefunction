#include <iostream>
#include <chrono>
#include<vector>
#include <algorithm>

#define SIZE 100000
using namespace std;
using namespace std::chrono;

void ISort(vector<int> arr, int n);
void swap(int *xp, int *yp);
void BSort(vector<int> arr, int n);


int main() {
  vector<int> values(SIZE);
  auto f = []() -> int { return rand() % SIZE; };
  generate(values.begin(), values.end(), f);
  auto Istart = high_resolution_clock::now();
  ISort(values,SIZE);
  auto Istop = high_resolution_clock::now();
  auto Iduration = duration_cast<microseconds>(Istop - Istart);
  cout << "Time taken by Insertion method: "<< Iduration.count() << " microseconds" << endl;
  auto Bstart = high_resolution_clock::now();
  BSort(values,SIZE);
  auto Bstop = high_resolution_clock::now();
  auto Bduration = duration_cast<microseconds>(Bstop - Bstart);
  cout << "Time taken by Bubble method: "<< Iduration.count() << " microseconds" << endl;
}

void ISort(vector<int> arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void BSort(vector<int> arr, int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)    
     
    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}