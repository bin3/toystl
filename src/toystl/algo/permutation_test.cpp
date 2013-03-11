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
 * @date		2013-3-10
 */

#include "permutation.h"
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

namespace toystl {

TEST(Permutation, next_permutation) {
  const int kMaxN = 6;
  for (int n = 0; n <= kMaxN; ++n) {
    std::vector<int> v;
    for (int i = 0; i < n; ++i) {
      v.push_back(i);
    }
    std::vector<int> v2(v);
    bool ret = true;
    do {
      ret = std::next_permutation(v.begin(), v.end());
      EXPECT_EQ(ret, toystl::next_permutation(v2.begin(), v2.end()));
      EXPECT_EQ(v, v2);
    } while(ret);
    EXPECT_EQ(v, v2); // smallest permutation
  }
}

} /* namespace toystl */
