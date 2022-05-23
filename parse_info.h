#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "stime.h"

using namespace std;

std::vector<string> split(std::string str, char delimeter = ' '){
    std::vector<string> str_arr;
    string buffer;
    istringstream str_stm(str); // 문자열을 스트림으로 만든다

    while(std::getline(str_stm, buffer, delimeter)) {
        str_arr.push_back(buffer); // delimeter 기준으로 잘린 문자열 반환
    }

    return str_arr;
}

class STimeParser {
public:
    static std::vector<std::vector<STime>> get_stime(vector<string> filenames, int dow) {
        std::vector<std::vector<STime>> t_vector(dow,std::vector<STime>());

        std::ifstream ifst;

        for(const auto& filename : filenames)
        {
            string buffer;
            ifst.open(filename);
            if(ifst.good()) // 파일이 잘 열렸다면
            {
                while(std::getline(ifst, buffer)) // 한줄씩 읽어들인다.
                {
                    vector<string> list = split(buffer, ',');
                    int dow = std::stoi(list[0].c_str());
                    float start = std::stof(list[1].c_str());
                    float end = std::stof(list[2].c_str());

                    STime t(dow, start, end);
                    t_vector[dow].push_back(t); // 해당하는 요일에 값을 넣는다.
                }
            }
            else {
                cerr << filename << "파일을 열 수 없음." << endl;
            }
            ifst.close();
        }

        return t_vector;
    }

};