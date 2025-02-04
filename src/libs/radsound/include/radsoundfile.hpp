//=============================================================================
// Copyright (c) 2002 Radical Games Ltd.  All rights reserved.
//=============================================================================


//============================================================================
// File: radsoundfile.hpp
//
// Description: This file contains the definition of the .rsd file header.
//============================================================================

#ifndef RADSOUNDFILE_HPP
#define RADSOUNDFILE_HPP

//=============================================================================
// Build Configuration Check
//=============================================================================

#if !defined(RAD_PS2) && !defined(RAD_XBOX) && !defined(RAD_WIN32)
    #error 'FTech requires definition of RAD_PS2, RAD_XBOX, or RAD_WIN32'
#endif

//=============================================================================
// Include Files
//=============================================================================

#include <radsound_hal.hpp>

//=============================================================================
// Types
//=============================================================================

#define RADSOUNDHAL_FILE_VERSION "RSD4"

//=============================================================================
// Struct: RsdHeader
//
// Description: This the fixed-size file header of an .rsd file.  Use
//		wavtorsd.exe to build .rsd files.
//=============================================================================

struct radSoundHalFileHeader
{
    char m_RsdDataTag[4];    // RADSOUND_HAL_FILEVERSION
    char m_SoundDataType[4]; // "VAG ", "PCM ", "XADP"
    unsigned int m_Channels;
    unsigned int m_BitResolution;
    unsigned int m_SamplingRate;

    // Round the size of this structure to 128 bytes

    char m_ReservedForFutureUse[ 16 ];

	// Helper functions

	void ConvertToPlatformEndian( void );

	// Initializes an audio format component based on this file header.

	void InitializeAudioFormat( IRadSoundHalAudioFormat * pIRadSoundHalAudioFormat,
        radMemoryAllocator allocatorCustomInfo );

    static IRadSoundHalAudioFormat::Encoding GetEncodingFromChars( char chars[ 4 ] );
};

#define RSD_FILE_DATA_OFFSET  2048 // sector size

#endif // RSDFILE_HPP