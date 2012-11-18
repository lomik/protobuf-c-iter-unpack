AC_DEFUN([AC_PROGNAME], [
AC_MSG_CHECKING(for __progname)
AC_CACHE_VAL(ac_cv_extern__progname,
    AC_TRY_LINK([],
        [extern char *__progname;
        puts(__progname)],
        ac_cv_extern__progname=yes,
        ac_cv_extern__progname=no))
if test $ac_cv_extern__progname = yes ; then
        AC_DEFINE(HAVE__PROGNAME, [], [Define if __progname exists])
        AC_MSG_RESULT(yes)
else
        AC_MSG_RESULT(no)
fi ])

AC_DEFUN([AC_GCC_ATOMIC], [
AC_MSG_CHECKING(for gcc internal atomic functions)
AC_CACHE_VAL(ac_cv_has_gcc_atomic,
AC_TRY_LINK([],[int count = 0; int prev = __sync_fetch_and_add(&count, 1);],
    ac_cv_has_gcc_atomic=yes,
    ac_cv_has_gcc_atomic=no))
AC_MSG_RESULT($ac_cv_has_gcc_atomic)
if test $ac_cv_has_gcc_atomic = no; then
    GCC_ATOMIC_ARCH="-march=$host_cpu"
    AC_SUBST(GCC_ATOMIC_ARCH)
fi])

