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












/* Map GCC architecture identification macros to their MSVC equivalents.
 * This mapping was previously specified in <winnt.h>, and duplicated in
 * <windows.h>; it is now only defined here, because both <windows.h> and
 * <winnt.h> must include this file anyway, and the potentially error prone
 * burden of maintaining duplicates is as unnecessary as it is undesirable.
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















 /* The the user has explicitly declared a source level dependency on
  * ISO-C99 features; regardless of how it was declared, redefine it to
  * ensure that any plausible dependency is covered.
  */

	/* _ISOC99_SOURCE */





 /* __MINGW_H: $RCSfile: _mingw.h.in,v $: end of file */
 

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










  /* _SYS_TYPES_H normal inclusion */

	/* ! RC_INVOKED */
	/* !_SYS_TYPES_H: $RCSfile: types.h,v $: end of file */
 


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





/* Prototypes for the ISO-C Standard library string functions.
 */






 /* ! _UWIN */
 /* ! _NO_OLDNAMES */

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


/* The following flags are used to tell iswctype() and _isctype() what
 * character classes are to be matched; (note that _BLANK will match for
 * SP and non-ASCII horizontal space chars -- e.g. for "no-break space",
 * 0xA0, in CP1250 -- but NOT for HT).
 *
 * These are defined such that they will be made visible by inclusion
 * of either <wctype.h> (this file), or <ctype.h>:
 */

	/* !(_WCTYPE_H && _CTYPE_H) */

	/* _WCTYPE_H */
	/* ! RC_INVOKED */
	/* !_WCTYPE_H: $RCSfile: wctype.h,v $: end of file */
 

 /* This is also necessary, to support the non-ANSI wchar.h declarations
  * which MSDN identifies as being provided here.
  */
	/* !__STRICT_ANSI__ */



	/* !__WCHAR_H_SOURCED__ */

	/* _STDLIB_H only */
	/* _STDLIB_H || _WCHAR_H */

	/* _STDLIB_H */


	/* ! RC_INVOKED */
	/* ! _STDLIB_H: $RCSfile: stdlib.h,v $: end of file */
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
	/* !__WCHAR_H_SOURCED__ */

	/* _DIRECT_H */

/* The following group of function prototypes are to be declared
 * either when including <dirent.h> in its own right, or when it
 * is included selectively by <wchar.h>; however...
 */
	/* __MSVCRT__ && ! (defined _DIRENT_H && defined _WCHAR_H) */


	/* ! RC_INVOKED */
  /* !_DIRECT_H: $RCSfile: direct.h,v $: end of file */
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
	/* !__WCHAR_H_SOURCED__ */

	/* !_NO_OLDNAMES */

	/* __MSVCRT__ */

/* From here on, it is sufficient to leave __struct_stat_defined as
 * a macro which expands to nothing.
 */

 /* !__struct_stat_defined */


	/* _SYS_STAT_H */

	/* __MSVCRT__ && !(_SYS_STAT_H && _WCHAR_H) */


	/* ! RC_INVOKED */
	/* !_SYS_STAT__H: $RCSfile: stat.h,v $: end of file */
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
	/* !__WCHAR_H_SOURCED__ */

	/* _CONIO_H */

	/* ! (_CONIO_H && _WCHAR_H) */


	/* ! RC_INVOKED */
	/* !_CONIO_H: $RCSfile: conio.h,v $: end of file */
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
	/* !__STRICT_ANSI__ */

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
 /* !_TIME_H: $RCSfile: time.h,v $: end of file */
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
	/* !__WCHAR_H_SOURCED__ */

/* Mode constants for spawn() functions.
 */

	/* !_NO_OLDNAMES */

	/* _PROCESS_H */

	/* ! (_PROCESS_H && _WCHAR_H) */


	/* ! RC_INVOKED */
	/* !_PROCESS_H: $RCSfile: process.h,v $: end of file */
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
	/* !__STRICT_ANSI__ */


/* Wide character string functions must be specified here, as required
 * by the ISO-C Standard; however, MSVC contravenes this standard by also
 * requiring them to appear in <string.h>.  We declare them here, where
 * they rightfully belong, but we also arrange for them to be available
 * for selective inclusion by <string.h>; to facilitate this, we must
 * change the declarative condition...
 */
	/* ! RC_INVOKED */
	/* !__STRING_H_SOURCED__ */
	/* ! RC_INVOKED */

	/* _WCHAR_H && ! RC_INVOKED */
	/* !_WCHAR_H: $RCSfile: wchar.h,v $: end of file */
 
 /* ! __STRICT_ANSI__ */

	/* _POSIX_C_SOURCE >= 200809L */

	/* SUSv2 */





	/* ! RC_INVOKED */
	/* !_STRING_H: $RCSfile: string.h,v $: end of file */
 

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
   printf("\nIn the lexicographical order: \n");
   for (int i = 0; i < 5; ++i) {
      fputs(str[i], stdout);
   }
   return 0;
}                                