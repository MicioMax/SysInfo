#ifndef _SysInfo_SysInfo_in_h_
#define _SysInfo_SysInfo_in_h_

#ifdef PLATFORM_OSX
	#error SysInfo does not support OSX
#endif

#include "Core/Core.h"

#if defined(PLATFORM_WIN32) 
	#include <shellapi.h>
	#include <tlhelp32.h>
	#include <psapi.h>
	#include <winioctl.h>
	#define CY tagCY
	// To compile in MinGW you will probably need to get files Rpcsal.h, WbemCli.h, WbemProv.h 
	// and for sure you will need wbemuuid.lib, even deleting libwbemuuid.a, as it is uncomplete
	#include <rpcsal.h>	
	#include <wbemcli.h>
	#include <wbemprov.h>
	#include <winnls.h> 
	#include <vfw.h>
	typedef ACCESS_MASK REGSAM;
	#include <powrprof.h>
	#include <lm.h>
	#include <winsock2.h>
	#include <ws2tcpip.h>
	#ifndef PROCESS_QUERY_LIMITED_INFORMATION
	#define PROCESS_QUERY_LIMITED_INFORMATION 0x1000
	#endif	
#endif
#ifdef PLATFORM_POSIX
	#include <sys/time.h>
	#include <sys/resource.h>
	#include <sys/ioctl.h>
	#include <net/if.h>
	
	#include <fcntl.h>
	#include <sys/types.h>
	#include <sys/stat.h>
#ifndef PLATFORM_OSX
	#include <sys/vfs.h>
#endif
	#include <sys/utsname.h>
	#include <dirent.h>
	#include <pwd.h>
	#include <grp.h>
	#include <time.h>
	#include <signal.h>
	#include <sys/reboot.h>
	
	#include <X11/Xlib.h>
	#include <X11/Xos.h>
	#include <X11/Xfuncs.h>
	#include <X11/Xutil.h>
	#include <X11/Xatom.h>
#ifndef flagNO_XTEST
	#include <X11/extensions/XTest.h>
#endif
	#include <X11/XKBlib.h>
	
	#include <arpa/inet.h>
	#ifdef flagGUI
		#define SetX11ErrorHandler();
		#define SetSysInfoX11ErrorHandler();
	#else
		#define SetX11ErrorHandler();
		int SysInfoX11ErrorHandler(_XDisplay *, XErrorEvent *);
		void SetSysInfoX11ErrorHandler();					
	#endif

#endif

#define _Browser_Browser_h
#include "SysInfo.h"
#ifdef _WIN32
#include "OSwin.h"
#endif

namespace Upp {

#if defined(__GNUC__) && !defined(COMPILER_CLANG)
#define __cdecl __attribute__((cdecl))
#endif
	
}

#endif
