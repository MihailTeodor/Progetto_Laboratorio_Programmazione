#ifndef FILELOADER_H
#define FILELOADER_H
#include <fstream>
#include <list>
#include <cstring>
#include <algorithm>
#include "subject.h"
#include "observer.h"
#include "progressBar.h"
#include <QObject>

using namespace std;

class FileLoader: public QObject, public Subject{
    Q_OBJECT
public:
    FileLoader ();

    virtual ~FileLoader();

    void registerObserver (Observer* o)override {
        observers.push_back(o);
    }

    void removeObserver (Observer* o)override {
        observers.remove(o);
    }

    int getNumDoc() const {
        return numDoc;
    }

    const list<Observer *> &getObservers() const {
        return observers;
    }

    int getValue() const {
        return value;
    }

   const list<string> &getFilesToUpload() const {
        return filesToUpload;
    }

    const string &getNomeFile() const {
        return nomeFile;
    }

    double getSizeValue() const {
        return sizeValue;
    }

    double getCurrentBitSize() const {
        return currentBitSize;
    }

    void addFile(const string fileName){
        filesToUpload.push_back(fileName);
        sizeValue+=getFileSize(fileName);
        numDoc++;
    }

public slots:
    void loadFiles();

public:
    int getNumFilesToUpload()const{
        return filesToUpload.size();
    }

    int getPercentage();

    void notifyObserver() override {
        list<Observer*>::const_iterator  it;
        for( it = begin(observers); it != end(observers); ++it){
            (*it)-> update();
        }
    }

   double getBitPercentage();
   streampos getFileSize(const string );

   void setNumDoc(int numDoc) {
       FileLoader::numDoc = numDoc;
   }

   void setValue(int value) {
       FileLoader::value = value;
   }

   void setSizeValue(double sizeValue) {
       FileLoader::sizeValue = sizeValue;
   }

   void setCurrentBitSize(double currentBitSize) {
       FileLoader::currentBitSize = currentBitSize;
   }

private:
    list <Observer*> observers;
    list<string> filesToUpload;
    ifstream file;
    int numDoc;
    string nomeFile;
    int value;
    double sizeValue;
    double currentBitSize;
};

#endif // FILELOADER_H
