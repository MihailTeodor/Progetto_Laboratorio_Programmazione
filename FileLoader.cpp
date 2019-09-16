//
// Created by utente on 12/09/2016.
//


#include <iostream>
#include "FileLoader.h"

FileLoader ::FileLoader() : numDoc(0),value(0), sizeValue(0), currentBitSize(0){ }


void FileLoader::loadFiles() {
    while(getNumFilesToUpload()>0) {
        nomeFile = *filesToUpload.begin();
        ifstream file(nomeFile, ios::in | ios::binary);
        if (!file) {
            cerr << "Errore nell'apertura del file: " << nomeFile << endl;
        }
        else {
            cout << "File " << nomeFile << " aperto con successo" << endl;
            value++;
            currentBitSize+=getFileSize(nomeFile);
        }
        filesToUpload.pop_front();
        notifyObserver();
    }
}


FileLoader::~FileLoader() {
    observers.clear();
    file.close();
    cout<<"File chiusi"<<endl;
}


int FileLoader::getPercentage() {
    int val= (100*value)/numDoc;
    return val;
}


streampos FileLoader::getFileSize(const string filename) {
    streampos fsize=0;
    ifstream file(filename, ios::binary);
    fsize=file.tellg();
    file.seekg(0, ios::end);
    fsize= file.tellg()-fsize;
    file.close();
    return fsize;
}


double  FileLoader::getBitPercentage() {
    double val=(100*currentBitSize)/sizeValue;
    return val;
}

