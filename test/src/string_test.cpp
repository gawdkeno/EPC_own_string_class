#include "technikumSTL/string.h"
#include <gtest/gtest.h>
#include <iostream>

using namespace technikum;

// TEST(TmpAddTest, CheckValues)
//{
//   ASSERT_EQ(technikum::add(1, 2), 3);
//   EXPECT_TRUE(true);
// }

int main()
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
}

/* int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
*/