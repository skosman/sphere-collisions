# Create options for sanitizer
option(ENABLE_ASAN "Address Sanitizer enabled." false)
option(ENABLE_UBSAN "Undefined Behaviour Santizer enabled." false)

# Check if ASan enabled
if (ENABLE_ASAN)
	if(CMAKE_CXX_COMPILER_ID MATCHES GNU OR 
	CMAKE_CXX_COMPILER_ID MATCHES Clang)
		# Check that gcc or Clang compilers are being used
		# Add the -f option to the flags to use for compiling
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
		
		# Add the -f option to the linker flags	
		set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")
		
	else()
		# Handle unsupported compilers
		message(FATEL_ERROR "Only GCC and Clang are supported")
	endif()
endif()

# Check if UBSan enabled
if (ENABLE_UBSAN)
	if(CMAKE_CXX_COMPILER_ID MATCHES GNU OR 
	CMAKE_CXX_COMPILER_ID MATCHES Clang)
		# Check that gcc or Clang compilers are being used
		# Add the -f option to the flags to use for compiling
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")
		
		# Add the -f option to the linker flags	
		set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=undefined")
		
	else()
		# Handle unsupported compilers
		message(FATEL_ERROR "Only GCC and Clang are supported")
	endif()
endif()

