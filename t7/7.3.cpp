/*3.已知有一个整形数组a，其内容为1 3 5 7 9 2 4 6 8 10。
先对数组进行升序排序，再使用它产生向量b，然后再在向量的尾部追回11，
并按降序输出向量的内容和capacity()内容。*/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
/*************************************************************************/
int main()
{
	int a[10] = { 1,3,5,7,9,2,4,6,8,10 };
	sort(a, a + 10);
	copy(a, a + 10, ostream_iterator<int>(cout, " "));
	cout << endl;

	vector <int> b(a, a + 10);//定义向量b
	b.push_back(11);

	vector <int>::iterator p = b.begin();//定义向量指针p
	while (p != b.end()){
		cout << *p << " ";
		p++;
	}
	cout << endl;

	reverse_copy(b.begin(), b.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << b.capacity() << endl;

	return 0;
}
/*************************************************************************/