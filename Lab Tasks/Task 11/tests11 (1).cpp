// Test cases
TEST(PostfixEvaluationTest, BasicTest1) {
    std::string expression = "3 4 + 5 * 6 -";  // equivalent to (3 + 4) * 5 - 6 = 19
    std::string result = evaluatePostfixExpression(expression);
    EXPECT_EQ(result, "19");
}

TEST(PostfixEvaluationTest, BasicTest2) {
    std::string expression = "1 2 3 * +";  // equivalent to 1 + (2 * 3) = 7
    std::string result = evaluatePostfixExpression(expression);
    EXPECT_EQ(result, "7");
}

TEST(PostfixEvaluationTest, DivisionByZeroTest) {
    std::string expression = "5 0 /";  // division by zero error
    std::string result = evaluatePostfixExpression(expression);
    EXPECT_EQ(result, "Error: division by zero");
}

TEST(PostfixEvaluationTest, BasicTest3) {
    std::string expression = "2 3 * + 4 -";  // equivalent to (2 * 3) + 4 = 10
    std::string result = evaluatePostfixExpression(expression);
    EXPECT_EQ(result, "10");
}

TEST(PostfixEvaluationTest, InvalidExpressionTest) {
std::string expression = "1 2 3 * + +"; // invalid expression
std::string result = evaluatePostfixExpression(expression);
EXPECT_EQ(result, "Error: invalid expression");
}

TEST(PostfixEvaluationTest, MissingOperandTest) {
std::string expression = "2 +"; // invalid expression
std::string result = evaluatePostfixExpression(expression);
EXPECT_EQ(result, "Error: invalid expression");
}

TEST(PostfixEvaluationTest, ExtraOperandTest) {
std::string expression = "2 3 + 4"; // invalid expression
std::string result = evaluatePostfixExpression(expression);
EXPECT_EQ(result, "Error: invalid expression");
}

// Tests for countNodes() function
TEST(CountNodesTest, EmptyTree) {
    Node* root = nullptr;
    EXPECT_EQ(0, countNodes(root));
}

TEST(CountNodesTest, SingleNodeTree) {
    Node* root = new Node{1, nullptr, nullptr};
    EXPECT_EQ(1, countNodes(root));
    delete root;
}

TEST(CountNodesTest, BinaryTree) {
    Node* root = new Node{1, nullptr, nullptr};
    root->left = new Node{2, nullptr, nullptr};
    root->right = new Node{3, nullptr, nullptr};
    root->left->left = new Node{4, nullptr, nullptr};
    root->left->right = new Node{5, nullptr, nullptr};
    root->right->left = new Node{6, nullptr, nullptr};
    root->right->right = new Node{7, nullptr, nullptr};

    EXPECT_EQ(7, countNodes(root));

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
}
