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
 

int main(void) {
  #if defined __USE_XOPEN
    printf("Hello World\n");
    return 0;
  #else
    printf("Hello new World\n");
    return 22;
  #endif
  #if defined __USE_UNIX98 || defined __USE_XOPEN2K
    printf("Hello World22\n");
    return 0;
  #else
    printf("Hello new World2\n");
    return 0;
  #endif

}               