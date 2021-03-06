do_stage() {
	rm -f ${STAGING_DIR_HOST}${layout_base_libdir}/libc.so.6
	oe_runmake 'install_root=${STAGING_DIR_HOST}' \
		   'includedir=${layout_includedir}' 'libdir=${layout_libdir}' 'slibdir=${layout_base_libdir}' \
		   '${STAGING_DIR_HOST}${layout_base_libdir}/libc.so.6' \
		   install

	# "make install" omits some (not all) RPC headers that other distros
	# ship.
	install -d ${STAGING_INCDIR}/rpcsvc

	for r in ${rpcsvc}; do
		h=`echo $r|sed -e's,\.x$,.h,'`
		install -m 0644 ${S}/sunrpc/rpcsvc/$h ${STAGING_INCDIR}/rpcsvc/
	done
}

do_stage_append_openstmstb(){
	for i in ${STAGING_INCDIR}/*.h; do
		cp -pr ${i} ${CROSS_DIR}/${TARGET_SYS}/include/
	done
	for i in gnu sys bits net; do
		cp -pr ${STAGING_INCDIR}/${i} ${CROSS_DIR}/${TARGET_SYS}/include/
	done
}
