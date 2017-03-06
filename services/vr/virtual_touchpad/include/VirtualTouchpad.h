#ifndef ANDROID_DVR_VIRTUAL_TOUCHPAD_INTERFACE_H
#define ANDROID_DVR_VIRTUAL_TOUCHPAD_INTERFACE_H

#include <utils/Errors.h>
#include <utils/RefBase.h>
#include <utils/StrongPointer.h>

namespace android {
namespace dvr {

// Provides a virtual touchpad for injecting events into the input system.
//
class VirtualTouchpad : public RefBase {
 public:
  enum : int {
    PRIMARY = 0,
    VIRTUAL = 1,
  };

  // Create a virtual touchpad.
  // Implementations should provide this, and hide their constructors.
  // For the user, switching implementations should be as simple as changing
  // the class whose |Create()| is called.
  static sp<VirtualTouchpad> Create() {
    return sp<VirtualTouchpad>();
  }

  // Generate a simulated touch event.
  //
  // @param touchpad Touchpad selector index.
  // @param x Horizontal touch position.
  // @param y Vertical touch position.
  //            Values must be in the range [0.0, 1.0).
  // @param pressure Touch pressure.
  //            Positive values represent contact; use 1.0f if contact
  //            is binary. Use 0.0f for no contact.
  // @returns OK on success.
  //
  virtual status_t Touch(int touchpad, float x, float y, float pressure) = 0;

  // Generate a simulated touchpad button state.
  //
  // @param touchpad Touchpad selector index.
  // @param buttons A union of MotionEvent BUTTON_* values.
  // @returns OK on success.
  //
  // Currently only BUTTON_BACK is supported, as the implementation
  // restricts itself to operations actually required by VrWindowManager.
  //
  virtual status_t ButtonState(int touchpad, int buttons) = 0;

 protected:
  VirtualTouchpad() {}
  ~VirtualTouchpad() override {}

 private:
  VirtualTouchpad(const VirtualTouchpad&) = delete;
  void operator=(const VirtualTouchpad&) = delete;
};

}  // namespace dvr
}  // namespace android

#endif  // ANDROID_DVR_VIRTUAL_TOUCHPAD_INTERFACE_H
