#include"SearchBanneryTree.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	vector<string> vs = { "Æ»¹û","Ïã½¶","²¤ÂÜ","Æ»¹û","Ïã½¶",
		"²¤ÂÜ","²İİ®","Æ»¹û","Ïã½¶","²¤ÂÜ","Æ»¹û","Ïã½¶",
		"²¤ÂÜ","Î÷¹Ï","²İİ®","Î÷¹Ï" };
	key_value::SBTree<string, int> counttree;
	vector<string>::iterator it = vs.begin();
	while (it!=vs.end())
	{
		auto n = counttree.Find(*it);
		if (n == nullptr)
		{
			counttree.Insert(*it,1);
		}
		else if (n != nullptr)
		{
			n->_value++;
		}
		it++;
	}
	counttree.Inorder();
	return 0;
}