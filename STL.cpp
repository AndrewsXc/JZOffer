/* qsort example */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* qsort */

using namespace std;

#pragma region Qsort C
//	void qsort (void* base, size_t num, size_t size, int(*compar)(const void*, const void*));


int values[] = { 40, 10, 100, 90, 20, 25 };

int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	int n;
	qsort(values, 6, sizeof(int), compare);
	for (n = 0; n<6; n++)
		printf("%d ", values[n]);
	return 0;
}
#pragma endregion





#pragma region Sort STL
//	default (1)	
//template <class RandomAccessIterator>
//void sort(RandomAccessIterator first, RandomAccessIterator last);
//custom(2)
//template <class RandomAccessIterator, class Compare>
//void sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);


// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

bool myfunction(int i, int j) { return (i<j); }

struct myclass {
	bool operator() (int i, int j) { return (i<j); }
} myobject;

int main() {
	int myints[] = { 32,71,12,45,26,80,53,33 };
	std::vector<int> myvector(myints, myints + 8);               // 32 71 12 45 26 80 53 33

																 // using default comparison (operator <):
	std::sort(myvector.begin(), myvector.begin() + 4);           //(12 32 45 71)26 80 53 33

																 // using function as comp
	std::sort(myvector.begin() + 4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)

																 // using object as comp
	std::sort(myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)

															   // print out content:
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	return 0;
}
#pragma endregion


#pragma region 二分搜索 查找 C
//	default (1)	


void* bsearch(const void* key, const void* base,
	size_t num, size_t size,
	int(*compar)(const void*, const void*));

/* bsearch example */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* qsort, bsearch, NULL */

int compareints(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int values[] = { 50, 20, 60, 40, 10, 30 };

int main()
{
	int * pItem;
	int key = 40;
	qsort(values, 6, sizeof(int), compareints);
	pItem = (int*)bsearch(&key, values, 6, sizeof(int), compareints);
	if (pItem != NULL)
		printf("%d is in the array.\n", *pItem);
	else
		printf("%d is not in the array.\n", key);
	return 0;
}

/* bsearch example with strings */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* qsort, bsearch, NULL */
#include <string.h>     /* strcmp */

char strvalues[][20] = { "some","example","strings","here" };

int main()
{
	char * pItem;
	char key[20] = "example";

	/* sort elements in array: */
	qsort(strvalues, 4, 20, (int(*)(const void*, const void*)) strcmp);

	/* search for the key: */
	pItem = (char*)bsearch(key, strvalues, 4, 20, (int(*)(const void*, const void*)) strcmp);

	if (pItem != NULL)
		printf("%s is in the array.\n", pItem);  // cout << example is in the array
	else
		printf("%s is not in the array.\n", key);
	return 0;
}
#pragma endregion


#pragma region 二分搜索 查找 STL binary_search
//	default (1)	
//template <class ForwardIterator, class T>
//bool binary_search(ForwardIterator first, ForwardIterator last, const T& val);
//custom(2)
//template <class ForwardIterator, class T, class Compare>
//bool binary_search(ForwardIterator first, ForwardIterator last, const T& val, Compare comp);



// binary_search example
#include <iostream>     // std::cout
#include <algorithm>    // std::binary_search, std::sort
#include <vector>       // std::vector

bool myfunction(int i, int j) { return (i<j); }

int main() {
	int myints[] = { 1,2,3,4,5,4,3,2,1 };
	std::vector<int> v(myints, myints + 9);                         // 1 2 3 4 5 4 3 2 1

																	// using default comparison:
	std::sort(v.begin(), v.end());

	std::cout << "looking for a 3... ";
	if (std::binary_search(v.begin(), v.end(), 3))
		std::cout << "found!\n"; else std::cout << "not found.\n";

	// using myfunction as comp:
	std::sort(v.begin(), v.end(), myfunction);

	std::cout << "looking for a 6... ";
	if (std::binary_search(v.begin(), v.end(), 6, myfunction))
		std::cout << "found!\n"; else std::cout << "not found.\n";

	return 0;
}
#pragma endregion




#pragma region 二分搜索 lower_bound upper_bound equal_bound
//lower_bound[ )
//upper_bound[ )
//equal_bound[ )

// lower_bound/upper_bound example
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector

int main() {
	int myints[] = { 10,20,30,30,20,10,10,20 };
	std::vector<int> v(myints, myints + 8);           // 10 20 30 30 20 10 10 20

	std::sort(v.begin(), v.end());                // 10 10 10 20 20 20 30 30

	std::vector<int>::iterator low, up;
	low = std::lower_bound(v.begin(), v.end(), 20); //          ^
	up = std::upper_bound(v.begin(), v.end(), 20); //                   ^

	std::cout << "lower_bound at position " << (low - v.begin()) << '\n';
	std::cout << "upper_bound at position " << (up - v.begin()) << '\n';

	return 0;
}

// equal_range example
// equal_range example
#include <iostream>     // std::cout
#include <algorithm>    // std::equal_range, std::sort
#include <vector>       // std::vector

bool mygreater(int i, int j) { return (i>j); }

int main() {
	int myints[] = { 10,20,30,30,20,10,10,20 };
	std::vector<int> v(myints, myints + 8);                         // 10 20 30 30 20 10 10 20
	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> bounds;

	// using default comparison:
	std::sort(v.begin(), v.end());                              // 10 10 10 20 20 20 30 30
	bounds = std::equal_range(v.begin(), v.end(), 20);          //          ^        ^

																  // using "mygreater" as comp:
	std::sort(v.begin(), v.end(), mygreater);                     // 30 30 20 20 20 10 10 10
	bounds = std::equal_range(v.begin(), v.end(), 20, mygreater); //       ^        ^

	std::cout << "bounds at positions " << (bounds.first - v.begin());
	std::cout << " and " << (bounds.second - v.begin()) << '\n';

	return 0;
}
#pragma endregion