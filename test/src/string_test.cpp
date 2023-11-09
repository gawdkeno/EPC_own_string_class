#include "technikumSTL/string.h"
#include <gtest/gtest.h>
#include <iostream>
#include <algorithm>

using namespace technikum;

// Test the default constructor.
TEST(DefaultConstructorTest, DefaultConstructorCreatesEmptyString)
{
  technikum::string defaultStr;
  EXPECT_EQ(defaultStr.length(), 0);
  EXPECT_EQ(defaultStr.c_str(), nullptr);
}

// Test the copy constructor with an empty string.
TEST(CopyConstructorTest, CopyingEmptyString)
{
  technikum::string emptyStr;
  technikum::string copiedStr(emptyStr);
  EXPECT_EQ(copiedStr.length(), 0);
  EXPECT_EQ(copiedStr.c_str(), nullptr);
}

// Test the copy constructor with a non-empty string.
TEST(CopyConstructorTest, CopyingNonEmptyString)
{
  const char* initial = "hello";
  technikum::string newStr(initial);
  technikum::string copiedStr(newStr);
  EXPECT_EQ(copiedStr.length(), 5);
  EXPECT_STREQ(copiedStr.c_str(), initial);
}

// Test the move constructor.
TEST(MoveConstructorTest, MoveConstructorTransfersOwnership)
{
  const char* initial = "move";
  technikum::string str(initial);
  technikum::string movedStr(std::move(str));
  EXPECT_EQ(movedStr.length(), 4);
  EXPECT_STREQ(movedStr.c_str(), initial);
  EXPECT_EQ(str.length(), 0);
  EXPECT_EQ(str.c_str(), nullptr);
}

// Test the move assignment operator.
TEST(MoveAssignmentTest, MoveAssignmentOperator)
{
  const char* initial = "hello";
  technikum::string newStr(initial);
  technikum::string testStr;
  testStr = std::move(newStr);
  EXPECT_EQ(testStr.length(), 5);
  EXPECT_STREQ(testStr.c_str(), initial);
  EXPECT_EQ(newStr.length(), 0);
  EXPECT_EQ(newStr.c_str(), nullptr);
}

// Test the copy assignment operator for self-assignment.
TEST(SelfAssignmentTest, CopyAssignmentToSelfDoesNotAlterString)
{
  const char* initial = "test";
  technikum::string str(initial);
  str = str;  // Self-assignment
  EXPECT_EQ(str.length(), 4);
  EXPECT_STREQ(str.c_str(), initial);
}

// Test the addition of strings.
TEST(OperatorTest, Addition)
{
  const char* initial = "hello";
  technikum::string newStr(initial);
  technikum::string CharStr;
  CharStr = newStr + " world";
  EXPECT_EQ(CharStr.length(), 11);
  EXPECT_STREQ(CharStr.c_str(), "hello world");
}

// Test the append operator with another string.
TEST(OperatorTest, AppendOperatorWithString)
{
  const char* initial = "hello";
  technikum::string str(initial);
  str += technikum::string(" world");
  EXPECT_EQ(str.length(), 11);
  EXPECT_STREQ(str.c_str(), "hello world");
}

// Test the append operator with a C-string.
TEST(OperatorTest, AppendOperatorWithCStr)
{
  const char* initial = "hello";
  technikum::string str(initial);
  str += " world";
  EXPECT_EQ(str.length(), 11);
  EXPECT_STREQ(str.c_str(), "hello world");
}

// Test the append function with itself.
TEST(EdgeCasesTest, AppendToItself)
{
  const char* initial = "hello";
  technikum::string str(initial);
  str.append(str);
  EXPECT_EQ(str.length(), 10);
  EXPECT_STREQ(str.c_str(), "hellohello");
}

// Test the null input string.
TEST(EdgeCasesTest, NullString)
{
  technikum::string str(nullptr);
  EXPECT_EQ(str.length(), 0);
  EXPECT_EQ(str.c_str(), nullptr);
}

// Test concatenation with empty string.
TEST(ConcatenationTest, ConcatenateEmptyString)
{
  const char* initial = "hello";
  technikum::string str(initial);
  str += "";
  EXPECT_EQ(str.length(), 5);
  EXPECT_STREQ(str.c_str(), "hello");
}

// Test to iterate over string with non-const iterator.
TEST(StringIteratorTest, IterateWithNonConstIterator)
{
  technikum::string str("Hello");
  std::string result;

  for (auto it = str.begin(); it != str.end(); ++it)
  {
    result += *it;
  }

  EXPECT_EQ(result, "Hello");
}

// Test to iterate over string with const iterator.
TEST(StringIteratorTest, IterateWithConstIterator)
{
  const technikum::string str("World");
  std::string result;

  for (auto it = str.begin(); it != str.end(); ++it)
  {
    result += *it;
  }

  EXPECT_EQ(result, "World");
}

// Test to modify string using non-const iterator.
TEST(StringIteratorTest, ModifyWithStringNonConstIterator)
{
  technikum::string str("Hello");
  for (auto it = str.begin(); it != str.end(); ++it)
  {
    *it = std::toupper(*it);  // Modify the string to uppercase.
  }

  EXPECT_EQ(std::string(str.c_str()), "HELLO");
}

// Test that const iterator does not allow modification.
TEST(StringIteratorTest, ConstIteratorPreventsModification)
{
  const technikum::string str("Hello");
  // Uncommenting the following lines should cause a compilation error.
   //for (auto it = str.begin(); it != str.end(); ++it) {
   //  *it = std::toupper(*it); // This should be impossible with a const iterator.
   //}
}

// Test to use STL algorithm with non-const iterator.
TEST(StringIteratorTest, UseSTLAlgorithmWithNonConstIterator)
{
  technikum::string str("Hello World");
  auto it = std::find(str.begin(), str.end(), 'W');

  EXPECT_NE(it, str.end());
  EXPECT_EQ(*it, 'W');
}

// Test to use STL algorithm with const iterator.
TEST(StringIteratorTest, UseSTLAlgorithmWithConstIterator)
{
  const technikum::string str("Hello World");
  auto it = std::find(str.begin(), str.end(), 'W');

  EXPECT_NE(it, str.end());
  EXPECT_EQ(*it, 'W');
}
