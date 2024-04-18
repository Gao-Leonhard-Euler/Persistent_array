#include <iostream>
#include "Persistent_array.h"

using namespace std;
using namespace my_data_struct;

int main() {
    // Create an array containing 5 integers
    int initialArray[] = {1, 2, 3, 4, 5};
    
    // Construct a persistent array object with the initial array
    persistent_array<int> pa(initialArray, initialArray + 5);
    
    // Output the size of the initial array
    cout << "Initial array size: " << pa.size() << endl;
    
    // View the elements in the array
    cout << "Array elements at version 0:" << endl;
    for (int i = 0; i < pa.size(); ++i) {
        cout << pa.view(i) << " ";
    }
    cout << endl;
    
    // Modify the element at position 2 to 10
    unsigned int newVersion = pa.change(2, 10);
    
    // Output the size of the array after the change
    cout << "Array size after change: " << pa.size() << endl;
    
    // View the elements after the change at the new version
    cout << "Array elements after change at version " << newVersion << ":" << endl;
    for (int i = 0; i < pa.size(); ++i) {
        cout << pa.view(i, newVersion) << " ";
    }
    cout << endl;
    
    // View the elements at the initial version (version 0)
    cout << "Array elements at initial version (version 0):" << endl;
    for (int i = 0; i < pa.size(); ++i) {
        cout << pa.view(i, 0) << " ";
    }
    cout << endl;
    
    return 0;
}
