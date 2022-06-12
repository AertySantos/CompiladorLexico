/*
 * stdio.h
 *
 * Definitions of types and prototypes of functions for operations on
 * standard input and standard output streams.
 *
 * $Id: stdio.h,v 0fe8afb3a429 2019/10/26 09:33:12 keith $
 *
 * Written by Colin Peters <colin@bird.fu.is.saga-u.ac.jp>
  * Copyright (C) 1997-2005, 2007-2010, 2014-2019, MinGW.org Project.
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice, this permission notice, and the following
 * disclaimer shall be included in all copies or substantial portions of
 * the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OF OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * NOTE: The file manipulation functions provided by Microsoft seem to
 * work with either slash (/) or backslash (\) as the directory separator;
 * (this is consistent with Microsoft's own documentation, on MSDN).
 *
 */
#ifndef _STDIO_H
#pragma GCC system_header

/* When including <wchar.h>, some of the definitions and declarations
 * which are nominally provided in <stdio.h> must be duplicated.  Rather
 * than require duplicated maintenance effort, we provide for partial
 * inclusion of <stdio.h> by <wchar.h>; only when not included in
 * this partial fashion...
 */
#ifndef __WCHAR_H_SOURCED__
 /* ...which is exclusive to <wchar.h>, do we assert the multiple
  * inclusion guard for <stdio.h> itself.
  */
#define _STDIO_H
#endif

/* All the headers include this file.
 */
/*
 * _mingw.h
 *
 * MinGW specific macros included by ALL mingwrt include files; (this file
 * is part of the MinGW32 runtime library package).
 *
 * $Id: _mingw.h.in,v ffb333107b88 2020/03/05 13:49:29 keith $
 *
 * Written by Mumit Khan  <khan@xraylith.wisc.edu>
 * Copyright (C) 1999, 2001-2011, 2014-2020, MinGW.org Project
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef __MINGW_H
#define __MINGW_H

/* In previous versions, __MINGW32_VERSION was expressed as a dotted
 * numeric pair, representing major.minor; unfortunately, this doesn't
 * adapt well to the inclusion of a patch-level component, since the
 * major.minor.patch dotted triplet representation is not valid as a
 * numeric entity.  Thus, for this version, we adopt a representation
 * which encodes the version as a long integer value, expressing:
 *
 *   __MINGW32_VERSION = 1,000,000 * major + 1,000 * minor + patch
 *
 * DO NOT EDIT these package version assignments manually; they are
 * derived from the package version specification within configure.ac,
 * whence they are propagated automatically, at package build time.
 */
#define __MINGW32_VERSION           5004002L
#define __MINGW32_MAJOR_VERSION           5
#define __MINGW32_MINOR_VERSION           4
#define __MINGW32_PATCHLEVEL              2

#if __GNUC__ >= 3 && ! defined __PCC__
#pragma GCC system_header
#endif

#ifndef _MSVCRTVER_H
/* Legacy versions of mingwrt use the macro __MSVCRT_VERSION__ to
 * enable evolving features of different MSVCRT.DLL versions.  This
 * usage is no longer recommended, but the __MSVCRT_VERSION__ macro
 * remains useful when a non-freely distributable MSVCRxx.DLL is to
 * be substituted for MSVCRT.DLL; for such usage, the substitute
 * MSVCRxx.DLL may be identified as specified in...
 */
/*
 * msvcrtver.h
 *
 * Macros for identification of specific versions of MSVC runtime
 * libraries, which may be substituted for MSVCRT.DLL
 *
 * $Id: msvcrtver.h,v be739aa1d35f 2015/06/19 11:43:28 keithmarshall $
 *
 * Written by Keith Marshall <keithmarshall@users.sourceforge.net>
 * Copyright (C) 2015, MinGW.org Project
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef _MSVCRTVER_H
#define _MSVCRTVER_H
#pragma GCC system_header

/* When it is intended to link an application with any one of the
 * MSVC version specific MSVCRxx.DLL libraries, rather than with the
 * OS default MSVCRT.DLL, the particular substitute MSVCRxx.DLL may
 * be specified as any one of the following...
 */
#define __MSVCR60_DLL		0x0600
#define __MSVCR61_DLL		0x0601
#define __MSVCR70_DLL		0x0700
#define __MSVCR71_DLL		0x0701
#define __MSVCR80_DLL		0x0800
#define __MSVCR90_DLL		0x0900
#define __MSVCR100_DLL		0x1000
#define __MSVCR110_DLL		0x1100
#define __MSVCR120_DLL		0x1200

#ifndef __MSVCRT_VERSION__
/* This may be set, when the intent is to link with any of the above
 * non-freely distributable MSVCRxx.DLL libraries, rather than with the
 * pseudo-free MSVCRT.DLL provided as an OS component.  High byte is the
 * major version number, low byte is the minor; however, users are advised
 * to use custom GCC specs files to set this, while also substituting the
 * appropriate library in place of MSVCRT.DLL, rather than to simply set
 * it directly.
 *
 * It should be noted that __MSVCRT_VERSION__ is NOT a good indicator of
 * evolving MSVCRT.DLL features; that is better accomplished by using the
 * NTDDI_VERSION setting from the Windows API.  Thus, users of MSVCRT.DLL
 * should NOT set __MSVCRT_VERSION__, leaving us to establish a default,
 * equivalent to MSVCR60.DLL, which seems reasonably well aligned with
 * the feature set of the earliest MSVCRT.DLL version we support.
 */
# define __MSVCRT_VERSION__  __MSVCR60_DLL
#endif

/* This is an exception to the normal rule, that all mingwrt system
 * header files should include _mingw.h, since inclusion of _mingw.h
 * itself will cause this file to be included.  Thus, we recommend
 * that this file should not be included directly, but we do not
 * forbid doing so; however, in this event...
 */
#ifndef __MINGW_H
/* ...we must ensure that _mingw.h has also been included.
 */
#endif

#endif /* !_MSVCRTVER_H: $RCSfile: msvcrtver.h,v $: end of file */
 
#endif

/* A better inference than __MSVCRT_VERSION__, of the capabilities
 * supported by the operating system default MSVCRT.DLL, is provided
 * by the Windows API version identification macros.
 */
/*
 * w32api.h
 *
 * Package version identification, operating system support level set up,
 * and "convenience" macros to be shared by all package header files.
 *
 * $Id: w32api.h.in,v a0309c955244 2017/03/20 20:01:38 keithmarshall $
 *
 * Written by Earnie Boyd  <earnie@users.sourceforge.net>
 * Copyright (C) 2001-2011, 2015, 2016, MinGW.org Project
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef _W32API_H
#define _W32API_H
#pragma GCC system_header

/* Package version identification: formerly specified as a simple
 * dotted numeric pair representing major.minor, this doesn't adapt
 * well to the inclusion of the patch-level, since the dotted triplet
 * representation of major.minor.patch is not a valid representation
 * of a numeric entity.  Thus, from version 3.18 onwards we adopt a
 * representation which encodes the version as a long integer value,
 * expressing:
 *
 *   __W32API_VERSION = 1,000,000 * major + 1,000 * minor + patch
 *
 * DO NOT EDIT these package version assignments manually; they are
 * derived from the package version specification within configure.ac,
 * whence they are propagated automatically, at package build time.
 */
#define __W32API_VERSION           5004002L
#define __W32API_MAJOR_VERSION           5
#define __W32API_MINOR_VERSION           4
#define __W32API_PATCHLEVEL              2

/* The underlying operating system platform version, and its
 * identifying macros for application support, are established by:
 */
/*
 * sdkddkver.h
 *
 * Macros to set up the compilation environment, such that it provides
 * support for a user specified host OS version, (default Win2K).
 *
 * $Id: sdkddkver.h,v a643540a9b10 2021/02/13 17:12:51 keith $
 *
 * Written by Earnie Boyd  <earnie@users.sourceforge.net>
 * Copyright (C) 2012, 2013, 2015, 2021, MinGW.org Project
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef _SDKDDKVER_H
#define _SDKDDKVER_H
#pragma GCC system_header

/* Define masks for extracting version components from NTDDI_VERSION;
 * values and names are guessed based on comments in the documentation; see
 * http://msdn.microsoft.com/en-us/library/windows/desktop/aa383745(v=vs.85).aspx
 */
#define OSVERSION_MASK  	0xFFFF0000
#define SPVERSION_MASK  	0x0000FF00
#define SUBVERSION_MASK 	0x000000FF

/* Macros to facilitate such extraction; derived from comments on MSDN or
 * on social.microsoft.com
 */
#define OSVER(ver)		((ver) & OSVERSION_MASK)
#define SPVER(ver)		(((ver) & SPVERSION_MASK) >> 8)
#define SUBVER(ver)		((ver) & SUBVERSION_MASK)
#define WINNTVER(ver)		((ver) >> 16)

/* Macros to construct a minimal NTDDI_VERSION from a _WIN32_WINNT value.
 */
#define NTDDI_VERSION_FROM_WIN32_WINNT(ver) _NTDDI_VERSION_FROM_WIN32_WINNT(ver)
#define _NTDDI_VERSION_FROM_WIN32_WINNT(ver) ver##0000

/* Version constants specifying _WIN32_WINNT versions; these are defined at
 * http://msdn.microsoft.com/en-us/library/windows/desktop/aa383745(v=vs.85).aspx
 * (values for legacy platforms have been inferred from historical knowledge).
 */
#define _WIN32_WINNT_NT4	0x0400		/* Windows NT4 */
#define _WIN32_WINNT_NT4E	0x0401		/* Windows NT4E */
#define _WIN32_WINNT_NT4SP3	0x0403		/* Windows NT4 + ServicePack 3 */
#define _WIN32_WINDOWS_95	0x0400		/* Windows 95 */
#define _WIN32_WINDOWS_98	0x0410		/* Windows 98 */
#define _WIN32_WINDOWS_ME	0x0490		/* Windows Millenium Edition */
#define _WIN32_WINNT_WIN2K	0x0500		/* Windows 2000 */
#define _WIN32_WINNT_WINXP	0x0501		/* Windows XP */
#define _WIN32_WINNT_WS03	0x0502		/* Windows Server 2003 */
#define _WIN32_WINNT_WIN6	0x0600		/* Alias for Windows Vista */
#define _WIN32_WINNT_VISTA	0x0600		/* Windows Vista */
#define _WIN32_WINNT_WS08	0x0600		/* Windows Server 2008 */
#define _WIN32_WINNT_LONGHORN	0x0600		/* Alias for Windows Vista */
#define _WIN32_WINNT_WIN7	0x0601		/* Windows 7 */
#define _WIN32_WINNT_WIN8	0x0602		/* Windows 8 */
#define _WIN32_WINNT_WINBLUE	0x0603		/* Windows 8.1 */
#define _WIN32_WINNT_WIN10	0x0A00		/* Windows 10 */

/* Version constants specifying Internet Explorer versions; also defined at
 * http://msdn.microsoft.com/en-us/library/windows/desktop/aa383745(v=vs.85).aspx
 */
#define _WIN32_IE_IE50  	0x0500
#define _WIN32_IE_IE501 	0x0501
#define _WIN32_IE_IE55  	0x0550
#define _WIN32_IE_IE56  	0x0560
#define _WIN32_IE_IE60  	0x0600
#define _WIN32_IE_IE60SP1 	0x0601
#define _WIN32_IE_IE60SP2 	0x0603
#define _WIN32_IE_IE70  	0x0700
#define _WIN32_IE_IE80  	0x0800
#define _WIN32_IE_IE90  	0x0900
#define _WIN32_IE_IE100  	0x0A00
#define _WIN32_IE_IE110  	0x0A00

#define _WIN32_IE_IE30  	0x0300
#define _WIN32_IE_IE301 	0x0301
#define _WIN32_IE_IE302 	0x0302
#define _WIN32_IE_IE40  	0x0400
#define _WIN32_IE_IE401 	0x0401

/* Version constants specifying NTDDI_VERSION; these are also defined at
 * http://msdn.microsoft.com/en-us/library/windows/desktop/aa383745(v=vs.85).aspx
 */
#define __NTDDI_WIN5		0x05000000
#define __NTDDI_WIN51		0x05010000
#define __NTDDI_WIN52		0x05020000
#define __NTDDI_WIN6		0x06000000
#define __NTDDI_WIN61		0x06010000
#define __NTDDI_WIN62		0x06020000
#define __NTDDI_WIN63		0x06030000
#define __NTDDI_WIN10		0x0A000000
#define __NTDDI_SP0		0x00000000
#define __NTDDI_SP1		0x00000100
#define __NTDDI_SP2		0x00000200
#define __NTDDI_SP3		0x00000300
#define __NTDDI_SP4		0x00000400

#define __NTDDI_SUBVER		SUBVER

#define NTDDI_WIN2K		__NTDDI_WIN5 + __NTDDI_SP0
#define NTDDI_WIN2KSP1		__NTDDI_WIN5 + __NTDDI_SP1
#define NTDDI_WIN2KSP2		__NTDDI_WIN5 + __NTDDI_SP2
#define NTDDI_WIN2KSP3		__NTDDI_WIN5 + __NTDDI_SP3
#define NTDDI_WIN2KSP4		__NTDDI_WIN5 + __NTDDI_SP4

#define NTDDI_WINXP		__NTDDI_WIN51 + __NTDDI_SP0
#define NTDDI_WINXPSP1		__NTDDI_WIN51 + __NTDDI_SP1
#define NTDDI_WINXPSP2		__NTDDI_WIN51 + __NTDDI_SP2
#define NTDDI_WINXPSP3		__NTDDI_WIN51 + __NTDDI_SP3

#define NTDDI_WS03		__NTDDI_WIN52 + __NTDDI_SP0
#define NTDDI_WS03SP1		__NTDDI_WIN52 + __NTDDI_SP1
#define NTDDI_WS03SP2		__NTDDI_WIN52 + __NTDDI_SP2

#define NTDDI_VISTA		__NTDDI_WIN6 + __NTDDI_SP0
#define NTDDI_VISTASP1		__NTDDI_WIN6 + __NTDDI_SP1
#define NTDDI_VISTASP2		__NTDDI_WIN6 + __NTDDI_SP2

#define NTDDI_LONGHORN		NTDDI_VISTA

#define NTDDI_WIN6		NTDDI_VISTA
#define NTDDI_WIN6SP1		NTDDI_VISTASP1
#define NTDDI_WIN6SP2		NTDDI_VISTASP2

#define NTDDI_WS08		__NTDDI_WIN6 + __NTDDI_SP1

#define NTDDI_WIN7		__NTDDI_WIN61 + __NTDDI_SP0

#define NTDDI_WIN8		__NTDDI_WIN62 + __NTDDI_SP0

#define NTDDI_WINBLUE		__NTDDI_WIN63 + __NTDDI_SP0

#define NTDDI_WIN10		__NTDDI_WIN10 + __NTDDI_SUBVER(0)
#define NTDDI_WINTHRESHOLD	__NTDDI_WIN10 + __NTDDI_SUBVER(0)
#define NTDDI_WIN10_TH2 	__NTDDI_WIN10 + __NTDDI_SUBVER(1)
#define NTDDI_WIN10_RS1 	__NTDDI_WIN10 + __NTDDI_SUBVER(2)
#define NTDDI_WIN10_RS2 	__NTDDI_WIN10 + __NTDDI_SUBVER(3)
#define NTDDI_WIN10_RS3 	__NTDDI_WIN10 + __NTDDI_SUBVER(4)
#define NTDDI_WIN10_RS4 	__NTDDI_WIN10 + __NTDDI_SUBVER(5)
#define NTDDI_WIN10_RS5 	__NTDDI_WIN10 + __NTDDI_SUBVER(6)
#define NTDDI_WIN10_19H1	__NTDDI_WIN10 + __NTDDI_SUBVER(7)

/* Although NTDDI_VERSION is now the preferred designator for the
 * level of support required from the operating system, legacy code
 * is likely to have specified WINVER, from which _WIN32_WINNT may
 * be inferred.
 */
#if defined WINVER && ! defined _WIN32_WINNT
# define _WIN32_WINNT WINVER

/* Additionally, legacy code intended for deployment on the Win9x
 * series operating systems may have specified _WIN32_WINDOWS, as
 * an alternative to, or in addition to, _WIN32_WINNT.
 */
#elif defined _WIN32_WINDOWS && ! defined _WIN32_WINNT
# define _WIN32_WINNT _WIN32_WINDOWS
#endif

/* Stipulate defaults; check consistency of any user specified overrides.
 */
#ifdef NTDDI_VERSION
# ifdef _WIN32_WINNT
#  if _WIN32_WINNT != WINNTVER(NTDDI_VERSION)
#   error "_WIN32_WINNT setting conflicts with specified NTDDI_VERSION"
#  endif
# else
#  define _WIN32_WINNT WINNTVER(NTDDI_VERSION)
#  ifndef WINVER
#   define WINVER _WIN32_WINNT
#  endif
# endif
#endif

#ifndef _WIN32_WINNT
# ifdef WINVER
#  define _WIN32_WINNT WINVER
# else
#  ifdef _WARN_DEFAULTS
#   warning "Assuming default setting of _WIN32_WINNT_WIN2K for _WIN32_WINNT"
#  endif
#  define _WIN32_WINNT _WIN32_WINNT_WIN2K
# endif
#endif

#ifndef WINVER
# define WINVER _WIN32_WINNT
#elif WINVER != _WIN32_WINNT
 /* TODO(REVIEW): is this appropriate for WINVER consistency checking?
  */
# error "_WIN32_WINNT setting conflicts with specified WINVER"
#endif

#ifndef NTDDI_VERSION
# ifdef _WARN_DEFAULTS
#  warning "Assuming default NTDDI_VERSION setting to match _WIN32_WINNT"
# endif
# define NTDDI_VERSION NTDDI_VERSION_FROM_WIN32_WINNT(_WIN32_WINNT)
#endif

#ifndef _WIN32_IE
/* https://msdn.microsoft.com/en-us/library/windows/desktop/bb776779%28v=vs.85%29.aspx
 * specifies that the user should define _WIN32_IE, but in the absence of
 * any such definition, a default equivalent to IE-5.0 may be assumed.
 */
# ifdef _WARN_DEFAULTS
#  warning "Assuming default _WIN32_IE setting to match _WIN32_IE_IE50"
# endif
# define _WIN32_IE _WIN32_IE_IE50
#endif

/* Map GCC architecture identification macros to their MSVC equivalents.
 * This mapping was previously specified in <winnt.h>, and duplicated in
 * <windows.h>; it is now only defined here, because both <windows.h> and
 * <winnt.h> must include this file anyway, and the potentially error prone
 * burden of maintaining duplicates is as unnecessary as it is undesirable.
 */
#ifndef _M_IX86
 /* Note that we must process the _M_IX86 equivalent macros in diminishing
  * order of processor version, since GCC defines __i386__ as identification
  * for the X86 processor family, in addition to any one of the other three
  * macros, which may be used to identify a particular processor version.
  */
# if defined(__i686__)
#  define _M_IX86		600

# elif defined(__i586__)
#  define _M_IX86		500

# elif defined(__i486__)
#  define _M_IX86		400

# elif defined(__i386__)
#  define _M_IX86		300
# endif
#endif

/* The preceding logic may have established the host type as X86, or it
 * may have done nothing at all; we must check further.
 */
#ifdef _M_IX86
 /* We've established that we ARE compiling for an X86 host; any MinGW32
  * compiler SHOULD have set this for us already...
  */
# ifndef _X86_
  /* ...but cross-check it anyway, in case the user may have some unusual
   * compiler configuration in place.
   */
#  define _X86_ 		1
# endif

# ifndef _M_IX86_FP
  /* MSVC defines this, to provide additional information about particular
   * capabilties of the X86 host environment; specifically...
   */
#  ifdef __SSE2__
   /* ...this indicates that the SSE2 instruction set (or better) may be
    * assumed to be supported...
    */
#   define _M_IX86_FP		2

#  elif defined(__SSE__)
   /* ...whereas, this promises only basic SSE instruction set support...
    */
#   define _M_IX86_FP		1

#  else
   /* ...and this disallows its use, entirely.
    */
#   define _M_IX86_FP		0
#  endif
# endif

/* When not compiling for an X86 host; check mapping from other possible
 * GCC architecture identifiers, to their MSVC equivalents.
 */
#elif defined(__x86_64__) || defined(__amd64__)
 /* This represents an Intel X86-64, or (compatible) AMD-64 processor;
  * MSVC defines...
  */
# ifndef _M_X64
  /* ...this to represent the former, together with...
   */
#  define _M_X64		1
# endif
# ifndef _M_AMD64
  /* ...this alias, to represent the latter.
   */
#  define _M_AMD64		1
# endif

#elif defined(__ia64__)
 /* This represents an Intel Itanium processor, which MSVC designates
  * by defining this feature test macro.
  */
# ifndef _M_IA64
#  define _M_IA64		1
# endif
#endif	/* !_M_IX86 */

#endif /* _SDKDDKVER_H: $RCSfile: sdkddkver.h,v $: end of file */
 

/* The following defines are for documentation purposes.  Although not used
 * within it, they were provided in earlier versions of the Win32 API, as a
 * convenience for users who wished to symbolically declare a minimum level
 * of required operating system and Internet Explorer version support, when
 * assigning WINVER, _WIN32_WINDOWS, _WIN32_WINNT, and _WIN32_IE values.
 *
 * Each of the following "old name" macros is now considered deprecated in
 * favour of manifest "preferred name" macro definitions from <sdkddkver.h>.
 * Hence, redefine each in terms of the appropriate "preferred name" macro;
 * new code should avoid the old names, and use the preferred name instead.
 *
 *
 * _WIN32_WINDOWS and/or WINVER may be set to any of the following manifest
 * values, to specify a minimum Win9x support level requirement:
 *
 *      Old Name	Preferred Name
 *      -------------	------------------
 */
#define Windows95	_WIN32_WINDOWS_95
#define Windows98	_WIN32_WINDOWS_98
#define WindowsME	_WIN32_WINDOWS_ME

/* _WIN32_WINNT and/or WINVER may be set to any of the following manifest
 * values, to specify a minimum WinNT support level requirement:
 *
 *      Old Name	Preferred Name
 *      -------------	------------------
 */
#define WindowsNT4	_WIN32_WINNT_NT4
#define Windows2000	_WIN32_WINNT_WIN2K
#define WindowsXP	_WIN32_WINNT_WINXP
#define Windows2003	_WIN32_WINNT_WS03
#define WindowsVista	_WIN32_WINNT_VISTA

/* _WIN32_IE may be set to any of the following manifest values, to
 * specify a minimum Internet Explorer support level requirement:
 *
 *      Old Name	Preferred Name
 *      -------------	------------------
 */
#define IE3		_WIN32_IE_IE30
#define IE301		_WIN32_IE_IE301
#define IE302		_WIN32_IE_IE302
#define IE4		_WIN32_IE_IE40
#define IE401		_WIN32_IE_IE401
#define IE5		_WIN32_IE_IE50
#define IE5a		_WIN32_IE_IE50
#define IE5b		_WIN32_IE_IE50
#define IE501		_WIN32_IE_IE501
#define IE55		_WIN32_IE_IE55
#define IE56		_WIN32_IE_IE56
#define IE6		_WIN32_IE_IE60
#define IE601		_WIN32_IE_IE60SP1
#define IE602		_WIN32_IE_IE60SP2
#define IE7		_WIN32_IE_IE70


/* Only Microsoft could attempt to justify this insanity: when building
 * a UTF-16LE application -- apparently their understanding of Unicode is
 * limited to this -- the C/C++ runtime requires that the user must define
 * the _UNICODE macro, while to use the Windows API's UTF-16LE capabilities,
 * it is the UNICODE macro, (without the leading underscore), which must be
 * defined.  The (bogus) explanation appears to be that it is the C standard
 * which dictates the requirement for the leading underscore, to avoid any
 * possible conflict with a user defined symbol; (bogus because the macro
 * must be user defined anyway -- it is not a private symbol -- and in
 * any case, the Windows API already reserves the UNICODE symbol as
 * a user defined macro, with equivalent intent.
 *
 * The real explanation, of course, is that this is just another example
 * of Microsoft irrationality; in any event, there seems to be no sane
 * scenario in which defining one without the other would be required,
 * or indeed would not raise potential for internal inconsistency, so we
 * ensure that either both are, or neither is defined.
 */
#if defined UNICODE && ! defined _UNICODE
# define _UNICODE  UNICODE
#elif defined _UNICODE && ! defined UNICODE
# define UNICODE  _UNICODE
#endif
/* Related to the UNICODE macro definition, there are many functions in
 * the Win32 API with a generic name, which is mapped to a variant with
 * wchar_t UTF-16LE encoding of string arguments, in cases when UNICODE
 * is defined, as facilitated by the following macro...
 */
#ifdef UNICODE
 /* ...by appending a "W" suffix to the generic function name...
  */
# define __AW_SUFFIXED__(__NAME__)  __NAME__##W
#else
 /* ...or by appending an "A" suffix, to select an ANSI variant with
  * char encoding of string arguments, when UNICODE is not defined.
  */
# define __AW_SUFFIXED__(__NAME__)  __NAME__##A
#endif
/* Further related, the __AW_EXTENDED__ macro reproduces the effect of
 * __AW_SUFFIXED__, with the addition of a single underscore character
 * separating the base name from the appropriate suffix.
 */
#define __AW_EXTENDED__(__NAME__)  __AW_SUFFIXED__(__NAME__##_)

/* __AW_EXTENDED__ may often be used to map manifest string constants.
 * The following triplet provide a convenient mechanism to derive the
 * UNICODE variant of the string from its ANSI definition; (note that
 * this requires a two stage expansion, to ensure that the "L" prefix
 * is attached to the expansion of the ANSI string definition, rather
 * than just to the defining macro name).
 */
#define __AW_STRING_A__(__TEXT__)  __TEXT__
#define __AW__WCHAR_T__(__TEXT__)  __AW_STRING_A__(L##__TEXT__)
#define __AW_STRING_W__(__TEXT__)  __AW__WCHAR_T__(__TEXT__)

/* Further uses of __AW_SUFFIXED__ and __AW_EXTENDED__, encapsulated
 * within __AW_ALIAS__ and __AW_ALIAS_EX__; each provides a convenient
 * generic mapping for type names with alternative representations for
 * UNICODE and non-UNICODE usage.
 */
#define __AW_ALIAS__(__NAME__)     __AW_SUFFIXED__(__NAME__) __NAME__
#define __AW_ALIAS_EX__(__NAME__)  __AW_EXTENDED__(__NAME__) __NAME__

#ifdef __cplusplus
/* When compiling C++ code, these macros provide a convenient notation
 * for designating those sections of system header files which declare
 * prototypes for API functions with "C" binding...
 */
# define _EXTERN_C       extern "C"
# define _BEGIN_C_DECLS  extern "C" {
# define _END_C_DECLS    }

#else
/* ...while remaining transparent, when compiling C code.
 */
# define _EXTERN_C       extern
# define _BEGIN_C_DECLS
# define _END_C_DECLS
#endif

#endif /* ! _W32API_H: $RCSfile: w32api.h.in,v $: end of file */
 

/* The following are defined by the user (or by the compiler), to specify how
 * identifiers are imported from a DLL.  All headers should include this first,
 * and then use __DECLSPEC_SUPPORTED to choose between the old ``__imp__name''
 * style or the __MINGW_IMPORT style for declarations.
 *
 * __DECLSPEC_SUPPORTED            Defined if dllimport attribute is supported.
 * __MINGW_IMPORT                  The attribute definition to specify imported
 *                                 variables/functions.
 * _CRTIMP                         As above.  For MS compatibility.
 *
 * Macros to enable MinGW features which deviate from standard MSVC
 * compatible behaviour; these may be specified directly in user code,
 * activated implicitly, (e.g. by specifying _POSIX_C_SOURCE or such),
 * or by inclusion in __MINGW_FEATURES__:
 *
 * __USE_MINGW_ANSI_STDIO          Select a more ANSI C99 compatible
 *                                 implementation of printf() and friends;
 *                                 (users should not set this directly).
 *
 * Other macros:
 *
 * __int64                         define to be long long.  Using a typedef
 *                                 doesn't work for "unsigned __int64"
 *
 *
 * Manifest definitions for flags to control globbing of the command line
 * during application start up, (before main() is called).  The first pair,
 * when assigned as bit flags within _CRT_glob, select the globbing algorithm
 * to be used; (the MINGW algorithm overrides MSCVRT, if both are specified).
 * Prior to mingwrt-3.21, only the MSVCRT option was supported; this choice
 * may produce different results, depending on which particular version of
 * MSVCRT.DLL is in use; (in recent versions, it seems to have become
 * definitively broken, when globbing within double quotes).
 */
#define __CRT_GLOB_USE_MSVCRT__  	0x0001

/* From mingwrt-3.21 onward, this should be the preferred choice; it will
 * produce consistent results, regardless of the MSVCRT.DLL version in use.
 */
#define __CRT_GLOB_USE_MINGW__   	0x0002

/* When the __CRT_GLOB_USE_MINGW__ flag is set, within _CRT_glob, the
 * following additional options are also available; they are not enabled
 * by default, but the user may elect to enable any combination of them,
 * by setting _CRT_glob to the boolean sum (i.e. logical OR combination)
 * of __CRT_GLOB_USE_MINGW__ and the desired options.
 *
 *    __CRT_GLOB_USE_SINGLE_QUOTE__	allows use of single (apostrophe)
 *    					quoting characters, analogously to
 *    					POSIX usage, as an alternative to
 *    					double quotes, for collection of
 *    					arguments separated by white space
 *    					into a single logical argument.
 *
 *    __CRT_GLOB_BRACKET_GROUPS__	enable interpretation of bracketed
 *    					character groups as POSIX compatible
 *    					globbing patterns, matching any one
 *    					character which is either included
 *    					in, or excluded from the group.
 *
 * The following options, which may also be specified within _CRT_glob,
 * are specified in terms of their glob() flags, as defined in <glob.h>
 *
 *    GLOB_CASEMATCH			enable case sensitive matching for
 *    					globbing patterns; this is default
 *    					behaviour for POSIX, but because of
 *    					the case insensitive nature of the
 *    					MS-Windows file system, it is more
 *    					appropriate to use case insensitive
 *    					globbing as the MinGW default.
 *
 *    GLOB_BRACE			enable expansion of GNU style brace
 *    					delimited expression groups within
 *    					the globbing pattern.
 *
 */
#define __CRT_GLOB_USE_SINGLE_QUOTE__	0x0010
#define __CRT_GLOB_BRACKET_GROUPS__	0x0020

/* The MinGW globbing algorithm uses the ASCII DEL control code as a marker
 * for globbing characters which were embedded within quoted arguments; (the
 * quotes are stripped away BEFORE the argument is globbed; the globbing code
 * treats the marked character as immutable, and strips out the DEL markers,
 * before storing the resultant argument).  The DEL code is mapped to this
 * function here; DO NOT change it, without rebuilding the runtime.
 */
#define __CRT_GLOB_ESCAPE_CHAR__	(char)(127)


/* Load any user-customized features configuration...
 */
#ifdef _MINGW_FEATURES_HEADER
/* ...from a user-specified, or project-specified alternative file...
 */
_MINGW_FEATURES_HEADER#else
/* ...or fall back to the default configuration file, (which may,
 * or may not have been customized).
 */
/*
 * features.h
 *
 * Features configuration for MinGW.org GCC implementation; users may
 * customize this file, to establish their preferred default behaviour.
 * Projects may provide an alternative, package-specific configuration,
 * either by placing their own customized <features.h> in the package
 * -I path, ahead of the system default, or by assignment of their
 * preferred alternative to the _MINGW_FEATURES_HEADER macro.
 *
 *
 * $Id$
 *
 * Template written by Keith Marshall <keith@users.osdn.me>
 * Copyright (C) 2019, MinGW.org Project.
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice, this permission notice, and the following
 * disclaimer shall be included in all copies or substantial portions of
 * the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OF OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef __MINGW_FEATURES__
#pragma GCC system_header

/* Users are expected to customize this header, but it remains subject to
 * automatic updates by system software.  To ensure that any customisation
 * is not ovewritten, during such updates, it MUST observe the following:
 *
 * This header MUST define __MINGW_FEATURES__; the definition MUST begin
 * with "#define __MINGW_FEATURES__ (__MINGW_FEATURES_BEGIN__) \"; it MUST
 * extend over multiple lines, and terminate with "__MINGW_FEATURES_END__";
 * intervening lines may enumerate any defined features, one per line, and
 * each specified as an argument to either the __MINGW_FEATURE_ENABLE__(),
 * or the __MINGW_FEATURE_IGNORE__() macro, (ensuring that at least one
 * space separates either of these macro names from its parenthesized
 * argument name).
 *
 * CAUTION:
 * If customizing this features configuration, ALWAYS refer to features
 * using their designated symbolic constant names; NEVER usurp the use of
 * these symbolic constants for any other purpose, and NEVER assume that
 * any such constant has a specific value ... their definitions may vary
 * between distinct MinGW Runtime Library software releases!
 */
#define __MINGW_FEATURES__    (__MINGW_FEATURES_BEGIN__)        \
 __MINGW_FEATURE_IGNORE__     (__MINGW_ANSI_STDIO__)            \
 __MINGW_FEATURE_IGNORE__     (__MINGW_LC_MESSAGES__)           \
 __MINGW_FEATURE_IGNORE__     (__MINGW_LC_ENVVARS__)            \
 __MINGW_FEATURES_END__

#endif	/* !__MINGW_FEATURES__: $RCSfile$: end of file */
 
#endif

#ifndef __MINGW_FEATURES__
/* Regardless of how the preceding features configuration header was
 * identified, we normally expect that will have defined this, but we
 * supply this fall-back, just in case it is needed.
 */
#define __MINGW_FEATURES__		0ULL
#endif

/* Define macros to facilitate the user-specified configuration.
 */
#define __MINGW_FEATURE_ENABLE__(__FEATURE__) | (__FEATURE__)
#define __MINGW_FEATURE_IGNORE__(__FEATURE__)

#define __MINGW_FEATURES_BEGIN__	0x0000000000000000ULL
#define __MINGW_FEATURES_UNSET__	0x0000000000000000ULL
#define __MINGW_FEATURES_END__

/* Manifest definitions identifying the flag bits, controlling activation
 * of MinGW features, as specified by the user in __MINGW_FEATURES__.
 */
#define __MINGW_ANSI_STDIO__		0x0000000000000001ULL
/*
 * The following three are not yet formally supported; they are
 * included here, to document anticipated future usage.
 */
#define __MINGW_LC_EXTENSIONS__ 	0x0000000000000050ULL
#define __MINGW_LC_MESSAGES__		0x0000000000000010ULL
#define __MINGW_LC_ENVVARS__		0x0000000000000040ULL


/* Try to avoid problems with outdated checks for GCC __attribute__ support.
 */
#undef __attribute__

#if defined (__PCC__)
#  undef __DECLSPEC_SUPPORTED
# ifndef __MINGW_IMPORT
#  define __MINGW_IMPORT extern
# endif
# ifndef _CRTIMP
#  define _CRTIMP
# endif
# ifndef __cdecl
#  define __cdecl  _Pragma("cdecl")
# endif
# ifndef __stdcall
#  define __stdcall _Pragma("stdcall")
# endif
# ifndef __int64
#  define __int64 long long
# endif
# ifndef __int32
#  define __int32 long
# endif
# ifndef __int16
#  define __int16 short
# endif
# ifndef __int8
#  define __int8 char
# endif
# ifndef __small
#  define __small char
# endif
# ifndef __hyper
#  define __hyper long long
# endif
# ifndef __volatile__
#  define __volatile__ volatile
# endif
# ifndef __restrict__
#  define __restrict__ restrict
# endif
# define NONAMELESSUNION
#elif defined(__GNUC__)
# ifdef __declspec
#  ifndef __MINGW_IMPORT
   /* Note the extern. This is needed to work around GCC's
      limitations in handling dllimport attribute.  */
#   define __MINGW_IMPORT  extern __attribute__((__dllimport__))
#  endif
#  ifndef _CRTIMP
#   ifdef __USE_CRTIMP
#    define _CRTIMP  __attribute__((dllimport))
#   else
#    define _CRTIMP
#   endif
#  endif
#  define __DECLSPEC_SUPPORTED
# else /* __declspec */
#  undef __DECLSPEC_SUPPORTED
#  undef __MINGW_IMPORT
#  ifndef _CRTIMP
#   define _CRTIMP
#  endif
# endif /* __declspec */
/*
 * The next two defines can cause problems if user code adds the
 * __cdecl attribute like so:
 * void __attribute__ ((__cdecl)) foo(void);
 */
# ifndef __cdecl
#  define __cdecl  __attribute__((__cdecl__))
# endif
# ifndef __stdcall
#  define __stdcall __attribute__((__stdcall__))
# endif
# ifndef __int64
#  define __int64 long long
# endif
# ifndef __int32
#  define __int32 long
# endif
# ifndef __int16
#  define __int16 short
# endif
# ifndef __int8
#  define __int8 char
# endif
# ifndef __small
#  define __small char
# endif
# ifndef __hyper
#  define __hyper long long
# endif
#else /* ! __GNUC__ && ! __PCC__ */
# ifndef __MINGW_IMPORT
#  define __MINGW_IMPORT  __declspec(dllimport)
# endif
# ifndef _CRTIMP
#  define _CRTIMP  __declspec(dllimport)
# endif
# define __DECLSPEC_SUPPORTED
# define __attribute__(x) /* nothing */
#endif

#if defined (__GNUC__) && defined (__GNUC_MINOR__)
#define __MINGW_GNUC_PREREQ(major, minor) \
  (__GNUC__ > (major) \
   || (__GNUC__ == (major) && __GNUC_MINOR__ >= (minor)))
#else
#define __MINGW_GNUC_PREREQ(major, minor)  0
#endif

#ifdef __cplusplus
# define __CRT_INLINE    inline
#else
# if __GNUC_STDC_INLINE__
#  define __CRT_INLINE   extern inline __attribute__((__gnu_inline__))
# else
#  define __CRT_INLINE   extern __inline__
# endif
#endif

# ifdef __GNUC__
  /* A special form of __CRT_INLINE is provided; it will ALWAYS request
   * inlining when possible.  Originally specified as _CRTALIAS, this is
   * now deprecated in favour of __CRT_ALIAS, for syntactic consistency
   * with __CRT_INLINE itself.
   */
#  define  _CRTALIAS   __CRT_INLINE __attribute__((__always_inline__))
#  define __CRT_ALIAS  __CRT_INLINE __attribute__((__always_inline__))
# else
#  define  _CRTALIAS   __CRT_INLINE	/* deprecated form */
#  define __CRT_ALIAS  __CRT_INLINE	/* preferred form */
# endif
/*
 * Each function which is implemented as a __CRT_ALIAS should also be
 * accompanied by an externally visible interface.  The following pair
 * of macros provide a mechanism for implementing this, either as a stub
 * redirecting to an alternative external function, or by compilation of
 * the normally inlined code into free standing object code; each macro
 * provides a way for us to offer arbitrary hints for use by the build
 * system, while remaining transparent to the compiler.
 */
#define __JMPSTUB__(__BUILD_HINT__)
#define __LIBIMPL__(__BUILD_HINT__)

#ifdef __cplusplus
# define __UNUSED_PARAM(x)
#else
# ifdef __GNUC__
#  define __UNUSED_PARAM(x) x __attribute__((__unused__))
# else
#  define __UNUSED_PARAM(x) x
# endif
#endif

#ifdef __GNUC__
#define __MINGW_ATTRIB_NORETURN __attribute__((__noreturn__))
#define __MINGW_ATTRIB_CONST __attribute__((__const__))
#else
#define __MINGW_ATTRIB_NORETURN
#define __MINGW_ATTRIB_CONST
#endif

#if __MINGW_GNUC_PREREQ (3, 0)
#define __MINGW_ATTRIB_MALLOC __attribute__((__malloc__))
#define __MINGW_ATTRIB_PURE __attribute__((__pure__))
#else
#define __MINGW_ATTRIB_MALLOC
#define __MINGW_ATTRIB_PURE
#endif

/* Attribute `nonnull' was valid as of gcc 3.3.  We don't use GCC's
   variadiac macro facility, because variadic macros cause syntax
   errors with  --traditional-cpp.  */
#if  __MINGW_GNUC_PREREQ (3, 3)
#define __MINGW_ATTRIB_NONNULL(arg) __attribute__((__nonnull__(arg)))
#else
#define __MINGW_ATTRIB_NONNULL(arg)
#endif /* GNUC >= 3.3 */

#if  __MINGW_GNUC_PREREQ (3, 1)
#define __MINGW_ATTRIB_DEPRECATED __attribute__((__deprecated__))
#else
#define __MINGW_ATTRIB_DEPRECATED
#endif /* GNUC >= 3.1 */

#if  __MINGW_GNUC_PREREQ (3, 3)
#define __MINGW_NOTHROW __attribute__((__nothrow__))
#else
#define __MINGW_NOTHROW
#endif /* GNUC >= 3.3 */


/* TODO: Mark (almost) all CRT functions as __MINGW_NOTHROW.  This will
allow GCC to optimize away some EH unwind code, at least in DW2 case.  */

/* Activation of MinGW specific extended features:
 */
#ifdef __USE_MINGW_ANSI_STDIO
/* Users should not set this directly; rather, define one (or more)
 * of the feature test macros (tabulated below), or specify any of the
 * compiler's command line options, (e.g. -posix, -ansi, or -std=c...),
 * which cause _POSIX_SOURCE, or __STRICT_ANSI__ to be defined.
 */
# warning "Direct definition of __USE_MINGW_ANSI_STDIO is deprecated."
# pragma message "See <_mingw.h> for preferred feature activation methods."

#else	/* ! defined __USE_MINGW_ANSI_STDIO */
/* We must check this BEFORE we specifiy any implicit _POSIX_C_SOURCE,
 * otherwise we would always implicitly choose __USE_MINGW_ANSI_STDIO,
 * even if none of these selectors are specified explicitly...
 */
# if  defined __STRICT_ANSI__  ||  defined _SVID_SOURCE            \
  ||  defined _ISOC99_SOURCE   ||  defined _ISOC11_SOURCE          \
  ||  defined _POSIX_SOURCE    ||  defined _POSIX_C_SOURCE         \
  ||  defined _XOPEN_SOURCE    ||  defined _XOPEN_SOURCE_EXTENDED  \
  ||  defined _GNU_SOURCE      ||  defined _BSD_SOURCE
  /*
   * but where any of these source code qualifiers are specified,
   * then assume ANSI I/O standards are preferred over Microsoft's...
   */
#  define __USE_MINGW_ANSI_STDIO   __MINGW_ANSI_STDIO__
# else
  /* otherwise use whatever __MINGW_FEATURES__ specifies...
   */
#  define __USE_MINGW_ANSI_STDIO  (__MINGW_FEATURES__ & __MINGW_ANSI_STDIO__)
# endif
#endif

/* Some applications may define _XOPEN_SOURCE, without assigning any
 * value to it.  Such usage may have been permitted in early SUS, but
 * it became obsolete as of SUSv2.  Attempt to detect obsolete usage,
 * as it makes an effective evaluation of any _XOPEN_SOURCE version
 * dependency difficult, (without the use of ugly kludges at EVERY
 * point of reference which attempts a version comparison).
 */
#define __paste(prefix,suffix)  prefix ## suffix
#define __valueless(token)  ((token - 0) == 0) && (__paste(token,10) == 10)

#if defined _XOPEN_SOURCE && __valueless(_XOPEN_SOURCE)
/* _XOPEN_SOURCE appears to have been defined without its mandatory
 * value; diagnose this brain-damaged obsolete usage (verbosely)...
 */
#warning "_XOPEN_SOURCE seems to have been improperly defined."
#warning "Mandatory _XOPEN_SOURCE value assignment appears to be missing."
#warning "Redefining _XOPEN_SOURCE to mitigate obsolete misuse."

/* ...and redefine, emulating implicit behaviour of -D_XOPEN_SOURCE on
 * the GCC command line, (which DOES assign an implied value of one).
 */
#undef  _XOPEN_SOURCE
#define _XOPEN_SOURCE  1
#endif

#ifndef _POSIX_C_SOURCE
 /* Users may define this, either directly or indirectly, to explicitly
  * enable a particular level of visibility for the subset of those POSIX
  * features which are supported by MinGW; (notice that this offers no
  * guarantee that any particular POSIX feature will be supported).
  */
# if defined _XOPEN_SOURCE
  /* Specifying this is the preferred method for setting _POSIX_C_SOURCE;
   * (POSIX defines an explicit relationship to _XOPEN_SOURCE).  Note that
   * any such explicit setting will augment the set of features which are
   * available to any compilation unit, even if it seeks to be strictly
   * ANSI-C compliant.
   */
#  if _XOPEN_SOURCE < 500
#   define _POSIX_C_SOURCE  1L		/* POSIX.1-1990 / SUSv1 */

#  elif _XOPEN_SOURCE < 600
#   define _POSIX_C_SOURCE  199506L	/* POSIX.1-1996 / SUSv2 */

#  elif _XOPEN_SOURCE < 700
#   define _POSIX_C_SOURCE  200112L	/* POSIX.1-2001 / SUSv3 */

#  else
#   define _POSIX_C_SOURCE  200809L	/* POSIX.1-2008 / SUSv4 */
#  endif

# elif defined _GNU_SOURCE || defined _BSD_SOURCE || ! defined __STRICT_ANSI__
  /*
   * No explicit level of support has been specified; implicitly grant
   * the most comprehensive level to any compilation unit which requests
   * either GNU or BSD feature support, or does not seek to be strictly
   * ANSI-C compliant.
   */
#  define _POSIX_C_SOURCE  200809L

#  if ! defined _EMULATE_GLIBC && ! defined _POSIX_SOURCE
   /* For this default case, unless it has already been specified
    * otherwise, we enable some GNU glibc extensions, which may be
    * considered as violations of strict POSIX.1 conformance.
    */
#   define _EMULATE_GLIBC  1
#  endif

# elif defined _POSIX_SOURCE
  /* Now formally deprecated by POSIX, some old code may specify this;
   * it will enable a minimal level of POSIX support, in addition to the
   * limited feature set enabled for strict ANSI-C conformity.
   */
#  define _POSIX_C_SOURCE  1L
# endif
#endif

#if _POSIX_C_SOURCE >= 199506L
/* Conformance with POSIX.1-1996 has been requested; ensure that any
 * interfaces which have been marked as "obsolescent", from this POSIX
 * version onwards, will be reported as "deprecated", at point of use.
 */
# define __POSIX_1996_DEPRECATED  __MINGW_ATTRIB_DEPRECATED
#else
/* POSIX.1-1996 conformance is NOT required; do not object to use of
 * interfaces which became "obsolescent" in this POSIX version, but
 * were still fully supported in earlier versions.
 */
# define __POSIX_1996_DEPRECATED
#endif

#if _POSIX_C_SOURCE >= 200112L
/* Conformance with POSIX.1-2001 has been requested; ensure that any
 * interfaces which have been marked as "obsolescent", from this POSIX
 * version onwards, will be reported as "deprecated", at point of use.
 */
# define __POSIX_2001_DEPRECATED  __MINGW_ATTRIB_DEPRECATED
#else
/* POSIX.1-2001 conformance is NOT required; do not object to use of
 * interfaces which became "obsolescent" in this POSIX version, but
 * were still fully supported in earlier versions.
 */
# define __POSIX_2001_DEPRECATED
#endif

#if _POSIX_C_SOURCE >= 200809L
/* Conformance with POSIX.1-2008 has been requested; ensure that any
 * interfaces which have been marked as "obsolescent", from this POSIX
 * version onwards, will be reported as "deprecated", at point of use.
 */
# define __POSIX_2008_DEPRECATED  __MINGW_ATTRIB_DEPRECATED
#else
/* POSIX.1-2008 conformance is NOT required; do not object to use of
 * interfaces which became "obsolescent" in this POSIX version, but
 * were still fully supported in earlier versions.
 */
# define __POSIX_2008_DEPRECATED
#endif

#ifndef _ISOC99_SOURCE
 /* libmingwex.a provides free-standing implementations for many of the
  * functions which were introduced in C99; MinGW headers do not expose
  * prototypes for these, unless this feature test macro is defined, by
  * the user, or implied by other standards.  We will use a bit-mapped
  * representation, comprising the bit-wise sum of:
  *
  *   0x08  user declared
  *   0x04  required by C compiler, supporting ISO-C99
  *   0x02  required by C++ compiler, supporting ISO-C++11
  *   0x01  required to support recent POSIX.1 features
  *
  * to ensure that we can identify the reason for implicit declaration,
  * (in the event that we may need to discriminate).
  */
# ifdef _ISOC11_SOURCE
  /* The user has explicitly selected ISO-C11 compliance; regardless of
   * requested C11 compliance level, implicitly enable C99 compliance to
   * the maximum level supported.
   */
#  define _ISOC99_SOURCE  0x0F

# elif __STDC_VERSION__ >= 199901L
  /* This represents a compiler supporting ISO-C99; enable all potential
   * use of ISO-C99 features, (to the maximum extent supportable), which
   * presumably also covers all C++11 and POSIX.1 usage.
   */
#  define _ISOC99_SOURCE  0x07

# elif __cplusplus >= 201103L
  /* C++11 also incorporates many (if not all) of the ISO-C99 features,
   * which we have guarded by _ISOC99_SOURCE; enable such features, to
   * the required extent, (which is likely also sufficient to support
   * any POSIX.1 dependencies).
   */
#  define _ISOC99_SOURCE  0x03

# elif _POSIX_C_SOURCE >= 200112L
  /* This represents the minimum level of ISO-C99 support, which may be
   * required by POSIX.1, (and which may be no less than full support).
   */
#  define _ISOC99_SOURCE  0x01
# endif

#else
 /* The the user has explicitly declared a source level dependency on
  * ISO-C99 features; regardless of how it was declared, redefine it to
  * ensure that any plausible dependency is covered.
  */
# undef _ISOC99_SOURCE
# define _ISOC99_SOURCE  0x0F

#endif	/* _ISOC99_SOURCE */

#if _ISOC99_SOURCE && __cplusplus >= 201103L && __GNUC__ < 6
 /* Due to a configuration defect in GCC versions prior to GCC-6, when
  * compiling C++11 code, the ISO-C99 functions may not be incorporated
  * into the appropriate namespace(s); we may be able to mitigate this,
  * by ensuring that these GCC configuration macros are defined.
  */
# define _GLIBCXX_USE_C99	1
# define _GLIBCXX_HAVE_WCSTOF	1
#endif

#if ! defined _MINGW32_SOURCE_EXTENDED && ! defined __STRICT_ANSI__
 /* Enable mingw32 extensions by default, except when __STRICT_ANSI__
  * conformity mode has been enabled.
  */
# define _MINGW32_SOURCE_EXTENDED  1
#endif

#endif /* __MINGW_H: $RCSfile: _mingw.h.in,v $: end of file */
 

#ifndef RC_INVOKED
/* POSIX stipulates that the following set of types, (as identified by
 * __need_TYPENAME macros), shall be defined consistently with <stddef.h>;
 * by defining the appropriate __need_TYPENAME macros, we may selectively
 * obtain the required definitions by inclusion of <stddef.h>, WITHOUT
 * automatic exposure of any of its additional content.
 */
#define __need_NULL
#define __need_size_t
#define __need_wchar_t
#define __need_wint_t
/* Copyright (C) 1989-2019 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.17  Common definitions  <stddef.h>
 */
#if (!defined(_STDDEF_H) && !defined(_STDDEF_H_) && !defined(_ANSI_STDDEF_H) \
     && !defined(__STDDEF_H__)) \
    || defined(__need_wchar_t) || defined(__need_size_t) \
    || defined(__need_ptrdiff_t) || defined(__need_NULL) \
    || defined(__need_wint_t)

/* Any one of these symbols __need_* means that GNU libc
   wants us just to define one data type.  So don't define
   the symbols that indicate this file's entire job has been done.  */
#if (!defined(__need_wchar_t) && !defined(__need_size_t)	\
     && !defined(__need_ptrdiff_t) && !defined(__need_NULL)	\
     && !defined(__need_wint_t))
#define _STDDEF_H
#define _STDDEF_H_
/* snaroff@next.com says the NeXT needs this.  */
#define _ANSI_STDDEF_H
#endif

#ifndef __sys_stdtypes_h
/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */

#if defined(__NetBSD__)


#endif

#if defined (__FreeBSD__)


#endif

#if defined(__NetBSD__)
#if !defined(_SIZE_T_) && !defined(_BSD_SIZE_T_)
#define _SIZE_T
#endif
#if !defined(_PTRDIFF_T_) && !defined(_BSD_PTRDIFF_T_)
#define _PTRDIFF_T
#endif
/* On BSD/386 1.1, at least, machine/ansi.h defines _BSD_WCHAR_T_
   instead of _WCHAR_T_. */
#if !defined(_WCHAR_T_) && !defined(_BSD_WCHAR_T_)
#ifndef _BSD_WCHAR_T_
#define _WCHAR_T
#endif
#endif
/* Undef _FOO_T_ if we are supposed to define foo_t.  */
#if defined (__need_ptrdiff_t) || defined (_STDDEF_H_)
#undef _PTRDIFF_T_
#undef _BSD_PTRDIFF_T_
#endif
#if defined (__need_size_t) || defined (_STDDEF_H_)
#undef _SIZE_T_
#undef _BSD_SIZE_T_
#endif
#if defined (__need_wchar_t) || defined (_STDDEF_H_)
#undef _WCHAR_T_
#undef _BSD_WCHAR_T_
#endif
#endif /* defined(__NetBSD__) */

/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */
#if defined (__sequent__) && defined (_PTRDIFF_T_)
#undef _PTRDIFF_T_
#endif

/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
#if defined (_TYPE_ptrdiff_t) && (defined (__need_ptrdiff_t) || defined (_STDDEF_H_))
_TYPE_ptrdiff_t;
#undef _TYPE_ptrdiff_t
#endif
#if defined (_TYPE_size_t) && (defined (__need_size_t) || defined (_STDDEF_H_))
_TYPE_size_t;
#undef _TYPE_size_t
#endif
#if defined (_TYPE_wchar_t) && (defined (__need_wchar_t) || defined (_STDDEF_H_))
_TYPE_wchar_t;
#undef _TYPE_wchar_t
#endif

/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
#if defined (_STDDEF_H) || defined (__need_ptrdiff_t)
#ifndef _PTRDIFF_T	/* in case <sys/types.h> has defined it. */
#ifndef _T_PTRDIFF_
#ifndef _T_PTRDIFF
#ifndef __PTRDIFF_T
#ifndef _PTRDIFF_T_
#ifndef _BSD_PTRDIFF_T_
#ifndef ___int_ptrdiff_t_h
#ifndef _GCC_PTRDIFF_T
#ifndef _PTRDIFF_T_DECLARED /* DragonFly */
#define _PTRDIFF_T
#define _T_PTRDIFF_
#define _T_PTRDIFF
#define __PTRDIFF_T
#define _PTRDIFF_T_
#define _BSD_PTRDIFF_T_
#define ___int_ptrdiff_t_h
#define _GCC_PTRDIFF_T
#define _PTRDIFF_T_DECLARED
#ifndef __PTRDIFF_TYPE__
#define __PTRDIFF_TYPE__ long int
#endif
typedef __PTRDIFF_TYPE__ ptrdiff_t;
#endif /* _PTRDIFF_T_DECLARED */
#endif /* _GCC_PTRDIFF_T */
#endif /* ___int_ptrdiff_t_h */
#endif /* _BSD_PTRDIFF_T_ */
#endif /* _PTRDIFF_T_ */
#endif /* __PTRDIFF_T */
#endif /* _T_PTRDIFF */
#endif /* _T_PTRDIFF_ */
#endif /* _PTRDIFF_T */

/* If this symbol has done its job, get rid of it.  */
#undef	__need_ptrdiff_t

#endif /* _STDDEF_H or __need_ptrdiff_t.  */

/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
#if defined (_STDDEF_H) || defined (__need_size_t)
#ifndef __size_t__	/* BeOS */
#ifndef __SIZE_T__	/* Cray Unicos/Mk */
#ifndef _SIZE_T	/* in case <sys/types.h> has defined it. */
#ifndef _SYS_SIZE_T_H
#ifndef _T_SIZE_
#ifndef _T_SIZE
#ifndef __SIZE_T
#ifndef _SIZE_T_
#ifndef _BSD_SIZE_T_
#ifndef _SIZE_T_DEFINED_
#ifndef _SIZE_T_DEFINED
#ifndef _BSD_SIZE_T_DEFINED_	/* Darwin */
#ifndef _SIZE_T_DECLARED	/* FreeBSD 5 */
#ifndef ___int_size_t_h
#ifndef _GCC_SIZE_T
#ifndef _SIZET_
#ifndef __size_t
#define __size_t__	/* BeOS */
#define __SIZE_T__	/* Cray Unicos/Mk */
#define _SIZE_T
#define _SYS_SIZE_T_H
#define _T_SIZE_
#define _T_SIZE
#define __SIZE_T
#define _SIZE_T_
#define _BSD_SIZE_T_
#define _SIZE_T_DEFINED_
#define _SIZE_T_DEFINED
#define _BSD_SIZE_T_DEFINED_	/* Darwin */
#define _SIZE_T_DECLARED	/* FreeBSD 5 */
#define ___int_size_t_h
#define _GCC_SIZE_T
#define _SIZET_
#if defined (__FreeBSD__) \
  || defined(__DragonFly__) \
  || defined(__FreeBSD_kernel__) \
  || defined(__VMS__)
/* __size_t is a typedef, must not trash it.  */
#else
#define __size_t
#endif
#ifndef __SIZE_TYPE__
#define __SIZE_TYPE__ long unsigned int
#endif
#if !(defined (__GNUG__) && defined (size_t))
typedef __SIZE_TYPE__ size_t;
#ifdef __BEOS__
typedef long ssize_t;
#endif /* __BEOS__ */
#endif /* !(defined (__GNUG__) && defined (size_t)) */
#endif /* __size_t */
#endif /* _SIZET_ */
#endif /* _GCC_SIZE_T */
#endif /* ___int_size_t_h */
#endif /* _SIZE_T_DECLARED */
#endif /* _BSD_SIZE_T_DEFINED_ */
#endif /* _SIZE_T_DEFINED */
#endif /* _SIZE_T_DEFINED_ */
#endif /* _BSD_SIZE_T_ */
#endif /* _SIZE_T_ */
#endif /* __SIZE_T */
#endif /* _T_SIZE */
#endif /* _T_SIZE_ */
#endif /* _SYS_SIZE_T_H */
#endif /* _SIZE_T */
#endif /* __SIZE_T__ */
#endif /* __size_t__ */
#undef	__need_size_t
#endif /* _STDDEF_H or __need_size_t.  */


/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
#if defined (_STDDEF_H) || defined (__need_wchar_t)
#ifndef __wchar_t__	/* BeOS */
#ifndef __WCHAR_T__	/* Cray Unicos/Mk */
#ifndef _WCHAR_T
#ifndef _T_WCHAR_
#ifndef _T_WCHAR
#ifndef __WCHAR_T
#ifndef _WCHAR_T_
#ifndef _BSD_WCHAR_T_
#ifndef _BSD_WCHAR_T_DEFINED_    /* Darwin */
#ifndef _BSD_RUNE_T_DEFINED_	/* Darwin */
#ifndef _WCHAR_T_DECLARED /* FreeBSD 5 */
#ifndef _WCHAR_T_DEFINED_
#ifndef _WCHAR_T_DEFINED
#ifndef _WCHAR_T_H
#ifndef ___int_wchar_t_h
#ifndef __INT_WCHAR_T_H
#ifndef _GCC_WCHAR_T
#define __wchar_t__	/* BeOS */
#define __WCHAR_T__	/* Cray Unicos/Mk */
#define _WCHAR_T
#define _T_WCHAR_
#define _T_WCHAR
#define __WCHAR_T
#define _WCHAR_T_
#define _BSD_WCHAR_T_
#define _WCHAR_T_DEFINED_
#define _WCHAR_T_DEFINED
#define _WCHAR_T_H
#define ___int_wchar_t_h
#define __INT_WCHAR_T_H
#define _GCC_WCHAR_T
#define _WCHAR_T_DECLARED

/* On BSD/386 1.1, at least, machine/ansi.h defines _BSD_WCHAR_T_
   instead of _WCHAR_T_, and _BSD_RUNE_T_ (which, unlike the other
   symbols in the _FOO_T_ family, stays defined even after its
   corresponding type is defined).  If we define wchar_t, then we
   must undef _WCHAR_T_; for BSD/386 1.1 (and perhaps others), if
   we undef _WCHAR_T_, then we must also define rune_t, since 
   headers like runetype.h assume that if machine/ansi.h is included,
   and _BSD_WCHAR_T_ is not defined, then rune_t is available.
   machine/ansi.h says, "Note that _WCHAR_T_ and _RUNE_T_ must be of
   the same type." */
#ifdef _BSD_WCHAR_T_
#undef _BSD_WCHAR_T_
#ifdef _BSD_RUNE_T_
#if !defined (_ANSI_SOURCE) && !defined (_POSIX_SOURCE)
typedef _BSD_RUNE_T_ rune_t;
#define _BSD_WCHAR_T_DEFINED_
#define _BSD_RUNE_T_DEFINED_	/* Darwin */
#if defined (__FreeBSD__) && (__FreeBSD__ < 5)
/* Why is this file so hard to maintain properly?  In contrast to
   the comment above regarding BSD/386 1.1, on FreeBSD for as long
   as the symbol has existed, _BSD_RUNE_T_ must not stay defined or
   redundant typedefs will occur when stdlib.h is included after this file. */
#undef _BSD_RUNE_T_
#endif
#endif
#endif
#endif
/* FreeBSD 5 can't be handled well using "traditional" logic above
   since it no longer defines _BSD_RUNE_T_ yet still desires to export
   rune_t in some cases... */
#if defined (__FreeBSD__) && (__FreeBSD__ >= 5)
#if !defined (_ANSI_SOURCE) && !defined (_POSIX_SOURCE)
#if __BSD_VISIBLE
#ifndef _RUNE_T_DECLARED
typedef __rune_t        rune_t;
#define _RUNE_T_DECLARED
#endif
#endif
#endif
#endif

#ifndef __WCHAR_TYPE__
#define __WCHAR_TYPE__ int
#endif
#ifndef __cplusplus
typedef __WCHAR_TYPE__ wchar_t;
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif /* _WCHAR_T_DECLARED */
#endif /* _BSD_RUNE_T_DEFINED_ */
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif /* __WCHAR_T__ */
#endif /* __wchar_t__ */
#undef	__need_wchar_t
#endif /* _STDDEF_H or __need_wchar_t.  */

#if defined (__need_wint_t)
#ifndef _WINT_T
#define _WINT_T

#ifndef __WINT_TYPE__
#define __WINT_TYPE__ unsigned int
#endif
typedef __WINT_TYPE__ wint_t;
#endif
#undef __need_wint_t
#endif

#if defined(__NetBSD__)
/*  The references to _GCC_PTRDIFF_T_, _GCC_SIZE_T_, and _GCC_WCHAR_T_
    are probably typos and should be removed before 2.8 is released.  */
#ifdef _GCC_PTRDIFF_T_
#undef _PTRDIFF_T_
#undef _BSD_PTRDIFF_T_
#endif
#ifdef _GCC_SIZE_T_
#undef _SIZE_T_
#undef _BSD_SIZE_T_
#endif
#ifdef _GCC_WCHAR_T_
#undef _WCHAR_T_
#undef _BSD_WCHAR_T_
#endif
/*  The following ones are the real ones.  */
#ifdef _GCC_PTRDIFF_T
#undef _PTRDIFF_T_
#undef _BSD_PTRDIFF_T_
#endif
#ifdef _GCC_SIZE_T
#undef _SIZE_T_
#undef _BSD_SIZE_T_
#endif
#ifdef _GCC_WCHAR_T
#undef _WCHAR_T_
#undef _BSD_WCHAR_T_
#endif
#endif /* __NetBSD__ */

#endif /* __sys_stdtypes_h */

/* A null pointer constant.  */

#if defined (_STDDEF_H) || defined (__need_NULL)
#undef NULL		/* in case <stdio.h> has defined it. */
#ifdef __GNUG__
#define NULL __null
#else   /* G++ */
#ifndef __cplusplus
#define NULL ((void *)0)
#else   /* C++ */
#define NULL 0
#endif  /* C++ */
#endif  /* G++ */
#endif	/* NULL not defined and <stddef.h> or need NULL.  */
#undef	__need_NULL

#ifdef _STDDEF_H

/* Offset of member MEMBER in a struct of type TYPE. */
#define offsetof(TYPE, MEMBER) __builtin_offsetof (TYPE, MEMBER)

#if (defined (__STDC_VERSION__) && __STDC_VERSION__ >= 201112L) \
  || (defined(__cplusplus) && __cplusplus >= 201103L)
#ifndef _GCC_MAX_ALIGN_T
#define _GCC_MAX_ALIGN_T
/* Type whose alignment is supported in every context and is at least
   as great as that of any standard type not using alignment
   specifiers.  */
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
  /* _Float128 is defined as a basic type, so max_align_t must be
     sufficiently aligned for it.  This code must work in C++, so we
     use __float128 here; that is only available on some
     architectures, but only on i386 is extra alignment needed for
     __float128.  */
#ifdef __i386__
  __float128 __max_align_f128 __attribute__((__aligned__(__alignof(__float128))));
#endif
} max_align_t;
#endif
#endif /* C11 or C++11.  */

#if defined(__cplusplus) && __cplusplus >= 201103L
#ifndef _GXX_NULLPTR_T
#define _GXX_NULLPTR_T
  typedef decltype(nullptr) nullptr_t;
#endif
#endif /* C++11.  */

#endif /* _STDDEF_H was defined this time */

#endif /* !_STDDEF_H && !_STDDEF_H_ && !_ANSI_STDDEF_H && !__STDDEF_H__
	  || __need_XXX was not defined before */
 

#if _POSIX_C_SOURCE >= 200809L
 /* Similarly, for types defined in <sys/types.h>, (which are explicitly
  * dependent on the POSIX.1-2008 feature test)...
  */
# define __need_off_t
# define __need_ssize_t
#endif

/* Although non-standard themselves, we also need either one or other
 * of the following pair of data types, from <sys/types.h>, because our
 * standard fpos_t is opaquely defined in terms of...
 */
#ifdef __MSVCRT__
 /* ...an explicitly 64-bit file offset type, for MSVCRT.DLL users...
  */
# define __need___off64_t
#else
 /* ...or a 32-bit equivalent, for pre-MSVCRT.DLL users.
  */
# define __need___off32_t
#endif

/* Note the use of the #include "..." form here, to ensure that we get
 * the correct header file, relative to the location of this <stdio.h>
 */
/*
 * sys/types.h
 *
 * Definitions of (primarily POSIX) system data types.
 *
 * $Id: types.h,v d90134289a6d 2016/10/13 20:03:56 keithmarshall $
 *
 * Written by Colin Peters <colin@bird.fu.is.saga-u.ac.jp>
 * Copyright (C) 1997-1999, 2001, 2003, 2004, 2008, 2011, 2014-2016,
 *   MinGW.org Project.
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice, this permission notice, and the following
 * disclaimer shall be included in all copies or substantial portions of
 * the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OF OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef _SYS_TYPES_H
#pragma GCC system_header

/* All the headers include this file.
 */
#if ! defined __need_off_t && ! defined __need___off64_t \
 && ! defined __need_ssize_t && ! defined __need_time_t
 /*
  * ...and define the multiple inclusion guard macro for this
  * header, ONLY IF no such selector macro is defined.
  */
#define _SYS_TYPES_H
#endif

#ifndef RC_INVOKED
/* First handle those typedefs which POSIX requires us to be able
 * to expose selectively, via other system headers.
 */
#if ! defined __have_typedef_off_t \
 && ( defined _SYS_TYPES_H || defined __need_off_t )
 /* We base this on an implementation specific private typedef,
  * analogous to our __off64_t (defined below)...
  */
  typedef __int32  __off32_t;

 /* The POSIX off_t typedef is uglified, by Microsoft, as _off_t;
  * ensure that we provide support for the Microsoft form...
  */
  typedef __off32_t  _off_t;

# if _POSIX_C_SOURCE || ! defined _NO_OLDNAMES
  /* ...but note that this form should ALWAYS be preferred when
   * compiling POSIX compatible source code, and should also be
   * made generally available unless Microsoft's old names have
   * been suppressed, (by defining _NO_OLDNAMES).
   */
  typedef _off_t  off_t;
# endif
# if __GNUC__ < 4
  /* Some compilers, including GCC prior to v4, may get upset
   * if we try to specify these typedefs more than once.
   */
#  define __have_typedef_off_t
# endif
#endif
#undef __need_off_t

#if ! defined __have_typedef___off64_t \
 && ( defined _SYS_TYPES_H || defined __need___off64_t )
 /* This is neither an ISO-C standard type, nor even a POSIX
  * standard type; keep it runtime implementation specific.
  */
  typedef __int64  __off64_t;

# ifndef __STRICT_ANSI__
  /* GCC itself, (specifically libgfortran.a), gratuitously
   * assumes that non-standard type off64_t is defined; make
   * it so, pending upstream correction.
   */
  typedef __off64_t  off64_t;
# endif

# if __GNUC__ < 4
  /* Some compilers, including GCC prior to v4, may get upset
   * if we try to specify these typedefs more than once.
   */
#  define __have_typedef___off64_t
# endif
#endif
#undef __need___off64_t

#if ! defined __have_typedef_ssize_t \
 && ( defined _SYS_TYPES_H || defined __need_ssize_t )
 /* POSIX ssize_t typedef, uglified by Microsoft as _ssize_t; ensure
  * that we support the Microsoft form...
  */
  typedef int  _ssize_t;

# if _POSIX_C_SOURCE || ! defined _NO_OLDNAMES
  /* ...but note that this form should ALWAYS be preferred when
   * compiling POSIX compatible source code, and should also be
   * made generally available unless Microsoft's old names have
   * been suppressed, (by defining _NO_OLDNAMES).
   */
  typedef _ssize_t  ssize_t;
# endif
# if __GNUC__ < 4
  /* Some compilers, including GCC prior to v4, may get upset
   * if we try to specify these typedefs more than once.
   */
#  define __have_typedef_ssize_t
# endif
#endif
#undef __need_ssize_t

#if ! defined __have_typedef_time_t \
 && ( defined _SYS_TYPES_H || defined __need_time_t )
 /* Current versions of MSVC define time_t ambiguously, in terms of
  * one of the following unambiguous internal types:
  */
  typedef __int32 __time32_t;	/* unambiguous 32-bit time_t */
  typedef __int64 __time64_t;	/* unambiguous 64-bit time_t */

# if __MSVCRT_VERSION__ < __MSVCR80_DLL || defined _USE_32BIT_TIME_T
  /* From MSVCR80.DLL onwards, Microsoft have royally messed up the
   * definition of time_t; maintain POSIX consistency, (as MSVCRT.DLL
   * itself does), unless the user is explicitly using one of these
   * brain damaged DLL variants, and has not elected to retain the
   * 32-bit time_t representation.
   */
   typedef __time32_t time_t;

# else
  /* Microsoft's brain damaged default, from MSVCR80.DLL onwards.
   */
   typedef __time64_t time_t;
# endif
# if __GCC__ < 4
  /* Assume any compiler which is not GCC-4.x or newer may require
   * guarding against repeated time_t typedefs.
   */
#  define __have_typedef_time_t  1
# endif
#endif
#undef __need_time_t

#ifdef _SYS_TYPES_H
/* This is normal <sys/types.h> inclusion, i.e. for its own sake.
 *
 * A small subset of the required type definitions are actually
 * furnished by <stddef.h>; get them by selective inclusion...
 */
#define __need_size_t
#define __need_ptrdiff_t
#define __need_wchar_t
#ifdef __MSVCRT__
 /* Additionally, note that _dev_t is a special case, requiring
  * this definition when linking with MSVCRT.DLL...
  */
typedef unsigned int	_dev_t;

#else
 /* ...but this alternative, when linking with CRTDLL.DLL
  */
typedef short		_dev_t;

#endif
 /* ...while the remaining type names have consistent definitions,
  * regardless of any particular DLL association.
  */
typedef short		_ino_t;
typedef unsigned short	_mode_t;
typedef int		_pid_t;
typedef int		_sigset_t;

/* Users who value portability should prefer...
 */
#if _POSIX_C_SOURCE || ! defined _NO_OLDNAMES
 /* ...the standard POSIX type names, (which are consistent with
  * earlier Microsoft naming practice, and are also historically
  * exposed by MinGW, except when _NO_OLDNAMES is defined).
  */
typedef _dev_t		 dev_t;
typedef _ino_t		 ino_t;
typedef _mode_t 	 mode_t;
typedef _pid_t		 pid_t;
typedef _sigset_t	 sigset_t;
#endif

typedef __int64 	 fpos64_t;

#if _POSIX_C_SOURCE
/* useconds_t is an obsolete POSIX data type; we continue to define
 * it here, for backward compatibility, but we flag it as deprecated,
 * due to its obsolete status.
 */
typedef unsigned long useconds_t __MINGW_ATTRIB_DEPRECATED;
#endif
#endif  /* _SYS_TYPES_H normal inclusion */

#endif	/* ! RC_INVOKED */
#endif	/* !_SYS_TYPES_H: $RCSfile: types.h,v $: end of file */
 
#ifndef __VALIST
 /* Also similarly, for the va_list type, defined in "stdarg.h"
  */
# if defined __GNUC__ && __GNUC__ >= 3
#  define __need___va_list
/* Copyright (C) 1989-2019 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.15  Variable arguments  <stdarg.h>
 */

#ifndef _STDARG_H
#ifndef _ANSI_STDARG_H_
#ifndef __need___va_list
#define _STDARG_H
#define _ANSI_STDARG_H_
#endif /* not __need___va_list */
#undef __need___va_list

/* Define __gnuc_va_list.  */

#ifndef __GNUC_VA_LIST
#define __GNUC_VA_LIST
typedef __builtin_va_list __gnuc_va_list;
#endif

/* Define the standard macros for the user,
   if this invocation was from the user program.  */
#ifdef _STDARG_H

#define va_start(v,l)	__builtin_va_start(v,l)
#define va_end(v)	__builtin_va_end(v)
#define va_arg(v,l)	__builtin_va_arg(v,l)
#if !defined(__STRICT_ANSI__) || __STDC_VERSION__ + 0 >= 199900L \
    || __cplusplus + 0 >= 201103L
#define va_copy(d,s)	__builtin_va_copy(d,s)
#endif
#define __va_copy(d,s)	__builtin_va_copy(d,s)

/* Define va_list, if desired, from __gnuc_va_list. */
/* We deliberately do not define va_list when called from
   stdio.h, because ANSI C says that stdio.h is not supposed to define
   va_list.  stdio.h needs to have access to that data type, 
   but must not use that name.  It should use the name __gnuc_va_list,
   which is safe because it is reserved for the implementation.  */

#ifdef _BSD_VA_LIST
#undef _BSD_VA_LIST
#endif

#if defined(__svr4__) || (defined(_SCO_DS) && !defined(__VA_LIST))
/* SVR4.2 uses _VA_LIST for an internal alias for va_list,
   so we must avoid testing it and setting it here.
   SVR4 uses _VA_LIST as a flag in stdarg.h, but we should
   have no conflict with that.  */
#ifndef _VA_LIST_
#define _VA_LIST_
#ifdef __i860__
#ifndef _VA_LIST
#define _VA_LIST va_list
#endif
#endif /* __i860__ */
typedef __gnuc_va_list va_list;
#ifdef _SCO_DS
#define __VA_LIST
#endif
#endif /* _VA_LIST_ */
#else /* not __svr4__ || _SCO_DS */

/* The macro _VA_LIST_ is the same thing used by this file in Ultrix.
   But on BSD NET2 we must not test or define or undef it.
   (Note that the comments in NET 2's ansi.h
   are incorrect for _VA_LIST_--see stdio.h!)  */
#if !defined (_VA_LIST_) || defined (__BSD_NET2__) || defined (____386BSD____) || defined (__bsdi__) || defined (__sequent__) || defined (__FreeBSD__) || defined(WINNT)
/* The macro _VA_LIST_DEFINED is used in Windows NT 3.5  */
#ifndef _VA_LIST_DEFINED
/* The macro _VA_LIST is used in SCO Unix 3.2.  */
#ifndef _VA_LIST
/* The macro _VA_LIST_T_H is used in the Bull dpx2  */
#ifndef _VA_LIST_T_H
/* The macro __va_list__ is used by BeOS.  */
#ifndef __va_list__
typedef __gnuc_va_list va_list;
#endif /* not __va_list__ */
#endif /* not _VA_LIST_T_H */
#endif /* not _VA_LIST */
#endif /* not _VA_LIST_DEFINED */
#if !(defined (__BSD_NET2__) || defined (____386BSD____) || defined (__bsdi__) || defined (__sequent__) || defined (__FreeBSD__))
#define _VA_LIST_
#endif
#ifndef _VA_LIST
#define _VA_LIST
#endif
#ifndef _VA_LIST_DEFINED
#define _VA_LIST_DEFINED
#endif
#ifndef _VA_LIST_T_H
#define _VA_LIST_T_H
#endif
#ifndef __va_list__
#define __va_list__
#endif

#endif /* not _VA_LIST_, except on certain systems */

#endif /* not __svr4__ */

#endif /* _STDARG_H */

#endif /* not _ANSI_STDARG_H_ */
#endif /* not _STDARG_H */
 #  define __VALIST __builtin_va_list
# else
#  define __VALIST char *
# endif
#endif
#endif	/* ! RC_INVOKED */

#ifdef _STDIO_H
/* Flags for the iobuf structure
 */
#define _IOREAD 	1	/* currently reading */
#define _IOWRT		2	/* currently writing */
#define _IORW	   0x0080	/* opened as "r+w" */

/* The three standard file pointers provided by the run time library.
 * NOTE: These will go to the bit-bucket silently in GUI applications!
 */
#define STDIN_FILENO	0
#define STDOUT_FILENO	1
#define STDERR_FILENO	2

/* Returned by various functions on end of file condition or error.
 */
#define EOF	      (-1)

#endif	/* _STDIO_H */

/* The maximum length of a file name.  It may be better to use the Windows'
 * GetVolumeInformation() function in preference to this constant, but hey,
 * this works!  Note that <io.h> also defines it, but we don't guard it, so
 * that the compiler has a chance to catch inconsistencies.
 *
 * FIXME: Right now, we define this unconditionally for both full <stdio.h>
 * inclusion, and for partial inclusion on behalf of <wchar.h>, (which needs
 * it for some non-ANSI structure declarations).  The conditions under which
 * <wchar.h> needs this require review, because defining it as a consequence
 * of including <wchar.h> alone may violate strict ANSI conformity.
 */
#define FILENAME_MAX  (260)

#ifdef _STDIO_H
/* The maximum number of files that may be open at once. I have set this to
 * a conservative number. The actual value may be higher.
 */
#define FOPEN_MAX      (20)

/* After creating this many names, tmpnam and tmpfile return NULL
 */
#define TMP_MAX      32767

/* Tmpnam, tmpfile and, sometimes, _tempnam try to create
 * temp files in the root directory of the current drive
 * (not in pwd, as suggested by some older MS doc's).
 * Redefining these macros does not effect the CRT functions.
 */
#define _P_tmpdir   "\\"
#ifndef __STRICT_ANSI__
#define P_tmpdir _P_tmpdir
#endif
#define _wP_tmpdir  L"\\"

/* The maximum size of name (including NUL) that will be put in the user
 * supplied buffer caName for tmpnam.
 * Inferred from the size of the static buffer returned by tmpnam
 * when passed a NULL argument. May actually be smaller.
 */
#define L_tmpnam (16)

#define _IOFBF		0x0000	/* full buffered */
#define _IOLBF		0x0040	/* line buffered */
#define _IONBF		0x0004	/* not buffered */

#define _IOMYBUF	0x0008	/* stdio malloc()'d buffer */
#define _IOEOF		0x0010	/* EOF reached on read */
#define _IOERR		0x0020	/* I/O error from system */
#define _IOSTRG 	0x0040	/* Strange or no file descriptor */
#ifdef _POSIX_SOURCE
# define _IOAPPEND	0x0200
#endif

/* The buffer size as used by setbuf such that it is equivalent to
 * (void) setvbuf(fileSetBuffer, caBuffer, _IOFBF, BUFSIZ).
 */
#define BUFSIZ		   512

/* Constants for nOrigin indicating the position relative to which fseek
 * sets the file position.  Defined unconditionally since ISO and POSIX
 * say they are defined here.
 */
#define SEEK_SET	     0
#define SEEK_CUR	     1
#define SEEK_END	     2

#endif	/* _STDIO_H */

#ifndef RC_INVOKED
#if ! (defined _STDIO_H && defined _WCHAR_H)
/* The structure underlying the FILE type; this should be defined when
 * including either <stdio.h> or <wchar.h>.  If both header include guards
 * are now in place, then we must currently be including <stdio.h> in its
 * own right, having already processed this block during a prior partial
 * inclusion by <wchar.h>; there is no need to process it a second time.
 *
 * Some believe that nobody in their right mind should make use of the
 * internals of this structure. Provided by Pedro A. Aranda Gutiirrez
 * <paag@tid.es>.
 */
typedef struct _iobuf
{
  char	*_ptr;
  int	 _cnt;
  char	*_base;
  int	 _flag;
  int	 _file;
  int	 _charbuf;
  int	 _bufsiz;
  char	*_tmpfname;
} FILE;

#endif  /* ! (_STDIO_H && _WCHAR_H) */
#ifdef _STDIO_H
/* Content to be exposed only when including <stdio.h> in its own right;
 * these will not be exposed when __WCHAR_H_SOURCE__ is defined, as will
 * be the case when <stdio.h> is included indirectly, by <wchar.h>
 *
 *
 * The standard file handles
 */
#ifndef __DECLSPEC_SUPPORTED

extern FILE (*_imp___iob)[];	/* A pointer to an array of FILE */

#define _iob (*_imp___iob)	/* An array of FILE */

#else /* __DECLSPEC_SUPPORTED */

__MINGW_IMPORT FILE _iob[];	/* An array of FILE imported from DLL. */

#endif /* __DECLSPEC_SUPPORTED */

#define stdin	(&_iob[STDIN_FILENO])
#define stdout	(&_iob[STDOUT_FILENO])
#define stderr	(&_iob[STDERR_FILENO])

/* Need to close the current _STDIO_H specific block here...
 */
#endif
/* ...because, we need this regardless of the inclusion mode...
 */
_BEGIN_C_DECLS

#ifdef _STDIO_H
/* ...then revert to _STDIO_H specific mode, to declare...
 *
 *
 * File Operations
 */
_CRTIMP __cdecl __MINGW_NOTHROW  FILE * fopen (const char *, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE * freopen (const char *, const char *, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    fflush (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    fclose (FILE *);

/* Note: Microsoft also declares remove & rename (but not their wide char
 * variants) in <io.h>; since duplicate prototypes are acceptable, provided
 * they are consistent, we simply declare them here anyway, while allowing
 * the compiler to check consistency as appropriate.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int    remove (const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    rename (const char *, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE * tmpfile (void);
_CRTIMP __cdecl __MINGW_NOTHROW  char * tmpnam (char *);

#ifndef __STRICT_ANSI__
_CRTIMP __cdecl __MINGW_NOTHROW  char *_tempnam (const char *, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int   _rmtmp (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int   _unlink (const char *);

#if __MSVCRT_VERSION__>=__MSVCR80_DLL
/* The following pair of non-ANSI functions require a non-free version of
 * the Microsoft runtime; neither is provided by any MSVCRT.DLL variant.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  void  _lock_file(FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  void  _unlock_file(FILE *);
#endif

#ifndef NO_OLDNAMES
_CRTIMP __cdecl __MINGW_NOTHROW  char * tempnam (const char *, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    rmtmp (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int    unlink (const char *);
#endif
#endif /* __STRICT_ANSI__ */

_CRTIMP __cdecl __MINGW_NOTHROW  int    setvbuf (FILE *, char *, int, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  void   setbuf (FILE *, char *);

/* Formatted Output
 *
 * MSVCRT implementations are not ANSI C99 conformant...
 * we offer conforming alternatives from libmingwex.a
 */
#undef  __mingw_stdio_redirect__
#define __mingw_stdio_redirect__(F) __cdecl __MINGW_NOTHROW __Wformat(F)
#define __Wformat_mingw_printf(F,A) __attribute__((__format__(__mingw_printf__,F,A)))

#if __GNUC__ >= 6
/* From GCC-6 onwards, we will provide customized -Wformat
 * handling, via our own mingw_printf format category...
 */
#define __Wformat(F)		__Wformat_##F __mingw_##F

#else	/* __GNUC__ < 6 */
/* ...whereas, for earlier GCC, we preserve the status quo,
 * offering no -Wformat checking for those functions which
 * replace the MSVCRT.DLL versions...
 */
#define __Wformat(F)		__mingw_##F

/* ...while degrading to gnu_printf checking for snprintf()
 * and vsnprintf(), (which are ALWAYS MinGW.org variants).
 */
#define __mingw_printf__	__gnu_printf__
#endif

/* The following convenience macros specify the appropriate
 * -Wformat checking for MSVCRT.DLL replacement functions...
 */
#define __Wformat_printf	__Wformat_mingw_printf(1,2)
#define __Wformat_fprintf	__Wformat_mingw_printf(2,3)
#define __Wformat_sprintf	__Wformat_mingw_printf(2,3)
#define __Wformat_vprintf	__Wformat_mingw_printf(1,0)
#define __Wformat_vfprintf	__Wformat_mingw_printf(2,0)
#define __Wformat_vsprintf	__Wformat_mingw_printf(2,0)

/* ...while this pair are specific to the two MinGW.org
 * only functions.
 */
#define __Wformat_snprintf	__Wformat_mingw_printf(3,4)
#define __Wformat_vsnprintf	__Wformat_mingw_printf(3,0)

extern int __mingw_stdio_redirect__(fprintf)(FILE*, const char*, ...);
extern int __mingw_stdio_redirect__(printf)(const char*, ...);
extern int __mingw_stdio_redirect__(sprintf)(char*, const char*, ...);
extern int __mingw_stdio_redirect__(snprintf)(char*, size_t, const char*, ...);
extern int __mingw_stdio_redirect__(vfprintf)(FILE*, const char*, __VALIST);
extern int __mingw_stdio_redirect__(vprintf)(const char*, __VALIST);
extern int __mingw_stdio_redirect__(vsprintf)(char*, const char*, __VALIST);
extern int __mingw_stdio_redirect__(vsnprintf)(char*, size_t, const char*, __VALIST);

/* When using these C99 conforming alternatives, we may wish to support
 * some of Microsoft's quirky formatting options, even when they violate
 * strict C99 conformance.
 */
#define _MSVC_PRINTF_QUIRKS		0x0100U
#define _QUERY_MSVC_PRINTF_QUIRKS	~0U, 0U
#define _DISABLE_MSVC_PRINTF_QUIRKS	~_MSVC_PRINTF_QUIRKS, 0U
#define _ENABLE_MSVC_PRINTF_QUIRKS	~0U, _MSVC_PRINTF_QUIRKS

/* Those quirks which conflict with ANSI C99 specified behaviour are
 * disabled by default; use the following function, like this:
 *
 *   _mingw_output_format_control( _ENABLE_MSVC_PRINTF_QUIRKS );
 *
 * to enable them, like this:
 *
 *   state = _mingw_output_format_control( _QUERY_MSVC_PRINTF_QUIRKS )
 *		& _MSVC_PRINTF_QUIRKS;
 *
 * to ascertain the currently active enabled state, or like this:
 *
 *   _mingw_output_format_control( _DISABLE_MSVC_PRINTF_QUIRKS );
 *
 * to disable them again.
 */
extern unsigned int _mingw_output_format_control( unsigned int, unsigned int );

#if __USE_MINGW_ANSI_STDIO || defined _ISOC99_SOURCE
/* User has expressed a preference for C99 conformance...
 */
# undef __mingw_stdio_redirect__
# if defined __GNUC__
/* FIXME: Is there any GCC version prerequisite here?
 *
 * We prefer inline implementations for both C and C++, when we can be
 * confident that the GNU specific __inline__ mechanism is supported.
 */
#  define __mingw_stdio_redirect__  static __inline__ __cdecl __MINGW_NOTHROW

# elif defined __cplusplus
/* For non-GNU C++ we use inline implementations, to avoid interference
 * with namespace qualification, which may result from using #defines.
 */
#  define __mingw_stdio_redirect__  inline __cdecl __MINGW_NOTHROW

# else	/* Neither GCC, nor non-GNU C++ */
/* Can't use inlines; fall back on module local static stubs.
 */
#  define __mingw_stdio_redirect__  static __cdecl __MINGW_NOTHROW

# endif	/* Neither GCC, nor non-GNU C++ */
#endif	/* __USE_MINGW_ANSI_STDIO || defined _ISOC99_SOURCE */

#if __USE_MINGW_ANSI_STDIO
/* The MinGW ISO-C conforming implementations of the printf() family
 * of functions are to be used, in place of non-conforming Microsoft
 * implementations; force call redirection, via the following set of
 * in-line functions.
 */
__mingw_stdio_redirect__
int fprintf (FILE *__stream, const char *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vfprintf( __stream, __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}

__mingw_stdio_redirect__
int printf (const char *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vprintf( __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}

__mingw_stdio_redirect__
int sprintf (char *__stream, const char *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vsprintf( __stream, __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}

__mingw_stdio_redirect__
int vfprintf (FILE *__stream, const char *__format, __VALIST __local_argv)
{
  return __mingw_vfprintf( __stream, __format, __local_argv );
}

__mingw_stdio_redirect__
int vprintf (const char *__format, __VALIST __local_argv)
{
  return __mingw_vprintf( __format, __local_argv );
}

__mingw_stdio_redirect__
int vsprintf (char *__stream, const char *__format, __VALIST __local_argv)
{
  return __mingw_vsprintf( __stream, __format, __local_argv );
}

#else	/* !__USE_MINGW_ANSI_STDIO */
/* Default configuration: simply direct all calls to MSVCRT...
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int fprintf (FILE *, const char *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int printf (const char *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int sprintf (char *, const char *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int vfprintf (FILE *, const char *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW  int vprintf (const char *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW  int vsprintf (char *, const char *, __VALIST);

#endif	/* !__USE_MINGW_ANSI_STDIO */

#if __GNUC__ && defined _ISOC99_SOURCE
/* Although MinGW implementations of the ISO-C99 snprintf() and
 * vsnprintf() functions do not conflict with any implementation
 * in MSVCRT.DLL, (because MSVCRT.DLL does not implement either),
 * there are -Wformat attribute conflicts with the GCC built-in
 * prototypes associated with each; by providing the following
 * in-line function implementations, which will override GCC's
 * built-in prototypes, we may avoid these conflicts.
 */
__mingw_stdio_redirect__
int snprintf (char *__buf, size_t __len, const char *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vsnprintf( __buf, __len, __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}

__mingw_stdio_redirect__
int vsnprintf (char *__buf, size_t __len, const char *__format, __VALIST __local_argv)
{
  return __mingw_vsnprintf( __buf, __len, __format, __local_argv );
}
#endif	/* __GNUC__ && defined _ISOC99_SOURCE */

/* Regardless of user preference, always offer these alternative
 * entry points, for direct access to the MSVCRT implementations,
 * with ms_printf -Wformat checking in each case.
 */
#undef  __Wformat
#undef  __mingw_stdio_redirect__
#define __mingw_stdio_redirect__(F) __cdecl __MINGW_NOTHROW __Wformat(F)
#define __Wformat_msvcrt_printf(F,A) __attribute__((__format__(__ms_printf__,F,A)))
#define __Wformat(F) __Wformat_ms_##F __msvcrt_##F

#define __Wformat_ms_printf	__Wformat_msvcrt_printf(1,2)
#define __Wformat_ms_fprintf	__Wformat_msvcrt_printf(2,3)
#define __Wformat_ms_sprintf	__Wformat_msvcrt_printf(2,3)
#define __Wformat_ms_vprintf	__Wformat_msvcrt_printf(1,0)
#define __Wformat_ms_vfprintf	__Wformat_msvcrt_printf(2,0)
#define __Wformat_ms_vsprintf	__Wformat_msvcrt_printf(2,0)

_CRTIMP int __mingw_stdio_redirect__(fprintf)(FILE *, const char *, ...);
_CRTIMP int __mingw_stdio_redirect__(printf)(const char *, ...);
_CRTIMP int __mingw_stdio_redirect__(sprintf)(char *, const char *, ...);
_CRTIMP int __mingw_stdio_redirect__(vfprintf)(FILE *, const char *, __VALIST);
_CRTIMP int __mingw_stdio_redirect__(vprintf)(const char *, __VALIST);
_CRTIMP int __mingw_stdio_redirect__(vsprintf)(char *, const char *, __VALIST);

#undef  __mingw_stdio_redirect__
#undef  __Wformat

/* The following three ALWAYS refer to the MSVCRT implementations...
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int _snprintf (char *, size_t, const char *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int _vsnprintf (char *, size_t, const char *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW  int _vscprintf (const char *, __VALIST);

#ifdef _ISOC99_SOURCE
/* Microsoft does not provide implementations for the following,
 * which are required by C99.  Note in particular that Microsoft's
 * corresponding implementations of _snprintf() and _vsnprintf() are
 * NOT compatible with C99, but the following are; if you want the
 * MSVCRT behaviour, you MUST use the Microsoft "uglified" names.
 */
__cdecl __MINGW_NOTHROW __Wformat_snprintf
int snprintf (char *, size_t, const char *, ...);

__cdecl __MINGW_NOTHROW __Wformat_vsnprintf
int vsnprintf (char *, size_t, const char *, __VALIST);

__cdecl __MINGW_NOTHROW
int vscanf (const char * __restrict__, __VALIST);

__cdecl __MINGW_NOTHROW
int vfscanf (FILE * __restrict__, const char * __restrict__, __VALIST);

__cdecl __MINGW_NOTHROW
int vsscanf (const char * __restrict__, const char * __restrict__, __VALIST);

#endif  /* _ISOC99_SOURCE */
#endif	/* <stdio.h> included in its own right */

#if __MSVCRT_VERSION__ >= __MSVCR80_DLL || _WIN32_WINNT >= _WIN32_WINNT_VISTA
/* In MSVCR80.DLL, (and its descendants), Microsoft introduced variants
 * of the printf() functions, with names qualified by an underscore prefix
 * and "_p" or "_p_l" suffixes; implemented in Microsoft's typically crass,
 * non-standard, and non-portable fashion, these provide support for access
 * to printf() arguments in random order, as was standardised by POSIX as a
 * feature of the optional Extended Systems Interface (XSI) specification,
 * and is now required for conformity with the POSIX.1-2008 base standard.
 * Although these additional Microsoft functions were subsequently added
 * to MSVCRT.DLL, from Windows-Vista onward, and they are prototyped here,
 * MinGW applications are strenuously encouraged to avoid using them; a
 * much better alternative is to "#define _XOPEN_SOURCE 700" before any
 * system header is included, then use POSIX standard printf() functions
 * instead; this is both portable to many non-Windows platforms, and it
 * offers better compatibility with earlier Windows versions.
 */
#ifndef __have_typedef_locale_t
/* Note that some of the following require the opaque locale_t data type,
 * which we may obtain, by selective inclusion, from <locale.h>
 */
#define __need_locale_t
/*
 * locale.h
 *
 * Functions and types for localization (ie. changing the appearance of
 * output based on the standards of a certain country, or region).
 *
 * $Id: locale.h,v f057349c225e 2016/06/12 19:22:07 keithmarshall $
 *
 * Written by Colin Peters <colin@bird.fu.is.saga-u.ac.jp>
 * Copyright (C) 1997, 1999-2001, 2003, 2004, 2007, 2016, MinGW.org Project.
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice, this permission notice, and the following
 * disclaimer shall be included in all copies or substantial portions of
 * the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OF OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef	_LOCALE_H
#pragma GCC system_header

/* Some headers will include this file, just to acquire a globally
 * consistent definition for the opaque locale_t data object type; it
 * is only useful on Vista, or for users of non-free MSVCR80.DLL, (or
 * its later derivatives), so, when either of these is applicable,
 * ensure that we define it, (if we haven't done so already).
 */
#if ! defined __have_typedef_locale_t \
&& (__MSVCRT_VERSION__ >= __MSVCR80_DLL || _WIN32_WINNT >= _WIN32_WINNT_VISTA)
/*
 * FIXME: Do these actually have any value for Vista?  Although the Vista
 * release of MSVCRT.DLL exports several functions which require locale_t
 * parameters, it appears to lack any mechanism whereby an object of that
 * type might be created, or otherwise, a reference to such an object may
 * be acquired.
 */
typedef struct __mingw_opaque_locale_t  *_locale_t;
typedef struct __mingw_opaque_locale_t  * locale_t;

/* Set a (private) pre-processor flag, to indicate that these data types
 * have been defined; although GCC versions from 4.x onwards may accept
 * repeated (consistent) definitions, this flag gives us the facility to
 * avoid the overhead of repeatedly parsing this file, just to satisfy a
 * __need_locale_t request which has been satisfied already.
 */
#define __have_typedef_locale_t  1
#endif	/* !__have_typedef_locale_t */

/* When we are interested in more than just locale_t...
 */
#ifndef __need_locale_t
/* ...content from <locale.h> is selectively shared with <wchar.h>;
 * defer definition of the normal repeat inclusion guard, until...
 */
#ifndef __WCHAR_H_SOURCED__
 /* ...we have confirmed that this inclusion is NOT the <wchar.h>
  * selective request, or just a __need_locale_t request.
  */
#define	_LOCALE_H

/* All MinGW headers should include <_mingw.h>; do so only when NOT
 * sourced by <wchar.h>, (which should have included it already).
 */
#define	LC_ALL		0
#define LC_COLLATE	1
#define LC_CTYPE	2
#define	LC_MONETARY	3
#define	LC_NUMERIC	4
#define	LC_TIME		5
#define	LC_MIN		LC_ALL
#define	LC_MAX		LC_TIME

#ifndef RC_INVOKED
/* Both ISO-C and POSIX stipulate that <locale.h> should reproduce the
 * definition of NULL, from <stddef.h>; although not required by either
 * standard, we also require wchar_t, to support our declaration of the
 * Microsoft specific _wsetlocale() function, below.
 */
#define __need_NULL
#define __need_wchar_t
#endif	/* ! RC_INVOKED */
#endif	/* !__WCHAR_H_SOURCED__ */

#ifndef RC_INVOKED

_BEGIN_C_DECLS

#ifdef _LOCALE_H
 /* The following pair of function prototypes are to be declared
  * only when including <locale.h> in its own right, (i.e. when NOT
  * sourced by <wchar.h>)...
  */
_CRTIMP __cdecl __MINGW_NOTHROW  char *setlocale (int, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  struct lconv *localeconv (void);

#endif
 /* ...whereas, this must be declared in either case; (note that it
  * not necessary to guard against a possible repeat declaration, as
  * the compiler should accept this, without complaint, provided any
  * prior declaration is consistent).
  */
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *_wsetlocale (int, const wchar_t *);

#if __MSVCRT_VERSION__ >= __MSVCR80_DLL
/* The following are available to users of non-free MSVCR80.DLL, and
 * its later derivatives.  They are REQUIRED to create, or otherwise
 * acquire a reference to, a locale_t object; they SHOULD also have
 * been made available in MSVCRT.DLL, from Vista onwards, to support
 * the use of functions added in that release which require locale_t
 * parameters, but it seems that Microsoft, exhibiting their usual
 * ineptitude, have neglected that requirement.
 */
#ifdef _LOCALE_H
/* This triplet of functions are to be declared only when <locale.h>
 * is included directly, and so is parsed in full...
 */
_CRTIMP __cdecl __MINGW_NOTHROW  _locale_t _create_locale (int, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  _locale_t _get_current_locale (void);
_CRTIMP __cdecl __MINGW_NOTHROW   void     _free_locale (locale_t);

#endif
/* ...whereas, this is required both when included directly, and also
 * when indirectly included by <wchar.h>
 */
_CRTIMP __cdecl __MINGW_NOTHROW  _locale_t _wcreate_locale (int, const wchar_t *);

#endif	/* __MSVCRT_VERSION__ >= __MSVCR80_DLL */

_END_C_DECLS

#endif	/* ! RC_INVOKED */
#endif	/* !__need_locale_t */

/* We've already handled any pending __need_locale_t request; ensure
 * that we cancel it, so that any more comprehensive further request,
 * before _LOCALE_H is defined, will be handled appropriately.
 */
#undef	__need_locale_t

#endif  /* !_LOCALE_H: $RCSfile: locale.h,v $: end of file */
 
#endif

#ifdef _STDIO_H
/* The following are to be declared only when <stdio.h> is explicitly
 * included; the first six are NOT dependent on locale_t...
 */
_CRTIMP __cdecl __MINGW_NOTHROW
int _printf_p (const char *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
int _fprintf_p (FILE *, const char *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
int _sprintf_p (char *, size_t, const char *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
int _vprintf_p (const char *, __VALIST);

_CRTIMP __cdecl __MINGW_NOTHROW
int _vfprintf_p (FILE *, const char *, __VALIST);

_CRTIMP __cdecl __MINGW_NOTHROW
int _vsprintf_p (char *, size_t, const char *, __VALIST);

/* ...whereas the following six DO depend on locale_t.
 *
 * CAVEAT: unless you are linking with non-free MSVCR80.DLL, or one
 * of its later derivatives, good luck trying to use these; see the
 * explanation in <locale.t>, as to why you may be unable to create,
 * or otherwise acquire a reference to, a locale_t object.
 */
_CRTIMP __cdecl __MINGW_NOTHROW
int _printf_p_l (const char *, locale_t, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
int _fprintf_p_l (FILE *, const char *, locale_t, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
int _sprintf_p_l (char *, size_t, const char *, locale_t, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
int _vprintf_p_l (const char *, locale_t, __VALIST);

_CRTIMP __cdecl __MINGW_NOTHROW
int _vfprintf_p_l (FILE *, const char *, locale_t, __VALIST);

_CRTIMP __cdecl __MINGW_NOTHROW
int _vsprintf_p_l (char *, size_t, const char *, locale_t, __VALIST);

#endif	/* <stdio.h> included in its own right */
#endif	/* MSVCR80.DLL and descendants, or MSVCRT.DLL since Vista */

#if ! (defined _STDIO_H && defined _WCHAR_H)
#if __MSVCRT_VERSION__ >= __MSVCR80_DLL || _WIN32_WINNT >= _WIN32_WINNT_VISTA
/* Wide character variants of the foregoing "positional parameter" printf()
 * functions; MSDN says that these should be declared when either <stdio.h>, or
 * <wchar.h> is included, so we make them selectively available to <wchar.h>,
 * but, just as in the foregoing, we advise against their use.
 */
_CRTIMP __cdecl __MINGW_NOTHROW
int _wprintf_p (const wchar_t *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
int _fwprintf_p (FILE *, const wchar_t *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
int _swprintf_p (wchar_t *, size_t, const wchar_t *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
int _vwprintf_p (const wchar_t *, __VALIST);

_CRTIMP __cdecl __MINGW_NOTHROW
int _vfwprintf_p (FILE *, const wchar_t *, __VALIST);

_CRTIMP __cdecl __MINGW_NOTHROW
int _vswprintf_p (wchar_t *, size_t, const wchar_t *, __VALIST);

_CRTIMP __cdecl __MINGW_NOTHROW
int _wprintf_p_l (const wchar_t *, locale_t, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
int _fwprintf_p_l (FILE *, const wchar_t *, locale_t, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
int _swprintf_p_l (wchar_t *, size_t, const wchar_t *, locale_t, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
int _vwprintf_p_l (const wchar_t *, locale_t, __VALIST);

_CRTIMP __cdecl __MINGW_NOTHROW
int _vfwprintf_p_l (FILE *, const wchar_t *, locale_t, __VALIST);

_CRTIMP __cdecl __MINGW_NOTHROW
int _vswprintf_p_l (wchar_t *, size_t, const wchar_t *, locale_t, __VALIST);

#endif	/* MSVCR80.DLL and descendants, or MSVCRT.DLL since Vista */
#endif	/* ! (defined _STDIO_H && defined _WCHAR_H) */
#ifdef _STDIO_H
/* Once again, back to <stdio.h> specific declarations.
 */
#if _POSIX_C_SOURCE >= 200809L
/* POSIX standard IEEE 1003.1-2008 added getdelim() and getline()
 */
__cdecl __MINGW_NOTHROW ssize_t
getdelim (char ** __restrict__, size_t * __restrict__, int, FILE * __restrict__);

__cdecl __MINGW_NOTHROW ssize_t
getline (char ** __restrict__, size_t * __restrict__, FILE * __restrict__);

#ifndef __NO_INLINE__
/* getline() is a trivial specialization of getdelim(), which may
 * be readily expressed by inline expansion.
 */
__CRT_ALIAS __LIBIMPL__(( FUNCTION = getline ))
__cdecl __MINGW_NOTHROW ssize_t getline
( char **__restrict__ __l, size_t *__restrict__ __n, FILE *__restrict__ __s )
{ return getdelim( __l, __n, '\n', __s ); }

#endif  /* !__NO_INLINE__ */
#endif  /* POSIX.1-2008 */

/* Formatted Input
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int    fscanf (FILE *, const char *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int    scanf (const char *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int    sscanf (const char *, const char *, ...);

/* Character Input and Output Functions
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int    fgetc (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  char * fgets (char *, int, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    fputc (int, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    fputs (const char *, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  char * gets (char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    puts (const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    ungetc (int, FILE *);

/* Traditionally, getc and putc are defined as macros. but the
 * standard doesn't say that they must be macros.  We use inline
 * functions here to allow the fast versions to be used in C++
 * with namespace qualification, eg., ::getc.
 *
 * NOTE: _filbuf and _flsbuf  are not thread-safe.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int   _filbuf (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int   _flsbuf (int, FILE *);

#if !defined _MT

__CRT_INLINE __cdecl __MINGW_NOTHROW  int getc (FILE *);
__CRT_INLINE __cdecl __MINGW_NOTHROW  int getc (FILE * __F)
{
  return (--__F->_cnt >= 0)
    ?  (int) (unsigned char) *__F->_ptr++
    : _filbuf (__F);
}

__CRT_INLINE __cdecl __MINGW_NOTHROW  int putc (int, FILE *);
__CRT_INLINE __cdecl __MINGW_NOTHROW  int putc (int __c, FILE * __F)
{
  return (--__F->_cnt >= 0)
    ?  (int) (unsigned char) (*__F->_ptr++ = (char)__c)
    :  _flsbuf (__c, __F);
}

__CRT_INLINE __cdecl __MINGW_NOTHROW  int getchar (void);
__CRT_INLINE __cdecl __MINGW_NOTHROW  int getchar (void)
{
  return (--stdin->_cnt >= 0)
    ?  (int) (unsigned char) *stdin->_ptr++
    : _filbuf (stdin);
}

__CRT_INLINE __cdecl __MINGW_NOTHROW  int putchar(int);
__CRT_INLINE __cdecl __MINGW_NOTHROW  int putchar(int __c)
{
  return (--stdout->_cnt >= 0)
    ?  (int) (unsigned char) (*stdout->_ptr++ = (char)__c)
    :  _flsbuf (__c, stdout);}

#else  /* Use library functions.  */

_CRTIMP __cdecl __MINGW_NOTHROW  int    getc (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    putc (int, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    getchar (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int    putchar (int);

#endif

/* Direct Input and Output Functions
 */
_CRTIMP __cdecl __MINGW_NOTHROW  size_t fread (void *, size_t, size_t, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  size_t fwrite (const void *, size_t, size_t, FILE *);

/* File Positioning Functions
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int    fseek (FILE *, long, int);
_CRTIMP __cdecl __MINGW_NOTHROW  long   ftell (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  void   rewind (FILE *);

#ifdef __USE_MINGW_FSEEK
/* Workaround for a limitation on Win9x where a file is not zero padded
 * on write, following a seek beyond the original end of file; supporting
 * redirector functions are implemented in libmingwex.a
 *
 * Note: this is improper usage.  __USE_MINGW_FSEEK exhibits the form of a
 * private (system reserved) feature test macro; as such, users should not
 * define it directly, and thus, it really should not have been defined at
 * this point; discourage this practice.
 */
#warning "The __USE_MINGW_FSEEK feature test is deprecated"
#pragma info "Define _WIN32_WINDOWS, instead of __USE_MINGW_FSEEK"

#elif _WIN32_WINDOWS >= _WIN32_WINDOWS_95 && _WIN32_WINDOWS < _WIN32_WINNT_WIN2K
/* This is correct usage; the private __USE_MINGW_FSEEK feature affects only
 * Win9x, so enable it implicitly when the _WIN32_WINDOWS feature is specified,
 * thus indicating the user's intent to target a Win9x platform.
 */
#define __USE_MINGW_FSEEK
#endif

#ifdef __USE_MINGW_FSEEK
/* Regardless of how it may have become defined, when __USE_MINGW_FSEEK has
 * been defined, we must redirect calls to fseek() and fwrite(), so that the
 * Win9x zero padding limitation can be mitigated.
 */
__cdecl __MINGW_NOTHROW  int __mingw_fseek (FILE *, __off64_t, int);
__CRT_ALIAS int fseek( FILE *__fp, long __offset, int __whence )
{ return __mingw_fseek( __fp, (__off64_t)(__offset), __whence ); }

__cdecl __MINGW_NOTHROW  size_t __mingw_fwrite (const void *, size_t, size_t, FILE *);
__CRT_ALIAS size_t fwrite( const void *__buf, size_t __len, size_t __cnt, FILE *__fp )
{ return __mingw_fwrite( __buf, __len, __cnt, __fp ); }
#endif /* __USE_MINGW_FSEEK */

/* An opaque data type used for storing file positions...  The contents
 * of this type are unknown, but we (the compiler) need to know the size
 * because the programmer using fgetpos and fsetpos will be setting aside
 * storage for fpos_t aggregates.  Actually I tested using a byte array and
 * it is fairly evident that fpos_t is a 32-bit type in CRTDLL.DLL, but in
 * MSVCRT.DLL, it is a 64-bit type.  Define it in terms of an int type of
 * the appropriate size, encapsulated within an aggregate type, to make
 * it opaque to casting, and so discourage abuse.
 */
#ifdef __MSVCRT__
typedef union { __int64 __value; __off64_t __offset; } fpos_t;
#else
typedef union { __int32 __value; __off32_t __offset; } fpos_t;
#endif

_CRTIMP __cdecl __MINGW_NOTHROW  int fgetpos (FILE *, fpos_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  int fsetpos (FILE *, const fpos_t *);

#if _WIN32_WINNT >= _WIN32_WINNT_VISTA || __MSVCRT_VERSION__ >= __MSVCR80_DLL
 /* Microsoft introduced a number of variations on fseek() and ftell(),
  * beginning with MSVCR80.DLL; the bare _fseeki64() and _ftelli64() were
  * subsequently integrated into MSVCRT.DLL, from Vista onward...
  */
_CRTIMP __cdecl __MINGW_NOTHROW  int    _fseeki64 (FILE *, __int64, int);
_CRTIMP __cdecl __MINGW_NOTHROW __int64 _ftelli64 (FILE *);

#if __MSVCRT_VERSION__ >= __MSVCR80_DLL
 /* ...while the "nolock" variants remain exclusive to MSVCR80.DLL, and
  * its later MSVC specific derivatives.
  */
_CRTIMP __cdecl __MINGW_NOTHROW  int    _fseek_nolock (FILE *, long, int);
_CRTIMP __cdecl __MINGW_NOTHROW  long   _ftell_nolock (FILE *);

_CRTIMP __cdecl __MINGW_NOTHROW  int    _fseeki64_nolock (FILE *, __int64, int);
_CRTIMP __cdecl __MINGW_NOTHROW __int64 _ftelli64_nolock (FILE *);

#endif  /* MSVCR80.DLL and later derivatives ONLY */

#else	/* pre-MSVCR80.DLL or MSVCRT.DLL pre-Vista */
/* The Microsoft DLLs don't provide either _fseeki64() or _ftelli64(), but
 * they DO provide fgetpos(), fsetpos(), and _lseeki64(), which may be used
 * to emulate the two missing functions.  (Note that we choose to provide
 * these emulations in the form of MinGW external helper functions, rather
 * than pollute the <stdio.h> namespace with declarations, such as that
 * for _lseeki64(), which properly belongs in <io.h>).
 */
#ifndef __USE_MINGW_FSEEK
/* If this option has been selected, an alternative emulation for _fseeki64()
 * is provided later, to ensure that the call is wrapped in a MinGW specific
 * fseek() handling API.
 */
int __cdecl __MINGW_NOTHROW __mingw_fseeki64 (FILE *, __int64, int);
__CRT_ALIAS __cdecl __MINGW_NOTHROW  int _fseeki64 (FILE *__f, __int64 __o, int __w)
{ return __mingw_fseeki64 (__f, __o, __w); }
#endif

__int64 __cdecl __MINGW_NOTHROW __mingw_ftelli64 (FILE *);
__CRT_ALIAS __cdecl  __int64 __MINGW_NOTHROW _ftelli64 (FILE *__file )
{ return __mingw_ftelli64 (__file); }

#endif	/* pre-MSVCR80.DLL or MSVCRT.DLL pre-Vista */

/* Error Functions
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int feof (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int ferror (FILE *);

#ifdef __cplusplus
inline __cdecl __MINGW_NOTHROW  int feof (FILE * __F){ return __F->_flag & _IOEOF; }
inline __cdecl __MINGW_NOTHROW  int ferror (FILE * __F){ return __F->_flag & _IOERR; }
#else
#define feof(__F)     ((__F)->_flag & _IOEOF)
#define ferror(__F)   ((__F)->_flag & _IOERR)
#endif

_CRTIMP __cdecl __MINGW_NOTHROW  void clearerr (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  void perror (const char *);

#ifndef __STRICT_ANSI__
/*
 * Pipes
 */
_CRTIMP __cdecl __MINGW_NOTHROW  FILE * _popen (const char *, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _pclose (FILE *);

#ifndef NO_OLDNAMES
_CRTIMP __cdecl __MINGW_NOTHROW  FILE *  popen (const char *, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int     pclose (FILE *);
#endif

/* Other Non ANSI functions
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int    _flushall (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _fgetchar (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _fputchar (int);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE * _fdopen (int, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _fileno (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _fcloseall (void);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE * _fsopen (const char *, const char *, int);
#ifdef __MSVCRT__
_CRTIMP __cdecl __MINGW_NOTHROW  int    _getmaxstdio (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _setmaxstdio (int);
#endif

/* Microsoft introduced a capability in MSVCR80.DLL and later, to
 * set the minimum number of digits to be displayed in a printf()
 * floating point exponent; they retro-fitted this in MSVCRT.DLL,
 * from Windows-Vista onwards, but we provide our own wrappers in
 * libmingwex.a, which make it possible for us to emulate the API
 * for any version of MSVCRT.DLL (including WinXP and earlier).
 */
#define _TWO_DIGIT_EXPONENT    1

/* While Microsoft define the preceding manifest constant, they
 * appear to neglect to define its complement, (for restoration
 * of their default exponent display format); for orthogonality,
 * we will provide this regardless of Microsoft's negligence.
 */
#define _THREE_DIGIT_EXPONENT  0

/* Once again, unspecified by Microsoft, (and mostly redundant),
 * it is convenient to specify a combining mask for these.
 */
#define _EXPONENT_DIGIT_MASK  (_TWO_DIGIT_EXPONENT | _THREE_DIGIT_EXPONENT)

unsigned int __cdecl __mingw_get_output_format (void);
unsigned int __cdecl __mingw_set_output_format (unsigned int);

/* Also appearing for the first time in MSVCR80.DLL, and then also
 * retro-fitted to MSVCRT.DLL from Windows-Vista onwards, was this
 * pair of functions to control availability of "%n" formatting in
 * the MSVCRT.DLL printf() family of functions, for which we also
 * provide our own DLL version agnostic wrappers:
 */
int __cdecl __mingw_get_printf_count_output (void);
int __cdecl __mingw_set_printf_count_output (int);

#if __MSVCRT_VERSION__ >= __MSVCR80_DLL
/* When the user declares that MSVCR80.DLL features are supported,
 * we simply expose the corresponding APIs...
 */
_CRTIMP unsigned int __cdecl __MINGW_NOTHROW _get_output_format (void);
_CRTIMP unsigned int __cdecl __MINGW_NOTHROW _set_output_format (unsigned int);

_CRTIMP __cdecl __MINGW_NOTHROW  int _get_printf_count_output (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int _set_printf_count_output (int);

#else
/* ...otherwise, we emulate the APIs, in a DLL version agnostic
 * manner, using our own implementation wrappers.
 */
__CRT_ALIAS unsigned int __cdecl _get_output_format (void)
{ return __mingw_get_output_format (); }

__CRT_ALIAS unsigned int __cdecl _set_output_format (unsigned int __style)
{ return __mingw_set_output_format (__style); }

/* When using our own printf() implementation, "%n" format is ALWAYS
 * supported, so we make this API a no-op, reporting it to be so; for
 * the alternative case, when using MSVCRT.DLL's printf(), we delegate
 * to our wrapper API implementation, which will invoke the API function
 * calls within the DLL, if they are available, or persistently report
 * the state of "%n" formatting as DISABLED if they are not.
 */
#if __USE_MINGW_ANSI_STDIO
/* Note that __USE_MINGW_ANSI_STDIO is not guaranteed to resolve to any
 * symbol which will represent a compilable logic state; map it to this
 * alternative which will, for the true state...
 */
# define __USE_MINGW_PRINTF  1
#else
/* ...and for the false.
 */
# define __USE_MINGW_PRINTF  0
#endif

__CRT_ALIAS int __cdecl _get_printf_count_output (void)
{ return __USE_MINGW_PRINTF ? 1 : __mingw_get_printf_count_output (); }

__CRT_ALIAS int __cdecl _set_printf_count_output (int __mode)
{ return __USE_MINGW_PRINTF ? 1 : __mingw_set_printf_count_output (__mode); }
#endif

#ifndef _NO_OLDNAMES
_CRTIMP __cdecl __MINGW_NOTHROW  int    fgetchar (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int    fputchar (int);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE * fdopen (int, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    fileno (FILE *);
#endif	/* !_NO_OLDNAMES */

#define _fileno(__F) ((__F)->_file)
#ifndef _NO_OLDNAMES
#define fileno(__F) ((__F)->_file)
#endif

#if defined (__MSVCRT__) && ! defined (__NO_MINGW_LFS)
__CRT_ALIAS FILE * __cdecl __MINGW_NOTHROW  fopen64 (const char *, const char *);
__CRT_ALIAS __JMPSTUB__(( FUNCTION = fopen64, REMAPPED = fopen ))
FILE * __cdecl __MINGW_NOTHROW  fopen64 (const char * filename, const char * mode)
{ return fopen (filename, mode); }

int __cdecl __MINGW_NOTHROW  fseeko64 (FILE *, __off64_t, int);

#ifdef __USE_MINGW_FSEEK
/* When this option is selected, we need to redirect calls to _fseeki64()
 * and fseeko64() through a MinGW specific wrapper.  Since the two functions
 * are fundamentally identical, differing only in the type of the "offset"
 * argument, (and both types are effectively 64-bit signed ints anyway),
 * the same wrapper will suffice for both.
 */
__CRT_ALIAS int _fseeki64( FILE *__fp, __int64 __offset, int __whence )
{ return __mingw_fseek( __fp, (__off64_t)(__offset), __whence ); }

__CRT_ALIAS int fseeko64( FILE *__fp, __off64_t __offset, int __whence )
{ return __mingw_fseek( __fp, __offset, __whence ); }
#endif

__off64_t __cdecl __MINGW_NOTHROW ftello64 (FILE *);

#endif	/* __MSVCRT__ && !__NO_MINGW_LFS */
#endif	/* !__STRICT_ANSI__ */
#endif	/* _STDIO_H */

#if ! (defined _STDIO_H && defined _WCHAR_H)
/* The following are declared when including either <stdio.h> or <wchar.h>.
 * If both header include guards are now in place, then we must currently be
 * including <stdio.h> in its own right, having already processed this block
 * during prior partial inclusion by <wchar.h>; there is no need to process
 * it a second time.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int     fwprintf (FILE *, const wchar_t *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int     wprintf (const wchar_t *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int     vfwprintf (FILE *, const wchar_t *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW  int     vwprintf (const wchar_t *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _snwprintf (wchar_t *, size_t, const wchar_t *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _vscwprintf (const wchar_t *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _vsnwprintf (wchar_t *, size_t, const wchar_t *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW  int     fwscanf (FILE *, const wchar_t *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int     wscanf (const wchar_t *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int     swscanf (const wchar_t *, const wchar_t *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t  fgetwc (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t  fputwc (wchar_t, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t  ungetwc (wchar_t, FILE *);

#ifndef __STRICT_ANSI__
/* These differ from the ISO C prototypes, which have a maxlen parameter (like snprintf).
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int  swprintf (wchar_t *, const wchar_t *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int  vswprintf (wchar_t *, const wchar_t *, __VALIST);
#endif

#ifdef __MSVCRT__
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t * fgetws (wchar_t *, int, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int       fputws (const wchar_t *, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t    getwc (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t    getwchar (void);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t    putwc (wint_t, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t    putwchar (wint_t);

#ifndef __STRICT_ANSI__
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t * _getws (wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  int       _putws (const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE    * _wfdopen(int, const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE    * _wfopen (const wchar_t *, const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE    * _wfreopen (const wchar_t *, const wchar_t *, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE    * _wfsopen (const wchar_t *, const wchar_t *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t * _wtmpnam (wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t * _wtempnam (const wchar_t *, const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  int       _wrename (const wchar_t *, const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  int       _wremove (const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  void      _wperror (const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE    * _wpopen (const wchar_t *, const wchar_t *);

#endif  /* !__STRICT_ANSI__ */
#endif	/* __MSVCRT__ */

#ifdef _ISOC99_SOURCE
__JMPSTUB__(( FUNCTION = snwprintf, DLLENTRY = _snwprintf ))
__cdecl __MINGW_NOTHROW  int snwprintf (wchar_t *, size_t, const wchar_t *, ...);
__cdecl __MINGW_NOTHROW  int vsnwprintf (wchar_t *, size_t, const wchar_t *, __VALIST);

#ifndef __NO_INLINE__
__CRT_INLINE __cdecl __MINGW_NOTHROW
__JMPSTUB__(( FUNCTION = vsnwprintf, DLLENTRY = _vsnwprintf ))
int vsnwprintf (wchar_t *__s, size_t __n, const wchar_t *__fmt, __VALIST __arg)
{ return _vsnwprintf ( __s, __n, __fmt, __arg); }
#endif

__cdecl __MINGW_NOTHROW  int  vwscanf (const wchar_t *__restrict__, __VALIST);
__cdecl __MINGW_NOTHROW
int  vfwscanf (FILE *__restrict__, const wchar_t *__restrict__, __VALIST);
__cdecl __MINGW_NOTHROW
int  vswscanf (const wchar_t *__restrict__, const wchar_t * __restrict__, __VALIST);

#endif  /* _ISOC99_SOURCE */
#endif  /* ! (_STDIO_H && _WCHAR_H) */

#if defined _STDIO_H && ! defined __STRICT_ANSI__
#if defined __MSVCRT__ && ! defined _NO_OLDNAMES
_CRTIMP __cdecl __MINGW_NOTHROW  FILE * wpopen (const wchar_t *, const wchar_t *);
#endif

/* Other non-ANSI wide character functions...
 */
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t _fgetwchar (void);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t _fputwchar (wint_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _getw (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _putw (int, FILE *);

#ifndef _NO_OLDNAMES
/* ...and their original names, before Microsoft uglification...
 */
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t  fgetwchar (void);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t  fputwchar (wint_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int     getw (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int     putw (int, FILE *);

#endif  /* !_NO_OLDNAMES */
#endif  /* !__STRICT_ANSI__ */

_END_C_DECLS

#endif	/* ! RC_INVOKED */
#endif  /* !_STDIO_H: $RCSfile: stdio.h,v $: end of file */
 
/*
 * string.h
 *
 * ISO-C standard header, with MSVC compatible extensions.
 *
 * $Id: string.h,v 9214845bad91 2017/12/18 11:45:49 keith $
 *
 * Written by Colin Peters <colin@bird.fu.is.saga-u.ac.jp>
 * Copyright (C) 1997-2000, 2002-2004, 2007, 2009, 2015-2017,
 *  MinGW.org Project.
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice, this permission notice, and the following
 * disclaimer shall be included in all copies or substantial portions of
 * the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OF OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef _STRING_H
#pragma GCC system_header
#define _STRING_H

/* All MinGW system headers must include this...
 */
#ifndef RC_INVOKED
/* ISO-C requires this header to expose definitions for NULL and size_t,
 * retaining compatiblity with their fundamental <stddef.h> definitions.
 */
#define __need_NULL
#define __need_size_t
#ifndef __STRICT_ANSI__
 /* MSVC extends this requirement to include a definition of wchar_t,
  * (which contravenes strict ISO-C standards conformity).
  */
# define __need_wchar_t
#endif
#include <stddef.h>

#if _EMULATE_GLIBC
/* GNU's glibc declares strcasecmp() and strncasecmp() in <string.h>,
 * contravening POSIX.1-2008 which requires them to be declared only in
 * <strings.h>; we may emulate this anomalous glibc behaviour, which is
 * ostensibly to support BSD usage, (in spite of such usage now being
 * obsolete in BSD), by simply including our <strings.h> here.
 */
/*
 * strings.h
 *
 * API declarations for POSIX.1-2008 string functions supported by MinGW.
 *
 * $Id: strings.h,v cd6da3db1be2 2017/01/10 19:43:48 keithmarshall $
 *
 * Written by Keith Marshall <keithmarshall@users.sourceforge.net>
 * Copyright (C) 2015-2017, MinGW.org Project.
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice, this permission notice, and the following
 * disclaimer shall be included in all copies or substantial portions of
 * the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OF OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef _STRINGS_H
#pragma GCC system_header

/* In addition to the POSIX strcasecmp() and strncasecmp() functions,
 * this header declares the prototypes for the MSVC specific stricmp()
 * and strincmp() functions, which MSVC expects to find in <string.h>;
 * thus, we support selective partial inclusion by <string.h>, to make
 * this pair of function prototypes available as MSVC expects...
 */
#ifndef __STRING_H_SOURCED__
/* ...and we define the _STRINGS_H guard macro only when NOT included
 * in this partial fashion.
 */
#define _STRINGS_H

/* All MinGW system headers must include <_mingw.h>; if we had been
 * sourced by <string.h>, we could safely assume that it had already
 * done this, but since that doesn't apply in this case, we must do
 * it ourselves.
 */
#ifndef RC_INVOKED
/* POSIX.1-2008 requires this header to expose the typedef for size_t; to
 * ensure consistency, we import this from GCC's own <stddef.h> header.
 */
#define __need_size_t
#endif	/* ! RC_INVOKED */
#endif	/* !__STRING_H_SOURCED__ */

#if ! (defined __STRICT_ANSI__ && defined __NO_INLINE__)
/* These are the MSVCRT.DLL equivalents for POSIX.1's strcasecmp() and
 * strncasecmp() functions, for which we provide in-line implementations
 * in <strings.h> respectively; MSVC expects to find these prototypes in
 * <string.h>, but we also need them here, in <strings.h>, to facilitate
 * the in-line function implementations; we declare them here, and allow
 * <string.h> to include them selectively.  Note that <string.h> doesn't
 * need these if __STRICT_ANSI__ is defined, while <strings.h> doesn't
 * if __NO_INLINE__ is defined; thus we declare them, unless BOTH of
 * these conditions for not requiring them are satisfied.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int _stricmp( const char *, const char * );
_CRTIMP __cdecl __MINGW_NOTHROW  int _strnicmp( const char *, const char *, size_t );
#endif	/* !(__STRICT_ANSI__ && __NO_INLINE__) */

#if defined _STRINGS_H && ! defined RC_INVOKED
#ifndef __NO_INLINE__
/* Provide in-line implementations for strcasecmp(), and strncasecmp(),
 * effectively aliasing them to the respective MSVCRT.DLL (non-standard)
 * equivalents, as prototyped above.
 */
__CRT_ALIAS __JMPSTUB__(( FUNCTION = strcasecmp, REMAPPED = _stricmp ))
  int strcasecmp( const char *__s1, const char *__s2 )
  { return _stricmp( __s1, __s2 ); }

__CRT_ALIAS __JMPSTUB__(( FUNCTION = strncasecmp, REMAPPED = _strnicmp ))
  int strncasecmp( const char *__s1, const char *__s2, size_t __n )
  { return _strnicmp( __s1, __s2, __n ); }

#endif	/* !__NO_INLINE__ */

_END_C_DECLS

#endif	/* _STRINGS_H && ! RC_INVOKED */
#endif	/* !_STRINGS_H: $RCSfile: strings.h,v $: end of file */
 
#endif

_BEGIN_C_DECLS

#define __STRING_H_SOURCED__
/* Prototypes for the ISO-C Standard library string functions.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  void *memchr (const void *, int, size_t) __MINGW_ATTRIB_PURE;
_CRTIMP __cdecl __MINGW_NOTHROW  int memcmp (const void *, const void *, size_t) __MINGW_ATTRIB_PURE;
_CRTIMP __cdecl __MINGW_NOTHROW  void *memcpy (void *, const void *, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  void *memmove (void *, const void *, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  void *memset (void *, int, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  char *strcat (char *, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  char *strchr (const char *, int) __MINGW_ATTRIB_PURE;
_CRTIMP __cdecl __MINGW_NOTHROW  int strcmp (const char *, const char *) __MINGW_ATTRIB_PURE;
_CRTIMP __cdecl __MINGW_NOTHROW  int strcoll (const char *, const char *); /* Compare using locale */
_CRTIMP __cdecl __MINGW_NOTHROW  char *strcpy (char *, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  size_t strcspn (const char *, const char *) __MINGW_ATTRIB_PURE;
_CRTIMP __cdecl __MINGW_NOTHROW  char *strerror (int); /* NOTE: NOT an old name wrapper. */

_CRTIMP __cdecl __MINGW_NOTHROW  size_t strlen (const char *) __MINGW_ATTRIB_PURE;
_CRTIMP __cdecl __MINGW_NOTHROW  char *strncat (char *, const char *, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int strncmp (const char *, const char *, size_t) __MINGW_ATTRIB_PURE;
_CRTIMP __cdecl __MINGW_NOTHROW  char *strncpy (char *, const char *, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  char *strpbrk (const char *, const char *) __MINGW_ATTRIB_PURE;
_CRTIMP __cdecl __MINGW_NOTHROW  char *strrchr (const char *, int) __MINGW_ATTRIB_PURE;
_CRTIMP __cdecl __MINGW_NOTHROW  size_t strspn (const char *, const char *) __MINGW_ATTRIB_PURE;
_CRTIMP __cdecl __MINGW_NOTHROW  char *strstr (const char *, const char *) __MINGW_ATTRIB_PURE;
_CRTIMP __cdecl __MINGW_NOTHROW  char *strtok (char *, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  size_t strxfrm (char *, const char *, size_t);

#ifndef __STRICT_ANSI__
/* Extra non-ANSI functions provided by the CRTDLL library
 */
_CRTIMP __cdecl __MINGW_NOTHROW  char *_strerror (const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  void *_memccpy (void *, const void *, int, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int _memicmp (const void *, const void *, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  char *_strdup (const char *) __MINGW_ATTRIB_MALLOC;
_CRTIMP __cdecl __MINGW_NOTHROW  int _strcmpi (const char *, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int _stricoll (const char *, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  char *_strlwr (char *);
_CRTIMP __cdecl __MINGW_NOTHROW  char *_strnset (char *, int, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  char *_strrev (char *);
_CRTIMP __cdecl __MINGW_NOTHROW  char *_strset (char *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  char *_strupr (char *);
_CRTIMP __cdecl __MINGW_NOTHROW  void _swab (const char *, char *, size_t);

#if !_EMULATE_GLIBC
/* MSVC's non-ANSI _stricmp() and _strnicmp() functions must also be
 * prototyped here, but we need to share them with <strings.h>, where
 * we declare their POSIX strcasecmp() and strncasecmp() equivalents;
 * get the requisite prototypes by selective <strings.h> inclusion,
 * (noting that we've already done so, if emulating glibc, but if not,
 * we use quoted inclusion now, to ensure that we get our "strings.h",
 * which is equipped to support __STRING_H_SOURCED__ filtering).
 */
#endif

# ifdef __MSVCRT__
 /* These were not present in the CRTDLL prior to the first release of
  * MSVCRT.DLL, but are available in all versions of that library.
  */
_CRTIMP __cdecl __MINGW_NOTHROW  int _strncoll(const char *, const char *, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int _strnicoll(const char *, const char *, size_t);
# endif

# ifndef _NO_OLDNAMES
 /* Non-underscore decorated versions of non-ANSI functions. They live in the
  * OLDNAMES libraries, whence they provide a little extra portability.
  */
_CRTIMP __cdecl __MINGW_NOTHROW  void *memccpy (void *, const void *, int, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int memicmp (const void *, const void *, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  char *strdup (const char *) __MINGW_ATTRIB_MALLOC;
_CRTIMP __cdecl __MINGW_NOTHROW  int strcmpi (const char *, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int stricmp (const char *, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int stricoll (const char *, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  char *strlwr (char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int strnicmp (const char *, const char *, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  char *strnset (char *, int, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  char *strrev (char *);
_CRTIMP __cdecl __MINGW_NOTHROW  char *strset (char *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  char *strupr (char *);

#  ifndef _UWIN
  /* FIXME: Do we really care that UWin doesn't support this?  We are
   * under no obligation to support UWin.
   */
_CRTIMP __cdecl __MINGW_NOTHROW  void swab (const char *, char *, size_t);

#  endif /* ! _UWIN */
# endif /* ! _NO_OLDNAMES */

/* MSVC also expects <string.h> to declare duplicates of the wchar_t
 * string functions which are nominally declared in <wchar.h>, (which
 * is where ISO-C specifies that they should be declared).  For the
 * convenience of applications which rely on this Microsoft anomaly,
 * inclusion of <wchar.h>, within the current __STRING_H_SOURCED__
 * scope, will selectively expose the required function prototypes;
 * however, strictly ISO-C conforming applications should include
 * <wchar.h> directly; they should not rely on this MSVC specific
 * anomalous behaviour.  (We use the quoted form of inclusion here,
 * to ensure that we get our own "wchar.h", and not any predecessor
 * which may have been insinuated into the system include path, and
 * so could interfere with our mechanism for partial inclusion of
 * shared header content).
 */
/*
 * wchar.h
 *
 * Declarations relating to support for wide characters; many are simply
 * inherited by (sub-optimal) inclusion of other header files.
 *
 * $Id: wchar.h,v 3346bd5e5239 2020/07/04 21:06:58 keith $
 *
 * Unattributed original source.
 * Adapted by Rob Savoye <rob@cygnus.com>
 * Copyright (C) 1997, 1999-2009, 2011, 2015, 2016, 2018-2020,
 *   MinGW.org Project.
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice, this permission notice, and the following
 * disclaimer shall be included in all copies or substantial portions of
 * the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OF OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef _WCHAR_H
#pragma GCC system_header

/* This header declares prototypes for wchar_t string functions, as are
 * prescribed by ISO-C, but which MSVC also expects, (in contravention of
 * ISO-C prescriptions), to find in <string.h>.  To accommodate this MSVC
 * anomaly, we make provision for <string.h> to include a selected subset
 * of <wchar.h>; thus, we do not immediately define _WCHAR_T...
 */
#ifndef __STRING_H_SOURCED__
/* ...but defer it until we have confirmed that this is NOT inclusion for
 * only this subset of <wchar.h> declarations.
 */
#define _WCHAR_H

/* All MinGW headers are required to include <_mingw.h>; in the case of
 * selective inclusion by <string.h>, we expect it to have already done
 * so, but since that doesn't apply here, we must do it ourselves.
 */
#ifndef __STRICT_ANSI__
 /* MSDN says that isw* char classifications appear in both <wchar.h>,
  * and in <wctype.h>.  Although these <wctype.h> classifications are as
  * prescribed by ISO-C, their exposure in <wchar.h> is not; nonetheless,
  * we replicate them here, for MSDN conformity.
  */
/*
 * wctype.h
 *
 * Functions for wide character classification and conversion.
 *
 * $Id: wctype.h,v 877c17d729df 2017/01/29 10:09:49 keithmarshall $
 *
 * Written by Mumit Khan <khan@xraylith.wisc.edu>
 * Copyright (C) 1999-2003, 2005-2007, 2016, 2017, MinGW.org Project
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice, this permission notice, and the following
 * disclaimer shall be included in all copies or substantial portions of
 * the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OF OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef _WCTYPE_H
#pragma GCC system_header

#ifndef __CTYPE_H_SOURCED__
/* Perversely, (since they provide <wctype.h> themselves), Microsoft
 * say that most of the definitions and declarations which follow are
 * provided by <ctype.h>, rather than here; (this conflicts with both
 * ISO-C and POSIX).  We prefer to provide them here, for ISO-C/POSIX
 * conformance, while also exposing them for selective inclusion by
 * <ctype.h>, to maintain Microsoft compatibility.
 *
 * We define the <wctype.h> multiple inclusion guard macro only when
 * <wctype.h> is included directly, NOT when included via <ctype.h>
 */
#define _WCTYPE_H

/* All MinGW headers must include <_mingw.h>; when sourced by <ctype.h>,
 * we may delegate that responsibility to it, but in the case of direct
 * inclusion, we must address it ourselves.
 */
#endif

/* The following flags are used to tell iswctype() and _isctype() what
 * character classes are to be matched; (note that _BLANK will match for
 * SP and non-ASCII horizontal space chars -- e.g. for "no-break space",
 * 0xA0, in CP1250 -- but NOT for HT).
 *
 * These are defined such that they will be made visible by inclusion
 * of either <wctype.h> (this file), or <ctype.h>:
 */
#define _ALPHA		0x0103
#define _LOWER		0x0002
#define _UPPER		0x0001
#define _DIGIT		0x0004
#define _SPACE		0x0008		/* HT  LF  VT  FF  CR  SP */
#define _PUNCT		0x0010
#define _CONTROL	0x0020
#define _BLANK		0x0040
#define _HEX		0x0080

#ifndef RC_INVOKED

/* ISO-C and POSIX specify that <wctype.h> must define wint_t, wctype_t,
 * and the WEOF macro, (which also requires wchar_t), as they are defined
 * in <wchar.h>; since <wchar.h> gets wint_t, (and wchar_t), from <stddef.h>,
 * we do likewise here.  Furthermore, to maintain Microsoft compatibility,
 * we must also do this on behalf of <ctype.h>; however...
 */
#if !(defined _WCTYPE_H && defined _CTYPE_H)
/* ...we need not incur the overhead of doing it twice, when both <ctype.h>
 * and <wctype.h> have been included.
 */
#define __need_wint_t
#define __need_wchar_t
#define WEOF	(wchar_t)(0xffff)

_BEGIN_C_DECLS

/* Wide character classification functions.  In typically perverse
 * fashion, and contrary to both ISO-C and POSIX, Microsoft specify
 * that these should be declared in <ctype.h>; thus, to accommodate
 * this persersity, we make them visible here, irrespective of any
 * selective inclusion filter macro.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int iswalnum (wint_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int iswalpha (wint_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int iswascii (wint_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int iswcntrl (wint_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int iswctype (wint_t, wctype_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int iswdigit (wint_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int iswgraph (wint_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int iswlower (wint_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int iswprint (wint_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int iswpunct (wint_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int iswspace (wint_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int iswupper (wint_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int iswxdigit (wint_t);

__MINGW_ATTRIB_DEPRECATED
/* This function is exported by all versions of MSVCRT.DLL, (up to and
 * including that in Windows-7), and in all non-free counterparts up to
 * and including MSVCR120.DLL, but as of MSVC-2013, Microsoft declare
 * it to be obsolete.  DO NOT USE IT!  Use iswctype() instead.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int is_wctype (wint_t, wctype_t);

#if _ISOC99_SOURCE
__cdecl __MINGW_NOTHROW  int iswblank (wint_t);
#endif

/* Wide character case transliteration functions; the following conform
 * to the ISO-C and POSIX standard declarations; Microsoft, at one time,
 * specified both as taking a wchar_t argument, and returning a wchar_t
 * result, but now take a wint_t argument, and return int.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t towlower (wint_t);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t towupper (wint_t);

#if !(defined __NO_INLINE__ || defined __NO_CTYPE_INLINES)
/* Provide inline alternatives to the DLL-exported isw*() functions.
 * Note that POSIX stipulates that these alternatives should be macros;
 * we prefer __CRT_INLINEs, (which GCC effectively treats as macros),
 * because they do not interfere with C++ namespace qualification.
 */
__CRT_INLINE __cdecl __MINGW_NOTHROW  int iswalnum (wint_t wc)
{ return (iswctype (wc, _ALPHA | _DIGIT)); }

__CRT_INLINE __cdecl __MINGW_NOTHROW  int iswalpha (wint_t wc)
{ return (iswctype (wc, _ALPHA )); }

__CRT_INLINE __cdecl __MINGW_NOTHROW  int iswascii (wint_t wc)
{ return ((wc & ~0x7F) == 0); }

__CRT_INLINE __cdecl __MINGW_NOTHROW  int iswcntrl (wint_t wc)
{ return (iswctype (wc, _CONTROL)); }

__CRT_INLINE __cdecl __MINGW_NOTHROW  int iswdigit (wint_t wc)
{ return (iswctype (wc, _DIGIT)); }

__CRT_INLINE __cdecl __MINGW_NOTHROW  int iswgraph (wint_t wc)
{ return (iswctype (wc, _PUNCT | _ALPHA | _DIGIT)); }

__CRT_INLINE __cdecl __MINGW_NOTHROW  int iswlower (wint_t wc)
{ return (iswctype (wc, _LOWER)); }

__CRT_INLINE __cdecl __MINGW_NOTHROW  int iswprint (wint_t wc)
{ return (iswctype (wc, _BLANK | _PUNCT | _ALPHA | _DIGIT)); }

__CRT_INLINE __cdecl __MINGW_NOTHROW  int iswpunct (wint_t wc)
{ return (iswctype (wc, _PUNCT)); }

__CRT_INLINE __cdecl __MINGW_NOTHROW  int iswspace (wint_t wc)
{ return (iswctype (wc, _SPACE)); }

__CRT_INLINE __cdecl __MINGW_NOTHROW  int iswupper (wint_t wc)
{ return (iswctype (wc, _UPPER)); }

__CRT_INLINE __cdecl __MINGW_NOTHROW  int iswxdigit (wint_t wc)
{ return (iswctype (wc, _HEX)); }

#if _ISOC99_SOURCE
__CRT_INLINE __cdecl __MINGW_NOTHROW  int iswblank (wint_t wc)
{ return (iswctype (wc, _BLANK) || wc == L'\t'); }
#endif
#endif	/* !__NO_CTYPE_INLINES */

_END_C_DECLS

#endif	/* !(_WCTYPE_H && _CTYPE_H) */

#ifdef _WCTYPE_H
/* Although Microsoft make most of the content, which ISO-C and POSIX say
 * should be in <wctype.h>, available through <ctype.h>, the declarations
 * in this section are exclusive to <wctype.h>
 */
typedef wchar_t  wctrans_t;

_BEGIN_C_DECLS

/* These are provided in libmingwex.a.  Note, that they are also exported
 * by the MS C++ runtime lib (MSVCP60.DLL).  The MSVCP60.DLL implementations
 * of wctrans and towctrans are not C99 compliant in that wctrans("tolower")
 * returns 0, while C99 specifies that a non-zero value should be returned
 * for a valid string descriptor.  If you want the MS behaviour (and you
 * have MSVCP60.DLL in your path) add -lmsvcp60 to your command line.
 */
__cdecl __MINGW_NOTHROW  wint_t towctrans (wint_t, wctrans_t);
__cdecl __MINGW_NOTHROW  wctrans_t wctrans (const char*);
__cdecl __MINGW_NOTHROW  wctype_t wctype (const char*);

_END_C_DECLS

#endif	/* _WCTYPE_H */
#endif	/* ! RC_INVOKED */
#endif	/* !_WCTYPE_H: $RCSfile: wctype.h,v $: end of file */
 

 /* This is also necessary, to support the non-ANSI wchar.h declarations
  * which MSDN identifies as being provided here.
  */
#endif	/* !__STRICT_ANSI__ */

#define WCHAR_MIN	0
#define WCHAR_MAX	0xffff

#define WEOF		(wchar_t)(0xffff)

#ifndef RC_INVOKED
#define __WCHAR_H_SOURCED__
/* ISO-C, POSIX, and Microsoft specify an overlap of content between
 * <wchar.h> and other system header files; by inclusion of such other
 * headers within this "__WCHAR_H_SOURCED__" scope, we may selectively
 * retrieve the overlapping content, without requiring duplication of
 * that content here; thus, from...
 */
/*
 * stdlib.h
 *
 * ANSI/POSIX + Microsoft compatible standard library function prototypes,
 * associated macros, and manifest constant definitions.
 *
 * $Id: stdlib.h,v c5acb0e27565 2020/04/19 12:02:24 keith $
 *
 * Written by Colin Peters <colin@bird.fu.is.saga-u.ac.jp>
 * Copyright (C) 1997-2009, 2011, 2014-2016, 2018, 2020, MinGW.org Project.
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice, this permission notice, and the following
 * disclaimer shall be included in all copies or substantial portions of
 * the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OF OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef _STDLIB_H
#pragma GCC system_header

/* Some of the content of this header is made selectively accessible,
 * when indirectly included via <wchar.h>; only when we have established
 * that this inclusion is NOT via this selective method...
 */
#ifndef __WCHAR_H_SOURCED__
 /* ...do we define the repeat inclusion guard for <stdlib.h> itself.
  */
#define _STDLIB_H

/* All MinGW headers must include <_mingw.h>; if included via <wchar.h>,
 * we assume that this has been done already, otherwise we must attend to
 * it for <stdlib.h>.
 */
#ifndef RC_INVOKED
#define __need_size_t
#define __need_wchar_t
#define __need_NULL
#endif /* RC_INVOKED */

/* RAND_MAX is the maximum value that may be returned by rand.
 * The minimum is zero.
 */
#define RAND_MAX	0x7FFF

/* These values may be used as exit status codes.
 */
#define EXIT_SUCCESS	0
#define EXIT_FAILURE	1

/* Definitions for path name functions.
 * NOTE: All of these values have simply been chosen to be conservatively
 * high.  Remember that with long file names we can no longer depend on
 * extensions being short.
 */
#ifndef __STRICT_ANSI__

#ifndef MAX_PATH
#define MAX_PATH	(260)
#endif

#define _MAX_PATH	MAX_PATH
#define _MAX_DRIVE	(3)
#define _MAX_DIR	256
#define _MAX_FNAME	256
#define _MAX_EXT	256

#endif	/* !__STRICT_ANSI__ */
#endif	/* !__WCHAR_H_SOURCED__ */

#ifndef RC_INVOKED

_BEGIN_C_DECLS

#ifdef _STDLIB_H
#if ! defined __STRICT_ANSI__
/* This seems like a convenient place to declare these variables, which
 * give programs using WinMain (or main for that matter) access to main-ish
 * argc and argv. environ is a pointer to a table of environment variables.
 * NOTE: Strings in _argv and environ are ANSI strings.
 */
extern int     _argc;
extern char  **_argv;

#ifdef __MSVCRT__
/* Imports from the runtime DLL, for the above variables.
 */
extern __cdecl __MINGW_NOTHROW  int       *__p___argc(void);
extern __cdecl __MINGW_NOTHROW  char    ***__p___argv(void);
extern __cdecl __MINGW_NOTHROW  wchar_t ***__p___wargv(void);

#define __argc (*__p___argc())
#define __argv (*__p___argv())
#define __wargv (*__p___wargv())

#else  /* ! __MSVCRT__ */

#ifndef __DECLSPEC_SUPPORTED

extern int    *_imp____argc_dll;
extern char ***_imp____argv_dll;

#define __argc (*_imp____argc_dll)
#define __argv (*_imp____argv_dll)

#else  /* __DECLSPEC_SUPPORTED */

__MINGW_IMPORT int    __argc_dll;
__MINGW_IMPORT char **__argv_dll;

#define __argc __argc_dll
#define __argv __argv_dll

#endif  /* __DECLSPEC_SUPPORTED */

#endif  /* __MSVCRT__ */
#endif  /* __STRICT_ANSI__ */

#ifndef MB_CUR_MAX
/* FIXME: also defined in <ctype.h>; should be factored out.
 */
#ifdef __DECLSPEC_SUPPORTED
# ifdef __MSVCRT__
#  define MB_CUR_MAX __mb_cur_max
   __MINGW_IMPORT int __mb_cur_max;
# else  /* ! __MSVCRT__ */
#  define MB_CUR_MAX __mb_cur_max_dll
   __MINGW_IMPORT int __mb_cur_max_dll;
# endif  /* ! __MSVCRT__ */

#else  /* ! __DECLSPEC_SUPPORTED */
# ifdef __MSVCRT__
   extern int* _imp____mb_cur_max;
#  define MB_CUR_MAX (*_imp____mb_cur_max)
# else  /* ! __MSVCRT__ */
   extern int*  _imp____mb_cur_max_dll;
#  define MB_CUR_MAX (*_imp____mb_cur_max_dll)
# endif  /* ! __MSVCRT__ */
#endif  /*  __DECLSPEC_SUPPORTED */
#endif  /* MB_CUR_MAX */

/* In MSVCR80.DLL, Microsoft introduced the following pair of errno
 * accessor functions; they subsequently became available in MSVCRT.DLL
 * from Vista onward.  Although they are not required by ISO-C, and they
 * are more cumbersome to use, than referring to errno directly, the GCC
 * developers have gratuitously chosen to assume, in GCC-9.x, that they
 * are always supported on MS-Windows, regardless of Windows version.
 * Logically, we might expect these to be declared in <errno.h>, but
 * Microsoft's documentation insists that they are actually declared
 * here; thus, to satisfy the GCC-9.x requirement, we will declare
 * them unconditionally here ...
 */
__cdecl __MINGW_NOTHROW  int _get_errno(int *);
__cdecl __MINGW_NOTHROW  int _set_errno(int);

/* ... then provide in-line implementations, (depending on gratuitous
 * exposure of EINVAL, which strictly belongs in <errno.h> only, while
 * also requiring declaring the ISO-C errno feature, which Microsoft
 * documentation calls for both here, and in <errno.h>; we satisfy
 * both of these requirements by selective <errno.h> inclusion).
 */
#define __STDLIB_H_SOURCED__ 1
/*
 * errno.h
 *
 * Definition of error codes, and error code retrieval mechanism.
 *
 * $Id: errno.h,v 17d9ae7b7327 2020/01/17 15:39:44 keith $
 *
 * Written by Colin Peters <colin@bird.fu.is.saga-u.ac.jp>
 * Copyright (C) 1997-1999, 2001, 2003-2005, 2007, 2016, 2020,
 *   MinGW.org Project.
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice, this permission notice, and the following
 * disclaimer shall be included in all copies or substantial portions of
 * the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OF OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef _ERRNO_H
#pragma GCC system_header

/* Although ISO-C requires inclusion of <errno.h>, for all content
 * provided herein, Microsoft contravenes this by assuming that the
 * "errno" variable is also declared in <stdlib.h>; allow partial
 * inclusion, to support this anomaly...
 */
#ifndef __STDLIB_H_SOURCED__
/* ...defining the _ERRNO_H multiple inclusion guard, only when
 * <errno.h> is included explicitl, other than by <stdlib.h>
 */
#define _ERRNO_H

/* All MinGW headers are expected to include <_mingw.h>; however...
 */
#ifndef __ASSEMBLER__
/* ...the overhead of doing so is unwarranted, when <errno.h> has been
 * included directly in preprocessed assembly language code.
 */
#endif

/* Error code numbers -- these are as documented at
 * https://docs.microsoft.com/en-us/cpp/c-runtime-library/
 * errno-doserrno-sys-errlist-and-sys-nerr?view=vs-2019
 */
#define EPERM		 1	/* Operation not permitted */
#define ENOENT		 2	/* No such file or directory */
#define ENOFILE 	 2	/* Microsoft legacy alias for ENOENT */
#define ESRCH		 3	/* No such process */
#define EINTR		 4	/* Interrupted function call */
#define EIO		 5	/* Input/output error */
#define ENXIO		 6	/* No such device or address */
#define E2BIG		 7	/* Arg list too long */
#define ENOEXEC 	 8	/* Exec format error */
#define EBADF		 9	/* Bad file descriptor */
#define ECHILD		10	/* No child processes */
#define EAGAIN		11	/* Resource temporarily unavailable */
#define ENOMEM		12	/* Not enough space */
#define EACCES		13	/* Permission denied */
#define EFAULT		14	/* Bad address */

/* 15 - Unknown Error */

#define EBUSY		16	/* Device or resource busy */
#define EEXIST		17	/* File exists */
#define EXDEV		18	/* Improper link (cross-device link) */
#define ENODEV		19	/* No such device */
#define ENOTDIR 	20	/* Not a directory */
#define EISDIR		21	/* Is a directory */

#endif	/* !__STDLIB_H_SOURCED__ */
/* Microsoft's non-standard _get_errno() and _set_errno(), which are
 * declared in <stdlib.h>, and for which we provide in-line support on
 * legacy Windows versions, (also in <stdlib.h>), demand exposure of
 * EINVAL within <stdlib.h>, (for legacy support), regardless of the
 * state of _ERRNO_H.
 */
#define EINVAL		22	/* Invalid argument */

#ifdef _ERRNO_H
/* The remaining error codes are to be exposed only when <errno.h> has
 * been included explicitly.
 */
#define ENFILE		23	/* Too many open files in system */
#define EMFILE		24	/* Too many open files */
#define ENOTTY		25	/* Inappropriate I/O control operation */

/* 26 - Unknown Error */

#define EFBIG		27	/* File too large */
#define ENOSPC		28	/* No space left on device */
#define ESPIPE		29	/* Invalid seek (seek on a pipe?) */
#define EROFS		30	/* Read-only file system */
#define EMLINK		31	/* Too many links */
#define EPIPE		32	/* Broken pipe */
#define EDOM		33	/* Domain error (math functions) */
#define ERANGE		34	/* Result too large (possibly too small) */

/* 35 - Unknown Error */

#define EDEADLK 	36	/* Resource deadlock avoided (non-Cyg) */
#define EDEADLOCK	36	/* Microsoft legacy alias for EDEADLK */

/* 37 - Unknown Error */

#define ENAMETOOLONG	38	/* Filename too long (91 in Cyg?) */
#define ENOLCK		39	/* No locks available (46 in Cyg?) */
#define ENOSYS		40	/* Function not implemented (88 in Cyg?) */
#define ENOTEMPTY	41	/* Directory not empty (90 in Cyg?) */
#define EILSEQ		42	/* Illegal byte sequence */

#endif	/* _ERRNO_H */
#if ! (defined _ERRNO_H && defined _STDLIB_H)
/* ISO-C requires that the standard errno feature is defined here, in
 * <errno.h>, but Microsoft require it to also be defined in <stdlib.h>;
 * we expose it for inclusion of both <errno.h> and <stdlib.h>, but we
 * process it once only.
 */
#if ! defined RC_INVOKED && ! defined __ASSEMBLER__
/* C language function prototype declarations are unnecessary, when
 * compiling resource files, and they actually represent syntactically
 * invalid statements, in preprocessed assembly language code.
 */
_BEGIN_C_DECLS

/* Definitions of errno.  For _doserrno, sys_nerr and * sys_errlist,
 * see <stdlib.h>
 */
#ifdef _UWIN
#undef errno
extern int errno;
#else
_CRTIMP int* __cdecl __MINGW_NOTHROW _errno(void);
#define	errno		(*_errno())
#endif

_END_C_DECLS

#endif	/* ! RC_INVOKED && !__ASSEMBLY__ */
#endif	/* ! (_ERRNO_H && _STDLIB_H) */

#if defined _ERRNO_H && defined __PTW32_H && ! defined _PTW32_ERRNO_H
/* As a courtesy to users of pthreads-win32, ensure that the appropriate
 * additional error codes, as defined by that package, are automatically
 * defined when <errno.h> is included AFTER any pthreads-win32 header; a
 * complementary hook, in <_ptw32.h>, ensures that such additional error
 * codes are defined, if <errno.h> is included BEFORE any pthreads-win32
 * header is subsequently included.
 *
 * NOTE: this assumes pthreads-win32-2.10 or later, with corresponding
 * MinGW.org patches applied; it will favour "ptw32_errno.h" installed
 * in the mingwrt system include directory.
 */


#endif	/* __PTW32_H */
#endif	/* !_ERRNO_H: $RCSfile: errno.h,v $: end of file */
 
#if __MSVCRT_VERSION__ < __MSVCR80_DLL && _WIN32_WINNT < _WIN32_WINNT_VISTA
/* These in-line implementations will support universal use of this API,
 * even on legacy Windows versions pre-dating Vista, without requiring use
 * of non-free MSVCRT80.DLL or later.
 */
__CRT_ALIAS __cdecl __MINGW_NOTHROW  int _get_errno( int *__val )
{ return (__val == NULL) ? (errno = EINVAL) : 0 & (*__val = errno); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW  int _set_errno( int __val )
{ errno = __val; return 0; }

#endif
#undef __STDLIB_H_SOURCED__

_CRTIMP __cdecl __MINGW_NOTHROW  int *__doserrno(void);
#define _doserrno  (*__doserrno())

#if !defined (__STRICT_ANSI__)
/* Use environ from the DLL, not as a global.
 */
#ifdef __MSVCRT__
# define _environ  (*__p__environ())
extern _CRTIMP __cdecl __MINGW_NOTHROW  char ***__p__environ(void);
# define _wenviron  (*__p__wenviron())
extern _CRTIMP __cdecl __MINGW_NOTHROW  wchar_t ***__p__wenviron(void);

#else  /* ! __MSVCRT__ */
# ifndef __DECLSPEC_SUPPORTED
# define _environ (*_imp___environ_dll)
extern char ***_imp___environ_dll;

# else  /* __DECLSPEC_SUPPORTED */
# define _environ  _environ_dll
__MINGW_IMPORT char ** _environ_dll;
# endif  /* __DECLSPEC_SUPPORTED */
#endif  /* ! __MSVCRT__ */

#define environ _environ

#ifdef	__MSVCRT__
/* One of the MSVCRTxx libraries */

#ifndef __DECLSPEC_SUPPORTED
# define sys_nerr  (*_imp___sys_nerr)
extern int *_imp___sys_nerr;

#else /* __DECLSPEC_SUPPORTED */
__MINGW_IMPORT int _sys_nerr;

# ifndef _UWIN
# define sys_nerr  _sys_nerr
# endif  /* _UWIN */
#endif  /* __DECLSPEC_SUPPORTED */

#else  /* ! __MSVCRT__ */
/* CRTDLL run time library */

#ifndef __DECLSPEC_SUPPORTED
  extern int*	_imp___sys_nerr_dll;
# define sys_nerr	(*_imp___sys_nerr_dll)
#else  /* __DECLSPEC_SUPPORTED */
  __MINGW_IMPORT int	_sys_nerr_dll;
# define sys_nerr	_sys_nerr_dll
#endif  /* __DECLSPEC_SUPPORTED */

#endif  /* ! __MSVCRT__ */

#ifndef __DECLSPEC_SUPPORTED
#define sys_errlist  (*_imp___sys_errlist)
extern char ***_imp__sys_errlist;

#else  /* __DECLSPEC_SUPPORTED */
__MINGW_IMPORT char *_sys_errlist[];

#ifndef _UWIN
#define sys_errlist  _sys_errlist
#endif  /* _UWIN */
#endif  /* __DECLSPEC_SUPPORTED */

/* OS version and such constants.
 */
#ifdef	__MSVCRT__ /* MSVCRT.DLL and MSVCRxx.DLL variants */

extern _CRTIMP __cdecl __MINGW_NOTHROW  unsigned int *__p__osver(void);
extern _CRTIMP __cdecl __MINGW_NOTHROW  unsigned int *__p__winver(void);
extern _CRTIMP __cdecl __MINGW_NOTHROW  unsigned int *__p__winmajor(void);
extern _CRTIMP __cdecl __MINGW_NOTHROW  unsigned int *__p__winminor(void);

#ifndef __DECLSPEC_SUPPORTED
# define _osver     (*__p__osver())
# define _winver    (*__p__winver())
# define _winmajor  (*__p__winmajor())
# define _winminor  (*__p__winminor())

#else /* __DECLSPEC_SUPPORTED */
__MINGW_IMPORT  unsigned int _osver;
__MINGW_IMPORT  unsigned int _winver;
__MINGW_IMPORT  unsigned int _winmajor;
__MINGW_IMPORT  unsigned int _winminor;
#endif  /* __DECLSPEC_SUPPORTED */

#else  /* ! __MSVCRT__; thus CRTDLL */
#ifndef __DECLSPEC_SUPPORTED

#define _osver	    (*_imp___osver_dll)
#define _winver    (*_imp___winver_dll)
#define _winmajor  (*_imp___winmajor_dll)
#define _winminor  (*_imp___winminor_dll)

extern unsigned int *_imp___osver_dll;
extern unsigned int *_imp___winver_dll;
extern unsigned int *_imp___winmajor_dll;
extern unsigned int *_imp___winminor_dll;

#else  /* __DECLSPEC_SUPPORTED */

#define _osver	    _osver_dll
#define _winver    _winver_dll
#define _winmajor  _winmajor_dll
#define _winminor  _winminor_dll

__MINGW_IMPORT unsigned int _osver_dll;
__MINGW_IMPORT unsigned int _winver_dll;
__MINGW_IMPORT unsigned int _winmajor_dll;
__MINGW_IMPORT unsigned int _winminor_dll;

#endif  /* __DECLSPEC_SUPPORTED */
#endif  /* CRTDLL */

#if defined  __MSVCRT__
/* Although _pgmptr is exported as DATA, be safe and use the access
 * function __p__pgmptr() to get it.
 */
#define _pgmptr  (*__p__pgmptr())
_CRTIMP __cdecl __MINGW_NOTHROW  char **__p__pgmptr(void);

#define _wpgmptr  (*__p__wpgmptr())
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t **__p__wpgmptr(void);

#else  /* ! __MSVCRT__; thus CRTDLL */

# ifndef __DECLSPEC_SUPPORTED
# define _pgmptr  (*_imp___pgmptr_dll)
extern char **__imp__pgmptr_dll;

# else  /* __DECLSPEC_SUPPORTED */

# define _pgmptr _pgmptr_dll
__MINGW_IMPORT  char *_pgmptr_dll;
/* no wide version in CRTDLL */

# endif /* __DECLSPEC_SUPPORTED */
#endif	/* CRTDLL */

/* This variable determines the default file mode.
 * TODO: Which flags work?
 */
#if !defined (__DECLSPEC_SUPPORTED) || defined (__IN_MINGW_RUNTIME)

#ifdef __MSVCRT__
#define _fmode  (*_imp___fmode)
extern int *_imp___fmode;
#else
/* CRTDLL */
#define _fmode  (*_imp___fmode_dll)
extern int *_imp___fmode_dll;
#endif

#else  /* __DECLSPEC_SUPPORTED */
#ifdef __MSVCRT__
__MINGW_IMPORT  int _fmode;

#else  /* ! __MSVCRT__ */
#define _fmode	_fmode_dll
__MINGW_IMPORT  int _fmode_dll;

#endif  /* !__MSVCRT__ */
#endif  /* __DECLSPEC_SUPPORTED */
#endif  /* !__STRICT_ANSI__ */

_CRTIMP __cdecl __MINGW_NOTHROW  int atoi (const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  long atol (const char *);

_CRTIMP __cdecl __MINGW_NOTHROW  double strtod (const char *, char **);
_CRTIMP __cdecl __MINGW_NOTHROW  double atof (const char *);

#if !defined (__STRICT_ANSI__)
_CRTIMP __cdecl __MINGW_NOTHROW  double _wtof (const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  int _wtoi (const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  long _wtol (const wchar_t *);
#endif

#if __USE_MINGW_ANSI_STDIO
/* Microsoft's strtod() and atof() implementations, (in MSVCRT.DLL),
 * mishandle infinities and NaNs; on the basis that this conditional
 * exposes a more ISO-C conforming printf() I/O family implementaion,
 * we substitute a similarly more conforming implementation for each
 * of this pair of (somewhat related) functions.
 *
 * Note that we provide neither __JMPSTUB__ nor __LIBIMPL__ external
 * equivalents for either of these two inline functions, because they
 * would conflict with the runtime DLL implementations; users needing
 * an address reference for either must provide an equivalent of the
 * inline implementation, as non-inlined within their own code.
 */
extern __cdecl __MINGW_NOTHROW
double __strtod (const char *__restrict__, char **__restrict__);

__CRT_ALIAS __cdecl __MINGW_NOTHROW
double strtod (const char *__restrict__ __nptr, char **__restrict__ __endptr)
{ return __strtod( __nptr, __endptr ); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW
double atof (const char *__nptr) { return __strtod( __nptr, NULL ); }

#endif  /* __USE_MINGW_ANSI_STDIO */

#ifdef _ISOC99_SOURCE
/* Irrespective of requested standards conformity, where MSVCRT.DLL
 * falls short, ISO-C99 offers this pair of alternative return type
 * specific variants of strtod(), which MSVCRT.DLL does not, but we
 * do, in libmingwex.a:
 */
__cdecl __MINGW_NOTHROW
float strtof (const char *__restrict__, char **__restrict__);

__cdecl __MINGW_NOTHROW
long double strtold (const char *__restrict__, char **__restrict__);
#endif  /* _ISOC99_SOURCE */

_CRTIMP __cdecl __MINGW_NOTHROW  long strtol (const char *, char **, int);
_CRTIMP __cdecl __MINGW_NOTHROW  unsigned long strtoul (const char *, char **, int);

#endif	/* _STDLIB_H only */
#if ! (defined _STDLIB_H && defined _WCHAR_H)
/* Prototypes which are to be declared both here, in <stdlib.h>,
 * and also in <wchar.h>; declare them here, such that they may be
 * selectively included by <wchar.h>.
 */
_CRTIMP __cdecl __MINGW_NOTHROW
long wcstol (const wchar_t *, wchar_t **, int);

_CRTIMP __cdecl __MINGW_NOTHROW
unsigned long wcstoul (const wchar_t *, wchar_t **, int);

_CRTIMP __cdecl __MINGW_NOTHROW  double wcstod (const wchar_t *, wchar_t **);

/* The following MinGW specific alternatives to wcstod(), which may
 * offer more robust performance than the MSVCRT.DLL implementation,
 * are provided in libmingwex.a; (the float and long double variants
 * are simply aliases for the ISO-C99 equivalents which follow).
 */
__cdecl __MINGW_NOTHROW
double __mingw_wcstod (const wchar_t *__restrict__, wchar_t **__restrict__);

__cdecl __MINGW_NOTHROW
float __mingw_wcstof (const wchar_t *__restrict__, wchar_t **__restrict__);

__cdecl __MINGW_NOTHROW
long double __mingw_wcstold (const wchar_t *__restrict__, wchar_t **__restrict__);

#ifdef _ISOC99_SOURCE
/* Variants on wcstod(), specified by ISO-C99; once again, MSVCRT.DLL
 * doesn't have them, but we offer them in libmingwex.a
 */
__cdecl __MINGW_NOTHROW
float wcstof (const wchar_t *__restrict__, wchar_t **__restrict__);

__cdecl __MINGW_NOTHROW
long double wcstold (const wchar_t *__restrict__, wchar_t **__restrict__);
#endif  /* _ISOC99_SOURCE */

#ifdef __MSVCRT__
#if __MSVCRT_VERSION__ >= __MSVCR70_DLL || _WIN32_WINNT >= _WIN32_WINNT_WINXP
/* This pair of wide character equivalents for ISO-C99's strtoll() and
 * strtoull() require either WinXP (or later), or a non-free MSVC runtime
 * from MSVCR70.DLL onwards...
 */
_CRTIMP __cdecl __MINGW_NOTHROW
__int64 _wcstoi64(const wchar_t *, wchar_t **, int);

_CRTIMP __cdecl __MINGW_NOTHROW
unsigned __int64 _wcstoui64(const wchar_t *, wchar_t **, int);

#endif	/* WinXP || MSVCR70.DLL || later */

#if __MSVCRT_VERSION__ >= __MSVCR80_DLL || _WIN32_WINNT >= _WIN32_WINNT_VISTA
/* ...while the following pair require Win-Vista (or later), or non-free
 * MSVCRT runtime from MSVCR80.DLL onwards; they also require...
 */
#ifndef __have_typedef_locale_t
/* ...this opaque data type, which we may obtain by selective inclusion
 * from <locale.h>.  (Note that this may render them unusable for users of
 * MSVCRT.DLL; see the explanation in <locale.h>, regarding the difficulty
 * in creating, or otherwise acquiring a reference to, a _locale_t object,
 * notwithstanding the availability of the functions in MSVCRT.DLL, from
 * the release of Win-Vista onwards).
 */
#define __need_locale_t
#endif	/* !__have_typedef_locale_t */

_CRTIMP __cdecl __MINGW_NOTHROW
__int64 _wcstoi64_l(const wchar_t *, wchar_t **, int, _locale_t);

_CRTIMP __cdecl __MINGW_NOTHROW
unsigned __int64 _wcstoui64_l(const wchar_t *, wchar_t **, int, _locale_t);

#endif	/* Win-Vista || MSVCR80.DLL || later */

_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *_wgetenv (const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  int _wputenv (const wchar_t *);

_CRTIMP __cdecl __MINGW_NOTHROW
void _wsearchenv (const wchar_t *, const wchar_t *, wchar_t *);

_CRTIMP __cdecl __MINGW_NOTHROW  int _wsystem (const wchar_t *);

_CRTIMP __cdecl __MINGW_NOTHROW
void _wmakepath (wchar_t *, const wchar_t *, const wchar_t *, const wchar_t *,
    const wchar_t *
  );

_CRTIMP __cdecl __MINGW_NOTHROW
void _wsplitpath (const wchar_t *, wchar_t *, wchar_t *, wchar_t *, wchar_t *);

_CRTIMP __cdecl __MINGW_NOTHROW
wchar_t *_wfullpath (wchar_t *, const wchar_t *, size_t);

#endif	/* __MSVCRT__ */
#endif	/* _STDLIB_H || _WCHAR_H */

#ifdef _STDLIB_H  /* <stdlib.h> only */
_CRTIMP __cdecl __MINGW_NOTHROW  size_t wcstombs (char *, const wchar_t *, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int wctomb (char *, wchar_t);

_CRTIMP __cdecl __MINGW_NOTHROW  int mblen (const char *, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  size_t mbstowcs (wchar_t *, const char *, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int mbtowc (wchar_t *, const char *, size_t);

_CRTIMP __cdecl __MINGW_NOTHROW  int rand (void);
_CRTIMP __cdecl __MINGW_NOTHROW  void srand (unsigned int);

/* rand() is devoid of entropy, and is thus a mediocre pseudo-random number
 * generator.  Microsoft do offer a better quality (bogusly dubbed as a more
 * secure) PRNG, in the guise of rand_s(), but it
 *
 *   1) must be explicitly enabled, by user defined feature test macro;
 */
#ifdef _CRT_RAND_S
/*
 *   2) is not supported on Win9x, nor any WinNT version prior to WinXP;
 *   3) on WinXP, requires linking with non-free MSVCR80.DLL, or later;
 *   4) is provided by MSVCRT.DLL, only from Vista onward.
 */
#if __MSVCRT_VERSION__ >= __MSVCR80_DLL || _WIN32_WINNT >= _WIN32_WINNT_VISTA

_CRTIMP __cdecl __MINGW_NOTHROW  int rand_s (unsigned int *);

#endif	/* Win-Vista || MSVCR80.DLL || later */
#endif	/* _CRT_RAND_S enabled */

_CRTIMP __cdecl __MINGW_NOTHROW  void abort (void) __MINGW_ATTRIB_NORETURN;
_CRTIMP __cdecl __MINGW_NOTHROW  void exit (int) __MINGW_ATTRIB_NORETURN;

/* Note: this is in startup code, not imported directly from the runtime DLL
 */
int __cdecl __MINGW_NOTHROW atexit (void (*)(void));

_CRTIMP __cdecl __MINGW_NOTHROW  int system (const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  char *getenv (const char *);

#ifndef __STRICT_ANSI__
/* For GNU compatibility, in addition to the standard memory allocation
 * functions (declared below), we also include the non-standard alloca()
 * API declarations here, in accordance with GNU convention.
 */
/*
 * alloca.h
 *
 * Declarations for the alloca() function API, conforming to both GNU and
 * Microsoft's implementation conventions.
 *
 *
 * $Id: alloca.h,v b3d874172359 2019/07/01 20:48:01 keith $
 *
 * Written by Keith Marshall <keith@users.osdn.me>
 * Copyright (C) 2018, 2019, MinGW.org Project.
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef _ALLOCA_H
#define _ALLOCA_H
/* Microsoft requires the alloca() API to be declared in <malloc.h>;
 * GNU declares it in <alloca.h>, with default inclusion by <stdlib.h>
 * when !__STRICT_ANSI__.  To achieve compatibility with both, we will
 * define it in the GNU manner, conditionally including this file when
 * reading <stdlib.h>, and UNCONDITIONALLY including it in <malloc.h>
 */
#ifdef __GNUC__
#pragma GCC system_header
/* This implementation is unsupported, for any compiler other than GCC,
 * (which is the standard MinGW compiler, in any case); all MinGW source
 * may assume that <_mingw.h> has been included, so ensure that it is.
 */
#define __need_size_t
#if defined _GNU_SOURCE || ! defined _NO_OLDNAMES
/* This is the GNU standard API; it is also compatible with Microsoft's
 * original, but now deprecated, OLDNAMES naming convention.
 */
#undef alloca
void *alloca( size_t );
#define alloca( __request )  __builtin_alloca( __request )
#endif	/* _GNU_SOURCE || !_NO_OLDNAMES */

/* This represents the same API, but conforms to Microsoft's currently
 * preferred naming convention.
 */
#undef _alloca
void *_alloca( size_t );
#define _alloca( __request )  __builtin_alloca( __request )

_END_C_DECLS

#endif	/* __GNUC__ */
#endif	/* !_ALLOCA_H: $RCSfile: alloca.h,v $: end of file */
 #endif	/* !__STRICT_ANSI__ */

_CRTIMP __cdecl __MINGW_NOTHROW  void *calloc (size_t, size_t) __MINGW_ATTRIB_MALLOC;
_CRTIMP __cdecl __MINGW_NOTHROW  void *malloc (size_t) __MINGW_ATTRIB_MALLOC;
_CRTIMP __cdecl __MINGW_NOTHROW  void *realloc (void *, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  void free (void *);

/* The following pair of MinGW alternatives to realloc() and free() are
 * always suitable as substitutes for their MSVCRT.DLL counterparts; the
 * advantage of such substitutions is that these alternatives are able to
 * operate on heap memory which has been allocated by the MinGW aligned
 * memory allocation API functions, (but NOT the corresponding Microsoft
 * functions), in addition to memory allocated by malloc() or calloc().
 */
__cdecl __MINGW_NOTHROW  void *__mingw_realloc (void *, size_t);
__cdecl __MINGW_NOTHROW  void __mingw_free (void *);

/* Since MinGW's __mingw_free() and __mingw_realloc() are able to
 * operate transparently on pointers returned by any of Microsoft's
 * heap allocators, except their over-aligned variants, just as they
 * operate on pointers returned by MinGW's over-aligned allocators,
 * and all of ISO-C11, C++17, and POSIX.1 require this capability,
 * always prefer these replacements for free() and realloc().
 */
__JMPSTUB__(( LIB = memalign, FUNCTION = free ))
__CRT_ALIAS __cdecl __MINGW_NOTHROW  void free (void *__ptr)
{ __mingw_free (__ptr); }

__JMPSTUB__(( LIB = memalign, FUNCTION = realloc ))
__CRT_ALIAS __cdecl __MINGW_NOTHROW  void *realloc (void *__ptr, size_t __want)
{ return __mingw_realloc (__ptr, __want); }

#if __STDC_VERSION__ >= 201112L || __cplusplus >= 201703L
/* ISO-C99 adds support for over-aligned heap memory allocation, by use
 * of the aligned_alloc() function, (which was subsequently incorporated
 * into ISO-C++17 as std::aligned_alloc()); we may conveniently support
 * this by use of MinGW's __mingw_aligned_offset_malloc(), which is
 * nominally declared in <malloc.h>, and reproduced here:
 */
__cdecl __MINGW_NOTHROW __MINGW_ATTRIB_MALLOC
void *__mingw_aligned_offset_malloc (size_t, size_t, size_t);

__CRT_ALIAS __LIBIMPL__(( LIB = memalign, FUNCTION = aligned_alloc ))

__cdecl __MINGW_NOTHROW __MINGW_ATTRIB_MALLOC
void *aligned_alloc (size_t __alignment, size_t __want)
{ return __mingw_aligned_offset_malloc( __want, __alignment, (size_t)(0) ); }

/* For the ISO-C++17 case, we need to ensure that the feature test
 * macro _GLIBCXX_HAVE_ALIGNED_ALLOC is defined, with non-zero value;
 * (it is interpreted in <cstdlib>, but only for C++17 and later).
 */
#undef  _GLIBCXX_HAVE_ALIGNED_ALLOC
#define _GLIBCXX_HAVE_ALIGNED_ALLOC  1
#endif	/* ISO-C11 || ISO-C++17 */

#if _POSIX_C_SOURCE >= 200112L
/* POSIX.1-2001 supports an (earlier) alternative to the preceding
 * ISO-C11 aligned_alloc(), namely posix_memalign().  Once again, we
 * may conveniently use __mingw_aligned_offset_malloc() to implement
 * this, (duplicating its prototype once again, just in case we did
 * not implement the ISO-C11 function).
 */
__cdecl __MINGW_NOTHROW __MINGW_ATTRIB_MALLOC
void *__mingw_aligned_offset_malloc (size_t, size_t, size_t);

__CRT_ALIAS __LIBIMPL__(( LIB = memalign, FUNCTION = memalign ))

/* posix_memalign() differs semantically from aligned_alloc(), in
 * returning a status code, which is zero on success, or the value
 * of errno on failure, with the allocated memory pointer returned
 * via a reference parameter.  Normally, the reference to errno as
 * a possible return value would preclude inline implementation of
 * this function, but since Microsoft gratuitously defines errno
 * here, in <stdlib.h>, as well as in <errno.h>, this is okay.
 */
__cdecl __MINGW_NOTHROW
int posix_memalign (void **__p, size_t __alignment, size_t __want)
{ if( sizeof (void *) > __alignment ) __alignment = (sizeof (void *) << 1) - 1;
  *__p = __mingw_aligned_offset_malloc (__want, __alignment, (size_t)(0));
  return (*__p == NULL) ? errno : 0;
}
#endif	/* POSIX.1-2001 */

/* bsearch() and qsort() are declared both here, in <stdlib.h>, and in
 * non-ANSI header <search.h>; we reproduce these declarations in both,
 * with no attempt to guard them, so the compiler may verify that they
 * are consistent, if both headers are included.
 */
_CRTIMP __cdecl  void *bsearch
(const void *, const void *, size_t, size_t, int (*)(const void *, const void *));

_CRTIMP __cdecl  void qsort
(void *, size_t, size_t, int (*)(const void *, const void *));

_CRTIMP __cdecl __MINGW_NOTHROW  int abs (int) __MINGW_ATTRIB_CONST;
_CRTIMP __cdecl __MINGW_NOTHROW  long labs (long) __MINGW_ATTRIB_CONST;

/* div_t and ldiv_t are structures used to return the results of div()
 * and ldiv() functions.
 *
 * NOTE: div() and ldiv() appear not to work correctly unless
 *       -fno-pcc-struct-return is specified. This is included in the
 *       mingw32 specs file.
 */
typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;

_CRTIMP __cdecl __MINGW_NOTHROW  div_t div (int, int) __MINGW_ATTRIB_CONST;
_CRTIMP __cdecl __MINGW_NOTHROW  ldiv_t ldiv (long, long) __MINGW_ATTRIB_CONST;

#if !defined __STRICT_ANSI__ || (defined _ISOC99_SOURCE && !defined __NO_INLINE__)
/* Although not nominally valid in "__STRICT_ANSI__" mode, when compiling C99
 * source, we use Microsoft's _exit() function to facilitate our provision of
 * an inline implementation of ISO-C99's _Exit() function.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  void _exit (int) __MINGW_ATTRIB_NORETURN;

#ifdef __MSVCRT__
/* Similarly, we use Microsoft's MSVCRT.DLL specific _atoi64() function,
 * to facilitate an inline implementation of ISO-C99's atoll() function.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  __int64 _atoi64 (const char *);

#endif	/* __MSVCRT__ */
#endif	/* !__STRICT_ANSI__ || (_ISOC99_SOURCE && !__NO_INLINE__) */

#if !defined (__STRICT_ANSI__)
/* NOTE: Officially the three following functions are obsolete. The Win32 API
 *       functions SetErrorMode, Beep and Sleep are their replacements.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  void _beep (unsigned int, unsigned int) __MINGW_ATTRIB_DEPRECATED;
/* Not to be confused with  _set_error_mode (int).  */
_CRTIMP __cdecl __MINGW_NOTHROW  void _seterrormode (int) __MINGW_ATTRIB_DEPRECATED;
_CRTIMP __cdecl __MINGW_NOTHROW  void _sleep (unsigned long) __MINGW_ATTRIB_DEPRECATED;

/* _onexit is a Microsoft extension. Use atexit for portability. */
/* Note: This is in startup code, not imported directly from dll */
typedef  int (* _onexit_t)(void);
__cdecl __MINGW_NOTHROW  _onexit_t _onexit( _onexit_t );

_CRTIMP __cdecl __MINGW_NOTHROW  int _putenv (const char *);
_CRTIMP __cdecl __MINGW_NOTHROW
void _searchenv (const char *, const char *, char *);

_CRTIMP __cdecl __MINGW_NOTHROW  char *_ecvt (double, int, int *, int *);
_CRTIMP __cdecl __MINGW_NOTHROW  char *_fcvt (double, int, int *, int *);
_CRTIMP __cdecl __MINGW_NOTHROW  char *_gcvt (double, int, char *);

_CRTIMP __cdecl __MINGW_NOTHROW
void _makepath (char *, const char *, const char *, const char *, const char *);

_CRTIMP __cdecl __MINGW_NOTHROW
void _splitpath (const char *, char *, char *, char *, char *);

_CRTIMP __cdecl __MINGW_NOTHROW  char *_fullpath (char*, const char*, size_t);

_CRTIMP __cdecl __MINGW_NOTHROW  char *_itoa (int, char *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  char *_ltoa (long, char *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  char *_ultoa(unsigned long, char *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *_itow (int, wchar_t *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *_ltow (long, wchar_t *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *_ultow (unsigned long, wchar_t *, int);

#ifdef __MSVCRT__
_CRTIMP __cdecl __MINGW_NOTHROW  char* _i64toa (__int64, char *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  char* _ui64toa (unsigned __int64, char *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  __int64 _wtoi64 (const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t* _i64tow (__int64, wchar_t *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t* _ui64tow (unsigned __int64, wchar_t *, int);

_CRTIMP __cdecl __MINGW_NOTHROW  unsigned int (_rotl)(unsigned int, int) __MINGW_ATTRIB_CONST;
_CRTIMP __cdecl __MINGW_NOTHROW  unsigned int (_rotr)(unsigned int, int) __MINGW_ATTRIB_CONST;
_CRTIMP __cdecl __MINGW_NOTHROW  unsigned long (_lrotl)(unsigned long, int) __MINGW_ATTRIB_CONST;
_CRTIMP __cdecl __MINGW_NOTHROW  unsigned long (_lrotr)(unsigned long, int) __MINGW_ATTRIB_CONST;

_CRTIMP __cdecl __MINGW_NOTHROW  int _set_error_mode (int);

# define _OUT_TO_DEFAULT	0
# define _OUT_TO_STDERR 	1
# define _OUT_TO_MSGBOX 	2
# define _REPORT_ERRMODE	3

# if __MSVCRT_VERSION__ >= __MSVCR80_DLL
#  ifndef _UINTPTR_T_DEFINED
#   define _UINTPTR_T_DEFINED
#   ifdef _WIN64
      typedef unsigned __int64 uintptr_t;
#   else
      typedef unsigned int uintptr_t;
#   endif
#  endif

_CRTIMP __cdecl __MINGW_NOTHROW
unsigned int _set_abort_behavior (unsigned int, unsigned int);

/* These masks work with msvcr80.dll version 8.0.50215.44 (a beta release).
 */
#  define _WRITE_ABORT_MSG	1
#  define _CALL_REPORTFAULT	2

typedef void
(* _invalid_parameter_handler) (
    const wchar_t *,
    const wchar_t *,
    const wchar_t *,
    unsigned int,
    uintptr_t);
_invalid_parameter_handler _set_invalid_parameter_handler (_invalid_parameter_handler);

# endif /* __MSVCRT_VERSION__ >= __MSVCR80_DLL */
#endif	/* __MSVCRT__ */

#ifndef _NO_OLDNAMES
_CRTIMP __cdecl __MINGW_NOTHROW  int putenv (const char*);
_CRTIMP __cdecl __MINGW_NOTHROW  void searchenv (const char*, const char*, char*);

_CRTIMP __cdecl __MINGW_NOTHROW  char* itoa (int, char*, int);
_CRTIMP __cdecl __MINGW_NOTHROW  char* ltoa (long, char*, int);

#ifndef _UWIN
_CRTIMP __cdecl __MINGW_NOTHROW  char* ecvt (double, int, int*, int*);
_CRTIMP __cdecl __MINGW_NOTHROW  char* fcvt (double, int, int*, int*);
_CRTIMP __cdecl __MINGW_NOTHROW  char* gcvt (double, int, char*);

#endif	/* ! _UWIN */
#endif	/* ! _NO_OLDNAMES */
#endif	/* ! __STRICT_ANSI__ */

#ifdef _ISOC99_SOURCE
/* Further APIs required to support ISO-C99, but missing from MSVCRT.DLL;
 * we provide them in libmingwex.a:
 *
 * ISO-C99 name for _exit()
 */
__cdecl __MINGW_NOTHROW  void _Exit(int) __MINGW_ATTRIB_NORETURN;

#ifndef __NO_INLINE__
__CRT_INLINE __JMPSTUB__(( FUNCTION = _Exit, REMAPPED = _exit ))
__cdecl __MINGW_NOTHROW  void _Exit( int __status ){ _exit (__status); }
#endif

typedef struct { long long quot, rem; } lldiv_t;
__cdecl __MINGW_NOTHROW  lldiv_t lldiv (long long, long long) __MINGW_ATTRIB_CONST;

__cdecl __MINGW_NOTHROW  long long llabs (long long);

#ifndef __NO_INLINE__
__CRT_INLINE
/* No JMPSTUB or LIBIMPL reference here -- we provide a free-standing
 * implementation, along with imaxabs(), in mingwex/imaxabs.c
 */
__cdecl __MINGW_NOTHROW  long long llabs( long long __j )
{ return __j >= 0 ? __j : -__j; }
#endif

__cdecl __MINGW_NOTHROW
long long strtoll (const char *__restrict__, char **__restrict, int);

__cdecl __MINGW_NOTHROW
unsigned long long strtoull (const char *__restrict__, char **__restrict__, int);

#ifdef __MSVCRT__
/* MSVCRT.DLL does not provide ISO-C99's atoll() function, but it does
 * provide an analogue, in _atoi64(); map it accordingly.
 */
__cdecl __MINGW_NOTHROW  long long atoll (const char *);

#ifndef __NO_INLINE__
__CRT_INLINE __JMPSTUB__(( FUNCTION = atoll, REMAPPED = _atoi64 ))
__cdecl __MINGW_NOTHROW  long long atoll (const char * _c){ return _atoi64 (_c); }
#endif

#endif  /* __MSVCRT__ */
#endif  /* _ISOC99_SOURCE */

#if defined __MSVCRT__ && ! defined __STRICT_ANSI__
#if __MSVCRT_VERSION__ >= __MSVCR70_DLL || _WIN32_WINNT >= _WIN32_WINNT_WINXP
/* Microsoft specific alternatives to ISO-C99 strtoll() and strtoull(); the
 * first pair require WinXP (or later) or non-free MSVCR70.DLL onwards...
 */
_CRTIMP __cdecl __MINGW_NOTHROW
__int64 _strtoi64(const char*, char **, int);

_CRTIMP __cdecl __MINGW_NOTHROW
unsigned __int64 _strtoui64(const char*, char **, int);

#endif	/* WinXP || MSVCR70.DLL || later */
#if __MSVCRT_VERSION__ >= __MSVCR80_DLL || _WIN32_WINNT >= _WIN32_WINNT_VISTA
/* ...while the following pair require Win-Vista (or later), or non-free
 * MSVCR80.DLL onwards; (note that, like their wide character counterparts,
 * they may actually be unusable without MSVCR80.DLL onwards, because of
 * the difficulty in acquiring a reference to a _locale_t object).
 */
_CRTIMP __cdecl __MINGW_NOTHROW
__int64 _strtoi64_l(const char *, char **, int, _locale_t);

_CRTIMP __cdecl __MINGW_NOTHROW
unsigned __int64 _strtoui64_l(const char *, char **, int, _locale_t);

#endif	/* Win-Vista || MSVCR80.DLL || later */

/* Type long long analogues for MSVCRT.DLL specific type long functions;
 * none are actually provided by any version of MSVCRT.DLL, with names as
 * specified here, but rather as called by the inline functions used to
 * implement them, (i.e. the REMAPPED name specified in each__JMPSTUB__
 * function reference respectively).
 *
 * FIXME: Not one of these is specified by ISO-C99, nor by POSIX, either;
 * is there really any justification for us to specify them at all?  For
 * the time being, declare as deprecated; perhaps remove later?
 */
__cdecl __MINGW_NOTHROW __MINGW_ATTRIB_DEPRECATED  long long wtoll (const wchar_t *);
__cdecl __MINGW_NOTHROW __MINGW_ATTRIB_DEPRECATED  char *lltoa (long long, char *, int);
__cdecl __MINGW_NOTHROW __MINGW_ATTRIB_DEPRECATED  char *ulltoa (unsigned long long , char *, int);
__cdecl __MINGW_NOTHROW __MINGW_ATTRIB_DEPRECATED  wchar_t *lltow (long long, wchar_t *, int);
__cdecl __MINGW_NOTHROW __MINGW_ATTRIB_DEPRECATED  wchar_t *ulltow (unsigned long long, wchar_t *, int);

#ifndef __NO_INLINE__
/* None of these functions would exist at all, without either these inline
 * implementations, or their respective __JMPSTUB__ equivalents.
 */
__CRT_INLINE __JMPSTUB__(( FUNCTION = lltoa, REMAPPED = _i64toa ))
__cdecl __MINGW_NOTHROW  char *lltoa (long long __n, char * __c, int __i)
{ return _i64toa (__n, __c, __i); }

__CRT_INLINE __JMPSTUB__(( FUNCTION = ulltoa, REMAPPED = _ui64toa ))
__cdecl __MINGW_NOTHROW  char *ulltoa (unsigned long long __n, char * __c, int __i)
{ return _ui64toa (__n, __c, __i); }

__CRT_INLINE __JMPSTUB__(( FUNCTION = wtoll, REMAPPED = _wtoi64 ))
__cdecl __MINGW_NOTHROW  long long wtoll (const wchar_t * __w){ return _wtoi64 (__w); }

__CRT_INLINE __JMPSTUB__(( FUNCTION = lltow, REMAPPED = _i64tow ))
__cdecl __MINGW_NOTHROW  wchar_t *lltow (long long __n, wchar_t * __w, int __i)
{ return _i64tow (__n, __w, __i); }

__CRT_INLINE __JMPSTUB__(( FUNCTION = ulltow, REMAPPED = _ui64tow ))
__cdecl __MINGW_NOTHROW  wchar_t *ulltow (unsigned long long __n, wchar_t * __w, int __i)
{ return _ui64tow (__n, __w, __i); }

#endif  /* ! __NO_INLINE__ */
#endif  /* __MSVCRT__ && ! __STRICT_ANSI__ */

/* POSIX/BSD extensions in libmingwex.a; these should be exposed only on
 * the basis of appropriate POSIX or BSD specific feature tests...
 *
 * mkstemp(3) function support; added per feature request #2003.
 * POSIX wants _XOPEN_SOURCE >= 500, (implying _POSIX_C_SOURCE >= 200112L).
 */
#if _POSIX_C_SOURCE >= 200112L

__cdecl __MINGW_NOTHROW  int mkstemp (char *);
__cdecl __MINGW_NOTHROW  int __mingw_mkstemp (int, char *);

/* On POSIX platforms, programmers may adopt an idiom such as:
 *
 *   if( mkstemp( template ) >= 0 )
 *   { unlink( template );
 *     . . .
 *   }
 *
 * to ensure that a temporary file does NOT persist after it is
 * closed; MS-Windows does not allow such use of unlink(2), while
 * the file remains open.  Thus, MS-Windows programmers must take
 * extra care, to close and unlink temporary files AFTER use, if
 * similar behaviour is desired.
 *
 * To mitigate this MS-Windows limitation, we provide support for
 * an alternative, MinGW specific idiom:
 *
 *   #include <fcntl.h>
 *
 *   _MKSTEMP_SETMODE( _O_TEMPORARY );
 *   if( mkstemp( template ) >= 0 )
 *   {
 *     . . .
 *   }
 *
 * to achieve a similar effect to that of the above POSIX idiom; the
 * following macros are a MinGW specific extension, to facilite such
 * use of _O_TEMPORARY, (in addition to the POSIX required attributes),
 * when creating the temporary file.  Note that they require <fcntl.h>,
 * which <stdlib.h> should NOT automatically include; we leave it to
 * the user to explicitly include it, if using _MKSTEMP_SETMODE.
 */
#define _MKSTEMP_INVOKE       0
#define _MKSTEMP_DEFAULT     _O_CREAT | _O_EXCL | _O_RDWR
#define _MKSTEMP_SETMODE(M) __mingw_mkstemp( _MKSTEMP_DEFAULT | (M), NULL )

#ifndef _NO_OLDNAMES
#define MKSTEMP_SETMODE(M)  __mingw_mkstemp( _MKSTEMP_DEFAULT | (M), NULL )
#endif

__CRT_ALIAS __LIBIMPL__(( FUNCTION = mkstemp ))
__cdecl __MINGW_NOTHROW  int mkstemp (char *__filename_template)
{ return __mingw_mkstemp( _MKSTEMP_INVOKE, __filename_template ); }

#endif	/* _POSIX_C_SOURCE >= 200112L (for mkstemp()) */

/* mkdtemp(3) function support: added as adjunct to feature request #2003.
 * POSIX wants _XOPEN_SOURCE >= 700, (implying _POSIX_C_SOURCE >= 200809L).
 */
#if _POSIX_C_SOURCE >= 200809L

__cdecl __MINGW_NOTHROW  char *mkdtemp (char *);
__cdecl __MINGW_NOTHROW  char *__mingw_mkdtemp (char *);

__CRT_ALIAS __JMPSTUB__(( FUNCTION = mkdtemp ))
__cdecl __MINGW_NOTHROW  char *mkdtemp (char *__dirname_template)
{ return __mingw_mkdtemp( __dirname_template ); }

#endif	/* _POSIX_C_SOURCE >= 200809L (for mkdtemp()) */

#if _POSIX_C_SOURCE >= 200112L
/* setenv() and unsetenv() are also available, from POSIX.1-2001 onwards.
 */
__cdecl __MINGW_NOTHROW  int setenv( const char *, const char *, int );
__cdecl __MINGW_NOTHROW  int unsetenv( const char * );

__cdecl __MINGW_NOTHROW  int __mingw_setenv( const char *, const char *, int );

__CRT_ALIAS __JMPSTUB__(( FUNCTION = setenv ))
__cdecl __MINGW_NOTHROW  int setenv( const char *__n, const char *__v, int __f )
{ return __mingw_setenv( __n, __v, __f ); }

__CRT_ALIAS __LIBIMPL__(( FUNCTION = unsetenv ))
__cdecl __MINGW_NOTHROW  int unsetenv( const char *__name )
{ return __mingw_setenv( __name, NULL, 1 ); }

#endif	/* _POSIX_C_SOURCE >= 200112L (for setenv()) */
#endif	/* _STDLIB_H */

_END_C_DECLS

#endif	/* ! RC_INVOKED */
#endif	/* ! _STDLIB_H: $RCSfile: stdlib.h,v $: end of file */
 /* ...we obtain prototypes for universally supported functions:
 *
 *  long wcstol (const wchar_t *, wchar_t **, int);
 *  unsigned long wcstoul (const wchar_t *, wchar_t **, int);
 *  double wcstod (const wchar_t *, wchar_t **);
 *
 * The following are Microsoft specific, and require MSCVRT.DLL,
 * or any of its non-free derivatives; they are not available to
 * applications which use CRTDLL.DLL:
 *
 *  wchar_t *_wgetenv (const wchar_t *);
 *  int _wputenv (const wchar_t *);
 *  void _wsearchenv (const wchar_t *, const wchar_t *, wchar_t *);
 *  int _wsystem (const wchar_t *);
 *  void _wmakepath (wchar_t *, const wchar_t *, const wchar_t *,
 *          const wchar_t *, const wchar_t *
 *        );
 *  void _wsplitpath (const wchar_t *, wchar_t *, wchar_t *,
 *          wchar_t *, wchar_t *
 *        );
 *  wchar_t *_wfullpath (wchar_t *, const wchar_t *, size_t);
 *
 * ...with this pair requiring either WinXP (or later), or one of
 * the non-free MSVC runtimes from MSVCR70.DLL onwards:
 *
 *  __int64 _wcstoi64 (const wchar_t *, wchar_t **, int);
 *  unsigned __int64 _wcstoui64 (const wchar_t *, wchar_t **, int);
 *
 *  ...and this pair requiring Win-Vista (or later), or a non-free
 *  MSVC runtime from MSVCR80.DLL onwards:
 *
 *  __int64 _wcstoi64_l (const wchar_t *, wchar_t **, int, _locale_t);
 *  unsigned __int64 _wcstoui64_l (const wchar_t *, wchar_t **,
 *          int, _locale_t);
 *        );
 *
 * ...while this pair are ISO-C99 standards, which are available
 * in libmingwex.a, but not in any version of MSVCRT.DLL, (nor in
 * any of its non-free derivatives prior to MSVCR120.DLL), nor in
 * CRTDLL.DLL:
 *
 *  float wcstof (const wchar_t *restrict, wchar_t **restrict);
 *  long double wcstold (const wchar_t *restrict, wchar_t **restrict);
 *
 *
 * while...
 */
#ifndef __STRICT_ANSI__
/* ...when NOT compiling with "__STRICT_ANSI__" conformity checking,
 * from...
 */
/*
 * direct.h
 *
 * Functions for manipulating paths and directories, (included from io.h),
 * and functions for manipulating the current drive assignment.
 *
 * $Id: direct.h,v ac537590ff03 2016/04/26 22:05:33 keithmarshall $
 *
 * Written by Colin Peters <colin@bird.fu.is.saga-u.ac.jp>
 * Copyright (C) 1997, 1999-2001, 2003, 2004, 2007, 2016, MinGW.org Project.
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice, this permission notice, and the following
 * disclaimer shall be included in all copies or substantial portions of
 * the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OF OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef _DIRECT_H
#pragma GCC system_header

/* In addition to inclusion in its own right, this header supports
 * selective inclusion by <wchar.h>; thus...
 */
#ifndef __WCHAR_H_SOURCED__
 /* ...we defer definition of the normal multiple inclusion guard,
  * until we know that this is NOT a selective inclusion request.
  */
#define _DIRECT_H

#define __DIRECT_H_SOURCED__
/* All MinGW headers are required to include <_mingw.h>; additionally,
 * much of the content which we need here is defined in <io.h>, but we
 * also need the declaration of the _getdiskfree() function prototype,
 * and the definition for its associated _diskfree_t data structure,
 * from <dos.h>; thus, we may simply include <dos.h> here, and let
 * it take care of including both <mingw.h> and <io.h> for us.
 */
/*
 * dos.h
 *
 * Functions and structures inherited from MS-DOS.
 *
 * $Id: dos.h,v b79b7fd3032b 2016/09/13 20:14:13 keithmarshall $
 *
 * Written by Jan-Jaap van der Heijden
 * Copyright (C) 1997-1999, 2001-2004, 2007, 2016, MinGW.org Project.
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice, this permission notice, and the following
 * disclaimer shall be included in all copies or substantial portions of
 * the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OF OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef	_DOS_H
#pragma GCC system_header

/* This header supports selective inclusion by <direct.h>, for delegated
 * access to the content of <io.h>, and for declaration of the prototype
 * and associated data structure for the _getdiskfree() function; since
 * including <dos.h> in this manner does not make all of its content
 * visible, we defer definition of its multiple inclusion guard...
 */
#ifndef __DIRECT_H_SOURCED__
 /* ...until we have determined that this inclusion is NOT a selective
  * request from <direct.h>; in spite of it being obsolete, it appears
  * that the user may have included <dos.h> directly.
  */
#define	_DOS_H
/* If the user does include <dos.h> directly, we should raise an alert
 * to advise that <direct.h> is the preferred alternative; however, the
 * warning will interfere with the testsuite result...
 */
#ifndef __IN_MINGWRT_TESTSUITE__
/* ...so we suppress it in this specific instance.
 */
#warning "<dos.h> is obsolete; consider using <direct.h> instead."
#endif
#endif	/* !__DIRECT_H_SOURCED__ */

/* All MinGW headers are required to include <_mingw.h>; additionally,
 * for DOS file attributes, we must include <io.h>.  By unconditionally
 * including <io.h> here, we may delegate the inclusion of <_mingw.h> to
 * it, while also allowing <direct.h> to delegate responsibility for the
 * inclusion of both <_mingw.h> and <io.h> to us.
 */
/*
 * io.h
 *
 * System level I/O functions and types.
 *
 * $Id: io.h,v 4e77488c6712 2019/10/16 08:42:57 keith $
 *
 * Written by Colin Peters <colin@bird.fu.is.saga-u.ac.jp>
 * Copyright (C) 1997-2004, 2007, 2009, 2010, 2014-2016, 2019,
 *   MinGW.org Project.
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice, this permission notice, and the following
 * disclaimer shall be included in all copies or substantial portions of
 * the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OF OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 *
 * NOTE: The file manipulation functions provided by Microsoft seem to
 * work with either slash (/) or backslash (\) as the directory separator;
 * (this is consistent with Microsoft's own documentation, on MSDN).
 *
 */
#ifndef _IO_H
#pragma GCC system_header

/* Defer definition of the _IO_H multiple inclusion guard, to allow
 * for selective inclusion by <wchar.h>, (in which case we should
 * NOT define it).
 */
#ifndef __WCHAR_H_SOURCED__
#define _IO_H

/* All MinGW headers must include <_mingw.h>; we may do it here,
 * assuming that <wchar.h> will have already take care to do so in
 * the selective inclusion case.
 */
#endif	/* !__WCHAR_H_SOURCED__ */

/* This will give us intptr_t, which we need in ALL cases, whether
 * including <io.h> directly, or selectively via <wchar.h>; (note: we
 * use the #include "..." form here, to ensure that we read the type
 * definition directly from the stdint.h header located in the same
 * directory as this <io.h> file).
 */
#define __need_intptr_t
/*
 * stdint.h
 *
 * Integer type definitions, as prescribed by ISO-C9x Section 7.18
 * Based on ISO/IEC SC22/WG14 9899 Committee draft (SC22 N2794)
 *
 * $Id: stdint.h,v b8530dfcf7a9 2016/06/17 14:16:01 keithmarshall $
 *
 * Written by Danny Smith <danny_r_smith_2001@yahoo.co.nz>
 * Copyright (C) 2000-2002, 2004, 2005, 2007, 2009, 2016, MinGW.org Project.
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice, this permission notice, and the following
 * disclaimer shall be included in all copies or substantial portions of
 * the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OF OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef _STDINT_H
#pragma GCC system_header

/* To support selective definition of just intptr_t or uintptr_t,
 * we defer definition of the normal multiple inclusion guard macro,
 * until we've determined that neither selection is active.
 */
#if ! defined __need_intptr_t && ! defined __need_uintptr_t
#define _STDINT_H

/* All MinGW system headers are expected to include <_mingw.h>;
 * ensure that we have done so.
 */
#define __need_wint_t
#define __need_wchar_t
#define __need_intptr_t
#define __need_uintptr_t

#endif	/* !__need_intptr_t && !__need_uintptr_t */

/* 7.18.1.4  Integer types capable of holding object pointers.
 */
#if defined __need_intptr_t && ! defined __intptr_t
#define __intptr_t __intptr_t
#ifdef _WIN64
 typedef __int64 __intptr_t;
#else
 typedef int __intptr_t;
#endif
typedef __intptr_t intptr_t;

#endif	/* __need_intptr_t */
#undef __need_intptr_t

#if defined __need_uintptr_t && ! defined __uintptr_t
#define __uintptr_t __uintptr_t
#ifdef _WIN64
 typedef unsigned __int64 __uintptr_t;
#else
 typedef unsigned int __uintptr_t;
#endif
typedef __uintptr_t uintptr_t;

#endif	/* __need_uintptr_t */
#undef __need_uintptr_t

#ifdef  _STDINT_H
/* 7.18.1.5  Greatest-width integer types.
 */
typedef long long  intmax_t;
typedef unsigned long long uintmax_t;

/* 7.18.2  Limits of specified-width integer types.
 * (always defined in C, but C++ needs __STDC_LIMIT_MACROS)
 */
#if ! defined __cplusplus || defined __STDC_LIMIT_MACROS

/* 7.18.2.1  Limits of exact-width integer types.
 */
#define INT8_MIN		(-128)
#define INT16_MIN		(-32768)
#define INT32_MIN		(-2147483647 - 1)
#define INT64_MIN		(-9223372036854775807LL - 1)

#define INT8_MAX		127
#define INT16_MAX		32767
#define INT32_MAX		2147483647
#define INT64_MAX		9223372036854775807LL

#define UINT8_MAX		0xffU			/* 255U */
#define UINT16_MAX		0xffffU			/* 65535U */
#define UINT32_MAX		0xffffffffUL		/* 4294967295U */
#define UINT64_MAX		0xffffffffffffffffULL	/* 18446744073709551615ULL */

/* 7.18.2.2  Limits of minimum-width integer types.
 */
#define INT_LEAST8_MIN		INT8_MIN
#define INT_LEAST16_MIN 	INT16_MIN
#define INT_LEAST32_MIN 	INT32_MIN
#define INT_LEAST64_MIN 	INT64_MIN

#define INT_LEAST8_MAX		INT8_MAX
#define INT_LEAST16_MAX 	INT16_MAX
#define INT_LEAST32_MAX 	INT32_MAX
#define INT_LEAST64_MAX 	INT64_MAX

#define UINT_LEAST8_MAX 	UINT8_MAX
#define UINT_LEAST16_MAX	UINT16_MAX
#define UINT_LEAST32_MAX	UINT32_MAX
#define UINT_LEAST64_MAX	UINT64_MAX

/* 7.18.2.3  Limits of fastest minimum-width integer types.
 */
#define INT_FAST8_MIN		INT8_MIN
#define INT_FAST16_MIN		INT16_MIN
#define INT_FAST32_MIN		INT32_MIN
#define INT_FAST64_MIN		INT64_MIN

#define INT_FAST8_MAX		INT8_MAX
#define INT_FAST16_MAX		INT16_MAX
#define INT_FAST32_MAX		INT32_MAX
#define INT_FAST64_MAX		INT64_MAX

#define UINT_FAST8_MAX		UINT8_MAX
#define UINT_FAST16_MAX 	UINT16_MAX
#define UINT_FAST32_MAX 	UINT32_MAX
#define UINT_FAST64_MAX 	UINT64_MAX

/* 7.18.2.4  Limits of integer types capable of holding object pointers.
 */
#ifdef _WIN64
# define INTPTR_MIN		INT64_MIN
# define INTPTR_MAX		INT64_MAX
# define UINTPTR_MAX		UINT64_MAX
#else
# define INTPTR_MIN		INT32_MIN
# define INTPTR_MAX		INT32_MAX
# define UINTPTR_MAX		UINT32_MAX
#endif

/* 7.18.2.5  Limits of greatest-width integer types.
 */
#define INTMAX_MIN		INT64_MIN
#define INTMAX_MAX		INT64_MAX
#define UINTMAX_MAX		UINT64_MAX

/* 7.18.3  Limits of other integer types.
 */
#define PTRDIFF_MIN		INTPTR_MIN
#define PTRDIFF_MAX		INTPTR_MAX

#define SIG_ATOMIC_MIN		INTPTR_MIN
#define SIG_ATOMIC_MAX		INTPTR_MAX

#define SIZE_MAX		UINTPTR_MAX

/* The following pair are also defined in <wchar.h>, but leave them
 * unguarded, so that the compiler may check for consistency.
 */
#define WCHAR_MIN		0
#define WCHAR_MAX		0xffff /* UINT16_MAX */

/* wint_t is unsigned short for compatibility with MS runtime
 */
#define WINT_MIN		0
#define WINT_MAX		0xffff /* UINT16_MAX */

#endif	/* !__cplusplus || __STDC_LIMIT_MACROS */

/* 7.18.4  Macros for integer constants.
 * (always defined in C, but C++ needs __STDC_CONSTANT_MACROS)
 */
#if ! defined __cplusplus || defined __STDC_CONSTANT_MACROS

/* 7.18.4.1  Macros for minimum-width integer constants
 *
 * According to Douglas Gwyn <gwyn@arl.mil>:
 *  "This spec was changed in ISO/IEC 9899:1999 TC1; in ISO/IEC
 *  9899:1999 as initially published, the expansion was required
 *  to be an integer constant of precisely matching type, which
 *  is impossible to accomplish for the shorter types on most
 *  platforms, because C99 provides no standard way to designate
 *  an integer constant with width less than that of type int.
 *  TC1 changed this to require just an integer constant
 *  EXPRESSION with PROMOTED type".
 */
#define INT8_C(val)		val
#define UINT8_C(val)		val
#define INT16_C(val)		val
#define UINT16_C(val)		val

#define INT32_C(val)		val
#define UINT32_C(val)		val##U
#define INT64_C(val)		val##LL
#define UINT64_C(val)		val##ULL

/* 7.18.4.2  Macros for greatest-width integer constants.
 */
#define INTMAX_C(val)		INT64_C(val)
#define UINTMAX_C(val)		UINT64_C(val)

#endif  /* !__cplusplus || __STDC_CONSTANT_MACROS */
#endif	/* _STDINT_H */

#endif	/* !_STDINT_H: $RCSfile: stdint.h,v $: end of file */
 
/* Attributes of files as returned by _findfirst() et al.  MSDN is not
 * explicit about whether or not these should be defined when including
 * <wchar.h>, but since they complement the _wfindfirst() API, which is
 * declared there, it seems logical to make them visible in all cases
 * of <io.h> inclusion.
 */
#define _A_NORMAL	0x00000000
#define _A_RDONLY	0x00000001
#define _A_HIDDEN	0x00000002
#define _A_SYSTEM	0x00000004
#define _A_VOLID	0x00000008
#define _A_SUBDIR	0x00000010
#define _A_ARCH 	0x00000020

#ifndef RC_INVOKED

/* The maximum length of a file name.  It may be better to use the Windows'
 * GetVolumeInformation() function in preference to this constant, but hey,
 * this works!  In any case, we use this manifest constant when we declare
 * the _findfirst() API, so its definition must be visible in all places
 * where this, or any of its variants, is declared.
 *
 * Note that <stdio.h> also defines this, but we don't guard it, so that
 * the compiler has a chance to catch inconsistencies.
 */
#define FILENAME_MAX	(260)

/* We must define _fsize_t, but some compilers (including GCC prior to
 * version 4.0), may choke if we try to do so more than once...
 */
#if ! (defined _IO_H && defined _WCHAR_H) || defined __STRICT_ANSI__
 /* ...so DO NOT define it during direct <io.h> inclusion, (i.e. _IO_H
  * is defined), if <wchar.h> has already caused it to be defined, (i.e.
  * _WCHAR_H is ALSO defined, but __STRICT_ANSI__ is NOT).
  */
typedef	unsigned long	_fsize_t;
#endif	/* ! (_IO_H && _WCHAR_H) */

/* Functions for searching for files: _findfirst() sets errno to ENOENT,
 * and returns -1 if no match is found; otherwise it returns a handle to
 * be used in _findnext() and _findclose() calls. _findnext() may then be
 * used to identify further matches; it updates the search data, returning
 * zero, each time a further match is found, ultimately setting errno to
 * ENOENT, and returning -1 when no further match can be found.  When all
 * expected matches have been identified, _findclose() should be called,
 * to release the resources allocated to the search data.
 *
 * The API comprises several variants of the _findfirst() and _findnext()
 * functions, conforming generally to the usage model:
 *
 *  intptr_t handle = _findfirst (filespec, &search_data );
 *  if (handle >= (intptr_t)(0)) do { process search_data;
 *   } while (_findnext (handle, &search_data));
 *
 * where "filespec" represents a char *, or a wchar_t * specification,
 * (which may include wild cards), for a file name pattern to be matched,
 * and "search_data" represents a variant of the structure:
 */
#define __struct_finddata_t(__fd_time_t, __fd_size_t)			\
{ unsigned	attrib;		/* Attributes, see constants above. */	\
  __fd_time_t	time_create;						\
  __fd_time_t	time_access;	/* always midnight local time */	\
  __fd_time_t	time_write;						\
  __fd_size_t	size;							\
  __fd_name_t	name[FILENAME_MAX];	/* may include spaces. */	\
}

/* Time type and file size variations for __struct_finddata_t apply, for the
 * various functions comprising the file name search API, as tabulated below:
 *
 * Note: this is a reproduction of reference data as published in the MSDN
 * online documentation for the file name search API; it applies, specifically,
 * to the implementation of this API in the non-free run-time library versions
 * from MSVCR80.DLL onwards, (i.e. when __MSVCRT_VERSION__ is defined, and is
 * assigned a value >= 0x800).  When linking to the freely available MSVCRT.DLL
 * runtime, (__MSVCRT_VERSION__ should not be defined), or any earlier version
 * of the non-free run-time, the _USE_32BIT_TIME_T feature test is irrelevant;
 * the information presented in this table should be interpreted as if this
 * feature is always implicitly enabled.
 *
 *  Functions	       _USE_32BIT_TIME_T defined?    __fd_time_t     __fd_size_t
 *
 * _findfirst(),	Not defined			64-bit		32-bit
 * _wfindfirst()
 * _findfirst(),	Defined				32-bit		32-bit
 * _wfindfirst()
 *
 * _findfirst32(),	Not affected by the macro	32-bit		32-bit
 * _wfindfirst32()	definition
 *
 * _findfirst64(),	Not affected by the macro	64-bit		64-bit
 * _wfindfirst64()	definition
 *
 * _findfirsti64(),	Not defined			64-bit		64-bit
 * _wfindfirsti64()
 * _findfirsti64(),	Defined				32-bit		64-bit
 * _wfindfirsti64()
 *
 * _findfirst32i64(),	Not affected by the macro	32-bit		64-bit
 * _wfindfirst32i64()	definition
 *
 * _findfirst64i32(),	Not affected by the macro	64-bit		32-bit
 * _wfindfirst64i32()	definition
 *
 */
_BEGIN_C_DECLS

#ifdef _IO_H
#define __fd_name_t  char

/* The most universally available variants of the file name search
 * API employ either a generic representation of the related data, or
 * a variant in which the time stamps are represented generically, but
 * the file size is explicitly expressed as a 64-bit value.
 */
struct _finddata_t __struct_finddata_t (time_t, _fsize_t);
struct _finddatai64_t __struct_finddata_t (time_t, __int64);

/* Functions to manipulate data in either of these representations are
 * provided, as physical entities, in ALL versions of MSVCRT.DLL, and
 * in the non-free variants predating MSVCR80.DLL; (each such physical
 * function implementation interprets "generic" as 32-bit for both the
 * time_t and _fsize_t data fields).  From MSVCR80.DLL onward, there is
 * no physical implementation of these functions; they are emulated by
 * inline replacements (implemented below), which introduce ambiguity
 * in the interpretation of "generic", (noted as applicable): thus...
 */
#if __MSVCRT_VERSION__ < __MSVCR80_DLL
/* ...these physical function APIs are declared only when it is NOT
 * specified that MSVCR80.DLL or later is to be used.
 */
_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _findfirst (const char *, struct _finddata_t *);

_CRTIMP __cdecl __MINGW_NOTHROW
int _findnext (intptr_t, struct _finddata_t *);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _findfirsti64 (const char *, struct _finddatai64_t *);

_CRTIMP __cdecl __MINGW_NOTHROW
int _findnexti64 (intptr_t, struct _finddatai64_t *);

#endif	/* __MSVCRT_VERSION__ < __MSVCR80_DLL */

#if _WIN32_WINNT >= _WIN32_WINNT_WIN2K || __MSVCRT_VERSION__ >= __MSVCR61_DLL
/* The Win2K release of MSVCRT.DLL added a third variant of the API,
 * which had originally been introduced in MSVCR61.DLL; this variant
 * uses a data representation having both 64-bit time stamp values,
 * and 64-bit file size values.  (Note that there was no explictly
 * all 32-bit variant added at this point in the evolution of the
 * API; had there been, it would have been identically equivalent
 * to the original generic _findfirst()/_findnext() implementation).
 */
struct __finddata64_t __struct_finddata_t (__time64_t, __int64);
/*
 * Some MSDN documents, (particularly more recent documents), may
 * inconsistently refer to this structural type by the anomalous
 * name of _finddata64_t; support this anomaly.
 */
#define _finddata64_t  __finddata64_t

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _findfirst64 (const char *, struct __finddata64_t *);

_CRTIMP __cdecl __MINGW_NOTHROW
int _findnext64 (intptr_t, struct __finddata64_t *);

#if __MSVCRT_VERSION__ >= __MSVCR80_DLL
/* MSVCR80.DLL introduced three new data structures, with explicitly
 * sized elements; in the order specified below, the first and second
 * of these three are identically equivalent to the representations of
 * struct _finddata_t, and struct _finddatai64_t, as they are required
 * to be implemented to match the implementations of the corresponding
 * functions in ALL versions of MSVCRT.DLL, whereas the third has no
 * counterpart, in ANY version of MSVCRT.DLL.
 */
struct _finddata32_t __struct_finddata_t (__time32_t, __int32);
struct _finddata32i64_t __struct_finddata_t (__time32_t, __int64);
struct _finddata64i32_t __struct_finddata_t (__time64_t, __int32);

/* The actual functions implemented in MSVCR80.DLL, and its derivatives,
 * corresponding to each of these three data structures are:
 */
_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _findfirst32 (const char *, struct _finddata32_t *);

_CRTIMP __cdecl __MINGW_NOTHROW
int _findnext32 (intptr_t, struct _finddata32_t *);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _findfirst32i64 (const char *, struct _finddata32i64_t *);

_CRTIMP __cdecl __MINGW_NOTHROW
int _findnext32i64 (intptr_t, struct _finddata32i64_t *);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _findfirst64i32 (const char *, struct _finddata64i32_t *);

_CRTIMP __cdecl __MINGW_NOTHROW
int _findnext64i32 (intptr_t, struct _finddata64i32_t *);

/* Since MSVCR80.DLL, and its later derivatives, provide no physical
 * implementations of the original file name search API functions, we
 * must emulate them, (as Microsoft do), by providing replacements in
 * the form of inline functions; in doing so, we also need to contend
 * with the insane ambiguity of Microsoft's _USE_32BIT_TIME_T feature
 * test; thus...
 */
#if defined _USE_32BIT_TIME_T
/* ...when the user has defined the _USE_32BIT_TIME_T macro, we provide
 * inline implementations which remain fully compatible with the actual
 * functions, as provided by MSVCRT.DLL; (note that we do not provide
 * __JMPSTUB__ or __LIBIMPL__ references here, since we have no basis
 * for a rational choice between ambiguous alternatives).
 */
__CRT_ALIAS __cdecl __MINGW_NOTHROW
intptr_t _findfirst (const char *__filespec, struct _finddata_t *__search)
{ return _findfirst32 (__filespec, (struct _finddata32_t *)(__search)); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW
int _findnext (intptr_t __handle, struct _finddata_t *__search)
{ return _findnext32 (__handle, (struct _finddata32_t *)(__search)); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW
intptr_t _findfirsti64 (const char *__filespec, struct _finddatai64_t *__search)
{ return _findfirst32i64 (__filespec, (struct _finddata32i64_t *)(__search)); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW
int _findnexti64 (intptr_t __handle, struct _finddatai64_t *__search)
{ return _findnext32i64 (__handle, (struct _finddata32i64_t *)(__search)); }

#else	/* !_USE_32BIT_TIME_T */
/* ...but, when the user has NOT defined _USE_32BIT_TIME_T, we emulate
 * the brain damaged default behaviour of Microsoft's own SDKs.  This
 * accommodates an extended range of valid time stamp values, but it
 * utterly destroys compatibility with MSVCRT.DLL!
 */
__CRT_ALIAS __cdecl __MINGW_NOTHROW
intptr_t _findfirst (const char *__filespec, struct _finddata_t *__search)
{ return _findfirst64i32 (__filespec, (struct _finddata64i32_t *)(__search)); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW
int _findnext (intptr_t __handle, struct _finddata_t *__search)
{ return _findnext64i32 (__handle, (struct _finddata64i32_t *)(__search)); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW
intptr_t _findfirsti64 (const char *__filespec, struct _finddatai64_t *__search)
{ return _findfirst64 (__filespec, (struct __finddata64_t *)(__search)); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW
int _findnexti64 (intptr_t __handle, struct _finddatai64_t *__search)
{ return _findnext64 (__handle, (struct __finddata64_t *)(__search)); }

#endif	/* !_USE_32BIT_TIME_T */
#endif	/* __MSVCRT_VERSION__ >= __MSVCR80_DLL */
#endif	/* >= WIN2K || >= MSVCR61.DLL */

#undef  __fd_name_t
#endif	/* _IO_H */

#if ! (defined _IO_H && defined _WCHAR_H)
/* Wide character file name analogue of the file name search API;
 * declared both here, in <io.h>, and via selective inclusion from
 * <wchar.h>, it mirrors all aspects of the preceding API declarations,
 * except that all file names are expressed as wchar_t.
 */
#define __fd_name_t  wchar_t

/* Thus, the original API comprised this pair of generically specified
 * data structures...
 */
struct _wfinddata_t __struct_finddata_t (time_t, _fsize_t);
struct _wfinddatai64_t __struct_finddata_t (time_t, __int64);

#if __MSVCRT_VERSION__ < __MSVCR80_DLL
/* ...with corresponding functions to manipulate them; once again, there
 * is no physical implementation of these in MSVCR80.DLL or later, so we
 * declare them only when it is NOT specified that one of these run-time
 * library versions is to be used.
 */
_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _wfindfirst (const wchar_t *, struct _wfinddata_t *);

_CRTIMP __cdecl __MINGW_NOTHROW
int _wfindnext (intptr_t, struct _wfinddata_t *);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _wfindfirsti64 (const wchar_t *, struct _wfinddatai64_t *);

_CRTIMP __cdecl __MINGW_NOTHROW
int _wfindnexti64 (intptr_t, struct _wfinddatai64_t *);

#endif	/* __MSVCRT_VERSION__ < __MSVCR80_DLL */

#if _WIN32_WINNT >= _WIN32_WINNT_WIN2K || __MSVCRT_VERSION__ >= __MSVCR61_DLL
/* Win2K also added an all-64-bit variant of the _wfinddata API to
 * MSVCRT.DLL, after it originally appeared in MSVCR61.DLL.
 */
struct __wfinddata64_t __struct_finddata_t (__time64_t, __int64);
/*
 * As in the case of the __finddata64_t structure, some MSDN
 * documents, (particularly more recent documents), may refer
 * to __wfinddata64_t by the inconsistently anomalous name of
 * _wfinddata64_t; also support this anomaly.
 */
#define _wfinddata64_t  __wfinddata64_t

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _wfindfirst64 (const wchar_t *, struct __wfinddata64_t *);

_CRTIMP __cdecl __MINGW_NOTHROW
int _wfindnext64 (intptr_t, struct __wfinddata64_t *);

#if __MSVCRT_VERSION__ >= __MSVCR80_DLL
/* MSVCR80.DLL introduced a further three variants, which remain
 * exclusive to it and its later derivatives; none of these are
 * available in any version of MSVCRT.DLL.
 */
struct _wfinddata32_t    __struct_finddata_t (__time32_t, __int32);
struct _wfinddata32i64_t __struct_finddata_t (__time32_t, __int64);
struct _wfinddata64i32_t __struct_finddata_t (__time64_t, __int32);
/*
 * As in the __finddata64_t vs. _finddata64_t, and __wfinddata64_t
 * vs. _wfinddata64_t anomalous cases, there is at least one historic
 * MSDN reference to a __wfinddata32_t structural type, in a context
 * where _wfinddata32_t may be expected.  In this case, it appears
 * that __wfinddata32_t is the anomaly, and that it may be peculiar
 * to the VS-2005 documentation; nevertheless, the corresponding
 * definition is provided here, for the possible convenience of
 * any user who may depend on it, (but please avoid it).
 */
#define __wfinddata32_t  _wfinddata32_t

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _wfindfirst32 (const wchar_t *, struct _wfinddata32_t *);

_CRTIMP __cdecl __MINGW_NOTHROW
int _wfindnext32 (intptr_t, struct _wfinddata32_t *);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _wfindfirst32i64 (const wchar_t *, struct _wfinddata32i64_t *);

_CRTIMP __cdecl __MINGW_NOTHROW
int _wfindnext32i64 (intptr_t, struct _wfinddata32i64_t *);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _wfindfirst64i32 (const wchar_t *, struct _wfinddata64i32_t *);

_CRTIMP __cdecl __MINGW_NOTHROW
int _wfindnext64i32 (intptr_t, struct _wfinddata64i32_t *);

/* Once again, the variants of this API with generic time_t data
 * fields are NOT supported by any physical function implementation
 * in MSVCR80.DLL and later, so must be emulated; (again, we do not
 * provide any __JMPSTUB__ or __LIBIMPL__ references).
 */
#ifdef _USE_32BIT_TIME_T
/* First, we provide inline implementations which retain compatibility
 * with the physical implementations in MSVCRT.DLL; they require the
 * user to define the _USE_32BIT_TIME_T feature test macro...
 */
__CRT_ALIAS __cdecl __MINGW_NOTHROW
intptr_t _wfindfirst (const wchar_t *__filespec, struct _wfinddata_t *__search)
{ return _wfindfirst32 (__filespec, (struct _wfinddata32_t *)(__search)); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW
int _wfindnext (intptr_t __handle, struct _wfinddata_t *__search)
{ return _wfindnext32 (__handle, (struct _wfinddata32_t *)(__search)); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW
intptr_t _wfindfirsti64 (const wchar_t *__filespec, struct _wfinddatai64_t *__search)
{ return _wfindfirst32i64 (__filespec, (struct _wfinddata32i64_t *)(__search)); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW
int _wfindnexti64 (intptr_t __handle, struct _wfinddatai64_t *__search)
{ return _wfindnext32i64 (__handle, (struct _wfinddata32i64_t *)(__search)); }

#else	/* !_USE_32BIT_TIME_T */
/* ...whereas the brain damaged Microsoft defaults, which apply when
 * _USE_32BIT_TIME_T is not defined, break MSVCRT.DLL compatibility.
 */
__CRT_ALIAS __cdecl __MINGW_NOTHROW
intptr_t _wfindfirst (const wchar_t *__filespec, struct _wfinddata_t *__search)
{ return _wfindfirst64i32 (__filespec, (struct _wfinddata64i32_t *)(__search)); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW
int _wfindnext (intptr_t __handle, struct _wfinddata_t *__search)
{ return _wfindnext64i32 (__handle, (struct _wfinddata64i32_t *)(__search)); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW
intptr_t _wfindfirsti64 (const wchar_t *__filespec, struct _wfinddatai64_t *__search)
{ return _wfindfirst64 (__filespec, (struct __wfinddata64_t *)(__search)); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW
int _wfindnexti64 (intptr_t __handle, struct _wfinddatai64_t *__search)
{ return _wfindnext64 (__handle, (struct __wfinddata64_t *)(__search)); }

#endif	/* !_USE_32BIT_TIME_T */
#endif	/* __MSVCRT_VERSION__ >= MSVCR80.DLL */
#endif	/* >= _WIN2K || >= MSVCR61.DLL */

/* MSDN documents that <io.h> must be included to get a prototype for
 * _findclose(), which kind of negates the usefulness of declaring the
 * wchar_t variants of the file name search API in <wchar.h>; mitigate
 * this anomaly, by declaring _findclose() such that either <io.h> or
 * <wchar.h> (but only the first to be included) will provide it.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int _findclose (intptr_t);

#undef __fd_name_t
#endif	/* ! (_IO_H && _WCHAR_H) */

/* We have no further use for the __struct_finddata_t macro; delete it!
 */
#undef __struct_finddata_t

#ifdef _IO_H
/* The following declarations are to be exposed only when <io.h> is
 * included directly.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int _chdir (const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  char *_getcwd (char *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  int _mkdir (const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  char *_mktemp (char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int _rmdir (const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int _chmod (const char *, int);

#ifdef __MSVCRT__
_CRTIMP __cdecl __MINGW_NOTHROW  __int64 _filelengthi64 (int);
_CRTIMP __cdecl __MINGW_NOTHROW  __int64 _lseeki64 (int, __int64, int);
_CRTIMP __cdecl __MINGW_NOTHROW  __int64 _telli64 (int);

#ifndef __NO_MINGW_LFS
__CRT_INLINE __off64_t lseek64 (int, __off64_t, int);
__CRT_INLINE __JMPSTUB__(( FUNCTION = lseek64, REMAPPED = _lseeki64 ))
__off64_t lseek64 (int fd, __off64_t offset, int whence)
{ return _lseeki64 (fd, (__int64)(offset), whence); }
#endif

#endif /* __MSVCRT__ */

#ifndef _NO_OLDNAMES

#ifndef _UWIN
_CRTIMP __cdecl __MINGW_NOTHROW  int chdir (const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  char *getcwd (char *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  int mkdir (const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  char *mktemp (char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int rmdir (const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int chmod (const char *, int);
#endif /* _UWIN */

#endif /* !_NO_OLDNAMES */
#endif	/* _IO_H */

_END_C_DECLS

#endif	/* ! RC_INVOKED */

#ifdef _IO_H
/* Still applicable only when <io.h> is included directly, but we also
 * allow the resource compiler to see these.
 *
 * TODO: Maximum number of open handles has not been tested; we just set
 * it the same as FOPEN_MAX.
 */
#define HANDLE_MAX	FOPEN_MAX

/* Some defines for _access() mode checking: (Microsoft doesn't define
 * them, but it doesn't seem to hurt to add them ... or perhaps it does
 * hurt; on newer versions of MSVCRT.DLL, an access mode of 1 may raise
 * an invalid parameter error!
 */
#define F_OK	0	/* Check for file existence */
#define X_OK	1	/* MS access() doesn't check for execute permission. */
#define W_OK	2	/* Check for write permission */
#define R_OK	4	/* Check for read permission */
#endif	/* _IO_H */

#ifndef RC_INVOKED

_BEGIN_C_DECLS

#ifdef _IO_H
/* Again, specific to <io.h>, but not applicable to resources.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int _access (const char *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  int _chsize (int, long);
_CRTIMP __cdecl __MINGW_NOTHROW  int _close (int);
_CRTIMP __cdecl __MINGW_NOTHROW  int _commit (int);

/* NOTE: The only significant permissions bit appears to be
 * bit 7 (0x80), the "owner write permission" bit (on FAT).
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int _creat (const char *, int);

_CRTIMP __cdecl __MINGW_NOTHROW  int _dup (int);
_CRTIMP __cdecl __MINGW_NOTHROW  int _dup2 (int, int);
_CRTIMP __cdecl __MINGW_NOTHROW  long _filelength (int);
_CRTIMP __cdecl __MINGW_NOTHROW  long _get_osfhandle (int);
_CRTIMP __cdecl __MINGW_NOTHROW  int _isatty (int);

#ifndef	_STREAM_COMPAT
/* In a very odd turn of events this function is excluded from those
 * files which define _STREAM_COMPAT. This is required in order to
 * build GNU libio because of a conflict with _eof in streambuf.h
 * line 107. Actually I might just be able to change the name of
 * the enum member in streambuf.h ... we'll see. TODO
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int _eof (int);
#endif

/* Locking files: attribute constants are defined in <sys/locking.h>,
 * which users are expected to include.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int _locking (int, int, long);

_CRTIMP __cdecl __MINGW_NOTHROW  long _lseek (int, long, int);

/* Opening files, (or streams); manifest constants for construction of
 * the mode flags are defined in <fctl.h>, which users are expected to
 * include.  The "optional" third argument is an unsigned int; it is
 * REQUIRED, when creating a new file, to specify the permissions to
 * apply when said file is released by the creating process.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int _open (const char *, int, ...);

_CRTIMP __cdecl __MINGW_NOTHROW  int _open_osfhandle (intptr_t, int);
_CRTIMP __cdecl __MINGW_NOTHROW  int _pipe (int *, unsigned int, int);
_CRTIMP __cdecl __MINGW_NOTHROW  int _read (int, void *, unsigned int);
_CRTIMP __cdecl __MINGW_NOTHROW  int _setmode (int, int);

/* Microsoft declares remove() & rename(), (but not their wchar_t
 * counterparts), in <io.h> as well as in <stdio.h>; these should be
 * consistent with <stdio.h>, but we trust the compiler to alert us
 * (eventually) if not.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int remove (const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int rename (const char *, const char *);

/* Open files with specified sharing attributes; manifest constants
 * for constructing the sharing mode argument are in <share.h>, which
 * users must include.  The optional fourth argument is an unsigned
 * int, specifing permissions to apply after closing a new file.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int _sopen (const char *, int, int, ...);

_CRTIMP __cdecl __MINGW_NOTHROW  long _tell (int);

/* FIXME: POSIX wants umask() in <sys/stat.h>, and, although vague,
 * Microsoft may agree; we declare it here as well!
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int _umask (int);
_CRTIMP __cdecl __MINGW_NOTHROW  int _unlink (const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int _write (int, const void *, unsigned int);
#endif	/* _IO_H */

#if defined __MSVCRT__ && ! (defined _IO_H && defined _WCHAR_H)
/* These wchar_t functions are made available for selective inclusion
 * by <wchar.h>, in addition to direct inclusion of <io.h>, but they
 * are only supported by MSVCRT.DLL and derivatives; they don't exist
 * in CRTDLL.DLL.  Furthermore, if both _IO_H and _WCHAR_H have been
 * defined, by the time we get here, then this must be direct <io.h>
 * inclusion, and we've already declared these by prior inclusion of
 * <wchar.h>; there is no need to declare them again.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int _waccess (const wchar_t *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  int _wchmod (const wchar_t *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  int _wcreat (const wchar_t *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  int _wunlink (const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  int _wopen (const wchar_t *, int, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int _wsopen (const wchar_t *, int, int, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *_wmktemp (wchar_t *);
#endif /* __MSVCRT__ && ! (_IO_H && _WCHAR_H) */

#if defined _IO_H && ! defined _NO_OLDNAMES
/* Non-underscored versions of non-ANSI functions to improve portability;
 * these are implemented in libmoldname.a, and once again are declared
 * only when <io.h> is included directly.
 */
#ifndef _UWIN
_CRTIMP __cdecl __MINGW_NOTHROW  int access (const char*, int);
_CRTIMP __cdecl __MINGW_NOTHROW  int chsize (int, long );
_CRTIMP __cdecl __MINGW_NOTHROW  int close (int);
_CRTIMP __cdecl __MINGW_NOTHROW  int creat (const char*, int);
_CRTIMP __cdecl __MINGW_NOTHROW  int dup (int);
_CRTIMP __cdecl __MINGW_NOTHROW  int dup2 (int, int);
_CRTIMP __cdecl __MINGW_NOTHROW  int eof (int);
_CRTIMP __cdecl __MINGW_NOTHROW  long filelength (int);
_CRTIMP __cdecl __MINGW_NOTHROW  int isatty (int);
_CRTIMP __cdecl __MINGW_NOTHROW  long lseek (int, long, int);
_CRTIMP __cdecl __MINGW_NOTHROW  int open (const char*, int, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int read (int, void*, unsigned int);
_CRTIMP __cdecl __MINGW_NOTHROW  int setmode (int, int);
_CRTIMP __cdecl __MINGW_NOTHROW  int sopen (const char*, int, int, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  long tell (int);
_CRTIMP __cdecl __MINGW_NOTHROW  int umask (int);
_CRTIMP __cdecl __MINGW_NOTHROW  int unlink (const char*);
_CRTIMP __cdecl __MINGW_NOTHROW  int write (int, const void*, unsigned int);
#endif /* !_UWIN */

#ifdef __USE_MINGW_ACCESS
/* Old versions of MSVCRT.DLL's access() just ignored X_OK, while the
 * version shipped with Vista fails; this inline implementation of the
 * portably named access() function protects against such failure.
 */
#define access(__fname,__mode)  __mingw_access (__fname, __mode)
static __inline__ int __mingw_access (const char* __fname, int __mode)
  { return  _access (__fname, __mode & ~X_OK); }
#endif	/* _USE_MINGW_ACCESS */

#if 0
/* FIXME:
 * Wide character versions: may also be declared in <wchar.h>.
 * Where do these live?  Not in libmoldname.a nor in libmsvcrt.a;
 * do they exist at all?
 */
int 		waccess(const wchar_t *, int);
int 		wchmod(const wchar_t *, int);
int 		wcreat(const wchar_t *, int);
long 		wfindfirst(wchar_t *, struct _wfinddata_t *);
int 		wfindnext(long, struct _wfinddata_t *);
int 		wunlink(const wchar_t *);
int 		wrename(const wchar_t *, const wchar_t *);
int 		wopen(const wchar_t *, int, ...);
int 		wsopen(const wchar_t *, int, int, ...);
wchar_t * 	wmktemp(wchar_t *);
#endif

#endif	/* !_NO_OLDNAMES */

_END_C_DECLS

#endif	/* ! RC_INVOKED */
#endif	/* !_IO_H: $RCSfile: io.h,v $: end of file */
 
#ifndef RC_INVOKED

_BEGIN_C_DECLS

/* The following declarations are to be visible ONLY when <dos.h>
 * is included in its own right; they represent entities which are
 * present in CRTDLL.DLL, but not in MSVCRT.DLL
 */
#if defined _DOS_H && ! defined __MSVCRT__
#ifndef __DECLSPEC_SUPPORTED

# define _basemajor    (*_imp___basemajor_dll)
# define _baseminor    (*_imp___baseminor_dll)
# define _baseversion  (*_imp___baseversion_dll)
# define _osmajor      (*_imp___osmajor_dll)
# define _osminor      (*_imp___osminor_dll)
# define _osmode       (*_imp___osmode_dll)

extern unsigned int *_imp___basemajor_dll;
extern unsigned int *_imp___baseminor_dll;
extern unsigned int *_imp___baseversion_dll;
extern unsigned int *_imp___osmajor_dll;
extern unsigned int *_imp___osminor_dll;
extern unsigned int *_imp___osmode_dll;

#else /* __DECLSPEC_SUPPORTED */

# define _basemajor    _basemajor_dll
# define _baseminor    _baseminor_dll
# define _baseversion  _baseversion_dll
# define _osmajor      _osmajor_dll
# define _osminor      _osminor_dll
# define _osmode       _osmode_dll

__MINGW_IMPORT unsigned int _basemajor_dll;
__MINGW_IMPORT unsigned int _baseminor_dll;
__MINGW_IMPORT unsigned int _baseversion_dll;
__MINGW_IMPORT unsigned int _osmajor_dll;
__MINGW_IMPORT unsigned int _osminor_dll;
__MINGW_IMPORT unsigned int _osmode_dll;

#endif	/* __DECLSPEC_SUPPORTED */
#endif	/* _DOS_H && !__MSVCRT__ */

/* The following section, which declares the _getdiskfree() function
 * prototype, and also defines its associated _diskfree_t data structure,
 * is to be processed both when including <dos.h> in its own right, and
 * when selectively included by <direct.h>; however...
 */
#if ! (defined _DOS_H && defined _DIRECT_H)
 /* ...when both the _DOS_H guard, and the _DIRECT_H multiple inclusion
  * guards have been defined, by the time we get to here, then this is
  * <dos.h> inclusion in its own right, and we have ALREADY processed
  * these definitions through selective inclusion by <direct.h>; we
  * MUST NOT process them a second time.
  */
#ifndef	_NO_OLDNAMES
# define diskfree_t  _diskfree_t
#endif

struct _diskfree_t
{ /* A structure in which to store information about disk
   * free space, as returned by the _getdiskfree() function.
   */
  unsigned total_clusters;
  unsigned avail_clusters;
  unsigned sectors_per_cluster;
  unsigned bytes_per_sector;
};

_CRTIMP __cdecl __MINGW_NOTHROW
unsigned _getdiskfree (unsigned, struct _diskfree_t *);

#endif	/* ! ( _DOS_H && _DIRECT_H) */

_END_C_DECLS

#endif	/* ! RC_INVOKED */
#endif  /* !_DOS_H: $RCSfile: dos.h,v $: end of file */
 
#undef __DIRECT_H_SOURCED__
#endif	/* !__WCHAR_H_SOURCED__ */

#ifndef RC_INVOKED

_BEGIN_C_DECLS

#ifdef _DIRECT_H
/* Functions for manipulating disk drive selection; these are declared
 * only when <direct.h> is included in its own right.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int _getdrive (void);
_CRTIMP __cdecl __MINGW_NOTHROW  unsigned long _getdrives(void);
_CRTIMP __cdecl __MINGW_NOTHROW  int _chdrive (int);
_CRTIMP __cdecl __MINGW_NOTHROW  char *_getdcwd (int, char*, int);

#endif	/* _DIRECT_H */

/* The following group of function prototypes are to be declared
 * either when including <dirent.h> in its own right, or when it
 * is included selectively by <wchar.h>; however...
 */
#if defined __MSVCRT__ && ! (defined _DIRENT_H && defined _WCHAR_H)
 /*
  * ...they are available only within MSVCRT.DLL, (i.e. they are
  * NOT provided by CRTDLL.DLL), and if both _DIRENT_H and _WCHAR_H
  * are already defined, by the time we get to here, then this must
  * be an inclusion of <dirent.h> in its own right, AFTER they have
  * already been declared on behalf of <wchar.h>; there is no need
  * to declare them again.
  */
_CRTIMP __cdecl __MINGW_NOTHROW  int _wchdir (const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *_wgetcwd (wchar_t *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *_wgetdcwd (int, wchar_t *, int);
_CRTIMP __cdecl __MINGW_NOTHROW  int _wmkdir (const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  int _wrmdir (const wchar_t *);

#endif	/* __MSVCRT__ && ! (defined _DIRENT_H && defined _WCHAR_H) */

_END_C_DECLS

#endif	/* ! RC_INVOKED */
#endif  /* !_DIRECT_H: $RCSfile: direct.h,v $: end of file */
 /* ...we obtain prototypes for each of the following functions,
 * (none of which are available when using CRTDLL.DLL):
 *
 *  int _wchdir (const wchar_t *);
 *  wchar_t *_wgetcwd (wchar_t *, int);
 *  wchar_t *_wgetdcwd (int, wchar_t *, int);
 *  int _wmkdir (const wchar_t *);
 *  int _wrmdir (const wchar_t *);
 *
 *
 * while from...
 */
/*
 * stat.h
 *
 * Symbolic constants for opening and creating files, also stat, fstat and
 * chmod functions.
 *
 * $Id: stat.h,v aae5e4b880b9 2016/07/14 17:59:07 keithmarshall $
 *
 * Written by Colin Peters <colin@bird.fu.is.saga-u.ac.jp>
 * Copyright (C) 1997-2001, 2003-2005, 2007, 2016, MinGW.org Project.
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice, this permission notice, and the following
 * disclaimer shall be included in all copies or substantial portions of
 * the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OF OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef _SYS_STAT_H
#pragma GCC system_header

/* To support selective (partial) inclusion by <wchar.h>...
 */
#ifndef __WCHAR_H_SOURCED__
/* ...we defer the definition of the normal multiple inclusion guard macro,
 * until we know that this is NOT the <wchar.h> selective inclusion case.
 */
#define _SYS_STAT_H

/* All MinGW headers are required to include <_mingw.h>; however, Microsoft
 * also stipulate that USERS MUST include <sys/types.h>, BEFORE they include
 * <sys/stat.h>.  This is not only appallingly bad software engineering, on
 * Microsoft's part, but it is a potential obstacle to portability of POSIX
 * source code; (POSIX requires that <sys/stat.h> should be self-contained,
 * with no requirement for any specific header inclusion order).  Although
 * it is more inclusive that POSIX requires, we may mitigate the deficiency
 * inherent in Microsoft's poor software engineering, by simply including
 * <sys/types.h> here; in so doing, we may also delegate the inclusion of
 * <_mingw.h>, and the definition of all data types required herein, to...
 */
#define _S_IFIFO 	0x1000	/* FIFO */
#define _S_IFCHR 	0x2000	/* Character */
#define _S_IFDIR 	0x4000	/* Directory */
#define _S_IFREG 	0x8000	/* Regular */

#ifdef _MINGW_S_IFBLK_KLUDGE
/* For preference, this kludge should NOT be enabled; for rationale,
 * see: https://sourceforge.net/p/mingw/bugs/1146
 *
 * MS-Windows doesn't support testing for block special devices via the
 * st_mode flags; ideally, client code to be ported to Windows should not
 * blindly assume that S_IFBLK (or _S_IFBLK) is defined, but should rather
 * check for it, and compile dependent code conditionally.  Notwithstanding,
 * this kludge allows the user to force a definition, which we arbitrarily
 * choose to ensure that S_ISBLK (or _S_ISBLK) always returns FALSE, (i.e.
 * choose a value such that _S_IFBLK & _S_IFMT can NEVER equal _S_IFBLK).
 */
#define _S_IFBLK 	0x3001	/* Block: unsupported on Win32 */
#endif

#define _S_IFMT  	0xF000	/* File type mask */

#define _S_IEXEC 	0x0040
#define _S_IWRITE	0x0080
#define _S_IREAD 	0x0100

#define _S_IRWXU 	(_S_IREAD | _S_IWRITE | _S_IEXEC)
#define _S_IXUSR 	_S_IEXEC
#define _S_IWUSR 	_S_IWRITE
#define _S_IRUSR 	_S_IREAD

#define _S_ISDIR(m)	(((m) & _S_IFMT) == _S_IFDIR)
#define _S_ISFIFO(m)	(((m) & _S_IFMT) == _S_IFIFO)
#define _S_ISCHR(m)	(((m) & _S_IFMT) == _S_IFCHR)
#define _S_ISBLK(m)	(((m) & _S_IFMT) == _S_IFBLK)
#define _S_ISREG(m)	(((m) & _S_IFMT) == _S_IFREG)

#ifndef _NO_OLDNAMES

#define S_IFIFO 	_S_IFIFO
#define S_IFCHR 	_S_IFCHR
#ifdef _S_IFBLK
#define S_IFBLK 	_S_IFBLK
#endif
#define S_IFDIR 	_S_IFDIR
#define S_IFREG 	_S_IFREG
#define S_IFMT  	_S_IFMT
#define S_IEXEC 	_S_IEXEC
#define S_IWRITE	_S_IWRITE
#define S_IREAD 	_S_IREAD
#define S_IRWXU 	_S_IRWXU
#define S_IXUSR 	_S_IXUSR
#define S_IWUSR 	_S_IWUSR
#define S_IRUSR 	_S_IRUSR

#define S_ISDIR(m)	(((m) & S_IFMT) == S_IFDIR)
#define S_ISFIFO(m)	(((m) & S_IFMT) == S_IFIFO)
#define S_ISCHR(m)	(((m) & S_IFMT) == S_IFCHR)
#define S_ISBLK(m)	(((m) & S_IFMT) == S_IFBLK)
#define S_ISREG(m)	(((m) & S_IFMT) == S_IFREG)

#endif	/* !_NO_OLDNAMES */

#ifndef _S_IFBLK
/* When the _S_IFBLK kludge is NOT enabled, (as it ideally should not be),
 * ensure that any attempt to use its dependent macros is denied...
 */
# pragma GCC poison _S_ISBLK

# if defined _NO_UNSUPPORTED || defined _NO_OLDNAMES
  /* ...including that for the standard POSIX macro, when unsupported
   * features, or Microsoft's old names, are explicitly forbidden...
   */
#  pragma GCC poison S_ISBLK

# else /* !(_NO_UNSUPPORTED || _NO_OLDNAMES) */
  /* ...otherwise assume that the kludge is automatically enabled with
   * respect to S_ISBLK, (because GCC gratuitously misuses it).
   */
#  define S_IFBLK 	0x3001	/* Block: unsupported on Win32 */

# endif /* !(_NO_UNSUPPORTED || _NO_OLDNAMES) */
#endif	/* !_S_IFBLK */
#endif	/* !__WCHAR_H_SOURCED__ */

#ifndef RC_INVOKED
#ifndef __struct_stat_defined
/* The structure manipulated and returned by stat() and fstat(); note that
 * expansion of the macro provided below will yield variants of struct stat
 * to conform with Microsoft's usage, (and POSIX usage up to and including
 * POSIX.1-2001, but NOT the extended specification of POSIX.1-2008).
 *
 * NOTE: If called on a directory the values in the time fields are not only
 * invalid, they will cause localtime et. al. to return NULL. And calling
 * asctime with a NULL pointer causes an Invalid Page Fault. So watch it!
 */
#define __struct_stat_defined(__st_off_t, __st_time_t)			     \
{ _dev_t	st_dev; 	/* Equivalent to drive number 0=A 1=B ... */ \
  _ino_t	st_ino; 	/* Always zero ? */			     \
  _mode_t	st_mode;	/* See above constants */		     \
   short 	st_nlink;	/* Number of links. */			     \
   short 	st_uid; 	/* User: Maybe significant on NT ? */	     \
   short 	st_gid; 	/* Group: Ditto */			     \
  _dev_t	st_rdev;	/* Seems useless (not even filled in) */     \
  __st_off_t	st_size;	/* File size in bytes */		     \
  __st_time_t	st_atime;	/* Access time (always 00:00 on FAT) */	     \
  __st_time_t	st_mtime;	/* Modified time */			     \
  __st_time_t	st_ctime;	/* Creation time */			     \
}

/* Here, we expand the preceding macro to yield the actual definition
 * of struct stat, under its current Microsoft "uglified" name...
 */
struct _stat __struct_stat_defined( _off_t, time_t );

#ifndef _NO_OLDNAMES
/* ...while this alternative expansion yields its standard POSIX name,
 * (and its original Microsoft name); apart from its name, this must be
 * defined identically to struct _stat above.
 */
struct stat __struct_stat_defined( _off_t, time_t );
#endif	/* !_NO_OLDNAMES */

#if defined __MSVCRT__
/* This variant of struct stat is required to support the use of the
 * _stati64() function, which is provided by MSVCRT.DLL, but was not
 * present in CRTDLL.DLL...
 */
struct _stati64 __struct_stat_defined( __off64_t, time_t );

#if __MSVCRT_VERSION__ >= __MSVCR61_DLL || _WIN32_WINNT >= _WIN32_WINNT_WIN2K
/* ...while this supports the use of the _stat64() function, introduced
 * by MSVCR61.DLL, and subsequently added to MSVCRT.DLL for releases from
 * Win2K onwards...
 */
struct __stat64 __struct_stat_defined( __off64_t, __time64_t );

#if __MSVCRT_VERSION__ >= __MSVCR80_DLL
/* ...and these are specific to additional function variants, added to
 * the non-free MSVCR80.DLL, and its later derivatives, but not present
 * in MSVCRT.DLL (or CRTDLL.DLL).
 */
struct __stat32 __struct_stat_defined( __off32_t, __time32_t );
struct _stat32i64 __struct_stat_defined( __off64_t, __time32_t );
struct _stat64i32 __struct_stat_defined( __off32_t, __time64_t );

#endif	/* __MSVCRT_VERSION__ >= __MSVCR80_DLL */
#endif	/* __MSVCRT_VERSION__ >= __MSVCR61_DLL */
#endif	/* __MSVCRT__ */

/* From here on, it is sufficient to leave __struct_stat_defined as
 * a macro which expands to nothing.
 */
#undef  __struct_stat_defined
#define __struct_stat_defined

#endif /* !__struct_stat_defined */

_BEGIN_C_DECLS

#ifdef _SYS_STAT_H
/* This set of function prototypes are to be declared only when
 * <sys/stat.h> is included directly.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int _umask (int);
_CRTIMP __cdecl __MINGW_NOTHROW  int _chmod (const char *, int);

#if __MSVCRT_VERSION__ < __MSVCR80_DLL
/* This pair of functions are present in all versions of MSVCRT.DLL, but
 * they are NOT present in MSVCR80.DLL, nor in any of its later non-free
 * variants, all of which rely on inline aliases (defined below).
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int _fstat (int, struct _stat *);
_CRTIMP __cdecl __MINGW_NOTHROW  int _stat (const char *, struct _stat *);
#endif	/* __MSVCRT_VERSION__ < __MSVCR80_DLL */

#ifndef	_NO_OLDNAMES
/* These are the standard POSIX names, (and the original Microsoft names),
 * for the preceding four functions.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int umask (int);
_CRTIMP __cdecl __MINGW_NOTHROW  int chmod (const char *, int);

#if __MSVCRT_VERSION__ < __MSVCR80_DLL
/* Since the underlying functions, with "uglified" names, are not supported
 * by MSVCR80.DLL and its later derivitaves, there is also nothing to which
 * to map these originally named alternatives; declare prototypes only when
 * using DLL versions which can support them, while falling back to the use
 * of inline replacements (defined below) in the unsupported cases.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int fstat (int, struct stat *);
_CRTIMP __cdecl __MINGW_NOTHROW  int stat (const char *, struct stat *);
#endif	/* __MSVCRT_VERSION__ < __MSVCR80_DLL */
#endif	/* !_NO_OLDNAMES */

#if defined __MSVCRT__
#if __MSVCRT_VERSION__ < __MSVCR80_DLL
/* This pair of functions were withdrawn from MSVCR80.DLL, and its later
 * derivatives, but remain in all versions of MSVCRT.DLL
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int _fstati64 (int, struct _stati64 *);
_CRTIMP __cdecl __MINGW_NOTHROW  int _stati64 (const char *, struct _stati64 *);
#endif	/* __MSVCRT_VERSION__ < __MSVCR80_DLL */

#if __MSVCRT_VERSION__ >= __MSVCR61_DLL || _WIN32_WINNT >= _WIN32_WINNT_WIN2K
/* This pair of functions were introduced in MSVCR61.DLL, and were subsequently
 * added to MSVCRT.DLL from the release accompanying Win2K onwards...
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int _fstat64 (int, struct __stat64 *);
_CRTIMP __cdecl __MINGW_NOTHROW  int _stat64 (const char *, struct __stat64 *);

#if __MSVCRT_VERSION__ >= __MSVCR80_DLL
/* ...whereas this group were introduced in MSVCR80.DLL, and its later
 * derivatives, but are not present in MSVCRT.DLL
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int _fstat32 (int, struct __stat32 *);
_CRTIMP __cdecl __MINGW_NOTHROW  int _stat32 (const char *, struct __stat32 *);
_CRTIMP __cdecl __MINGW_NOTHROW  int _fstat32i64 (int, struct _stat32i64 *);
_CRTIMP __cdecl __MINGW_NOTHROW  int _fstat64i32 (int, struct _stat64i32 *);
_CRTIMP __cdecl __MINGW_NOTHROW  int _stat32i64 (const char *, struct _stat32i64 *);
_CRTIMP __cdecl __MINGW_NOTHROW  int _stat64i32 (const char *, struct _stat64i32 *);

#ifdef _USE_32BIT_TIME_T
/* We must provide inline replacements for the four MSVCRT.DLL functions
 * which have been withdrawn from MSVCR80.DLL, and its later derivatives;
 * this first set of replacements are compatible with their MSVCRT.DLL
 * equivalents, but require the user to define _USE_32BIT_TIME_T...
 */
__CRT_ALIAS __cdecl __MINGW_NOTHROW  int _fstat (int __v1, struct _stat *__v2)
  { return _fstat32 (__v1, (struct __stat32 *)(__v2)); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW  int _stat (const char *__v1, struct _stat *__v2)
  { return _stat32  (__v1, (struct __stat32 *)(__v2)); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW  int _fstati64 (int __v1, struct _stati64 *__v2)
  { return _fstat32i64 (__v1, (struct _stat32i64 *)(__v2)); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW  int _stati64 (const char *__v1, struct _stati64 *__v2)
  { return _stat32i64  (__v1, (struct _stat32i64 *)(__v2)); }

#else	/* !_USE_32BIT_TIME_T */
/* ...whereas, the following alternatives emulate the brain-damaged
 * behaviour of Microsoft's own implementations, which take effect when
 * the user does not define _USE_32BIT_TIME_T; they break compatibility
 * with MSVCRT.DLL
 */
__CRT_ALIAS __cdecl __MINGW_NOTHROW  int _fstat (int __v1, struct _stat *__v2)
  { return _fstat64i32 (__v1, (struct _stat64i32 *)(__v2)); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW  int _stat (const char *__v1, struct _stat *__v2)
  { return _stat64i32  (__v1, (struct _stat64i32 *)(__v2)); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW  int _fstati64 (int __v1, struct _stati64 *__v2)
  { return _fstat64 (__v1, (struct __stat64 *)(__v2)); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW  int _stati64 (const char *__v1, struct _stati64 *__v2)
  { return _stat64  (__v1,(struct __stat64*)(__v2)); }
#endif	/* !_USE_32BIT_TIME_T */

#ifndef _NO_OLDNAMES
/* Irrespective of the state of _USE_32BIT_TIME_T, we may provide inline
 * replacements for the stat() and fstat() functions, (which are missing
 * from MSVCR80.DLL and its later derivatives), simply by aliasing them
 * to their corresponding replacements with "uglified" names.
 */
__CRT_ALIAS __cdecl __MINGW_NOTHROW  int fstat (int __v1, struct _stat *__v2)
  { return _fstat (__v1, __v2); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW  int stat (const char *__v1, struct _stat *__v2)
  { return _stat (__v1, __v2); }

#endif	/* !_NO_OLDNAMES */
#endif	/* __MSVCRT_VERSION__ >= __MSVCR80_DLL */
#endif	/* __MSVCRT_VERSION__ >= __MSVCR61_DLL */
#endif	/* __MSVCRT__ */
#endif	/* _SYS_STAT_H */

#if defined __MSVCRT__ && !(defined _SYS_STAT_H && defined _WCHAR_H)
/* This final group of function prototypes, specific to MSVCRT.DLL and its
 * non-free derivatives, are to be declared both when <sys/stat.h> is included
 * directly, and when it is selectively included by <wchar.h>; however, if both
 * _SYS_STAT_H and _WCHAR_H are defined, by the time we get to here, then this
 * must be the direct inclusion case, after having already declared these via
 * selective inclusion by <wchar.h>, and we should not declare these again;
 * (in particular, we should not repeat inline function implementations).
 */
#if __MSVCRT_VERSION__ < __MSVCR80_DLL
/* As is the case for their regular counterparts, this pair of functions
 * remain available in MSVCRT.DLL itself, but they are not exported from its
 * non-free derivatives from MSVCR80.DLL onwards, whence it is expected that
 * they will be replaced by inline implementations.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int _wstat(const wchar_t *, struct _stat *);
_CRTIMP __cdecl __MINGW_NOTHROW  int _wstati64 (const wchar_t *, struct _stati64 *);
#endif	/* __MSVCRT_VERSION__ < __MSVCR80_DLL */

#if __MSVCRT_VERSION__ >= __MSVCR61_DLL || _WIN32_WINNT >= _WIN32_WINNT_WIN2K
/* Similarly, this variant was introduced in MSVCR80.DLL, and was subsequently
 * added to MSVCRT.DLL with the release of Win2K...
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int _wstat64 (const wchar_t *, struct __stat64 *);

#if __MSVCRT_VERSION__ >= __MSVCR80_DLL
/* ...whereas these variants are exclusive to the non-free MSVCR80.DLL, and
 * its later derivatives; they are not available in MSVCRT.DLL.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int _wstat32 (const wchar_t *, struct __stat32 *);
_CRTIMP __cdecl __MINGW_NOTHROW  int _wstat32i64 (const wchar_t *, struct _stat32i64 *);
_CRTIMP __cdecl __MINGW_NOTHROW  int _wstat64i32 (const wchar_t *, struct _stat64i32 *);

#ifdef _USE_32BIT_TIME_T
/* Once again, we must furnish inline replacements for the functions which
 * were withdrawn from MSVCR80.DLL and its later derivatives; these are the
 * implementations which remain compatible with MSVCRT.DLL, but require the
 * user to define _USE_32BIT_TIME_T...
 */
__CRT_ALIAS __cdecl __MINGW_NOTHROW  int _wstat (const wchar_t *__v1, struct _stat *__v2)
  { return _wstat32 (__v1, (struct __stat32 *)(__v2)); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW  int _wstati64 (const wchar_t *__v1, struct _stati64 *__v2)
  { return _wstat32i64 (__v1, (struct _stat32i64 *)(__v2)); }

#else	/* !_USE_32BIT_TIME_T */
/* ...whereas these emulate the brain-damaged Microsoft behaviour, for the
 * case when the user does not define _USE_32BIT_TIME_T, breaking MSVCRT.DLL
 * compatibility.
 */
__CRT_ALIAS __cdecl __MINGW_NOTHROW  int _wstat (const wchar_t *__v1, struct _stat *__v2)
  { return _wstat64i32 (__v1, (struct _stat64i32 *)(__v2)); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW  int _wstati64 (const wchar_t *__v1, struct _stati64 *__v2)
  { return _wstat64 (__v1, (struct __stat64 *)(__v2)); }

#endif	/* !_USE_32BIT_TIME_T */
#endif	/* __MSVCRT_VERSION__ >= 0x0800 */
#endif	/* __MSVCRT_VERSION__ >= 0x0601 */
#endif	/* __MSVCRT__ && !(_SYS_STAT_H && _WCHAR_H) */

_END_C_DECLS

#endif	/* ! RC_INVOKED */
#endif	/* !_SYS_STAT__H: $RCSfile: stat.h,v $: end of file */
 /* ...we obtain function prototypes, and all associated data type
 * definitions for this pair of actual functions, in all versions of
 * MSVCRT.DLL, and its non-free derivatives preceding MSVCR80.DLL, (or
 * inline replacement implementations for MSVCR80.DLL and later):
 *
 *  int _wstat (const wchar_t *, struct _stat *);
 *  int _wstati64 (const wchar_t *, struct _stati64 *);
 *
 * ...this additional actual function, available in MSVCRT.DLL from
 * Win2K onwards, or in non-free MSVCR61.DLL and again requiring an
 * inline replacement from MSVCR80.DLL onwards:
 *
 *  int _wstat64 (const wchar_t *, struct __stat64 *);
 *
 * ...and these actual functions, which are available only in non-free
 * MSVCR80.DLL, and its later derivatives:
 *
 *  int _wstat32 (const wchar_t *, struct __stat32 *);
 *  int _wstat32i64 (const wchar_t *, struct _stat32i64 *);
 *  int _wstat64i32 (const wchar_t *, struct _stat64i32 *);
 *
 *
 * from...
 */
/*
 * conio.h
 *
 * Low level console I/O functions.  Pretty please try to use the ANSI
 * standard ones if you are writing new code.
 *
 * $Id: conio.h,v 7f0aa41f8caf 2018/10/21 15:39:35 keith $
 *
 * Written by Colin Peters <colin@bird.fu.is.saga-u.ac.jp>
 * Copyright (C) 1997, 1999-2001, 2003, 2004, 2007, 2018, MinGW.org Project.
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice, this permission notice, and the following
 * disclaimer shall be included in all copies or substantial portions of
 * the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OF OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef _CONIO_H
#pragma GCC system_header

/* When including <wchar.h>, some of the definitions and declarations
 * which are nominally provided in <conio.h> must be duplicated.  Rather
 * than require duplicated maintenance effort, we provide for partial
 * inclusion of <conio.h> by <wchar.h>; only when not included in
 * this partial fashion...
 */
#ifndef __WCHAR_H_SOURCED__
 /* ...which is exclusive to <wchar.h>, do we assert the multiple
  * inclusion guard for <conio.h> itself.
  */
#define _CONIO_H

/* All MinGW.org headers are expected to include <_mingw.h>; when
 * selectively included by <wchar.h>, that responsibility has already
 * been addressed, but for free-standing inclusion we do so now.
 */
#endif	/* !__WCHAR_H_SOURCED__ */

#ifndef RC_INVOKED
/* There is nothing here which is useful to the resource compiler;
 * for any other form of compilation, and regardless of the scope in
 * which <conio.h> is included, we need definitions for wchar_t, and
 * wint_t; get them by selective inclusion of <stddef.h>.
 */
#define __need_wint_t
#define __need_wchar_t
#ifdef _CONIO_H
/* The following declarations are to be exposed only on free-standing
 * inclusion of <conio.h>
 */
_CRTIMP __cdecl __MINGW_NOTHROW  char *_cgets (char*);
_CRTIMP __cdecl __MINGW_NOTHROW  int   _cprintf (const char*, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int   _cputs (const char*);
_CRTIMP __cdecl __MINGW_NOTHROW  int   _cscanf (char*, ...);

_CRTIMP __cdecl __MINGW_NOTHROW  int   _getch (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int   _getche (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int   _kbhit (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int   _putch (int);
_CRTIMP __cdecl __MINGW_NOTHROW  int   _ungetch (int);

#if _WIN32_WINNT >= _WIN32_WINNT_WINXP || __MSVCRT_VERSION__ >= __MSVCR70_DLL
/* Wide character variants of the console I/O functions were first
 * introduced in non-free MSVCR70.DLL, and subsequently supported by
 * MSVCRT.DLL from WinXP onwards.  Some are declared in <wchar.t> in
 * addition to <conio.h>; the following are exclusive to <conio.h>
 */
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t  _putwch (wchar_t);

#if __MSVCRT_VERSION__ >= __MSVCR80_DLL
/* Variants which do not perform thread locking require non-free
 * MSVCR80.DLL, or later; they are not supported by MSVCRT.DLL
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int     _getch_nolock (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int     _getche_nolock (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int     _putch_nolock (int);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t  _putwch_nolock (wchar_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int     _ungetch_nolock (int);

#endif	/* MSVCR80.DLL or later */
#endif	/* WinXP, MSVCR70.DLL, or later */

#ifndef _NO_OLDNAMES
/* Early versions of the Microsoft runtime library provided a subset
 * of the above functions, named without the ugly initial underscore;
 * these remain supported, and should be used when coding to support
 * legacy Windows platforms.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int  getch (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int  getche (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int  kbhit (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int  putch (int);
_CRTIMP __cdecl __MINGW_NOTHROW  int  ungetch (int);

#endif	/* !_NO_OLDNAMES */
#endif	/* _CONIO_H */

#if ! (defined _CONIO_H && defined _WCHAR_H)
/* The following are to be exposed either on free-standing inclusion
 * of <conio.h>, or on selective inclusion by <wchar.h>, but if both
 * guards are defined, then this is free-standing inclusion, and we
 * have already declared these by selective inclusion; there is no
 * need to declare them a second time.
 */
#if _WIN32_WINNT >= _WIN32_WINNT_WINXP || __MSVCRT_VERSION__ >= __MSVCR70_DLL
/* Wide character variants of the console I/O functions, in this group,
 * were first introduced in non-free Microsoft runtimes, from MSVCR70.DLL
 * onwards; they were not supported by MSVCRT.DLL prior to WinXP.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t  _getwch (void);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t  _getwche (void);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t  _ungetwch (wint_t);

#if __MSVCRT_VERSION__ >= __MSVCR80_DLL
/* Variants which do not perform thread locking require non-free
 * MSVCR80.DLL, or later; they are not supported by MSVCRT.DLL
 */
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t  _getwch_nolock (void);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t  _getwche_nolock (void);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t  _ungetwch_nolock (wint_t);

#endif	/* MSVCR80.DLL or later */
#endif	/* WinXP, MSVCR70.DLL, or later */
#endif	/* ! (_CONIO_H && _WCHAR_H) */

_END_C_DECLS

#endif	/* ! RC_INVOKED */
#endif	/* !_CONIO_H: $RCSfile: conio.h,v $: end of file */
 /* ...we obtain, depending on active MSVCRT.DLL version conformity,
 * or non-free run-time version selection, an appropriate subset of:
 *
 *   wint_t _getwch (void);
 *   wint_t _getwche (void);
 *   wint_t _ungetwch (wint_t);
 *
 * ...and for non-free run-times from MSVCR80.DLL onwards only:
 *
 *   wint_t _getwch_nolock (void);
 *   wint_t _getwche_nolock (void);
 *   wint_t _ungetwch_nolock (wint_t);
 *
 *
 * and from...
 */
#endif	/* !__STRICT_ANSI__ */

/* From...
 */
/*
 * time.h
 *
 * Type definitions and function declarations relating to date and time.
 *
 * $Id: time.h,v c10027655651 2018/10/18 08:50:58 keith $
 *
 * Written by Colin Peters <colin@bird.fu.is.saga-u.ac.jp>
 * Copyright (C) 1997-2007, 2011, 2015-2018, MinGW.org Project.
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice, this permission notice, and the following
 * disclaimer shall be included in all copies or substantial portions of
 * the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OF OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */
#if ! defined _TIME_H || defined __need_time_t
#pragma GCC system_header

/* Irrespective of whether this is normal or selective inclusion of
 * <time.h>, we ALWAYS require the definition for time_t; get it by
 * selective inclusion from its primary source, in <sys/types.h>;
 * note that we must ALWAYS delegate this, when __need_time_t is
 * defined, even when _TIME_H had been defined previously, to ensure
 * that __need_time_t is properly reset, and thus cannot compromise
 * a later inclusion of <sys/types.h>
 */
#undef __need_time_h
#define __need_time_t  1
#ifndef _TIME_H
/* To support selective partial inclusion, we do not immediately define
 * the normal _TIME_H guard macro; initially, we also clear all of those
 * declaraction subset selection macros which are applicable herein.
 */
#undef __need_struct_timespec
#undef __need_wchar_decls

#if defined __SCHED_H_SOURCED__
/* This is selective inclusion by <sched.h>; although not a standard
 * MinGW.org header, we provide this hook to grant access from third
 * party implementations, (e.g. pthreads-win32), to get a definition
 * for struct timespec, which POSIX requires it to provide.
 *
 * Note that, in common with all selective inclusion strategies, we
 * do not define the _TIME_H guard macro in this case, and we select
 * only the minimally required subset of declarations to be exposed
 * from within <time.h>, as required by <sched.h>
 */
# define __need_struct_timespec  1

#elif defined __WCHAR_H_SOURCED__
/* This is selective inclusion by <wchar.h>; thus, we do not define the
 * _TIME_H guard macro, and we select only the minimally required subset
 * of declarations to be exposed from within <time.h>
 */
# define __need_wchar_decls  1

/* Both ISO-C and POSIX stipulate that <wchar.h> shall declare "struct tm"
 * as an incomplete structure, with its complete declaration to be provided
 * by <time.h>; provide an incomplete forward declaration, to satisfy this
 * minimal requirement for selective inclusion by <wchar.h>
 */
struct tm;

#else
#define _TIME_H
/* This is normal inclusion of <time.h>, in its own right.  All our system
 * headers are required to include <_mingw.h>, but in the case of selective
 * inclusion, we delegate that responsibility to the including header; when
 * including <time.h> directly, we must fulfil this requirement now.
 */
#define CLOCKS_PER_SEC	((clock_t)(1000))
#define CLK_TCK 	CLOCKS_PER_SEC

#define __need_struct_timespec  1
#define __need_wchar_decls  1
#endif

#ifndef RC_INVOKED
#if defined __need_struct_timespec && ! __struct_timespec_defined
/* Structure timespec is mandated by POSIX, for specification of
 * intervals with the greatest precision supported by the OS kernel.
 * Although this allows for specification to nanosecond precision, do
 * not be deluded into any false expectation that such short intervals
 * can be realized on Windows; on Win9x derivatives, the metronome used
 * by the process scheduler has a period of ~55 milliseconds, while for
 * WinNT derivatives, the corresponding period is ~15 milliseconds; thus,
 * the shortest intervals which can be realistically timed will range
 * from 0..55 milliseconds on Win9x hosts, and from 0..15 ms on WinNT,
 * with period values normally distributed around means of ~27.5 ms
 * and ~7.5 ms, for the two system types respectively.
 */
struct timespec
{ /* Period is sum of tv_sec + tv_nsec; while 32-bits is sufficient
   * to accommodate tv_nsec, we use 64-bit __time64_t for tv_sec, to
   * ensure that we have a sufficiently large field to accommodate
   * Microsoft's ambiguous __time32_t vs. __time64_t representation
   * of time_t; we may resolve this ambiguity locally, by casting a
   * pointer to a struct timespec to point to an identically sized
   * struct __mingw32_timespec, which is defined below.
   */
  __time64_t	  tv_sec;	/* seconds; accept 32 or 64 bits */
  __int32  	  tv_nsec;	/* nanoseconds */
};

# ifdef _MINGW32_SOURCE_EXTENDED
struct __mingw32_expanded_timespec
{
  /* Equivalent of struct timespec, with disambiguation for the
   * 32-bit vs. 64-bit tv_sec field declaration.  Period is the
   * sum of tv_sec + tv_nsec; we use explicitly sized types to
   * avoid 32-bit vs. 64-bit time_t ambiguity...
   */
  union
  { /* ...within this anonymous union, allowing tv_sec to accommodate
     * seconds expressed in either of Microsoft's (ambiguously sized)
     * time_t representations.
     */
    __time64_t	__tv64_sec;	/* unambiguously 64 bits */
    __time32_t	__tv32_sec;	/* unambiguously 32 bits */
    time_t	  tv_sec;	/* ambiguously 32 or 64 bits */
  };
  __int32  	  tv_nsec;	/* nanoseconds */
};
# endif /* _MINGW32_SOURCE_EXTENDED */

# define __struct_timespec_defined  1
#endif

#ifdef _TIME_H
#ifdef _MINGW32_SOURCE_EXTENDED

_BEGIN_C_DECLS

__CRT_ALIAS __LIBIMPL__(( FUNCTION = mingw_timespec ))
/* This non-ANSI convenience function facilitates access to entities
 * defined as struct timespec, while exposing the broken down form of
 * the tv_sec field, as declared within struct __mingw32_timespec.  It
 * is exposed only when _MINGW32_SOURCE_EXTENDED is defined, which is
 * normally implicitly the case, except when in __STRICT_ANSI__ mode
 * unless the user defines it explicitly.
 */
struct __mingw32_expanded_timespec *mingw_timespec( struct timespec *__tv )
{ return (struct __mingw32_expanded_timespec *)(__tv); }

_END_C_DECLS

#endif	/* _MINGW32_SOURCE_EXTENDED */

/* <time.h> is also required to duplicate the following type definitions,
 * which are nominally defined in <stddef.h>
 */
#define __need_NULL
#define __need_wchar_t
#define __need_size_t
#if __MSVCRT_VERSION__ < __MSVCR80_DLL
 /* Although specified as ISO-C functions, Microsoft withdrew direct
  * support for these, with their ISO-C names, from MSVCR80.DLL onwards,
  * preferring to map them via header file macros, to alternatively named
  * DLL functions with ambiguous time_t representations; they remain in
  * MSVCRT.DLL, however, with their original ISO-C names, and time_t
  * unambiguously represented as a 32-bit data type.
  */
_CRTIMP __cdecl __MINGW_NOTHROW  time_t time (time_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  double difftime (time_t, time_t);
_CRTIMP __cdecl __MINGW_NOTHROW  time_t mktime (struct tm *);
#endif

/* These functions write to and return pointers to static buffers that may
 * be overwritten by other function calls. Yikes!
 *
 * NOTE: localtime, and perhaps the others of the four functions grouped
 * below may return NULL if their argument is not 'acceptable'. Also note
 * that calling asctime with a NULL pointer will produce an Invalid Page
 * Fault and crap out your program. Guess how I know. Hint: stat called on
 * a directory gives 'invalid' times in st_atime etc...
 */
_CRTIMP __cdecl __MINGW_NOTHROW  char *asctime (const struct tm *);

#if __MSVCRT_VERSION__ < __MSVCR80_DLL
 /* Once again, these have been withdrawn from MSVCR80.DLL, (and later),
  * but remain in MSVCRT.DLL, with unambiguously 32-bit time_t.
  */
_CRTIMP __cdecl __MINGW_NOTHROW  char *ctime (const time_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  struct tm *gmtime (const time_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  struct tm *localtime (const time_t *);
#endif

_CRTIMP __cdecl __MINGW_NOTHROW
size_t strftime (char *, size_t, const char *, const struct tm *);

#ifndef __STRICT_ANSI__
extern _CRTIMP __cdecl __MINGW_NOTHROW  void _tzset (void);

#ifndef _NO_OLDNAMES
extern _CRTIMP __cdecl __MINGW_NOTHROW  void tzset (void);
#endif

_CRTIMP __cdecl __MINGW_NOTHROW  char *_strdate (char *);
_CRTIMP __cdecl __MINGW_NOTHROW  char *_strtime (char *);

#if __MSVCRT_VERSION__ >= __MSVCR61_DLL || _WIN32_WINNT >= _WIN32_WINNT_WIN2K
/* These 64-bit time_t variant functions first became available in
 * MSVCR61.DLL, and its descendants; they were subsequently included
 * in MSVCRT.DLL, from its Win2K release onwards.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  __time64_t _time64( __time64_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  __time64_t _mktime64 (struct tm *);
_CRTIMP __cdecl __MINGW_NOTHROW    char *_ctime64 (const __time64_t *);
_CRTIMP __cdecl __MINGW_NOTHROW    struct tm *_gmtime64 (const __time64_t *);
_CRTIMP __cdecl __MINGW_NOTHROW    struct tm *_localtime64 (const __time64_t *);

#endif	/* __MSVCR61_DLL, _WIN32_WINNT_WIN2K, and descendants. */

#if __MSVCRT_VERSION__ >= __MSVCR80_DLL || _WIN32_WINNT >= _WIN32_WINNT_VISTA
 /* The following were introduced in MSVCR80.DLL, and they subsequently
  * appeared in MSVCRT.DLL, from Windows-Vista onwards.
  */
_CRTIMP __cdecl __MINGW_NOTHROW    char *_ctime32 (const __time32_t *);
_CRTIMP __cdecl __MINGW_NOTHROW    double _difftime32 (__time32_t, __time32_t);
_CRTIMP __cdecl __MINGW_NOTHROW    double _difftime64 (__time64_t, __time64_t);
_CRTIMP __cdecl __MINGW_NOTHROW    struct tm *_gmtime32 (const __time32_t *);
_CRTIMP __cdecl __MINGW_NOTHROW    struct tm *_localtime32 (const __time32_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  __time32_t _mktime32 (struct tm *);
_CRTIMP __cdecl __MINGW_NOTHROW  __time32_t _mkgmtime32 (struct tm *);
_CRTIMP __cdecl __MINGW_NOTHROW  __time64_t _mkgmtime64 (struct tm *);
_CRTIMP __cdecl __MINGW_NOTHROW  __time32_t _time32 (__time32_t *);

# if __MSVCRT_VERSION__ >= __MSVCR80_DLL && defined _USE_32BIT_TIME_T
  /* Users of MSVCR80.DLL and later, (but not users of MSVCRT.DLL, even
   * for _WIN32_WINNT_VISTA and later), must contend with the omission of
   * the following functions from their DLL of choice, thus requiring these
   * brain damaged mappings, in terms of an ambiguously defined 'time_t';
   * thus, when 'time_t' is declared to be equivalent to '__time32_t':
   */
__CRT_ALIAS __cdecl __MINGW_NOTHROW  time_t time (time_t *__v)
 { return _time32 (__v); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW  double difftime (time_t __v1, time_t __v2)
 { return _difftime32 (__v1, __v2); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW  time_t mktime (struct tm *__v)
 { return _mktime32 (__v); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW  time_t _mkgmtime (struct tm *__v)
 { return _mkgmtime32 (__v); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW  char *ctime (const time_t *__v)
 { return _ctime32 (__v); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW  struct tm *gmtime (const time_t *__v)
 { return _gmtime32 (__v); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW  struct tm *localtime (const time_t *__v)
 { return _localtime32 (__v); }

# elif __MSVCRT_VERSION__ >= __MSVCR80_DLL
  /* Correspondingly, for users of MSVCR80.DLL and later only, when there
   * is no explicit declaration to direct the specification of 'time_t', and
   * thus 'time_t' is assumed to be equivalent to '__time64_t':
   */
__CRT_ALIAS __cdecl __MINGW_NOTHROW  time_t time (time_t *__v)
 { return _time64 (__v); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW  double difftime (time_t __v1, time_t __v2)
 { return _difftime64 (__v1, __v2); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW  time_t mktime (struct tm *__v)
 { return _mktime64 (__v); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW  time_t _mkgmtime (struct tm *__v)
 { return _mkgmtime64 (__v); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW  char *ctime (const time_t *__v)
 { return _ctime64 (__v); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW  struct tm *gmtime (const time_t *__v)
 { return _gmtime64 (__v); }

__CRT_ALIAS __cdecl __MINGW_NOTHROW  struct tm *localtime (const time_t *__v)
 { return _localtime64 (__v); }

# endif /* _USE_32BIT_TIME_T brain damage */
#endif	/* >=__MSVCR80.DLL || >=_WIN32_WINNT_VISTA */

/* _daylight: non zero if daylight savings time is used.
 * _timezone: difference in seconds between GMT and local time.
 * _tzname: standard/daylight savings time zone names (an array with two
 *          elements).
 */
#ifdef __MSVCRT__
/* These are for compatibility with pre-VC 5.0 supplied MSVCRT.DLL
 */
extern _CRTIMP __cdecl __MINGW_NOTHROW  int   *__p__daylight (void);
extern _CRTIMP __cdecl __MINGW_NOTHROW  long  *__p__timezone (void);
extern _CRTIMP __cdecl __MINGW_NOTHROW  char **__p__tzname (void);

__MINGW_IMPORT int   _daylight;
__MINGW_IMPORT long  _timezone;
__MINGW_IMPORT char *_tzname[2];

#else /* !__MSVCRT__ (i.e. using CRTDLL.DLL) */
#ifndef __DECLSPEC_SUPPORTED

extern int   *_imp___daylight_dll;
extern long  *_imp___timezone_dll;
extern char **_imp___tzname;

#define _daylight  (*_imp___daylight_dll)
#define _timezone  (*_imp___timezone_dll)
#define _tzname	   (*_imp___tzname)

#else /* __DECLSPEC_SUPPORTED */

__MINGW_IMPORT int   _daylight_dll;
__MINGW_IMPORT long  _timezone_dll;
__MINGW_IMPORT char *_tzname[2];

#define _daylight  _daylight_dll
#define _timezone  _timezone_dll

#endif /* __DECLSPEC_SUPPORTED */
#endif /* ! __MSVCRT__ */
#endif /* ! __STRICT_ANSI__ */

#ifndef _NO_OLDNAMES
#ifdef __MSVCRT__

/* These go in the oldnames import library for MSVCRT.
 */
__MINGW_IMPORT int   daylight;
__MINGW_IMPORT long  timezone;
__MINGW_IMPORT char *tzname[2];

#else /* ! __MSVCRT__ */
/* CRTDLL is royally messed up when it comes to these macros.
 * TODO: import and alias these via oldnames import library instead
 * of macros.
 */
#define daylight  _daylight

/* NOTE: timezone not defined as a macro because it would conflict with
 * struct timezone in sys/time.h.  Also, tzname used to a be macro, but
 * now it's in moldname.
 */
__MINGW_IMPORT char 	*tzname[2];

#endif	/* ! __MSVCRT__ */
#endif	/* ! _NO_OLDNAMES */

#if _POSIX_C_SOURCE
/* The nanosleep() function provides the most general purpose API for
 * process/thread suspension; it provides for specification of periods
 * ranging from ~7.5 ms mean, (on WinNT derivatives; ~27.5 ms on Win9x),
 * extending up to ~136 years, (effectively eternity).
 */
__cdecl __MINGW_NOTHROW
int nanosleep( const struct timespec *, struct timespec * );

#ifndef __NO_INLINE__
/* We may conveniently provide an in-line implementation here,
 * in terms of the __mingw_sleep() helper function.
 */
__cdecl __MINGW_NOTHROW
int __mingw_sleep( unsigned long, unsigned long );

__CRT_INLINE __LIBIMPL__(( FUNCTION = nanosleep ))
int nanosleep( const struct timespec *period, struct timespec *residual )
{
  if( residual != (void *)(0) )
    residual->tv_sec = (__time64_t)(residual->tv_nsec = 0);
  return __mingw_sleep((unsigned)(period->tv_sec), (period->tv_sec < 0LL)
    ? (unsigned)(-1) : (unsigned)(period->tv_nsec));
}
#endif	/* !__NO_INLINE__ */

#if _POSIX_C_SOURCE >= 199309L
/* POSIX.1b-1993 introduced the optional POSIX clocks API; it
 * was subsequently moved to "base", as of POSIX.1-2008, to the
 * extent required to support the CLOCK_REALTIME feature, with
 * the remainder of its features remaining optional.  We choose
 * to provide a subset, supporting CLOCK_MONOTONIC in addition
 * to the aforementioned CLOCK_REALTIME feature.
 *
 * We define the POSIX clockid_t type as a pointer to an opaque
 * structure; user code should never need to know details of the
 * internal layout of this structure.
 */
typedef struct __clockid__ *clockid_t;

/* POSIX prefers to have the standard clockid_t entities defined
 * as macros, each of which represents an entity of type clockid_t.
 * Since this is not an integer data type, POSIX does not strictly
 * require such macros to expand to constant expressions; however,
 * some ill-behaved applications, (GCC's Ada implementation is one
 * such), depend on such expansions.  Thus, although it will incur
 * a small additional run-time overhead to interpret them, we map
 * such entities in terms of pseudo-pointer references, (which we
 * discriminate from real pointer references, which we assume to
 * be always to even valued addresses, by forcing odd values for
 * the pseudo-pointer references).
 */
#define __MINGW_POSIX_CLOCKAPI(ID)  ((clockid_t)(1 + ((ID) << 1)))

/* The standard clockid_t entities which we choose to support.
 */
#define CLOCK_REALTIME  __MINGW_POSIX_CLOCKAPI (0)
#define CLOCK_MONOTONIC __MINGW_POSIX_CLOCKAPI (1)

/* Prototypes for the standard POSIX functions which provide the
 * API to these standard clockid_t entities.
 */
int clock_getres (clockid_t, struct timespec *);
int clock_gettime (clockid_t, struct timespec *);
int clock_settime (clockid_t, const struct timespec *);

#endif	/* _POSIX_C_SOURCE >= 199309L */
#endif	/* _POSIX_C_SOURCE */

_END_C_DECLS

#endif	/* _TIME_H included in its own right */

#if __need_wchar_decls && ! (defined _TIME_H && defined _WCHAR_H)
/* Wide character time function prototypes.  These are nominally declared
 * both here, in <time.h>, and also in <wchar.h>; we declare them here, and
 * make them available for selective inclusion by <wchar.h>, but such that
 * the declarations, and in particular any in-line implementation of the
 * _wctime() function, are visible only on the first time parse, when
 * one of either _TIME_H, or _WCHAR_H, but not both, is defined.
 */
_BEGIN_C_DECLS

#if defined __MSVCRT__ && ! defined __STRICT_ANSI__
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *_wasctime (const struct tm *);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *_wstrdate (wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *_wstrtime (wchar_t *);

#if __MSVCRT_VERSION__ >= __MSVCR61_DLL || _WIN32_WINNT >= _WIN32_WINNT_WIN2K
/* A __time64_t specific variant of _wctime(), identified as _wctime64(),
 * first appeared in the non-free MSVC specific MSVCR61.DLL, and was added
 * to the freely available platform MSVCRT.DLL from Win2K onwards...
 */
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *_wctime64 (const __time64_t *);
#endif
#if __MSVCRT_VERSION__ >= __MSVCR80_DLL || _WIN32_WINNT >= _WIN32_WINNT_VISTA
/* ...whereas its __time32_t specific counterpart, _wctime32(), did not
 * make an appearance until MSVCR80.DLL, and was not added to MSVCRT.DLL
 * until the release of Vista.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *_wctime32 (const __time32_t *);
#endif
#if __MSVCRT_VERSION__ < __MSVCR80_DLL
/* Present in all versions of MSVCRT.DLL, but withdrawn from non-free
 * MSVC specific releases from MSVCR80.DLL onwards; in all versions of
 * MSVCRT.DLL, _wctime() accepts a 32-bit time_t argument pointer.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *_wctime (const time_t *);

#else /* __MSVCRT_VERSION__ >= __MSVCR80_DLL */
/* For users of the non-free MSVC libraries, we must deal with both the
 * absence of _wctime(), and with Microsoft's attendant _USE_32BIT_TIME_T
 * brain damage, as we map an inline replacement...
 */
__CRT_ALIAS __cdecl __MINGW_NOTHROW  wchar_t *_wctime (const time_t *__v)
{
  /* ...in terms of an appropriately selected time_t size specific
   * alternative function, which should be available...
   */
# ifdef _USE_32BIT_TIME_T
  /* ...i.e. the __time32_t specific _wctime32(), when the user has
   * enabled this choice; (the only sane choice, if compatibility with
   * MSVCRT.DLL is desired)...
   */
  return _wctime32 (__v);

# else	/* !_USE_32BIT_TIME_T */
  /* ...or otherwise, the __time64_t specific _wctime64(), (in which
   * case, compatibility with MSVCRT.DLL must be sacrificed).
   */
  return _wctime64 (__v);
# endif	/* !_USE_32BIT_TIME_T */
}
#endif	/* __MSVCRT_VERSION__ >= __MSVCR80_DLL */
#endif	/* __MSVCRT__ && !__STRICT_ANSI__ */

_CRTIMP __cdecl __MINGW_NOTHROW
size_t wcsftime (wchar_t *, size_t, const wchar_t *, const struct tm *);

_END_C_DECLS

#endif	/* ! (defined _TIME_H && defined _WCHAR_H) */

/* We're done with all <time.h> specific content selectors; clear them.
 */
#undef __need_time_t
#undef __need_struct_timespec
#undef __need_wchar_decls

#endif /* ! RC_INVOKED */
#endif /* !_TIME_H after __need_time_t processing */
#endif /* !_TIME_H: $RCSfile: time.h,v $: end of file */
 /* ...we always obtain an opaque forward declaration of:
 *
 *  struct tm
 *
 * ...and prototype declarations for the following ISO-C99 function,
 * (which is always provided):
 *
 *  size_t wcsftime (wchar_t *, size_t, const wchar_t *, const struct tm *);
 *
 * ...together with the following non-ISO-C functions, (which are
 * NOT exposed when "__STRICT_ANSI__" checking is enabled):
 *
 *  wchar_t *_wctime (const time_t *);
 *  wchar_t *_wasctime (const struct tm *);
 *  wchar_t *_wstrdate (wchar_t *);
 *  wchar_t *_wstrtime (wchar_t *);
 *
 * Of the preceding group, we also note that, while it remains in
 * all versions of MSVCRT.DLL, (using a strictly 32-bit data type
 * to represent its "time_t" argument), the _wctime() function is
 * NOT present in MSVCR80.DLL, and later versions of the non-free
 * MSVC runtime libraries, in which it is replaced by either of:
 *
 *  wchar_t *_wctime64 (const __time64_t *);
 *  wchar_t *_wctime32 (const __time32_t *);
 *
 * ...with the actual replacement being chosen at compile time, on
 * the basis of the user specified "_USE_32BIT_TIME_T" feature test
 * macro, (a Microsoft specific, brain damaged concept), which maps
 * _wctime() itself, as an in-line alias for its corresponding
 * replacement library function.
 *
 */
#ifndef __STRICT_ANSI__
/* Once again, when NOT compiling with "__STRICT_ANSI__" conformity
 * checking, from...
 */
/*
 * process.h
 *
 * Declarations of functions for spawning child processes.
 *
 * $Id: process.h,v 4673484ef852 2020/01/17 16:58:38 keith $
 *
 * Written by Colin Peters <colin@bird.fu.is.saga-u.ac.jp>
 * Copyright (C) 1997-2001, 2003-2004, 2007-2008, 2016, MinGW.org Project.
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice, this permission notice, and the following
 * disclaimer shall be included in all copies or substantial portions of
 * the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OF OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef _PROCESS_H
#pragma GCC system_header

/* Defer defining the normal _PROCESS_H multiple inclusion guard macro,
 * to facilitate selective inclusion by <wchar.h>, (in which case we do
 * not wish to define it).
 */
#ifndef __WCHAR_H_SOURCED__
#define _PROCESS_H

/* All MinGW headers must include <_mingw.h>; do so here, assuming
 * that <wchar.h> will have already taken care of it, for the case
 * of selective inclusion.
 */
#define _WAIT_CHILD		0
#define _WAIT_GRANDCHILD	1

#ifndef _NO_OLDNAMES
#define WAIT_CHILD		_WAIT_CHILD
#define WAIT_GRANDCHILD 	_WAIT_GRANDCHILD
#endif	/* !_NO_OLDNAMES */
#endif	/* !__WCHAR_H_SOURCED__ */

/* Mode constants for spawn() functions.
 */
#define _P_WAIT 		0
#define _P_NOWAIT		1
#define _P_OVERLAY		2
#define _OLD_P_OVERLAY		_P_OVERLAY
#define _P_NOWAITO		3
#define _P_DETACH		4

#ifndef _NO_OLDNAMES
#define P_WAIT			_P_WAIT
#define P_NOWAIT		_P_NOWAIT
#define P_OVERLAY		_P_OVERLAY
#define OLD_P_OVERLAY		_OLD_P_OVERLAY
#define P_NOWAITO		_P_NOWAITO
#define P_DETACH		_P_DETACH
#endif	/* !_NO_OLDNAMES */

#ifndef RC_INVOKED

/* All Microsoft implementations of the exec() and spawn() functions
 * are declared with intptr_t as their return type; get its definition
 * by selective inclusion from "stdint.h"; (note: use #include "..."
 * here, to avoid side effects from any alternative <stdint.h>, which
 * is not in the same directory as this <process.h>).
 */
#define __need_intptr_t
#ifdef _PROCESS_H
_CRTIMP __cdecl __MINGW_NOTHROW  void _cexit (void);
_CRTIMP __cdecl __MINGW_NOTHROW  void _c_exit (void);

_CRTIMP __cdecl __MINGW_NOTHROW  int _cwait (int *, _pid_t, int);

_CRTIMP __cdecl __MINGW_NOTHROW  _pid_t _getpid (void);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _execl (const char *, const char *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _execle (const char *, const char *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _execlp (const char *, const char *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _execlpe (const char *, const char *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _execv (const char *, const char * const *);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _execve (const char *, const char * const *, const char * const *);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _execvp (const char *, const char * const *);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _execvpe (const char *, const char * const *, const char * const *);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _spawnl (int, const char *, const char *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _spawnle (int, const char *, const char *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _spawnlp (int, const char *, const char *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _spawnlpe (int, const char *, const char *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _spawnv (int, const char *, const char * const *);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _spawnve (int, const char *, const char * const *, const char * const *);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _spawnvp (int, const char *, const char * const *);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _spawnvpe (int, const char *, const char * const *, const char * const *);

/* Thread initiation and termination functions.
 *
 * NOTE: Apparently _endthread() calls CloseHandle() on the handle of the
 * thread, creating a potential for race conditions, if you are not careful.
 * Basically, you MUST ensure that NOTHING attempts to do ANYTHING with the
 * thread handle after the thread calls _endthread(), or returns from the
 * thread function.
 *
 * NOTE: No old names for these functions.  Use the underscore.
 */
_CRTIMP __cdecl __MINGW_NOTHROW
unsigned long _beginthread (void (*)(void *), unsigned, void *);

_CRTIMP __cdecl __MINGW_NOTHROW  void _endthread (void);

#ifdef __MSVCRT__
_CRTIMP __cdecl __MINGW_NOTHROW  unsigned long _beginthreadex
(void *, unsigned, unsigned (__stdcall *) (void *), void *, unsigned, unsigned *);

_CRTIMP __cdecl __MINGW_NOTHROW  void _endthreadex (unsigned);
#endif

#ifndef _NO_OLDNAMES
/* Functions named without the leading underscore, for portability.
 * These functions live in liboldnames.a.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int cwait (int *, pid_t, int);
_CRTIMP __cdecl __MINGW_NOTHROW  pid_t getpid (void);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t execl (const char *, const char *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t execle (const char *, const char *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t execlp (const char *, const char *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t execlpe (const char *, const char *,...);

#if __IN_MINGWRT_TESTSUITE__ && __GNUC__ >= 7
/* From GCC-7 onwards, with "-Wsystem-headers" enabled, the compiler may
 * emit unwanted "-Wbuiltin-declaration-mismatch" diagnostics related to
 * the following "execv" function declarations; these will precipitate
 * testsuite failures, so suppress them.
 */
# if __GNUC__ >= 9 || defined __cplusplus
  /* Prior to GCC-9, this limitation was apparent in the C++ compiler
   * only; it became apparent in the C compiler, from GCC-9.
   */
#  pragma GCC diagnostic ignored "-Wbuiltin-declaration-mismatch"
# endif
#endif

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t execv (const char *, const char * const *);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t execve (const char *, const char * const *, const char * const *);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t execvp (const char *, const char * const *);

#if defined __cplusplus && __IN_MINGWRT_TESTSUITE__ && __GNUC__ >= 7
/* Re-enable previously suppressed "-Wbuiltin-declaration-mismatch" warnings.
 */
# pragma GCC diagnostic warning "-Wbuiltin-declaration-mismatch"
#endif

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t execvpe (const char *, const char * const *, const char * const *);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t spawnl (int, const char *, const char *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t spawnle (int, const char *, const char *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t spawnlp (int, const char *, const char *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t spawnlpe (int, const char *, const char *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t spawnv (int, const char *, const char * const *);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t spawnve (int, const char *, const char * const *, const char * const *);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t spawnvp (int, const char *, const char * const *);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t spawnvpe (int, const char *, const char * const *, const char * const *);

#endif	/* !_NO_OLDNAMES */
#endif	/* _PROCESS_H */

#if ! (defined _PROCESS_H && defined _WCHAR_H)
/* Wide character variations of the exec() and spawn() functions are
 * declared both when <process.h> is included directly, and when it is
 * selectively included by <wchar.h>; however, if both _PROCESS_H and
 * _WCHAR_H are defined, by the time we get to here, then this must be
 * the direct inclusion case, and these have already been declared as
 * a result of selective inclusion; there is no need to declare them
 * a second time.
 */
_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _wexecl (const wchar_t *, const wchar_t *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _wexecle (const wchar_t *, const wchar_t *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _wexeclp (const wchar_t *, const wchar_t *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _wexeclpe (const wchar_t *, const wchar_t *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _wexecv (const wchar_t *, const wchar_t * const *);

_CRTIMP __cdecl __MINGW_NOTHROW  intptr_t _wexecve
(const wchar_t *, const wchar_t * const *, const wchar_t * const *);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _wexecvp (const wchar_t *, const wchar_t * const *);

_CRTIMP __cdecl __MINGW_NOTHROW  intptr_t _wexecvpe
(const wchar_t *, const wchar_t * const *, const wchar_t * const *);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _wspawnl (int, const wchar_t *, const wchar_t *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _wspawnle (int, const wchar_t *, const wchar_t *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _wspawnlp (int, const wchar_t *, const wchar_t *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _wspawnlpe (int, const wchar_t *, const wchar_t *, ...);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _wspawnv (int, const wchar_t *, const wchar_t * const *);

_CRTIMP __cdecl __MINGW_NOTHROW  intptr_t _wspawnve
(int, const wchar_t *, const wchar_t * const *, const wchar_t * const *);

_CRTIMP __cdecl __MINGW_NOTHROW
intptr_t _wspawnvp (int, const wchar_t *, const wchar_t * const *);

_CRTIMP __cdecl __MINGW_NOTHROW intptr_t _wspawnvpe
(int, const wchar_t *, const wchar_t * const *, const wchar_t * const *);

#endif	/* ! (_PROCESS_H && _WCHAR_H) */

_END_C_DECLS

#endif	/* ! RC_INVOKED */
#endif	/* !_PROCESS_H: $RCSfile: process.h,v $: end of file */
 /* ...we obtain function prototypes for:
 *
 *  intptr_t _wexecl (const wchar_t *, const wchar_t *, ...);
 *  intptr_t _wexecle (const wchar_t *, const wchar_t *, ...);
 *  intptr_t _wexeclp (const wchar_t *, const wchar_t *, ...);
 *  intptr_t _wexeclpe (const wchar_t *, const wchar_t *, ...);
 *
 *  intptr_t _wexecv (const wchar_t *, const wchar_t * const *);
 *  intptr_t _wexecve (
 *    const wchar_t *, const wchar_t * const *, const wchar_t * const *
 *   );
 *  intptr_t _wexecvp (const wchar_t *, const wchar_t * const *);
 *  intptr_t _wexecvpe (
 *    const wchar_t *, const wchar_t * const *, const wchar_t * const *
 *   );
 *
 *  intptr_t _wspawnl (int, const wchar_t *, const wchar_t *, ...);
 *  intptr_t _wspawnle (int, const wchar_t *, const wchar_t *, ...);
 *  intptr_t _wspawnlp (int, const wchar_t *, const wchar_t *, ...);
 *  intptr_t _wspawnlpe (int, const wchar_t *, const wchar_t *, ...);
 *
 *  intptr_t _wspawnv (int, const wchar_t *, const wchar_t * const *);
 *  intptr_t _wspawnve (
 *    int, const wchar_t *, const wchar_t * const *, const wchar_t * const *
 *   );
 *  intptr_t _wspawnvp (int, const wchar_t *, const wchar_t * const *);
 *  intptr_t _wspawnvpe (
 *    int, const wchar_t *, const wchar_t * const *, const wchar_t * const *
 *   );
 *
 */
#endif	/* !__STRICT_ANSI__ */

_BEGIN_C_DECLS

/* Wide character string functions must be specified here, as required
 * by the ISO-C Standard; however, MSVC contravenes this standard by also
 * requiring them to appear in <string.h>.  We declare them here, where
 * they rightfully belong, but we also arrange for them to be available
 * for selective inclusion by <string.h>; to facilitate this, we must
 * change the declarative condition...
 */
#endif	/* ! RC_INVOKED */
#endif	/* !__STRING_H_SOURCED__ */
#if ! defined RC_INVOKED
#if !(defined _WCHAR_H && (defined _STRING_H && ! defined __STRICT_ANSI__))
/* ...such that these declarations are exposed when either _WCHAR_H is defined,
 * or when _STRING_H is defined and __STRICT_ANSI__ is not, but NOT when BOTH of
 * these apply, since that indicates that this group of declarations has already
 * been processed, during partial inclusion of <wchar.h> by <string.h>, whereas
 * we are now including <wchar.h> in its own right.
 *
 *
 * Wide character versions of the ISO-C standard string functions.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *wcscat (wchar_t *, const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *wcschr (const wchar_t *, wchar_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int wcscmp (const wchar_t *, const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  int wcscoll (const wchar_t *, const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *wcscpy (wchar_t *, const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  size_t wcscspn (const wchar_t *, const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  size_t wcslen (const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *wcsncat (wchar_t *, const wchar_t *, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int wcsncmp (const wchar_t *, const wchar_t *, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *wcsncpy (wchar_t *, const wchar_t *, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *wcspbrk (const wchar_t *, const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *wcsrchr (const wchar_t *, wchar_t);
_CRTIMP __cdecl __MINGW_NOTHROW  size_t wcsspn (const wchar_t *, const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *wcsstr (const wchar_t *, const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *wcstok (wchar_t *, const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  size_t wcsxfrm (wchar_t *, const wchar_t *, size_t);

#ifndef __STRICT_ANSI__
/* UTF-16LE versions of non-ANSI string functions provided by CRTDLL.DLL
 */
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *_wcsdup (const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  int _wcsicmp (const wchar_t *, const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  int _wcsicoll (const wchar_t *, const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *_wcslwr (wchar_t*);
_CRTIMP __cdecl __MINGW_NOTHROW  int _wcsnicmp (const wchar_t *, const wchar_t *, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *_wcsnset (wchar_t *, wchar_t, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *_wcsrev (wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *_wcsset (wchar_t *, wchar_t);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *_wcsupr (wchar_t *);

#ifdef __MSVCRT__
_CRTIMP __cdecl __MINGW_NOTHROW  int _wcsncoll (const wchar_t *, const wchar_t *, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int _wcsnicoll (const wchar_t *, const wchar_t *, size_t);

/* A wide character counterpart to the strerror() API was introduced in
 * MSVCR70.DLL, and subsequently back-ported to MSVCRT.DLL in WinXP.
 */
#if __MSVCRT_VERSION__ >= __MSVCR70_DLL || NTDDI_VERSION >= NTDDI_WINXP
 /*
  * These are are the wide character counterparts to the strerror()
  * function itself, and the _strerror() function, respectively.
  */
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *_wcserror (int);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *__wcserror (const wchar_t *);

#endif	/* MSVCR70.DLL || WinXP */
#endif	/* __MSVCRT__ */

/* MSVCRT.DLL provides neither _wcscmpi() nor wcscmpi(); the heritage
 * is uncertain, but for the convenience, (and portability), of legacy
 * applications which assume wcscmpi() should be available:
 */
#define _wcscmpi _wcsicmp
int __cdecl __MINGW_NOTHROW  wcscmpi (const wchar_t *, const wchar_t *);

#ifndef __NO_INLINE__
__CRT_ALIAS __JMPSTUB__(( FUNCTION = wcscmpi, REMAPPED = _wcsicmp ))
  int wcscmpi (const wchar_t *__ws1, const wchar_t *__ws2)
  { return _wcsicmp (__ws1, __ws2); }
#endif	/* __NO_INLINE__ */

#ifndef _NO_OLDNAMES
/* Older CRTDLL.DLL versions may have provided these alternatively named
 * functions; we continue to support them, via the OLDNAME libraries:
 */
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *wcsdup (const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  int wcsicmp (const wchar_t *, const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  int wcsicoll (const wchar_t *, const wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *wcslwr (wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  int wcsnicmp (const wchar_t *, const wchar_t *, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *wcsnset (wchar_t *, wchar_t, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *wcsrev (wchar_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *wcsset (wchar_t *, wchar_t);
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *wcsupr (wchar_t *);

#endif	/* !_NO_OLDNAMES */
#endif	/* !__STRICT_ANSI__ */

#if _POSIX_C_SOURCE >= 200809L
#if __MSVCRT_VERSION__ >= __MSVCR80_DLL
/* MSVCR80.DLL adds a (mostly) POSIX.1-2008 conforming wcsnlen(); (it's
 * also available in MSVCRT.DLL from _WIN32_WINNT_VISTA onwards, but we
 * pretend otherwise, since recent GCC will try to use the function when
 * it can be found in libmsvcrt.a, so breaking it for use on WinXP and
 * earlier).
 */
#ifndef __STRICT_ANSI__   /* N.B.: this is not an ISO-C function */
_CRTIMP __cdecl __MINGW_NOTHROW  char *wcsnlen (const wchar_t *, size_t);
#endif

#else	/* MSVCRT.DLL || pre-MSVCR80.DLL */
/* Emulation, to support recent POSIX.1; we prefer this for ALL versions
 * of MSVCRT.DLL, (even those which already provide wcsnlen()); to avoid
 * the GCC breakage noted above.  (Note that we implement wcsnlen() with
 * the alternative external name, __mingw_wcsnlen() in libmingwex.a, to
 * avoid possible link time collision with MSVCR80.DLL's implementation,
 * then map this to wcsnlen() via a __CRT_ALIAS, with stubs designated
 * for linking from within the appropriate oldname libraries.
 */
extern size_t __mingw_wcsnlen (const wchar_t *, size_t);

__JMPSTUB__(( LIB=coldname; FUNCTION=wcsnlen ))
__CRT_ALIAS size_t wcsnlen (const wchar_t *__text, size_t __maxlen)
{ return __mingw_wcsnlen (__text, __maxlen); }

#endif	/* MSVCRT.DLL || pre-MSVCR80.DLL */
#endif	/* _POSIX_C_SOURCE >= 200809L */

/* This completes the set of declarations which are to be duplicated by
 * inclusion of <string.h>; revert the declarative condition, to make it
 * specific to <wchar.h> alone.
 */
#endif	/* !(_WCHAR_H && (_STRING_H && !__STRICT_ANSI__)) */
#endif	/* ! RC_INVOKED */

#if defined _WCHAR_H && ! defined RC_INVOKED
#ifndef __STRICT_ANSI__
typedef wchar_t  _Wint_t;
#endif

typedef int mbstate_t;

/* The following multi-byte character conversion functions have been
 * implemented by Microsoft, in non-free MSVCR80.DLL and later, (and
 * maybe also in some earlier non-free DLLs, such as MSVCP60.DLL and
 * later); they are also available in MSVCRT.DLL, from Vista onward,
 * but to provide continuing support for earlier Windows versions,
 * we always use MinGW replacements, provided in libmingwex.a
 */
__cdecl __MINGW_NOTHROW  wint_t btowc (int);
__cdecl __MINGW_NOTHROW  int wctob (wint_t);

__cdecl __MINGW_NOTHROW  size_t mbrlen
(const char *__restrict__, size_t, mbstate_t *__restrict__);

__cdecl __MINGW_NOTHROW  size_t mbrtowc
(wchar_t *__restrict__, const char *__restrict__, size_t, mbstate_t *__restrict__);

__cdecl __MINGW_NOTHROW  size_t mbsrtowcs
(wchar_t *__restrict__, const char **__restrict__, size_t, mbstate_t *__restrict__);

__cdecl __MINGW_NOTHROW  size_t wcrtomb
(char * __restrict__, wchar_t, mbstate_t *__restrict__);

__cdecl __MINGW_NOTHROW  size_t wcsrtombs
(char *__restrict__, const wchar_t **__restrict__, size_t, mbstate_t *__restrict__);

#if defined _ISOC99_SOURCE || defined __cplusplus
/* These ISO-C99 functions are implemented in libmingwex.a,
 * or, in some cases, as inline stubs; while provided as MinGW
 * extensions to support ISO-C99, they are also required by
 * GNU C++.
 */
__cdecl __MINGW_NOTHROW  int fwide (FILE *, int);
__cdecl __MINGW_NOTHROW  int mbsinit (const mbstate_t *);

#ifndef __NO_INLINE__
__CRT_INLINE __LIBIMPL__(( FUNCTION = fwide ))
__cdecl __MINGW_NOTHROW  int fwide (FILE *__UNUSED_PARAM(__stream), int __mode)
{ return __mode; } /* Nothing to do  */

__CRT_INLINE __LIBIMPL__(( FUNCTION = mbsinit ))
__cdecl __MINGW_NOTHROW  int mbsinit (const mbstate_t *__ps)
{ return ((__ps == NULL) || (*__ps == (mbstate_t)(0))); }
#endif

__cdecl __MINGW_NOTHROW  wchar_t *wmemset (wchar_t *, wchar_t, size_t);
__cdecl __MINGW_NOTHROW  wchar_t *wmemchr (const wchar_t *, wchar_t, size_t);

/* FIXME: what makes this so different from every other function
 * in this group?  Why is it not qualified with the __cdecl, and
 * __MINGW_NOTHROW attributes?
 */
int wmemcmp (const wchar_t *, const wchar_t *, size_t);

__cdecl __MINGW_NOTHROW
wchar_t *wmemcpy (wchar_t *__restrict__, const wchar_t *__restrict__, size_t);

__cdecl __MINGW_NOTHROW  wchar_t *wmemmove (wchar_t *, const wchar_t *, size_t);

__cdecl __MINGW_NOTHROW
long long wcstoll (const wchar_t *__restrict__, wchar_t **__restrict__, int);

__cdecl __MINGW_NOTHROW  unsigned long long wcstoull
(const wchar_t *__restrict__, wchar_t **__restrict__, int);
#endif /* _ISOC99_SOURCE */

_END_C_DECLS

#undef __WCHAR_H_SOURCED__
#endif	/* _WCHAR_H && ! RC_INVOKED */
#endif	/* !_WCHAR_H: $RCSfile: wchar.h,v $: end of file */
 
#endif /* ! __STRICT_ANSI__ */

#if _POSIX_C_SOURCE >= 200809L
#if __MSVCRT_VERSION__ >= __MSVCR80_DLL
/* MSVCR80.DLL adds a (mostly) POSIX.1-2008 conforming strnlen(); (it's
 * also available in MSVCRT.DLL from _WIN32_WINNT_VISTA onwards, but we
 * pretend otherwise, since recent GCC will try to use the function when
 * it can be found in libmsvcrt.a, so breaking it for use on WinXP and
 * earlier).
 */
_CRTIMP __cdecl __MINGW_NOTHROW  char *strnlen (const char *, size_t);

#else	/* MSVCRT.DLL || pre-MSVCR80.DLL */
/* Emulation, to support recent POSIX.1; we prefer this for ALL versions
 * of MSVCRT.DLL, (even those which already provide strnlen()); to avoid
 * the GCC breakage noted above.  (Note that we implement strnlen() with
 * the alternative external name, __mingw_strnlen() in libmingwex.a, to
 * avoid possible link time collision with MSVCR80.DLL's implementation,
 * then map this to strnlen() via a __CRT_ALIAS, with stubs designated
 * for linking from within the appropriate oldname libraries.
 */
extern size_t __mingw_strnlen (const char *, size_t);

__JMPSTUB__(( LIB=coldname; FUNCTION=strnlen ))
__CRT_ALIAS size_t strnlen (const char *__text, size_t __maxlen)
{ return __mingw_strnlen (__text, __maxlen); }

#endif	/* MSVCRT.DLL || pre-MSVCR80.DLL */
#endif	/* _POSIX_C_SOURCE >= 200809L */

#if _POSIX_C_SOURCE >= 199506L  /* SUSv2 */
/* SUSv2 added a re-entrant variant of strtok(), which maintains state
 * using a user supplied reference pointer, rather than the internal
 * reference used by strtok() itself, thus making it both thread-safe,
 * and suitable for interleaved use on multiple strings, even within a
 * single thread context, (which isn't possible with strtok() itself,
 * even with Microsoft's intrinsically thread-safe implementation).
 */
extern char *strtok_r
(char *__restrict__, const char *__restrict__, char **__restrict__);

#if _POSIX_C_SOURCE >= 200112L
/* POSIX.1-2001 added a re-entrant variant of strerror(), which stores
 * the message text in a user supplied buffer, rather than in (possibly
 * volatile) system supplied storage.  Although inherently thread-safe,
 * Microsoft's strerror() also uses a potentially volatile buffer, (in
 * the sense that it is overwritten by successive calls within a single
 * thread); thus, we provide our own implementation of POSIX.1-2001's
 * strerror_r() function, to facilitate the return of non-volatile
 * copies of strerror()'s message text.
 */
extern int strerror_r (int, char *, size_t);

#endif	/* POSIX.1-2001 */
#endif	/* SUSv2 */

#if __MSVCRT_VERSION__>=__MSVCR80_DLL || _WIN32_WINNT >= _WIN32_WINNT_VISTA
/* MSVCR80.DLL introduced a safer, (erroneously so called "more secure"),
 * alternative to strerror(), named strerror_s(); it was later retrofitted
 * to MSVCRT.DLL, from the release of Windows-Vista onwards.
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int strerror_s (char *, size_t, int);

/* Also introduced in MSVCR80.DLL, and retrofitted to MSVCRT.DLL from the
 * release of Windows-Vista, strtok_s() is a direct analogue for POSIX.1's
 * strtok_r() function; (contrary to Microsoft's description, it is neither
 * a "more secure", nor even a "safer" version of strtok() itself).
 */
_CRTIMP __cdecl __MINGW_NOTHROW  char *strtok_s (char *, const char *, char **);

#elif _POSIX_C_SOURCE >= 200112L
/* For the benefit of pre-Vista MSVCRT.DLL users, we provide an approximate
 * emulation of strerror_s(), in terms of inline referral to POSIX.1-2001's
 * strerror_r() function.
 */
__CRT_ALIAS int strerror_s (char *__buf, size_t __len, int __err)
{ return strerror_r (__err, __buf, __len); }
#endif

#undef __STRING_H_SOURCED__

_END_C_DECLS

#endif	/* ! RC_INVOKED */
#endif	/* !_STRING_H: $RCSfile: string.h,v $: end of file */
 

int main() {
   char str[5][50], temp[50];
   printf("Enter 5 words: ");

   // Getting strings input
   for (int i = 0; i < 5; ++i) {
      fgets(str[i], sizeof(str[i]), stdin);
   }

   // storing strings in the lexicographical order
   for (int i = 0; i < 5; ++i) {
      for (int j = i + 1; j < 5; ++j) {

         // swapping strings if they are not in the lexicographical order
         if (strcmp(str[i], str[j]) > 0) {
            strcpy(temp, str[i]);
            strcpy(str[i], str[j]);
            strcpy(str[j], temp);
         }
      }
   }
_ooooooops!
   printf("\nIn the lexicographical order: \n");
   for (int i = 0; i < 5; ++i) {
      fputs(str[i], stdout);
   }
   return 0;
}                               