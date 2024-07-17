// test cases
TEST(AVLTreeTest, InsertAndSearchTest) {
    AVLTree tree;
    tree.root = tree.insert(tree.root, 5);
    tree.root = tree.insert(tree.root, 4);
    tree.root = tree.insert(tree.root, 6);
    tree.root = tree.insert(tree.root, 2);

    EXPECT_TRUE(tree.search(tree.root, 5));
    EXPECT_FALSE(tree.search(tree.root, 7));
    EXPECT_TRUE(tree.search(tree.root, 2));
    EXPECT_FALSE(tree.search(tree.root, 3));
}

TEST(AVLTreeTest, DeleteTest) {
    AVLTree tree;
    tree.root = tree.insert(tree.root, 5);
    tree.root = tree.insert(tree.root, 4);
    tree.root = tree.insert(tree.root, 6);
    tree.root = tree.insert(tree.root, 2);

    tree.root = tree.delete_node(tree.root, 5);
    EXPECT_FALSE(tree.search(tree.root, 5));
    EXPECT_TRUE(tree.search(tree.root, 4));
    EXPECT_TRUE(tree.search(tree.root, 6));
    EXPECT_TRUE(tree.search(tree.root, 2));
}

TEST(AVLTreeTest, InsertDuplicatesTest) {
    AVLTree tree;
    tree.root = tree.insert(tree.root, 5);
    tree.root = tree.insert(tree.root, 5);
    tree.root = tree.insert(tree.root, 5);

    EXPECT_TRUE(tree.search(tree.root, 5));
    EXPECT_EQ(tree.size(tree.root), 1);
}

TEST(AVLTreeTest, DeleteNonexistentNodeTest) {
    AVLTree tree;
    tree.root = tree.insert(tree.root, 5);
    tree.root = tree.insert(tree.root, 4);

    tree.root = tree.delete_node(tree.root, 6); // try to delete nonexistent node
    EXPECT_TRUE(tree.search(tree.root, 5));
    EXPECT_TRUE(tree.search(tree.root, 4));
    EXPECT_EQ(tree.size(tree.root), 2);
}

TEST(AVLTreeTest, DeleteRootNodeTest) {
    AVLTree tree;
    tree.root = tree.insert(tree.root, 5);
    tree.root = tree.insert(tree.root, 4);
    tree.root = tree.insert(tree.root, 6);

    tree.root = tree.delete_node(tree.root, 5);
    EXPECT_FALSE(tree.search(tree.root, 5));
    EXPECT_TRUE(tree.search(tree.root, 4));
    EXPECT_TRUE(tree.search(tree.root, 6));
    EXPECT_EQ(tree.size(tree.root), 2);
}

TEST(AVLTreeTest, DeleteNodeWithOneChildTest) {
    AVLTree tree;
    tree.root = tree.insert(tree.root, 5);
    tree.root = tree.insert(tree.root, 4);
    tree.root = tree.insert(tree.root, 6);

    tree.root = tree.delete_node(tree.root, 4);
    EXPECT_FALSE(tree.search(tree.root, 4));
    EXPECT_TRUE(tree.search(tree.root, 5));
    EXPECT_TRUE(tree.search(tree.root, 6));
    EXPECT_EQ(tree.size(tree.root), 2);
}

TEST(AVLTreeTest, DeleteNodeWithTwoChildrenTest) {
    AVLTree tree;
    tree.root = tree.insert(tree.root, 5);
    tree.root = tree.insert(tree.root, 4);
    tree.root = tree.insert(tree.root, 6);
    tree.root = tree.insert(tree.root, 2);
    tree.root = tree.insert(tree.root, 3);

    tree.root = tree.delete_node(tree.root, 4);
    EXPECT_FALSE(tree.search(tree.root, 4));
    EXPECT_TRUE(tree.search(tree.root, 5));
    EXPECT_TRUE(tree.search(tree.root, 6));
    EXPECT_TRUE(tree.search(tree.root, 2));
    EXPECT_TRUE(tree.search(tree.root, 3));
    EXPECT_EQ(tree.size(tree.root), 4);
}
