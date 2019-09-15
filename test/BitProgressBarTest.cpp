//
// Created by utente on 20/09/2016.
//


#include <gtest/gtest.h>
#include "../FileLoader.h"
#include "../BitProgressBar.h"


class BitProgressBarTest : public ::testing::Test {
protected:
    FileLoader file;
    BitProgressBar* pb=new BitProgressBar(&file);
};


TEST_F(BitProgressBarTest, DefaultConstructorTest){
    Subject* subj=&file;
    ASSERT_EQ(0,pb->getBitPercentuale());
    ASSERT_EQ(subj, pb->getSubject());
    ASSERT_EQ(*file.getObservers().begin(),pb );
}


TEST_F(BitProgressBarTest, Destructor_Test){
    delete pb;
    ASSERT_EQ(nullptr, *file.getObservers().begin());
}


TEST_F(BitProgressBarTest, Update_TEST){
    file.setCurrentBitSize(5);
    file.setSizeValue(10);
    pb->update();
    ASSERT_EQ(50,pb->getBitPercentuale());
}