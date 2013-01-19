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
 * @date		2013-1-19
 */

#ifndef CSTRING_H_
#define CSTRING_H_

#include <cstddef>
#include <cstring>
#include <vector>

namespace toystl {

// KMP
inline char *strstr(const char *chaystack, const char *needle) {
  char* haystack = const_cast<char*>(chaystack);
  int m = std::strlen(needle);
  if (m == 0) return haystack;

  std::vector<int> jump_(m);
  jump_[0] = 0;
  int k = 0;
  for (int i = 1; i < m; ++i) {
    while (needle[k] != needle[i] && k != 0) {
      k = jump_[k - 1];
    }
    if (needle[k] == needle[i]) ++k;
    jump_[i] = k;
  }

  k = 0;
  for (; *haystack; ++haystack) {
    if (k == m) return haystack - m;
    while (needle[k] != *haystack && k != 0) {
      k = jump_[k - 1];
    }
    if (needle[k] == *haystack) ++k;
  }
  if (k == m) return haystack - m;
  return NULL;
}

} /* namespace toystl */
#endif /* CSTRING_H_ */
