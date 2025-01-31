//=============================================================================
// Copyright (c) 2002 Radical Games Ltd.  All rights reserved.
//=============================================================================


#ifndef _BASE_PLATFORM_HPP
#define _BASE_PLATFORM_HPP

#if defined(RAD_PS2)
    #include <p3d/platform/ps2/platform.hpp>
#elif defined(RAD_LINUX)
    #include <p3d/platform/linux/platform.hpp>
#elif defined(RAD_XBOX)
    #include <p3d/platform/xbox/platform.hpp>
#elif defined(RAD_WIN32)
    #include <p3d/platform/win32/platform.hpp>
#endif

#endif // _BASE_PLATFORM_HPP