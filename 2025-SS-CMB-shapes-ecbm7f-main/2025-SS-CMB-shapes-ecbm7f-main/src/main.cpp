#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Shape.h"

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;
using std::fixed;
using std::setprecision;

int main(int argc, char *argv[]) {
    // Do not touch
    string file;
    switch (argc) {
    case 1:
      file = "./argfile.in"; // default input file
      break;
    case 2:
      file = argv[1]; // file given from command line
      break;
    default:
      cout << "incorrect number of command line arguments" << endl;
      cout << "usage: " << argv[0] << " [file]" << endl;
      return 1;
      break;
    }
    
    std::ifstream fin(file); //connects to file
    if (!fin) {
      cout << "ERROR connecting to file: " << file << endl;
      exit(1);
    }
    cout << fixed << setprecision(2);
    //OK to touch code below
    string shapeName;
double l, w, h;

while (fin >> shapeName >> l >> w >> h) {
    Shape* shape = createShape(shapeName, l, w, h);

    cout << shape->getName() << endl;
cout << "TSA: " << shape->getTSA() << endl;
cout << "Vol: " << shape->getVolume() << endl;
cout << endl;  // blank line

    delete shape;
}
//read in from your file, then print your shapes' data!

    fin.close(); //always remember to close your file streams!

    return 0;
}
