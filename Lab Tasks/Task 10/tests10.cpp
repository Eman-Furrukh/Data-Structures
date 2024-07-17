#include <gtest/gtest.h>
#include <string>

using namespace std;

bool isBalanced(string expr);

// Test that a balanced expression returns true
TEST(IsBalancedTest, BalancedExpression) {
    string balancedExpr1 = "(a+b)*(c-d)/[e+f]";
    string balancedExpr2 = "((a+b)*(c-d))/(e+f)";
    EXPECT_TRUE(isBalanced(balancedExpr1));
    EXPECT_TRUE(isBalanced(balancedExpr2));
}

// Test that an unbalanced expression returns false
TEST(IsBalancedTest, UnbalancedExpression) {
    string unbalancedExpr1 = "(a+b)*[c-d)/{e+f}";
    string unbalancedExpr2 = "(a+b)*c-d)/{e+f}";
    EXPECT_FALSE(isBalanced(unbalancedExpr1));
    EXPECT_FALSE(isBalanced(unbalancedExpr2));
}

// Tests for the infixToPrefix function
TEST(InfixToPrefixTest, BasicTest) {
    string expr = "A+B";
    string expectedPrefix = "+AB";
    EXPECT_EQ(infixToPrefix(expr), expectedPrefix);
}

TEST(InfixToPrefixTest, AdvancedTest) {
    string expr = "A+(B-C)*D/E";
    string expectedPrefix = "+A/*-BCDE";
    EXPECT_EQ(infixToPrefix(expr), expectedPrefix);
}

TEST(InfixToPrefixTest, EmptyExpressionTest) {
string expr = "";
string expectedPrefix = "";
EXPECT_EQ(infixToPrefix(expr), expectedPrefix);
}

TEST(InfixToPrefixTest, SingleOperandTest) {
string expr = "A";
string expectedPrefix = "A";
EXPECT_EQ(infixToPrefix(expr), expectedPrefix);
}

TEST(InfixToPrefixTest, SingleOperatorTest) {
string expr = "+";
string expectedPrefix = "+";
EXPECT_EQ(infixToPrefix(expr), expectedPrefix);
}

TEST(InfixToPrefixTest, InvalidExpressionTest) {
string expr = "A+B)";
EXPECT_THROW(infixToPrefix(expr), invalid_argument);
}

TEST(InfixToPrefixTest, MultipleParenthesesTest) {
string expr = "(A+B)(C-D)";
string expectedPrefix = "+AB-CD";
EXPECT_EQ(infixToPrefix(expr), expectedPrefix);
}

TEST(InfixToPrefixTest, ComplexExpressionTest) {
string expr = "A+(B-C)(D/E^F+G)-H";
string expectedPrefix = "-+A-/BC+DE^FGH";
EXPECT_EQ(infixToPrefix(expr), expectedPrefix);
}