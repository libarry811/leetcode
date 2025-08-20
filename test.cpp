//#include <iostream>
//#include <iomanip>
//#include <cmath>
//using namespace std;
//
//// 正向计算：绩点 -> 成绩
//double gpaToScore(double gpa) {
//    if (gpa >= 3.3) {
//        return (89 - (3.7 - gpa) * 5 / 0.4) * 0.8;
//    }
//    else if (gpa >= 3.0) {
//        return (84 - (3.3 - gpa) * 3 / 0.3) * 0.8;
//    }
//    else {
//        return (81 - (3.0 - gpa) * 4 / 0.3) * 0.8;
//    }
//}
//
//// 逆向计算：成绩 -> 绩点
//double scoreToGpa(double score) {
//    if (score >= 67.2) {  // 对应原代码 s >= 3.3 的区间
//        return 3.7 - (89 - score / 0.8) * 0.4 / 5;
//    }
//    else if (score >= 64.8) {  // 对应原代码 3.0 <= s <= 3.29 的区间
//        return 3.3 - (84 - score / 0.8) * 0.3 / 3;
//    }
//    else {  // 对应原代码 s < 3.0 的区间
//        return 3.0 - (81 - score / 0.8) * 0.3 / 4;
//    }
//}
//
//int main()
//{
//    for (int i = 0; i < 50; i++)
//    {
//        double input;
//        cin >> input;
//
//        // 设置输出精度
//        cout << fixed << setprecision(2);
//
//        if (input >= 0 && input <= 4) {  // 输入是绩点
//            cout << gpaToScore(input) << endl;
//        }
//        else if (input >= 32.8 && input <= 74.2) {  // 输入是成绩
//            cout << scoreToGpa(input) << endl;
//        }
//        else {
//            cout << "输入值超出有效范围！" << endl;
//        }
//    }
//    return 0;
//}