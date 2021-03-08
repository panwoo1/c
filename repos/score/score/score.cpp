#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> set_grade() {
    vector<string> grades;
    string grade;
    string strNum = "";
    int length = grade.length();
    getline(cin, grade);
    for (int i = 0; i < length; i++) {

        if (grade.at(i) == ' ') {
            grades.push_back(strNum.c_str()); //입력값 넣어주기
        }

        else {
            strNum += grade.at(i); //마지막 위치 반환
            continue;
        }
    }

    grades.push_back(strNum.c_str()); //마지막 입력값 넣어주기

    return grades;
}

vector<int> set_weights() {
    vector<int> weights;
    string strInput;
    getline(cin, strInput);
    string strNum = "";

    for (int i = 0; i < strInput.length(); i++) {
        if (strInput.at(i) == ' ') {
            weights.push_back(atoi(strNum.c_str()));
            strNum = "";
        }

        else {
            strNum += strInput.at(i);
            continue;
        }
    }

    weights.push_back(atoi(strNum.c_str()));

    return weights;
}

int set_threshold() {
    int threshold;
    cin >> threshold;
    return threshold;
}

int solution(vector<string> grades, vector<int> weights, int threshold) {
    int answer = 0;
    int size = grades.size();
    int each_weights[1000] = { 0 };
    int total_weights = 0;

    int grade[9] = { 10, 9, 8, 7, 6, 5, 4, 3, 0 };
    for (int i = 0; i < grades.size(); i++) {
        if (grades[i] == "A+") each_weights[i] = grade[0] * weights[i];
        else if (grades[i] == "A0") each_weights[i] = grade[1] * weights[i];
        else if (grades[i] == "B+") each_weights[i] = grade[2] * weights[i];
        else if (grades[i] == "B0") each_weights[i] = grade[3] * weights[i];
        else if (grades[i] == "C+") each_weights[i] = grade[4] * weights[i];
        else if (grades[i] == "C0") each_weights[i] = grade[5] * weights[i];
        else if (grades[i] == "D+") each_weights[i] = grade[6] * weights[i];
        else if (grades[i] == "D0") each_weights[i] = grade[7] * weights[i];
        else if (grades[i] == "F") each_weights[i] = grade[8] * weights[i];
    }

    for (int j = 0; j < grades.size(); j++) {
        total_weights += each_weights[j];
    }

    answer = total_weights - threshold;
    cout << answer << endl;
    return answer;
}

int main() {
    set_grade();
    set_weights();
    set_threshold();
    int result = solution(set_grade(), set_weights(), set_threshold());

    return result;
}