DEFAULT_PREFERENCE = "-1"
DEFAULT_PREFERENCE_opendreambox = "1"

FILESPATHPKG .= ":qt-${PV}"

SRC_URI = "ftp://ftp.trolltech.com/qt/source/qt-everywhere-opensource-src-${PV}.tar.gz \
           file://configure-conf_compiler-fix.patch;patch=1 \
           file://0004-no-qmake.patch;patch=1 \
           file://0006-freetype-host-includes.patch;patch=1 \
	   file://0010-no-simpledecoration-example.patch;patch=1 \
           file://0001-Added-Openembedded-crossarch-option.patch;patch=1 \
           file://0002-Disable-tools-assistant.patch;patch=1 \
           file://0003-Disable-examples-designer.patch;patch=1 \
           file://0004-Disable-exaqmples-dbus-remotecontrolledcar.patch;patch=1 \
           file://0005-Disable-examples-help.patch;patch=1 \
           file://0007-Disable-demos-qtdemos.patch;patch=1 \
           file://0008-Disable-examples-declarative.patch;patch=1 \
           file://demos.browser.add.mediaservices.lib.patch;patch=1 \
           file://add.xmlpatterns.lib.patch;patch=1 \
           file://g++.conf \
           file://linux.conf \
           "

S = "${WORKDIR}/qt-everywhere-opensource-src-${PV}"

QT_LIB_NAMES += "QtDeclarative"
FILES_${QT_BASE_NAME}-tools                += "${bindir}/qml"

do_configure_prepend() {
    for pro in $(find ${S} -name "*.pro") ; do
        sed -i 's:$$QT_BUILD_TREE/bin/lrelease:${OE_QMAKE_LRELEASE}:g' $pro
    done

    sed -i s:SEDME:${S}: ${WORKDIR}/linux.conf
    sed -i \
    -e /QMAKE_MOC\ /d \
    -e /QMAKE_UIC\ /d \
    -e /QMAKE_UIC3\ /d \
    -e /QMAKE_RCC\ /d \
    ${S}/configure
}

do_configure_append() {
    sed -e '/QMAKE_TARGET /d' -e '/TARGET /d' -i ${S}/translations/Makefile
}

QT_GLFLAGS ?= ""
QT_CONFIG_FLAGS += " -xmlpatterns -no-rpath -qt3support -reduce-relocations -silent ${QT_GLFLAGS}"

do_compile() {
    # Fixup missing wsegl header in some SGX SDKs
    if ! [ -e ${STAGING_INCDIR}/wsegl.h ] ; then
        cp src/3rdparty/powervr/wsegl.h src/plugins/gfxdrivers/powervr/QWSWSEGL/
    fi

    unset CFLAGS CXXFLAGS
    install -m 0755 ${STAGING_BINDIR_NATIVE}/rcc4 ${S}/bin/rcc
    install -m 0755 ${STAGING_BINDIR_NATIVE}/moc4 ${S}/bin/moc
    install -m 0755 ${STAGING_BINDIR_NATIVE}/uic4 ${S}/bin/uic
    install -m 0755 ${STAGING_BINDIR_NATIVE}/lrelease4 ${S}/bin/lrelease

    oe_runmake ${EXTRA_ENV}
}

do_install_append() {
	install -d ${D}${bindir}
	for i in rcc uic moc ; do
		install -m 0755 ${S}/bin/$i ${D}${bindir}/
	done
}

LICENSE = "LGPLv2.1 GPLv3"
SRC_URI += " \
            file://hack-out-pg_config.patch;patch=1"
