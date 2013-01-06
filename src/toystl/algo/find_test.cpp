/*
 * Copyright (c) 2013 Binson Zhang.
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @author	Binson Zhang <bin183cs@gmail.com>
 * @date		2013-1-6
 */

#include "find.h"
#include <gtest/gtest.h>

#include <vector>
#include <algorithm>

namespace toystl {

bool IsOdd(int x) {
  return (x % 2) == 1;
}

bool IsEven(int x) {
  return (x % 2) == 0;
}

bool IsDouble(int lhs, int rhs) {
  return lhs == rhs * 2;
}

TEST(Find, find) {
  const int N = 10;
  std::vector<int> vec;
  for (int i = 0; i < N; ++i) {
    vec.push_back(i);
  }

  int val = 999;
  EXPECT_EQ(std::find(vec.begin(), vec.end(), val), toystl::find(vec.begin(), vec.end(), val));

  for (int i = 0; i < N; ++i) {
    val = vec[i];
    EXPECT_EQ(std::find(vec.begin(), vec.end(), val), toystl::find(vec.begin(), vec.end(), val));
  }
}

TEST(Find, find_if) {
  const int N = 10;
  std::vector<int> vec;
  for (int i = 0; i < N; ++i) {
    vec.push_back(i);
  }

  EXPECT_EQ(std::find_if(vec.begin(), vec.end(), IsOdd), toystl::find_if(vec.begin(), vec.end(), IsOdd));
  EXPECT_EQ(std::find_if(vec.begin(), vec.end(), IsEven), toystl::find_if(vec.begin(), vec.end(), IsEven));
}

TEST(Find, find_first_of) {
  const int N1 = 10;
  const int N2 = 4;
  std::vector<int> vec1;
  for (int i = 0; i < N1; ++i) {
    vec1.push_back(i);
  }
  std::vector<int> vec2;
  for (int i = 1; i <= N2; ++i) {
    vec2.push_back(i * 2);
  }
  EXPECT_EQ(std::find_first_of(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()),
      toystl::find_first_of(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()));
}

TEST(Find, find_first_of_pred) {
  const int N1 = 10;
  const int N2 = 4;
  std::vector<int> vec1;
  for (int i = 0; i < N1; ++i) {
    vec1.push_back(i);
  }
  std::vector<int> vec2;
  for (int i = 1; i <= N2; ++i) {
    vec2.push_back(i * 2);
  }
  EXPECT_EQ(std::find_first_of(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), IsDouble),
      toystl::find_first_of(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), IsDouble));
}

}
/* namespace toystl */
