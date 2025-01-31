#include <input/button.cpp>
#include <input/inputmanager.cpp>
#include <input/mappable.cpp>
#include <input/mapper.cpp>
#include <input/usercontroller.cpp>
#include <input/rumbleeffect.cpp>

#if defined(RAD_PS2)
#include <input/steeringspring.cpp>
#include <input/basedamper.cpp>
#include <input/forceeffect.cpp>
#include <input/constanteffect.cpp>
#include <input/wheelrumble.cpp>
#endif

#ifdef RAD_PS2
#include <input/rumbleps2.cpp>
#endif