#include <fstream>
#include <iostream>
using namespace std ;
int main () {
    ifstream inputFile("C++.txt");
    ofstream outputFile("C++.txt");
    fstream file ("C++.txt",ios::in|ios::out);
    return 0;
   
}