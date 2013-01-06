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

}
/* namespace toystl */
