#include <iostream>
#include <string>

#include "decl.h"

using namespace std;

Env::Env() {
    string line;
    cout << "Please input the maze's size(bigger than 1): " << endl;
    cin >> this->maze_size;
    cin.get();
    this->maze = new char* [this->maze_size];
    cout << "Next you need to build the maze yourself.Only two values are acceptable: *(for \"wall\") or #(for \"way).\"" << endl;
    for(int i = 0; i < this->maze_size; i ++) {
        int idx = 0;
        this->maze[i] = new char [this->maze_size];
        switch (i) {
            case 1:
                cout << "Type in the " << this->maze_size << " values of the " << i + 1<< "st line(separated by space):" << endl;
                break;
            case 2:
                cout << "Type in the " << this->maze_size << " values of the " << i + 1<< "nd line(separated by space):" << endl;
                break;
            case 3:
                cout << "Type in the " << this->maze_size << " values of the " << i + 1<< "rd line(separated by space):" << endl;
                break;
            default:
                cout << "Type in the " << this->maze_size << " values of the " << i + 1<< "th line(separated by space):" << endl;
                break;
        }
        getline(cin, line);
        for(int j = 0; j < line.size(); j ++) {
            if(line[j] == '#' || line[j] == '*') {
                this->maze[i][idx] = line[j];
                idx ++;
            }
        }
    }
    // define entrance and exit positions
    this->entrance.column = this->entrance.row = this->entrance.distance = 0;
    this->exit.column = this->exit.row = this->maze_size - 1;
    // enqueue the entrance
}
