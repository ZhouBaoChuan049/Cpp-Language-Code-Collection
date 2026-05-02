#include "SeparateChaining_HashTable.h"
using namespace Separate_Chaining;
void test01()
{
    HashBucket<int, int> hash;
    vector<pair<int, int>> v = {
        {0,0},{1,1},{2,2},{3,3},{4,4},{31,31}
    };
    for (auto e : v)
        hash.Insert(e);
}
int main()
{
    test01();
	return 0;
}