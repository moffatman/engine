// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_SHELL_PLATFORM_WINDOWS_TESTING_MOCK_WINDOW_BINDING_HANDLER_DELEGATE_H_
#define FLUTTER_SHELL_PLATFORM_WINDOWS_TESTING_MOCK_WINDOW_BINDING_HANDLER_DELEGATE_H_

#include "flutter/shell/platform/windows/window_binding_handler_delegate.h"
#include "gmock/gmock.h"

namespace flutter {
namespace testing {

class MockWindowBindingHandlerDelegate : public WindowBindingHandlerDelegate {
 public:
  MockWindowBindingHandlerDelegate() {}

  // Prevent copying.
  MockWindowBindingHandlerDelegate(MockWindowBindingHandlerDelegate const&) =
      delete;
  MockWindowBindingHandlerDelegate& operator=(
      MockWindowBindingHandlerDelegate const&) = delete;

  MOCK_METHOD2(OnWindowSizeChanged, void(size_t, size_t));
  MOCK_METHOD4(OnPointerMove,
               void(double, double, FlutterPointerDeviceKind, int32_t));
  MOCK_METHOD5(OnPointerDown,
               void(double,
                    double,
                    FlutterPointerDeviceKind,
                    int32_t,
                    FlutterPointerMouseButtons));
  MOCK_METHOD5(OnPointerUp,
               void(double,
                    double,
                    FlutterPointerDeviceKind,
                    int32_t,
                    FlutterPointerMouseButtons));
  MOCK_METHOD2(OnPointerLeave, void(FlutterPointerDeviceKind, int32_t));
  MOCK_METHOD1(OnPointerFlowStart, void(int32_t));
  MOCK_METHOD5(OnPointerFlowUpdate, void(int32_t, double, double, double, double));
  MOCK_METHOD1(OnPointerFlowEnd, void(int32_t));
  MOCK_METHOD1(OnText, void(const std::u16string&));
  MOCK_METHOD6(OnKey, bool(int, int, int, char32_t, bool, bool));
  MOCK_METHOD0(OnComposeBegin, void());
  MOCK_METHOD0(OnComposeCommit, void());
  MOCK_METHOD0(OnComposeEnd, void());
  MOCK_METHOD2(OnComposeChange, void(const std::u16string&, int));
  MOCK_METHOD7(OnScroll,
               void(double,
                    double,
                    double,
                    double,
                    int,
                    FlutterPointerDeviceKind,
                    int32_t));
};

}  // namespace testing
}  // namespace flutter

#endif  // FLUTTER_SHELL_PLATFORM_WINDOWS_TESTING_MOCK_WINDOW_BINDING_HANDLER_DELEGATE_H_
