//=============================================================================
// Copyright (c) 2002 Radical Games Ltd.  All rights reserved.
//=============================================================================


// stub OpenGL header, all pddi gl code uses this instead of '#include <GL/gl.h>

#include <glad/glad.h>

// TODO(3ur): this is a hack (idk why it isnt defined)
#define HACK

#ifdef HACK
#define GL_LIGHT_MODEL_COLOR_CONTROL_EXT 0x81F8
#define GL_SINGLE_COLOR_EXT              0x81F9
#define GL_SEPARATE_SPECULAR_COLOR_EXT   0x81FA
#define GL_BGR_EXT                       0x80E0
#define GL_BGRA_EXT                      0x80E1
#endif