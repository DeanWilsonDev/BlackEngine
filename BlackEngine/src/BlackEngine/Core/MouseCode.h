#include <_types/_uint16_t.h>
namespace BlackEngine {

using MouseCode = uint16_t;

namespace Mouse {

enum : MouseCode {
  Button0 = 0,
  Button1 = 1,
  Button2 = 2,
  Button3 = 3,
  Button4 = 4,
  Button5 = 5,
  Button6 = 6,
  Button7 = 7,

  MouseLast = Button7,
  MouseLeft = Button0,
  MouseRight = Button1,
  MouseMiddle = Button2,
};
} // namespace Mouse
} // namespace BlackEngine
