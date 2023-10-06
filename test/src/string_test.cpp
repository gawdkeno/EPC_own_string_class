#include "technikumSTL/string.h"

#include <gtest/gtest.h>

#include <iostream>

using namespace technikum;

TEST(CopyConstructorTest, CopyingEmptyString)
{
  technikum::string emptyStr;
  technikum::string copiedStr(emptyStr);
  EXPECT_EQ(copiedStr.length(), 0);
  EXPECT_EQ(copiedStr.c_str(), nullptr);
}

TEST(CopyConstructorTest, CopyingNonEmptyString)
{
  const char* initial = "hello";
  technikum::string newStr = technikum::string(initial);
  technikum::string copiedStr(newStr);
  EXPECT_EQ(copiedStr.length(), 5);
  EXPECT_STREQ(copiedStr.c_str(), initial);
}

TEST(MoveAssignmentTest, MoveAssignmentOperator)
{
  const char* initial = "hello";
  technikum::string newStr = technikum::string(initial);
  technikum::string testStr;
  testStr = std::move(newStr);
  EXPECT_EQ(testStr.length(), 5);
  EXPECT_STREQ(testStr.c_str(), initial);
  EXPECT_EQ(newStr.length(), 0);
  EXPECT_EQ(newStr.c_str(), nullptr);
}

TEST(OperatorTest, Addition)
{
  const char* initial = "hello";
  technikum::string newStr = technikum::string(initial);
  technikum::string CharStr;
  technikum::string StringStr;
  CharStr = newStr + "hello";
  StringStr = newStr + newStr;
  EXPECT_EQ(CharStr.length(), 10);
  EXPECT_STREQ(CharStr.c_str(), "hellohello");
  EXPECT_EQ(StringStr.length(), 10);
  EXPECT_STREQ(StringStr.c_str(), "hellohello");
}

TEST(OperatorTest, AppendOperator)
{
  const char* initial = "hello";
  technikum::string CharStr = technikum::string(initial);
  technikum::string StringStr = technikum::string(initial);
  StringStr += StringStr;
  CharStr += "hello";
  EXPECT_EQ(CharStr.length(), 10);
  EXPECT_STREQ(CharStr.c_str(), "hellohello");
  EXPECT_EQ(StringStr.length(), 10);
  EXPECT_STREQ(StringStr.c_str(), "hellohello");
}

TEST(EdgeCasesTest, NullString)
{
  technikum::string newStr = technikum::string(nullptr);
  EXPECT_EQ(newStr.length(), 0);
  EXPECT_EQ(newStr.c_str(), nullptr);
}

TEST(EdgeCasesTest, AppendToItself)
{
  const char* initial = "hello";
  technikum::string newStr = technikum::string(initial);
  newStr.append(newStr);
  EXPECT_EQ(newStr.length(), 10);
  EXPECT_STREQ(newStr.c_str(), "hellohello");
}

/* int main()
{
 string str1("Hello");
 string str2(" World");
 string str3(" my friend");

 str1.append(str2);
 str1.append(str3);

 const char* result = str1.c_str();
 size_t length = str1.length();

 std::cout << "String: " << result << std::endl;
 std::cout << "Length: " << length << std::endl;

 technikum::string newStr = technikum::string(str3);

 std::cout << "String: " << newStr.c_str() << std::endl;

 return 0;
} */

/* int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
*/