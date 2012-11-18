#! /bin/sh -e

set -xe
rm -rf autom4te.cache
aclocal --force -I m4 \
&& libtoolize -c -f \
&& autoconf -f -Wall,no-obsolete \
&& autoheader -f -Wall \
&& automake -a -c -f -Wall
rm -rf autom4te.cache
exit 0

