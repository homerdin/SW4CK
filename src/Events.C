//////////////////////////////////////////////////////////////////////////////
//// Copyright (c) 2021, Lawrence Livermore National Security, LLC and SW4CK
//// project contributors. See the COPYRIGHT file for details.
////
//// SPDX-License-Identifier: GPL-2.0-only
////////////////////////////////////////////////////////////////////////////////
#ifdef ENABLE_HIP
#include "hip/hip_ext.h"
#include "hip/hip_runtime.h"
#include "hip/hip_runtime_api.h"

hipEvent_t newEvent() {
  hipEvent_t event;
  hipEventCreate(&event);
  return event;
}

void insertEvent(hipEvent_t &event) { hipEventRecord(event); }

float timeEvent(hipEvent_t &start, hipEvent_t &stop) {
  hipEventSynchronize(stop);
  float ms = 0;
  hipEventElapsedTime(&ms, start, stop);
  return ms;
}
#endif
#ifdef ENABLE_CUDA

cudaEvent_t newEvent() {
  cudaEvent_t event;
  cudaEventCreate(&event);
  return event;
}

void insertEvent(cudaEvent_t &event) { cudaEventRecord(event); }

float timeEvent(cudaEvent_t &start, cudaEvent_t &stop) {
  cudaEventSynchronize(stop);
  float ms = 0;
  cudaEventElapsedTime(&ms, start, stop);
  return ms;
}
#endif
#ifdef ENABLE_SYCL
#include <sycl.hpp>
extern sycl::event currentEvent;
sycl::event newEvent() {
  return sycl::event();
}

void insertEvent(sycl::event &event) {
  currentEvent = event;
}

float timeEvent(sycl::event &event, sycl::event &e2) {
  auto end = currentEvent.get_profiling_info<sycl::info::event_profiling::command_end>();
  auto start = currentEvent.get_profiling_info<sycl::info::event_profiling::command_start>();

  return (end-start)/1.0e6;
}

#endif
