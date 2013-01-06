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

#ifndef FIND_H_
#define FIND_H_

namespace toystl {

template<typename InputIterator, typename Tp>
inline InputIterator find(InputIterator first, InputIterator last, const Tp& val) {
  while (first != last && !(*first == val)) {
    ++first;
  }
  return first;
}

template<typename InputIterator, typename Predicate>
inline InputIterator find_if(InputIterator first, InputIterator last, Predicate pred) {
  while (first != last && !pred(*first)) {
    ++first;
  }
  return first;
}

template<typename InputIterator1, typename InputIterator2>
inline InputIterator1 find_first_of(InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, InputIterator2 last2) {
  for ( ; first1 != last1; ++first1) {
    for (InputIterator2 it = first2; it != last2; ++it) {
      if (*first1 == *it) return first1;
    }
  }
  return last1;
}

template<typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
inline InputIterator1 find_first_of(InputIterator1 first1, InputIterator1 last1,
    InputIterator2 first2, InputIterator2 last2, BinaryPredicate pred) {
  for ( ; first1 != last1; ++first1) {
    for (InputIterator2 it = first2; it != last2; ++it) {
      if (pred(*first1, *it)) return first1;
    }
  }
  return last1;
}

} /* namespace toystl */
#endif /* FIND_H_ */
