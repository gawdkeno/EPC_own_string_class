#include <gtest/gtest.h>

#include <iostream>

#include "technikumSTL/UniquePtr.h"
#include "technikumSTL/string.h"

using namespace technikum;

TEST(SimpleTest, stringTest)
{
  UniquePtr<string> stringPointer(new string("Hello World"));
  EXPECT_EQ(stringPointer->c_str(), "Hello World");
}

TEST(SimpleTest, EntityTest)
{
  struct Entity
  {
    int id = -1;
  };
  technikum::UniquePtr<Entity> entityPointer(new Entity);
  EXPECT_EQ(entityPointer->id, -1);
}