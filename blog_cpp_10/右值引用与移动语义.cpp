#include<iostream>
#include<vector>
#include<string>
using namespace std;
//int main()
//{
//    string&& r3 = string("Ciallo");        
//	return 0;
//}
//int main() {
//    std::string&& r3 = string("Ciallo");
//    r3 = "Hello";
//    return 0;
//}
//#include <iostream>
//using namespace std;
//void f(int& x)
//{
//    std::cout << "Lvalue reference overload: f(" << x << ")" << '\n';
//}
//void f(const int& x)
//{
//    std::cout << "Const lvalue reference overload: f(" << x << ")" << '\n';
//}
//void f(int&& x)
//{
//    std::cout << "Rvalue reference overload: f(" << x << ")" << '\n';
//}
//int main()
//{
//    int a = 0;
//    const int b = 0;
//    f(a);
//    f(b);
//    f(1);
//    f(move(a));
//    return 0;
//}
     // 这里的传值返回拷贝代价就太大了
//class Solution
//{
//public:
//    vector<vector<int>> generate(int numRows) {
//        vector<vector<int>> vv(numRows);
//        for (int i = 0; i < numRows; ++i)
//            vv[i].resize(i + 1, 1);
//        for (int i = 2; i < numRows; ++i) {
//            for (int j = 1; j < i; ++j)
//                vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
//        }
//        return vv;
//    }
//};
//int main(){
//    vector<vector<int>> ret = Solution().generate(5);
//    return 0;
//}
class Solution
{
public:
    void generate(vector<vector<int>> ret,int numRows) {
        vector<vector<int>> vv(numRows);
        for (int i = 0; i < numRows; ++i)
            vv[i].resize(i + 1, 1);
        for (int i = 2; i < numRows; ++i) {
            for (int j = 1; j < i; ++j)
                vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
        }
        ret = vv;
        return ;
    }
};
int main(){
    vector<vector<int>> _ret;
    Solution().generate(_ret,5);
    return 0;
}
