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

/* When including <wchar.h>, some of the definitions and declarations
 * which are nominally provided in <stdio.h> must be duplicated.  Rather
 * than require duplicated maintenance effort, we provide for partial
 * inclusion of <stdio.h> by <wchar.h>; only when not included in
 * this partial fashion...
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



/* When it is intended to link an application with any one of the
 * MSVC version specific MSVCRxx.DLL libraries, rather than with the
 * OS default MSVCRT.DLL, the particular substitute MSVCRxx.DLL may
 * be specified as any one of the following...
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

/* Define masks for extracting version components from NTDDI_VERSION;
 * values and names are guessed based on comments in the documentation; see
 * http://msdn.microsoft.com/en-us/library/windows/desktop/aa383745(v=vs.85).aspx
 */


/* Stipulate defaults; check consistency of any user specified overrides.
 */









 /* TODO(REVIEW): is this appropriate for WINVER consistency checking?
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


   /* ...whereas, this promises only basic SSE instruction set support...
    */

   /* ...and this disallows its use, entirely.
    */



/* When not compiling for an X86 host; check mapping from other possible
 * GCC architecture identifiers, to their MSVC equivalents.
 */
 /* This represents an Intel X86-64, or (compatible) AMD-64 processor;
  * MSVC defines...
  */



 /* This represents an Intel Itanium processor, which MSVC designates
  * by defining this feature test macro.
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

/* Related to the UNICODE macro definition, there are many functions in
 * the Win32 API with a generic name, which is mapped to a variant with
 * wchar_t UTF-16LE encoding of string arguments, in cases when UNICODE
 * is defined, as facilitated by the following macro...
 */

 /* ...or by appending an "A" suffix, to select an ANSI variant with
  * char encoding of string arguments, when UNICODE is not defined.
  */

/* Further related, the __AW_EXTENDED__ macro reproduces the effect of
 * __AW_SUFFIXED__, with the addition of a single underscore character
 * separating the base name from the appropriate suffix.
 */

/* ...while remaining transparent, when compiling C code.
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
	/* !__MINGW_FEATURES__: $RCSfile$: end of file */
 




/* Define macros to facilitate the user-specified configuration.
 */

















 /* __declspec */

 /* __declspec */
/*
 * The next two defines can cause problems if user code adds the
 * __cdecl attribute like so:
 * void __attribute__ ((__cdecl)) foo(void);
 */








 /* ! __GNUC__ && ! __PCC__ */














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

	/* ! defined __USE_MINGW_ANSI_STDIO */
/* We must check this BEFORE we specifiy any implicit _POSIX_C_SOURCE,
 * otherwise we would always implicitly choose __USE_MINGW_ANSI_STDIO,
 * even if none of these selectors are specified explicitly...
 */

  /* otherwise use whatever __MINGW_FEATURES__ specifies...
   */



/* Some applications may define _XOPEN_SOURCE, without assigning any
 * value to it.  Such usage may have been permitted in early SUS, but
 * it became obsolete as of SUSv2.  Attempt to detect obsolete usage,
 * as it makes an effective evaluation of any _XOPEN_SOURCE version
 * dependency difficult, (without the use of ugly kludges at EVERY
 * point of reference which attempts a version comparison).
 */

/* ...and redefine, emulating implicit behaviour of -D_XOPEN_SOURCE on
 * the GCC command line, (which DOES assign an implied value of one).
 */





  /*
   * No explicit level of support has been specified; implicitly grant
   * the most comprehensive level to any compilation unit which requests
   * either GNU or BSD feature support, or does not seek to be strictly
   * ANSI-C compliant.
   */


  /* Now formally deprecated by POSIX, some old code may specify this;
   * it will enable a minimal level of POSIX support, in addition to the
   * limited feature set enabled for strict ANSI-C conformity.
   */




/* POSIX.1-1996 conformance is NOT required; do not object to use of
 * interfaces which became "obsolescent" in this POSIX version, but
 * were still fully supported in earlier versions.
 */



/* POSIX.1-2001 conformance is NOT required; do not object to use of
 * interfaces which became "obsolescent" in this POSIX version, but
 * were still fully supported in earlier versions.
 */



/* POSIX.1-2008 conformance is NOT required; do not object to use of
 * interfaces which became "obsolescent" in this POSIX version, but
 * were still fully supported in earlier versions.
 */


  /* This represents a compiler supporting ISO-C99; enable all potential
   * use of ISO-C99 features, (to the maximum extent supportable), which
   * presumably also covers all C++11 and POSIX.1 usage.
   */
  /* C++11 also incorporates many (if not all) of the ISO-C99 features,
   * which we have guarded by _ISOC99_SOURCE; enable such features, to
   * the required extent, (which is likely also sufficient to support
   * any POSIX.1 dependencies).
   */
  /* This represents the minimum level of ISO-C99 support, which may be
   * required by POSIX.1, (and which may be no less than full support).
   */



 /* The the user has explicitly declared a source level dependency on
  * ISO-C99 features; regardless of how it was declared, redefine it to
  * ensure that any plausible dependency is covered.
  */
	/* _ISOC99_SOURCE */





 /* __MINGW_H: $RCSfile: _mingw.h.in,v $: end of file */
 









/* On BSD/386 1.1, at least, machine/ansi.h defines _BSD_WCHAR_T_
   instead of _WCHAR_T_. */


/* Undef _FOO_T_ if we are supposed to define foo_t.  */



 /* defined(__NetBSD__) */

/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */


/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */




/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */

typedef __PTRDIFF_TYPE__ ptrdiff_t;
 /* _PTRDIFF_T_DECLARED */
 /* _GCC_PTRDIFF_T */
 /* ___int_ptrdiff_t_h */
 /* _BSD_PTRDIFF_T_ */
 /* _PTRDIFF_T_ */
 /* __PTRDIFF_T */
 /* _T_PTRDIFF */
 /* _T_PTRDIFF_ */
 /* _PTRDIFF_T */

/* If this symbol has done its job, get rid of it.  */

 /* _STDDEF_H or __need_ptrdiff_t.  */

/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */



 /* __BEOS__ */
 /* !(defined (__GNUG__) && defined (size_t)) */
 /* __size_t */
 /* _SIZET_ */
 /* _GCC_SIZE_T */
 /* ___int_size_t_h */
 /* _SIZE_T_DECLARED */
 /* _BSD_SIZE_T_DEFINED_ */
 /* _SIZE_T_DEFINED */
 /* _SIZE_T_DEFINED_ */
 /* _BSD_SIZE_T_ */
 /* _SIZE_T_ */
 /* __SIZE_T */
 /* _T_SIZE */
 /* _T_SIZE_ */
 /* _SYS_SIZE_T_H */
 /* _SIZE_T */
 /* __SIZE_T__ */
 /* __size_t__ */
 /* _STDDEF_H or __need_size_t.  */


/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */




/* FreeBSD 5 can't be handled well using "traditional" logic above
   since it no longer defines _BSD_RUNE_T_ yet still desires to export
   rune_t in some cases... */













 /* _WCHAR_T_DECLARED */
 /* _BSD_RUNE_T_DEFINED_ */







 /* __WCHAR_T__ */
 /* __wchar_t__ */
 /* _STDDEF_H or __need_wchar_t.  */


typedef __WINT_TYPE__ wint_t;






/*  The following ones are the real ones.  */



 /* __NetBSD__ */

 /* __sys_stdtypes_h */

/* A null pointer constant.  */

   /* G++ */
   /* C++ */
  /* C++ */
  /* G++ */
	/* NULL not defined and <stddef.h> or need NULL.  */


} max_align_t;

 /* C11 or C++11.  */


 /* C++11.  */

 /* _STDDEF_H was defined this time */

 /* !_STDDEF_H && !_STDDEF_H_ && !_ANSI_STDDEF_H && !__STDDEF_H__
	  || __need_XXX was not defined before */
 



/* Although non-standard themselves, we also need either one or other
 * of the following pair of data types, from <sys/types.h>, because our
 * standard fpos_t is opaquely defined in terms of...
 */

 /* ...or a 32-bit equivalent, for pre-MSVCRT.DLL users.
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

/* All the headers include this file.
 */
















  /* Microsoft's brain damaged default, from MSVCR80.DLL onwards.
   */
   typedef __time64_t time_t;





 /* ...but this alternative, when linking with CRTDLL.DLL
  */
typedef short		_dev_t;


 /* ...while the remaining type names have consistent definitions,
  * regardless of any particular DLL association.
  */
typedef short		_ino_t;
typedef unsigned short	_mode_t;
typedef int		_pid_t;
typedef int		_sigset_t;

/* Users who value portability should prefer...
 */


typedef __int64 	 fpos64_t;

/* useconds_t is an obsolete POSIX data type; we continue to define
 * it here, for backward compatibility, but we flag it as deprecated,
 * due to its obsolete status.
 */
typedef unsigned long useconds_t __MINGW_ATTRIB_DEPRECATED;

  /* _SYS_TYPES_H normal inclusion */

	/* ! RC_INVOKED */
	/* !_SYS_TYPES_H: $RCSfile: types.h,v $: end of file */
 
 /* not __need___va_list */

/* Define __gnuc_va_list.  */



/* Define the standard macros for the user,
   if this invocation was from the user program.  */




 /* __i860__ */
typedef __gnuc_va_list va_list;

 /* _VA_LIST_ */
 /* not __va_list__ */
 /* not _VA_LIST_T_H */
 /* not _VA_LIST */
 /* not _VA_LIST_DEFINED */






 /* not _VA_LIST_, except on certain systems */

 /* not __svr4__ */

 /* _STDARG_H */

 /* not _ANSI_STDARG_H_ */
 /* not _STDARG_H */
 

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



/* The buffer size as used by setbuf such that it is equivalent to
 * (void) setvbuf(fileSetBuffer, caBuffer, _IOFBF, BUFSIZ).
 */
	/* _STDIO_H */

  /* ! (_STDIO_H && _WCHAR_H) */
 /* __DECLSPEC_SUPPORTED */


/* ...because, we need this regardless of the inclusion mode...
 */
_BEGIN_C_DECLS




 /* __STRICT_ANSI__ */

_CRTIMP __cdecl __MINGW_NOTHROW  int    setvbuf (FILE *, char *, int, size_t);
_CRTIMP __cdecl __MINGW_NOTHROW  void   setbuf (FILE *, char *);

/* Formatted Output
 *
 * MSVCRT implementations are not ANSI C99 conformant...
 * we offer conforming alternatives from libmingwex.a
 */


/* The following convenience macros specify the appropriate
 * -Wformat checking for MSVCRT.DLL replacement functions...
 */
/* For non-GNU C++ we use inline implementations, to avoid interference
 * with namespace qualification, which may result from using #defines.
 */
	/* Neither GCC, nor non-GNU C++ */
	/* __USE_MINGW_ANSI_STDIO || defined _ISOC99_SOURCE */

	/* !__USE_MINGW_ANSI_STDIO */
/* Default configuration: simply direct all calls to MSVCRT...
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int fprintf (FILE *, const char *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int printf (const char *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int sprintf (char *, const char *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int vfprintf (FILE *, const char *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW  int vprintf (const char *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW  int vsprintf (char *, const char *, __VALIST);

	/* !__USE_MINGW_ANSI_STDIO */

	/* __GNUC__ && defined _ISOC99_SOURCE */

/* Regardless of user preference, always offer these alternative
 * entry points, for direct access to the MSVCRT implementations,
 * with ms_printf -Wformat checking in each case.
 */

/* The following three ALWAYS refer to the MSVCRT implementations...
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int _snprintf (char *, size_t, const char *, ...);
_CRTIMP __cdecl __MINGW_NOTHROW  int _vsnprintf (char *, size_t, const char *, __VALIST);
_CRTIMP __cdecl __MINGW_NOTHROW  int _vscprintf (const char *, __VALIST);

  /* _ISOC99_SOURCE */
	/* <stdio.h> included in its own right */


/* Some headers will include this file, just to acquire a globally
 * consistent definition for the opaque locale_t data object type; it
 * is only useful on Vista, or for users of non-free MSVCR80.DLL, (or
 * its later derivatives), so, when either of these is applicable,
 * ensure that we define it, (if we haven't done so already).
 */
	/* !__have_typedef_locale_t */

/* When we are interested in more than just locale_t...
 */
	/* ! RC_INVOKED */
	/* !__WCHAR_H_SOURCED__ */


 /* ...whereas, this must be declared in either case; (note that it
  * not necessary to guard against a possible repeat declaration, as
  * the compiler should accept this, without complaint, provided any
  * prior declaration is consistent).
  */
_CRTIMP __cdecl __MINGW_NOTHROW  wchar_t *_wsetlocale (int, const wchar_t *);


/* ...whereas, this is required both when included directly, and also
 * when indirectly included by <wchar.h>
 */
_CRTIMP __cdecl __MINGW_NOTHROW  _locale_t _wcreate_locale (int, const wchar_t *);

	/* __MSVCRT_VERSION__ >= __MSVCR80_DLL */

_END_C_DECLS

	/* ! RC_INVOKED */
	/* !__need_locale_t */

/* We've already handled any pending __need_locale_t request; ensure
 * that we cancel it, so that any more comprehensive further request,
 * before _LOCALE_H is defined, will be handled appropriately.
 */

  /* !_LOCALE_H: $RCSfile: locale.h,v $: end of file */
 


	/* <stdio.h> included in its own right */
	/* MSVCR80.DLL and descendants, or MSVCRT.DLL since Vista */

	/* MSVCR80.DLL and descendants, or MSVCRT.DLL since Vista */
	/* ! (defined _STDIO_H && defined _WCHAR_H) */
  /* !__NO_INLINE__ */
  /* POSIX.1-2008 */

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

  /* Use library functions.  */

_CRTIMP __cdecl __MINGW_NOTHROW  int    getc (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    putc (int, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    getchar (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int    putchar (int);



/* Direct Input and Output Functions
 */
_CRTIMP __cdecl __MINGW_NOTHROW  size_t fread (void *, size_t, size_t, FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  size_t fwrite (const void *, size_t, size_t, FILE *);

/* File Positioning Functions
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int    fseek (FILE *, long, int);
_CRTIMP __cdecl __MINGW_NOTHROW  long   ftell (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  void   rewind (FILE *);


/* This is correct usage; the private __USE_MINGW_FSEEK feature affects only
 * Win9x, so enable it implicitly when the _WIN32_WINDOWS feature is specified,
 * thus indicating the user's intent to target a Win9x platform.
 */


 /* __USE_MINGW_FSEEK */

/* An opaque data type used for storing file positions...  The contents
 * of this type are unknown, but we (the compiler) need to know the size
 * because the programmer using fgetpos and fsetpos will be setting aside
 * storage for fpos_t aggregates.  Actually I tested using a byte array and
 * it is fairly evident that fpos_t is a 32-bit type in CRTDLL.DLL, but in
 * MSVCRT.DLL, it is a 64-bit type.  Define it in terms of an int type of
 * the appropriate size, encapsulated within an aggregate type, to make
 * it opaque to casting, and so discourage abuse.
 */

typedef union { __int32 __value; __off32_t __offset; } fpos_t;


_CRTIMP __cdecl __MINGW_NOTHROW  int fgetpos (FILE *, fpos_t *);
_CRTIMP __cdecl __MINGW_NOTHROW  int fsetpos (FILE *, const fpos_t *);

  /* MSVCR80.DLL and later derivatives ONLY */

	/* pre-MSVCR80.DLL or MSVCRT.DLL pre-Vista */
/* The Microsoft DLLs don't provide either _fseeki64() or _ftelli64(), but
 * they DO provide fgetpos(), fsetpos(), and _lseeki64(), which may be used
 * to emulate the two missing functions.  (Note that we choose to provide
 * these emulations in the form of MinGW external helper functions, rather
 * than pollute the <stdio.h> namespace with declarations, such as that
 * for _lseeki64(), which properly belongs in <io.h>).
 */


__int64 __cdecl __MINGW_NOTHROW __mingw_ftelli64 (FILE *);
__CRT_ALIAS __cdecl  __int64 __MINGW_NOTHROW _ftelli64 (FILE *__file )
{ return __mingw_ftelli64 (__file); }

	/* pre-MSVCR80.DLL or MSVCRT.DLL pre-Vista */

/* Error Functions
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int feof (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int ferror (FILE *);




_CRTIMP __cdecl __MINGW_NOTHROW  void clearerr (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  void perror (const char *);



/* Other Non ANSI functions
 */
_CRTIMP __cdecl __MINGW_NOTHROW  int    _flushall (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _fgetchar (void);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _fputchar (int);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE * _fdopen (int, const char *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _fileno (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _fcloseall (void);
_CRTIMP __cdecl __MINGW_NOTHROW  FILE * _fsopen (const char *, const char *, int);


/* Microsoft introduced a capability in MSVCR80.DLL and later, to
 * set the minimum number of digits to be displayed in a printf()
 * floating point exponent; they retro-fitted this in MSVCRT.DLL,
 * from Windows-Vista onwards, but we provide our own wrappers in
 * libmingwex.a, which make it possible for us to emulate the API
 * for any version of MSVCRT.DLL (including WinXP and earlier).
 */

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

/* ...and for the false.
 */


__CRT_ALIAS int __cdecl _get_printf_count_output (void)
{ return __USE_MINGW_PRINTF ? 1 : __mingw_get_printf_count_output (); }

__CRT_ALIAS int __cdecl _set_printf_count_output (int __mode)
{ return __USE_MINGW_PRINTF ? 1 : __mingw_set_printf_count_output (__mode); }


	/* !_NO_OLDNAMES */





__off64_t __cdecl __MINGW_NOTHROW ftello64 (FILE *);

	/* __MSVCRT__ && !__NO_MINGW_LFS */
	/* !__STRICT_ANSI__ */
	/* _STDIO_H */



  /* !__STRICT_ANSI__ */
	/* __MSVCRT__ */



__cdecl __MINGW_NOTHROW  int  vwscanf (const wchar_t *__restrict__, __VALIST);
__cdecl __MINGW_NOTHROW
int  vfwscanf (FILE *__restrict__, const wchar_t *__restrict__, __VALIST);
__cdecl __MINGW_NOTHROW
int  vswscanf (const wchar_t *__restrict__, const wchar_t * __restrict__, __VALIST);

  /* _ISOC99_SOURCE */
  /* ! (_STDIO_H && _WCHAR_H) */



/* Other non-ANSI wide character functions...
 */
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t _fgetwchar (void);
_CRTIMP __cdecl __MINGW_NOTHROW  wint_t _fputwchar (wint_t);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _getw (FILE *);
_CRTIMP __cdecl __MINGW_NOTHROW  int    _putw (int, FILE *);

  /* !_NO_OLDNAMES */
  /* !__STRICT_ANSI__ */

_END_C_DECLS

	/* ! RC_INVOKED */
  /* !_STDIO_H: $RCSfile: stdio.h,v $: end of file */
 

 

 


printf("cade o else\n");


int main(void) {
  
      printf("Hello World\n");
    return 0;
  
  
    printf("Hello new World2\n");
    return 0;
  
  
}                