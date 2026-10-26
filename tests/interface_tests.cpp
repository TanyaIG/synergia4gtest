#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "binary_tree_interface.h"
#include "heap_interface.h"
#include "queue_interface.h"

#include <optional>
#include <string>

using ::testing::Return;

// Mock-объекты позволяют проверить контракт вызовов, не реализуя структуры данных.
template <typename T>
class MockQueue : public IQueue<T> {
public:
    MOCK_METHOD(void, push, (const T& value), (override));
    MOCK_METHOD(std::optional<T>, pop, (), (override));
};

template <typename T>
class MockHeap : public IHeap<T> {
public:
    MOCK_METHOD(void, push, (const T& value), (override));
    MOCK_METHOD(std::optional<T>, pop, (), (override));
};

template <typename T>
class MockBinaryTree : public IBinaryTree<T> {
public:
    MOCK_METHOD(void, push, (const T& value), (override));
    MOCK_METHOD(std::optional<T>, pop, (), (override));
    MOCK_METHOD(bool, search, (const T& value), (const, override));
};

TEST(QueueInterfaceTest, PushForwardsValueToImplementation) {
    MockQueue<int> queue;
    EXPECT_CALL(queue, push(42)).Times(1);
    queue.push(42);
}

TEST(QueueInterfaceTest, PopReturnsValueProvidedByImplementation) {
    MockQueue<int> queue;
    EXPECT_CALL(queue, pop()).WillOnce(Return(std::optional<int>{7}));
    EXPECT_EQ(queue.pop(), std::optional<int>{7});
}

TEST(QueueInterfaceTest, PopCanRepresentEmptyQueue) {
    MockQueue<int> queue;
    EXPECT_CALL(queue, pop()).WillOnce(Return(std::optional<int>{}));
    EXPECT_EQ(queue.pop(), std::nullopt);
}

TEST(HeapInterfaceTest, PushForwardsValueToImplementation) {
    MockHeap<int> heap;
    EXPECT_CALL(heap, push(15)).Times(1);
    heap.push(15);
}

TEST(HeapInterfaceTest, PopReturnsPriorityElementProvidedByImplementation) {
    MockHeap<int> heap;
    EXPECT_CALL(heap, pop()).WillOnce(Return(std::optional<int>{99}));
    EXPECT_EQ(heap.pop(), std::optional<int>{99});
}

TEST(HeapInterfaceTest, PopCanRepresentEmptyHeap) {
    MockHeap<int> heap;
    EXPECT_CALL(heap, pop()).WillOnce(Return(std::optional<int>{}));
    EXPECT_EQ(heap.pop(), std::nullopt);
}

TEST(BinaryTreeInterfaceTest, PushForwardsValueToImplementation) {
    MockBinaryTree<int> tree;
    EXPECT_CALL(tree, push(23)).Times(1);
    tree.push(23);
}

TEST(BinaryTreeInterfaceTest, SearchReturnsTrueForFoundValue) {
    MockBinaryTree<int> tree;
    EXPECT_CALL(tree, search(23)).WillOnce(Return(true));
    EXPECT_TRUE(tree.search(23));
}

TEST(BinaryTreeInterfaceTest, SearchReturnsFalseForMissingValue) {
    MockBinaryTree<int> tree;
    EXPECT_CALL(tree, search(404)).WillOnce(Return(false));
    EXPECT_FALSE(tree.search(404));
}

TEST(BinaryTreeInterfaceTest, PopReturnsValueProvidedByImplementation) {
    MockBinaryTree<int> tree;
    EXPECT_CALL(tree, pop()).WillOnce(Return(std::optional<int>{23}));
    EXPECT_EQ(tree.pop(), std::optional<int>{23});
}

TEST(BinaryTreeInterfaceTest, PopCanRepresentEmptyTree) {
    MockBinaryTree<int> tree;
    EXPECT_CALL(tree, pop()).WillOnce(Return(std::optional<int>{}));
    EXPECT_EQ(tree.pop(), std::nullopt);
}
