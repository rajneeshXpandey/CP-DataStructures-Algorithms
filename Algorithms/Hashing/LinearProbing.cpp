#include <bits/stdc++.h>
using namespace std;

void init(int a[], int size)
{
    for (int i = 0; i < size; i++)
        a[i] = -1;
}


// for quardratic probing we need to increment index = (index+i*i)%size
void insert(int a[], int size, int data)
{
    int key = data % size;

    int index = key;

    while (a[index] != -1)
    {
        index = (index + 1) % size;
        if (index == key)
        {
            cout << "Hashmap is full !" << endl;
        }
    }
    a[index] = data;
}

bool Deleted(int a[], int size, int val)
{
    int key = val % size;
    int index = key;

    while (a[index] != val)
    {

        index = (index + 1) % size;
        if (index == key)
            //not found
            return false;
    }
    a[index] = -1;
    return true;
}

int search(int a[], int size, int val)
{
    int key = val % size;
    int index = key;

    while (a[index] != val)
    {

        index = (index + 1) % size;
        if (index == key)
            //not found
            return -1;
    }
    
    return index;
}

int main()
{

    int n;
    cin >> n;
    int array[n];

    init(array, n);

    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        insert(array, n, data);
    }

    for (int i = 0; i < n; i++)
        cout << array[i] << " ";

    return 0;
}
