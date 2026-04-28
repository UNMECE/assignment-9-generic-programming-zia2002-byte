#include <iostream>
#include "genericarray.h"

using namespace std;

int main()
{
    GenericArray<int> int_array;

    for(int i = 0; i < 12; i++)
    {
        int_array.addElement(i * 2);
    }

    cout << "Size of array is " << int_array.size() << endl;
    cout << "Sum of array is " << int_array.sum() << endl;
    cout << "Maximum and Minimum: "
         << int_array.max() << "\t"
         << int_array.min() << endl;

    cout << "Value at index 3: "
         << int_array.at(3) << endl;

    int* sliced_array = int_array.slice(5,10);

    cout << "Sliced array: ";

    for(int i = 0; i < 6; i++)
    {
        cout << sliced_array[i] << " ";
    }

    cout << endl;

    delete[] sliced_array;

    return 0;
}
