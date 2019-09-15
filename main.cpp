#include <iostream>
#include "FileLoader.h"
#include "BitProgressBar.h"

using namespace std;

int main() {

    FileLoader file;
    ProgressBar*pb1=new ProgressBar(&file);
    BitProgressBar* pb2=new BitProgressBar(&file);
    file.addFile("C:\\Users\\gurzu\\Desktop\\prova.txt");
    file.addFile("C:\\Users\\gurzu\\Desktop\\prova1.txt");
    file.loadFiles();
    cout<<file.getFileSize("C:\\Users\\gurzu\\Desktop\\prova.txt")<<endl;
    cout<<file.getFileSize("C:\\Users\\gurzu\\Desktop\\prova1.txt")<<endl;

    return 0;
}

