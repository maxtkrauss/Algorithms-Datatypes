#include <iostream>

using namespace std;

int main() {

	int arr[1000];
	int count = 1;
	int input;

	for (int i = 0; i < 1000; i++) {
		arr[i] = count;
		count = count + 2;
	}

	int high = 999;
	int low = 0;
	int mid;

	cout << "Enter an odd number: " << endl;
	cin >> input;

	if (input % 2 == 0) {
		cout << "This is an even number" << endl;
		return 0;
	}

	do {		
		mid = (high + (low)) / 2;

		if (arr[mid] == input) {
			cout << input << " is at index " << mid;
			break;
		}
		else if (arr[mid] < input) {
			low = mid + 1;
		}
		else if (arr[mid] > input) {

			high = mid - 1;
		}
	} while (high != low);

	return 0;
}
