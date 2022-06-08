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
 /* ...which is exclusive to <wchar.h>, do we assert the multiple
  * inclusion guard for <stdio.h> itself.
  */


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


/* This is an exception to the normal rule, that all mingwrt system
 * header files should include _mingw.h, since inclusion of _mingw.h
 * itself will cause this file to be included.  Thus, we recommend
 * that this file should not be included directly, but we do not
 * forbid doing so; however, in this event...
 */


 /* !_MSVCRTVER_H: $RCSfile: msvcrtver.h,v $: end of file */
 


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


/* Stipulate defaults; check consistency of any user specified overrides.
 */









/* https://msdn.microsoft.com/en-us/library/windows/desktop/bb776779%28v=vs.85%29.aspx
 * specifies that the user should define _WIN32_IE, but in the absence of
 * any such definition, a default equivalent to IE-5.0 may be assumed.
 */



/* Map GCC architecture identification macros to their MSVC equivalents.
 * This mapping was previously specified in <winnt.h>, and duplicated in
 * <windows.h>; it is now only defined here, because both <windows.h> and
 * <winnt.h> must include this file anyway, and the potentially error prone
 * burden of maintaining duplicates is as unnecessary as it is undesirable.
 */
 /* Note that we must process the _M_IX86 equivalent macros in diminishing
  * order of processor version, since GCC defines __i386__ as identification
  * for the X86 processor family, in addition to any one of the other three
  * macros, which may be used to identify a particular processor version.
  */



/* The preceding logic may have established the host type as X86, or it
 * may have done nothing at all; we must check further.
 */
	/* !_M_IX86 */

 /* _SDKDDKVER_H: $RCSfile: sdkddkver.h,v $: end of file */
 

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

/* _WIN32_WINNT and/or WINVER may be set to any of the following manifest
 * values, to specify a minimum WinNT support level requirement:
 *
 *      Old Name	Preferred Name
 *      -------------	------------------
 */

/* _WIN32_IE may be set to any of the following manifest values, to
 * specify a minimum Internet Explorer support level requirement:
 *
 *      Old Name	Preferred Name
 *      -------------	------------------
 */


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

/* Related to the UNICODE macro definition, there are many functions in
 * the Win32 API with a generic name, which is mapped to a variant with
 * wchar_t UTF-16LE encoding of string arguments, in cases when UNICODE
 * is defined, as facilitated by the following macro...
 */

/* Further related, the __AW_EXTENDED__ macro reproduces the effect of
 * __AW_SUFFIXED__, with the addition of a single underscore character
 * separating the base name from the appropriate suffix.
 */

/* __AW_EXTENDED__ may often be used to map manifest string constants.
 * The following triplet provide a convenient mechanism to derive the
 * UNICODE variant of the string from its ANSI definition; (note that
 * this requires a two stage expansion, to ensure that the "L" prefix
 * is attached to the expansion of the ANSI string definition, rather
 * than just to the defining macro name).
 */

/* Further uses of __AW_SUFFIXED__ and __AW_EXTENDED__, encapsulated
 * within __AW_ALIAS__ and __AW_ALIAS_EX__; each provides a convenient
 * generic mapping for type names with alternative representations for
 * UNICODE and non-UNICODE usage.
 */



 /* ! _W32API_H: $RCSfile: w32api.h.in,v $: end of file */
 

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

/* From mingwrt-3.21 onward, this should be the preferred choice; it will
 * produce consistent results, regardless of the MSVCRT.DLL version in use.
 */

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

/* The MinGW globbing algorithm uses the ASCII DEL control code as a marker
 * for globbing characters which were embedded within quoted arguments; (the
 * quotes are stripped away BEFORE the argument is globbed; the globbing code
 * treats the marked character as immutable, and strips out the DEL markers,
 * before storing the resultant argument).  The DEL code is mapped to this
 * function here; DO NOT change it, without rebuilding the runtime.
 */


/* Load any user-customized features configuration...
 */




/* Define macros to facilitate the user-specified configuration.
 */


/* Manifest definitions identifying the flag bits, controlling activation
 * of MinGW features, as specified by the user in __MINGW_FEATURES__.
 */
/*
 * The following three are not yet formally supported; they are
 * included here, to document anticipated future usage.
 */


/* Try to avoid problems with outdated checks for GCC __attribute__ support.
 */








/*
 * Each function which is implemented as a __CRT_ALIAS should also be
 * accompanied by an externally visible interface.  The following pair
 * of macros provide a mechanism for implementing this, either as a stub
 * redirecting to an alternative external function, or by compilation of
 * the normally inlined code into free standing object code; each macro
 * provides a way for us to offer arbitrary hints for use by the build
 * system, while remaining transparent to the compiler.
 */







/* Attribute `nonnull' was valid as of gcc 3.3.  We don't use GCC's
   variadiac macro facility, because variadic macros cause syntax
   errors with  --traditional-cpp.  */
 /* GNUC >= 3.3 */

 /* GNUC >= 3.1 */

 /* GNUC >= 3.3 */


/* TODO: Mark (almost) all CRT functions as __MINGW_NOTHROW.  This will
allow GCC to optimize away some EH unwind code, at least in DW2 case.  */

/* Activation of MinGW specific extended features:
 */


/* Some applications may define _XOPEN_SOURCE, without assigning any
 * value to it.  Such usage may have been permitted in early SUS, but
 * it became obsolete as of SUSv2.  Attempt to detect obsolete usage,
 * as it makes an effective evaluation of any _XOPEN_SOURCE version
 * dependency difficult, (without the use of ugly kludges at EVERY
 * point of reference which attempts a version comparison).
 */



 /* Users may define this, either directly or indirectly, to explicitly
  * enable a particular level of visibility for the subset of those POSIX
  * features which are supported by MinGW; (notice that this offers no
  * guarantee that any particular POSIX feature will be supported).
  */









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



 /* The the user has explicitly declared a source level dependency on
  * ISO-C99 features; regardless of how it was declared, redefine it to
  * ensure that any plausible dependency is covered.
  */

	/* _ISOC99_SOURCE */





 /* __MINGW_H: $RCSfile: _mingw.h.in,v $: end of file */
 

/* POSIX stipulates that the following set of types, (as identified by
 * __need_TYPENAME macros), shall be defined consistently with <stddef.h>;
 * by defining the appropriate __need_TYPENAME macros, we may selectively
 * obtain the required definitions by inclusion of <stddef.h>, WITHOUT
 * automatic exposure of any of its additional content.
 */
 /* !_STDDEF_H && !_STDDEF_H_ && !_ANSI_STDDEF_H && !__STDDEF_H__
	  || __need_XXX was not defined before */
 



/* Although non-standard themselves, we also need either one or other
 * of the following pair of data types, from <sys/types.h>, because our
 * standard fpos_t is opaquely defined in terms of...
 */


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


/* First handle those typedefs which POSIX requires us to be able
 * to expose selectively, via other system headers.
 */








  /* _SYS_TYPES_H normal inclusion */

	/* ! RC_INVOKED */
	/* !_SYS_TYPES_H: $RCSfile: types.h,v $: end of file */
 
 /* Also similarly, for the va_list type, defined in "stdarg.h"
  */


	/* ! RC_INVOKED */

	/* _STDIO_H */

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

	/* _STDIO_H */

  /* ! (_STDIO_H && _WCHAR_H) */

/* ...because, we need this regardless of the inclusion mode...
 */

	/* <stdio.h> included in its own right */

	/* MSVCR80.DLL and descendants, or MSVCRT.DLL since Vista */

	/* ! (defined _STDIO_H && defined _WCHAR_H) */
	/* _STDIO_H */

  /* ! (_STDIO_H && _WCHAR_H) */

  /* !__STRICT_ANSI__ */


	/* ! RC_INVOKED */
  /* !_STDIO_H: $RCSfile: stdio.h,v $: end of file */
 


int main(void) {
  
  if(b == 10){
    printf "33";
  }

  int x = 0;
  
  printf("Hello World 0\n");
  i = 0;
  
      printf("Hello World 1\n");
    i = 1;
  
  
      printf("Hello World 3\n");
    i = 3;
  
  
  
    
}                