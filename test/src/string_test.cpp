#include "technikumSTL/string.h"
#include <gtest/gtest.h>
#include <iostream>

using namespace technikum;

// TEST(TmpAddTest, CheckValues)
//{
//   ASSERT_EQ(technikum::add(1, 2), 3);
//   EXPECT_TRUE(true);
// }

TEST(c_strSmallTest, CheckValues)
{
  const char* initial = "hello";
  technikum::string newStr = technikum::string(initial);
  ASSERT_STREQ(newStr.c_str(), initial);
  EXPECT_TRUE(true);
}

TEST(c_strBigTest, CheckValues)
{
  const char* initial = "helloAllOfYOuOutThereIHopeYouHaveAGreatDayGoodByeAAAAAAAAAAAHHHHHHHHHHHHHHHH";
  technikum::string newStr = technikum::string(initial);
  ASSERT_STREQ(newStr.c_str(), initial);
  EXPECT_TRUE(true);
}

TEST(c_strSpecialCharTest, CheckValues)
{
  const char* initial = "hello%&/=)(!§";
  technikum::string newStr = technikum::string(initial);
  ASSERT_STREQ(newStr.c_str(), initial);
  EXPECT_TRUE(true);
}

TEST(sizeSmallTest, CheckValues)
{
  technikum::string newStr = technikum::string("hello");
  int test = newStr.size();
  ASSERT_EQ(test, 5);
  EXPECT_TRUE(true);
}

TEST(sizeBigTest, CheckValues)
{
  technikum::string newStr = technikum::string("helloAllOfYOuOutThereIHopeYouHaveAGreatDayGoodByeAAAAAAAAAAAHHHHHHHHHHHHHHHH");
  int test = newStr.size();
  ASSERT_EQ(test, 76);
  EXPECT_TRUE(true);
}

TEST(AppendHelloWorldTest, CheckValues)
{
  technikum::string newStr = technikum::string("hello");
  technikum::string secStr = technikum::string("world");
  newStr.append(secStr);
  const char* test = newStr.c_str();
  ASSERT_STREQ(test, "helloworld");
  EXPECT_TRUE(true);
}

TEST(AppendWithEmptyTest, CheckValues)
{
  technikum::string newStr = technikum::string("Hello");
  technikum::string firStr = technikum::string(" ");
  technikum::string secStr = technikum::string("World");
  newStr.append(firStr);
  newStr.append(secStr);
  const char* test = newStr.c_str();
  ASSERT_STREQ(test, "Hello World");
  EXPECT_TRUE(true);
}

TEST(AppendMultiTest, CheckValues)
{
  technikum::string newStr = technikum::string("hello");
  technikum::string secStr = technikum::string("world");
  newStr.append(secStr);
  newStr.append(newStr);
  newStr.append(secStr);
  const char* test = newStr.c_str();
  ASSERT_STREQ(test, "helloworldhelloworldworld");
  EXPECT_TRUE(true);
}

/* int main()
{
  string str1("Hello");
  string str2(" World");
  string str3(" my friend");

  str1.append(str2);
  str1.append(str3);

  const char* result = str1.c_str();
  int length = str1.length();

  std::cout << "String: " << result << std::endl;
  std::cout << "Length: " << length << std::endl;

  return 0;
}*/

/* int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
*/