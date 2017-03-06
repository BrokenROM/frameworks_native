package android.dvr;

/** @hide */
interface VirtualTouchpadService
{
  const String SERVICE_NAME = "virtual_touchpad";

  /**
   * Generate a simulated touch event.
   *
   * @param touchpad Selects touchpad.
   * @param x Horizontal touch position.
   * @param y Vertical touch position.
   * @param pressure Touch pressure; use 0.0 for no touch (lift or hover).
   *
   * Position values in the range [0.0, 1.0) map to the screen.
   */
  void touch(int touchpad, float x, float y, float pressure);

  /**
   * Generate a simulated touchpad button state event.
   *
   * @param touchpad Selects touchpad.
   * @param buttons A union of MotionEvent BUTTON_* values.
   */
  void buttonState(int touchpad, int buttons);
}
