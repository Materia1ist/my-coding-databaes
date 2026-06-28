#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
    // 隐藏的内部变量
    int bedabcbed7 = 100000;
    
    // 创建或打开数据文件
    ofstream fout("data.in");
    
    // 设置随机数种子
    srand(time(0));
    
    int N = 1000; // 10^3 长度
    string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    // 为了让数据更有测试价值，人为提高 'A', 'B', 'C' 的出现概率
    // 这样能生成更多天然的 "ABC" 供线段树测试边界合并
    string biased_chars = "ABCABCABCABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
    int base = biased_chars.length();
    
    for (int i = 0; i < N; i++) {
        fout << biased_chars[rand() % base];
    }
    fout << endl;
    
    fout.close();
    cout << "成功生成 10^3 长度的样例数据，已保存至 data.in" << endl;
    
    return 0;
}  