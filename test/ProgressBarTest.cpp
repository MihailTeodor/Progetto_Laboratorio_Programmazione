//
// Created by utente on 19/09/2016.
//


#include <gtest/gtest.h>
#include "../FileLoader.h"


class ProgressBarTest : public ::testing::Test {
protected:

    FileLoader file;
    ProgressBar* pb=new ProgressBar(&file);
};

TEST_F(ProgressBarTest, DefaultConstructorTest){

    Subject* subj=&file;
    ASSERT_EQ(0,pb->getPercentuale());
    ASSERT_EQ(subj, pb->getFile());
    ASSERT_EQ(*file.getObservers().begin(),pb );

}

TEST_F(ProgressBarTest, Destructor_Test){

    delete pb;
    ASSERT_EQ(nullptr, *file.getObservers().begin());
}

TEST_F(ProgressBarTest, Update_TEST){

    file.setValue(5);
    file.setNumDoc(10);
    pb->update();
    ASSERT_EQ(50,pb->getPercentuale());
}