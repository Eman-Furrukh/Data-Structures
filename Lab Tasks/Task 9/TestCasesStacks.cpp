#include <gtest/gtest.h>
#include "Header.h"
//include header file
using namespace std;

stack s1; // create object of stack class

TEST (task1, T1){
    s1.push(1);
    s1.push(2);
    s1.push(3);
    node<int>* top=s1.Peek();
    EXPECT_EQ(3,top->val);
}

TEST (task1, T2){
    s1.pop();
    node<int>* top=s1.Peek();
    EXPECT_EQ(2,top->val);
    s1.pop();
    top=s1.Peek();
    EXPECT_EQ(1,top->val);

}
TEST (task1, T3){
    s1.push(3);
    s1.push(4);
    EXPECT_EQ(3,s1.sizeofstack());// if size is key word change it it sizeOfQueue.
}

TEST(task2, T1) {
   EXPECT_TRUE(validate("Text1.txt"));
}

TEST(task2, T2) {
   EXPECT_FALSE(validate("Text2.txt"));
}

TEST(task2, T3) {
   EXPECT_FALSE(validate("Text3.txt"));
}

TEST (task2, T4){
    char str[]="M A%! DAm#";
    EXPECT_TRUE(checkPal(str));
}



TEST (task2, T5){
    char str[] ="% Universi ty % ";   
    EXPECT_FALSE(checkPal(str));
}
/*
*/

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

