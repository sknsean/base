SUMMARY = "A System and service manager"
HOMEPAGE = "http://www.freedesktop.org/wiki/Software/systemd"

LICENSE = "GPL-2.0 & LGPL-2.1"

inherit autotools-autoreconf pkgconfig

SRC_URI = "git://github.com/systemd/systemd.git;protocol=git;tag=v${PV}"

S = "${SRCDIR}/systemd"

EXTRA_OECONF = " \
                --enable-split-usr \
                --without-python \
                --with-sysvrcnd-path=${sysconfdir} \
                --with-firmware-path=/lib/firmware \
		--disable-manpages \
		--enable-dbus \
		--enable-resolved \
		--enable-networkd \
		--enable-hostnamed \
		--enable-timedated \
		--enable-timesyncd \
		--enable-kdbus \
		--enable-logind \
		--enable-sysusers \
		--enable-bzip2 --enable-lz4 --enable-zlib \
                "
#--enable-xz

DEPENDS += "libpthread libcap libmount libdl libm librt libresolv libcrypt native:coreutils-ln \
		libdbus-1 libz libbz2 liblz4"

PACKAGES += "${PN}-udev ${PN}-zsh ${PN}-bash-completion"

FILES_${PN} += "${libdir}/sysusers.d/ \
		${libdir}/tmpfiles.d/ \
		${libdir}/sysctl.d/ \
		${libdir}/kernel/install.d/ \
		${datadir}/factory/etc/ \
		${datadir}/dbus-1/ \
		${libdir}/rpm/macros.d/ \
		${datadir}/polkit-1/ \
		"
FILES_${PN}-udev += "./etc/udev \
		${bindir}/udevadm \
		${libdir}/libudev.so* \
		${libdir}/udev/ \
		${libdir}/udev/rules.d/ \
		"
FILES_${PN}-zsh += "/usr/share/zsh/"
FILES_${PN}-bash-completion += "/usr/share/bash-completion/completions/"
