#include <gtest/gtest.h>

#include <string>
#include <utility>  // For std::move

#include "technikumSTL/UniquePtr.h"

// simple Entity structure for testing
struct Entity
{
  int id;
  explicit Entity(int newId) : id(newId)
  {
  }
};

// simple test to check if UniquePtr can be constructed and accessed
TEST(UniquePtrTest, CanConstructAndAccess)
{
  UniquePtr<Entity> entityPointer(new Entity(123));
  ASSERT_TRUE(entityPointer);
  EXPECT_EQ(entityPointer->id, 123);
}

// test move semantics of UniquePtr
TEST(UniquePtrTest, CanMoveUniquePtr)
{
  UniquePtr<Entity> originalPointer(new Entity(123));
  UniquePtr<Entity> movedPointer(std::move(originalPointer));

  ASSERT_FALSE(originalPointer);  // originalPointer should be null after move
  ASSERT_TRUE(movedPointer);
  EXPECT_EQ(movedPointer->id, 123);
}

// test  reset functionality
TEST(UniquePtrTest, CanResetUniquePtr)
{
  UniquePtr<Entity> entityPointer(new Entity(123));
  entityPointer.Reset(new Entity(456));

  ASSERT_TRUE(entityPointer);
  EXPECT_EQ(entityPointer->id, 456);
}

// test release functionality
TEST(UniquePtrTest, CanReleaseUniquePtr)
{
  UniquePtr<Entity> entityPointer(new Entity(123));
  Entity* rawPointer = entityPointer.Release();

  ASSERT_FALSE(entityPointer);  // entityPointer should be null after release
  ASSERT_TRUE(rawPointer);
  EXPECT_EQ(rawPointer->id, 123);

  delete rawPointer;  // clean up raw pointer.
}

// test swap functionality
TEST(UniquePtrTest, CanSwapUniquePtrs)
{
  UniquePtr<Entity> pointerOne(new Entity(123));
  UniquePtr<Entity> pointerTwo(new Entity(456));

  pointerOne.Swap(pointerTwo);

  ASSERT_TRUE(pointerOne);
  ASSERT_TRUE(pointerTwo);
  EXPECT_EQ(pointerOne->id, 456);
  EXPECT_EQ(pointerTwo->id, 123);
}

// A flag to check if the custom deleter was called
bool isDeleted = false;

// custom deleter that logs when it deletes an object.
struct CustomDeleter
{
  void operator()(Entity* ptr)
  {
    isDeleted = true;
    delete ptr;
  }
};

// test UniquePtr with a custom deleter
TEST(UniquePtrTest, CustomDeleterIsInvoked)
{
  {
    UniquePtr<Entity, CustomDeleter> entityPointer(new Entity(123));
  }  // entityPointer goes out of scope here

  EXPECT_TRUE(isDeleted);
}