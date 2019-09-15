//
// Created by utente on 16/09/2016.
//



#include <gtest/gtest.h>
#include "../FileLoader.h"
#include "../BitProgressBar.h"


class FileLoaderTest : public ::testing::Test {

protected:

        FileLoader file;
        ProgressBar*pb1=new ProgressBar(&file);


        string nfile= "C:\\Users\\gurzu\\Desktop\\prova.txt";
        string nfile2= "C:\\Users\\gurzu\\Desktop\\prova1.txt";

};

TEST_F(FileLoaderTest, DefaultConstructor) {

    ASSERT_EQ(0, file.getNumDoc());
    ASSERT_EQ(0, file.getValue());
    ASSERT_EQ(0, file.getSizeValue());
    ASSERT_EQ(0, file.getCurrentBitSize());
}



TEST_F(FileLoaderTest, RegisterObserver){

    ASSERT_EQ((*file.getObservers().begin()),pb1);
}



TEST_F(FileLoaderTest, RemoveObserver){

    ASSERT_EQ((*file.getObservers().begin()),pb1);
    delete pb1;
    ASSERT_EQ((*file.getObservers().begin()), nullptr);
}



TEST_F(FileLoaderTest, RegisterMultipleObservers){

    BitProgressBar* pb2 =new BitProgressBar(&file);
    auto it=file.getObservers().begin();
    ASSERT_EQ(pb1, *it);
    ASSERT_EQ(*(++it), pb2);
}



TEST_F(FileLoaderTest, AddFiles ){

    file.addFile(nfile);
    auto itr=file.getFilesToUpload().begin();
    ASSERT_EQ(*itr, nfile);
    ASSERT_EQ(1, file.getNumDoc());
    file.addFile(nfile2);
    ASSERT_EQ(*(++itr), nfile2);
    ASSERT_EQ(2,file.getNumDoc());
}




TEST_F(FileLoaderTest, LoadFiles){

    file.addFile("C:\\Users\\gurzu\\Desktop\\prova.txt");
    file.addFile("C:\\Users\\gurzu\\Desktop\\prova1.txt");
    file.loadFiles();
    string filename="C:\\Users\\gurzu\\Desktop\\prova1.txt";
    ASSERT_EQ(filename,file.getNomeFile());
    ASSERT_EQ(2,file.getValue());
    ASSERT_EQ(94,file.getCurrentBitSize());
}




TEST_F(FileLoaderTest, getPercentageTest) {

    file.setValue(3);
    file.setNumDoc(10);
    ASSERT_EQ(30,file.getPercentage());
}




TEST_F(FileLoaderTest, getBitPercentageTest){

    file.setCurrentBitSize(50);
    file.setSizeValue(100);
    ASSERT_EQ(50, file.getBitPercentage());
}

