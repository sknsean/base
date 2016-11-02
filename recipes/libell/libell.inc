DESCRIPTION = "Embedded Linux Library is targeted as a replacement for glib \
               for embedded use (reduces the image footprint)"

LICENSE = "LGPL-2.1"

COMPATIBLE_HOST_ARCHS = ".*linux"

inherit autotools-autoreconf library
SRC_URI = "git://git.kernel.org/pub/scm/libs/ell/ell.git;${COMMIT}"

S = "${SRCDIR}/ell"

DEPENDS += "libdl"
DEPENDS_${PN} = "libc"
RDEPENDS_${PN} = "libc"

do_autoreconf[prefuncs] += "do_autoreconf_mkdir"

do_autoreconf_mkdir() {
	mkdir -p ${S}/build-aux
}
