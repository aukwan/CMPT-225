#include <iostream>
#include <fstream>
using namespace std;

// Here I've left the code as I found it, to show you
// a contrasting (and in my opinion, nowhere near as clear)
// style.  Many C++ coders have this style.


// Find the mode of an array.
//
// Parameters:
//  arr is an integer array with n elements
// Return value:
//  return the mode
//

// Insertion Sort
void insertionSort(long *arr, int n) {
  for (int i = 1; i < n; i++) {
    long current = arr[i];
    int j = i - 1;
    while ((j>=0) && (arr[j] > current)) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = current;
  }
}

long mode (long *arr, int n) {
  // TO DO:: Fill in this function.
  if (n == 0) {
    return -1;
  }
  if (n > 1) {
    insertionSort(arr, n);
  }
  long arrMode = arr[0];
  int counter = 1;
  int modeCounter = 1;
  long current = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] == current) {
      counter++;
    } else {
      if (counter > modeCounter) {
        modeCounter = counter;
        arrMode = current;
      }
      current = arr[i];
      counter = 1;
    }
  }
  if (counter > modeCounter) {
    arrMode = current;
  }
  return arrMode;
}

// Input is the number of elements, followed by that many integers.
// Writes mode of elements to file specified as first command-line argument.
int main (int argc,  char* argv[]) {

	// ofstream for writing result.
	ofstream outputfile;

	// Parse command-line arguments.
	if (argc != 2) {
		// Note that the program name is the first argument, so argc==1 if there are no additional arguments.
		cerr << "Expected one argument." << endl;
		cerr << "  Usage: " << argv[0] << " output_filename" << endl;
		return 1;
	} else {
		// Open the filename specified for input.
		outputfile.open (argv[1]);
	}


	// Read a set of elements into an array.
	int n;
	long *arr;

	// Get the number of elements
	cout << "Enter the number of elements:" << endl;
	cin >> n;

	// Create array in dynamic memory.
	arr = new long[n];

	for (int i=0; i<n; i++) {
		cout << "Enter a number:" << endl;
		cin >> arr[i];
	}

	long m = mode(arr,n);

	cout << "The mode is " << m << endl;

	outputfile << m << endl;
	outputfile.close();

	// Free up memory.  Note use of delete [], since this is an array.
	delete [] arr;

	return 0;
}
