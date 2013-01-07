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

#ifndef SORT_H_
#define SORT_H_

#include <algorithm>
#include <toystl/iterator_base_types.h>

namespace toystl {

template<typename RandomAccessIterator, typename Compare>
inline void sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp) {
  if (first + 1 >= last) return;
  typename toystl::iterator_traits<RandomAccessIterator>::difference_type count = last - first;
  typename toystl::iterator_traits<RandomAccessIterator>::value_type pivot = *(first + (count >> 1));
  RandomAccessIterator bit = first;
  RandomAccessIterator eit = last - 1;
  while (bit <= eit) {
    while (comp(*bit, pivot))
      ++bit;
    while (comp(pivot, *eit))
      --eit;
    if (bit <= eit) {
      std::iter_swap(bit, eit);
      ++bit;
      --eit;
    }
  }
  if (first < eit + 1) toystl::sort(first, eit + 1, comp);
  if (bit < last) toystl::sort(bit, last, comp);
}

template<typename RandomAccessIterator>
inline void sort(RandomAccessIterator first, RandomAccessIterator last) {
  if (first + 1 >= last) return;
  typename toystl::iterator_traits<RandomAccessIterator>::difference_type count = last - first;
  typename toystl::iterator_traits<RandomAccessIterator>::value_type pivot = *(first + (count >> 1));
  RandomAccessIterator bit = first;
  RandomAccessIterator eit = last - 1;
  while (bit <= eit) {
    while (*bit < pivot)
      ++bit;
    while (pivot < *eit)
      --eit;
    if (bit <= eit) {
      std::iter_swap(bit, eit);
      ++bit;
      --eit;
    }
  }
  if (first < eit + 1) toystl::sort(first, eit + 1);
  if (bit < last) toystl::sort(bit, last);
}

inline void stable_sort() {}
inline void partial_sort_copy() {}

template<typename RandomAccessIterator>
inline void nth_element(RandomAccessIterator first, RandomAccessIterator nth,
    RandomAccessIterator last) {
  typename toystl::iterator_traits<RandomAccessIterator>::difference_type count = last - first;
  typename toystl::iterator_traits<RandomAccessIterator>::value_type pivot = *(first + (count >> 1));
  RandomAccessIterator bit = first;
  RandomAccessIterator eit = last - 1;
  while (bit <= eit) {
    while (*bit < pivot)
      ++bit;
    while (pivot < *eit)
      --eit;
    if (bit <= eit) {
      std::iter_swap(bit, eit);
      ++bit;
      --eit;
    }
  }
  if (nth < eit + 1) toystl::nth_element(first, nth, eit + 1);
  else if (bit <= nth) toystl::nth_element(bit, nth, last);
}

template<typename RandomAccessIterator>
inline void partial_sort(RandomAccessIterator first, RandomAccessIterator middle,
    RandomAccessIterator last) {
  typename toystl::iterator_traits<RandomAccessIterator>::difference_type count = last - first;
  typename toystl::iterator_traits<RandomAccessIterator>::value_type pivot = *(first + (count >> 1));
  RandomAccessIterator bit = first;
  RandomAccessIterator eit = last - 1;
  while (bit <= eit) {
    while (*bit < pivot)
      ++bit;
    while (pivot < *eit)
      --eit;
    if (bit <= eit) {
      std::iter_swap(bit, eit);
      ++bit;
      --eit;
    }
  }
  if (middle < eit + 1) toystl::partial_sort(first, middle, eit + 1);
  else {
    toystl::sort(first, eit + 1);
    if (bit <= middle) toystl::partial_sort(bit, middle, last);
  }
}

} /* namespace toystl */
#endif /* SORT_H_ */
