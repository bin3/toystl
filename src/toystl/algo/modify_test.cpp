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

#include "modify.h"
#include <gtest/gtest.h>

#include "util.h"

namespace toystl {

TEST(Modify, random_shuffle) {
  const int N = 10;
  std::vector<int> vec(N);
  std::vector<int> vec2;
  std::generate(vec.begin(), vec.end(), UniqueNumber());
  vec2 = vec;
  std::srand(0);
  std::random_shuffle(vec.begin(), vec.end());
  std::srand(0);
  toystl::random_shuffle(vec2.begin(), vec2.end());
//  EXPECT_EQ(vec, vec2);
}

TEST(Modify, random_shuffle_rand) {
  const int N = 10;
  std::vector<int> vec(N);
  std::vector<int> vec2;
  std::generate(vec.begin(), vec.end(), UniqueNumber());
  vec2 = vec;
  std::srand(0);
  std::random_shuffle(vec.begin(), vec.end(), RandomNumberGenerator);
  std::srand(0);
  toystl::random_shuffle(vec2.begin(), vec2.end(), RandomNumberGenerator);
//  EXPECT_EQ(vec, vec2);
}
} /* namespace toystl */
