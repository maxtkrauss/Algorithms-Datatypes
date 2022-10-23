#include <iostream>
#include <vector>

using namespace std;

vector<int> bubble_sort(vector<int> unsorted)
{
	for (int i = 0; i < unsorted.size() - 1; i++)
		for (int j = 0; j < unsorted.size() - i - 1; j++)
			if (unsorted[j] > unsorted[j + 1])
				swap(unsorted[j], unsorted[j + 1]);

	return unsorted;
};

void print_vect(vector<int> vect) {
	for (int i = 0; i < vect.size(); i++)
	{
		cout << vect[i] << ", ";
	}
}

int main() {

	vector<int> unsorted = {};

	for (int i = 0; i < 25; i++) {
		unsorted.push_back(rand());
	}

	vector<int> sorted = bubble_sort(unsorted);

	cout << "Unsorted: ";

	print_vect(unsorted);

	cout << endl << "Sorted: ";

	print_vect(sorted);

}