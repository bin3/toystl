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

#ifndef TOYSTL_ALGO_UTIL_H_
#define TOYSTL_ALGO_UTIL_H_

#include <cstdlib>
#include <algorithm>

namespace toystl {

inline int RandomNumber() {
  return rand() % 100;
}

struct UniqueNumber {
  UniqueNumber(): current_(0) {}
  int operator()() {
    return current_++;
  }
private:
  int current_;
};

} /* namespace toystl */

#endif /* TOYSTL_ALGO_UTIL_H_ */
