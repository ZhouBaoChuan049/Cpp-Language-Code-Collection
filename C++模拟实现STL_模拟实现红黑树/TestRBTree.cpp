#include"RBTree.h"
void TestOfRBTree(){
    vector<pair<int, int>> v = {
    {40,40}, {10,10}, {70,70}, {25,25}, {5,5},
    {60,60}, {15,15}, {80,80}, {30,30}, {1,1},
    {55,55}, {20,20}, {65,65}, {35,35}, {50,50},
    {75,75}, {33,33}, {45,45}, {85,85}, {37,37}
    };
    RBTree<int, int> tree01;
    for (auto e : v) {
        tree01.Insert(e);
    }
    tree01.Inorder();
    cout << tree01.IsBalanceTree() << endl;
    /*cout << tree01.Height() << endl;
    cout << tree01.Size() << endl;
    cout << tree01.Find(make_pair(35, 35));*/
}
int main()
{
    TestOfRBTree();
	return 0;
}