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
 * @date		2013-1-7
 */

#include "sort.h"
#include <gtest/gtest.h>

#include <cstdlib>
#include <vector>
#include <algorithm>

#include "util.h"

namespace toystl {

TEST(Sort, sort) {
  for (int n = 0; n <= 100; ++n) {
    std::vector<int> vec(n);
    std::vector<int> vec2;

    std::generate(vec.begin(), vec.end(), RandomNumberFunc);
    vec2 = vec;
    std::sort(vec.begin(), vec.end());
    toystl::sort(vec2.begin(), vec2.end());
    ASSERT_EQ(vec, vec2);

    std::generate(vec.begin(), vec.end(), UniqueNumber());
    vec2 = vec;
    std::sort(vec.begin(), vec.end());
    toystl::sort(vec2.begin(), vec2.end());
    ASSERT_EQ(vec, vec2);
  }
}

TEST(Sort, sort_comp) {
  std::greater<int> comp;
  for (int n = 0; n <= 100; ++n) {
    std::vector<int> vec(n);
    std::vector<int> vec2;

    std::generate(vec.begin(), vec.end(), RandomNumberFunc);
    vec2 = vec;
    std::sort(vec.begin(), vec.end(), comp);
    toystl::sort(vec2.begin(), vec2.end(), comp);
    ASSERT_EQ(vec, vec2);

    std::generate(vec.begin(), vec.end(), UniqueNumber());
    vec2 = vec;
    std::sort(vec.begin(), vec.end(), comp);
    toystl::sort(vec2.begin(), vec2.end(), comp);
    ASSERT_EQ(vec, vec2);
  }
}
} /* namespace toystl */
