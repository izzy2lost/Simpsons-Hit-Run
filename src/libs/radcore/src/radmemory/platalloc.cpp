//=============================================================================
// Copyright (c) 2002 Radical Games Ltd.  All rights reserved.
//=============================================================================



#include "pch.hpp"
#include <raddebug.hpp>
#include "platalloc.hpp"

#if defined RAD_PS2

    #include <malloc.h>

#elif defined RAD_WIN32 || defined RAD_XBOX
    
    #include <stdlib.h>
    
    #if defined MALLOC_DEBUG
        #include <crtdbg.h>
    #endif

#endif

//============================================================================
// ::radMemoryPlatInitialize
//============================================================================

void radMemoryPlatInitialize( void )
{

}


//============================================================================
// ::radMemoryPlatTerminate
//============================================================================

void radMemoryPlatTerminate( void )
{
}

//============================================================================
// ::radMemoryPlatAlloc
//============================================================================

void * radMemoryPlatAlloc( unsigned int numberOfBytes )
{
    void * pMemory;
    //
    // C++ standard says you can allocate 0 byte memory object.
    //
    if ( numberOfBytes == 0 )
    {
        numberOfBytes = 1;
    }

#if defined MALLOC_DEBUG
    #define MALLOC_OK
    pMemory = _malloc_dbg(numberOfBytes, _NORMAL_BLOCK, NULL, 0);
#endif

#if !defined( MALLOC_OK )
    pMemory = malloc( numberOfBytes );
#endif
    
    rWarningMsg( pMemory != NULL, "radMemory: Platform (malloc) allocator failed to allocate memory\n" );
    return pMemory;
}

//============================================================================
// ::radMemoryPlatFree
//============================================================================

void radMemoryPlatFree( void * pMemory )
{
#if defined MALLOC_DEBUG
    _free_dbg(pMemory, _NORMAL_BLOCK);
#endif

#if ! defined( MALLOC_OK )
	free( pMemory );
#endif
}

//============================================================================
// ::radMemoryPlatAllocAligned
//============================================================================

void * radMemoryPlatAllocAligned( unsigned int numberOfBytes, unsigned int alignment )
{
	#ifdef RAD_PS2

		return ::memalign( alignment, numberOfBytes );

	#else

		//
		// Roll our own with Os allocator
		//

		unsigned int pMemory = (unsigned int ) radMemoryPlatAlloc( numberOfBytes + alignment );
		rAssert( numberOfBytes == 0 || pMemory != 0 ); 

		unsigned int pAlignedMemory = pMemory + ( alignment - ( pMemory % alignment ) );

		((unsigned int*)pAlignedMemory)[ -1 ] = pMemory;   

		return (void*) pAlignedMemory;

	#endif
}

//============================================================================
// ::radMemoryPlatFreeAligned
//============================================================================

void radMemoryPlatFreeAligned( void * pAlignedMemory )
{

	#ifdef RAD_PS2
		
		free( pAlignedMemory );
	
	#else

        if ( pAlignedMemory != NULL )
        {
		    //
		    // UnRoll our own using Os allocator
		    //

		    radMemoryPlatFree( (void*) ((unsigned int*)pAlignedMemory)[ -1 ] );
        }

	#endif
}
