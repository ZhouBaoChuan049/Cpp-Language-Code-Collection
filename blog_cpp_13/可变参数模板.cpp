// Test.cpp
#include "ModernList.h"
#include<iostream>
using namespace std;
int main(){
    bit::list<pair<string, int>> lt1;
    pair<string, int> kv("苹果", 1);
    lt1.emplace_back("苹果", 1);
    return 0;
}