#############################################################################
# Makefile for building: Tank_QT_v2
# Generated by qmake (3.1) (Qt 6.6.2)
# Project:  Tank_QT_v2.pro
# Template: app
# Command: C:\Users\Giao\qt_free\6.6.2\mingw_64\bin\qmake.exe -o Makefile Tank_QT_v2.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug"
#############################################################################

MAKEFILE      = Makefile

EQ            = =

first: debug
install: debug-install
uninstall: debug-uninstall
QMAKE         = C:\Users\Giao\qt_free\6.6.2\mingw_64\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = copy /y
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = copy /y
INSTALL_PROGRAM = copy /y
INSTALL_DIR   = xcopy /s /q /y /i
QINSTALL      = C:\Users\Giao\qt_free\6.6.2\mingw_64\bin\qmake.exe -install qinstall
QINSTALL_PROGRAM = C:\Users\Giao\qt_free\6.6.2\mingw_64\bin\qmake.exe -install qinstall -exe
DEL_FILE      = del
SYMLINK       = $(QMAKE) -install ln -f -s
DEL_DIR       = rmdir
MOVE          = move
IDC           = idc
IDL           = midl
ZIP           = zip -r -9
DEF_FILE      = 
RES_FILE      = 
SED           = $(QMAKE) -install sed
MOVE          = move
SUBTARGETS    =  \
		debug \
		release


debug: FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-all: FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-all: FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: Tank_QT_v2.pro ../../../qt_free/6.6.2/mingw_64/mkspecs/win32-g++/qmake.conf ../../../qt_free/6.6.2/mingw_64/mkspecs/features/spec_pre.prf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/device_config.prf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/common/sanitize.conf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/common/gcc-base.conf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/common/g++-base.conf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/win32/windows_vulkan_sdk.prf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/common/windows-vulkan.conf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/common/g++-win32.conf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/common/windows-desktop.conf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/qconfig.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_ext_freetype.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_ext_libjpeg.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_ext_libpng.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_concurrent.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_concurrent_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_core.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_core_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_dbus.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_dbus_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_designer.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_designer_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_designercomponents_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_entrypoint_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_example_icons_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_fb_support_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_freetype_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_gui.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_gui_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_harfbuzz_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_help.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_help_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_jpeg_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_labsanimation.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_labsanimation_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_labsfolderlistmodel.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_labsfolderlistmodel_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_labsqmlmodels.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_labsqmlmodels_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_labssettings.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_labssettings_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_labssharedimage.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_labssharedimage_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_labswavefrontmesh.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_labswavefrontmesh_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_linguist.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_linguist_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_network.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_network_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_opengl.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_opengl_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_openglwidgets.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_openglwidgets_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_png_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_printsupport.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_printsupport_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qdoccatch_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qdoccatchconversionsprivate.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qdoccatchconversionsprivate_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qdoccatchgeneratorsprivate.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qdoccatchgeneratorsprivate_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qml.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qml_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmlcompiler.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmlcompiler_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmlcore.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmlcore_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmldebug_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmldom_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmlintegration.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmlintegration_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmllocalstorage.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmllocalstorage_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmlls_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmlmodels.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmlmodels_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmltest.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmltest_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmltoolingsettings_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmltyperegistrar_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmlworkerscript.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmlworkerscript_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmlxmllistmodel.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmlxmllistmodel_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quick.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quick_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickcontrols2.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickcontrols2_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickcontrols2impl.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickcontrols2impl_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickcontrolstestutilsprivate_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickdialogs2.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickdialogs2_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickdialogs2quickimpl.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickdialogs2quickimpl_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickdialogs2utils.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickdialogs2utils_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickeffects_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quicklayouts.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quicklayouts_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickparticles_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickshapes_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quicktemplates2.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quicktemplates2_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quicktestutilsprivate_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickwidgets.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_sql.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_sql_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_svg.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_svg_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_svgwidgets.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_svgwidgets_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_testlib.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_testlib_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_tools_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_uiplugin.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_uitools.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_uitools_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_widgets.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_widgets_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_xml.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_xml_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_zlib_private.pri \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/qt_functions.prf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/qt_config.prf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/win32-g++/qmake.conf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/spec_post.prf \
		.qmake.stash \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/exclusive_builds.prf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/toolchain.prf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/default_pre.prf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/win32/default_pre.prf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/resolve_config.prf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/exclusive_builds_post.prf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/default_post.prf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/qml_debug.prf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/precompile_header.prf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/warn_on.prf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/permissions.prf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/qt.prf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/resources_functions.prf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/resources.prf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/moc.prf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/win32/opengl.prf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/uic.prf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/qmake_use.prf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/file_copies.prf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/win32/windows.prf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/testcase_targets.prf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/exceptions.prf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/yacc.prf \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/lex.prf \
		Tank_QT_v2.pro \
		../../../qt_free/6.6.2/mingw_64/lib/Qt6Widgets.prl \
		../../../qt_free/6.6.2/mingw_64/lib/Qt6Gui.prl \
		../../../qt_free/6.6.2/mingw_64/lib/Qt6Core.prl \
		../../../qt_free/6.6.2/mingw_64/lib/Qt6EntryPoint.prl \
		../../../qt_free/6.6.2/mingw_64/mkspecs/features/build_pass.prf \
		src.qrc
	$(QMAKE) -o Makefile Tank_QT_v2.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug"
../../../qt_free/6.6.2/mingw_64/mkspecs/features/spec_pre.prf:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/device_config.prf:
../../../qt_free/6.6.2/mingw_64/mkspecs/common/sanitize.conf:
../../../qt_free/6.6.2/mingw_64/mkspecs/common/gcc-base.conf:
../../../qt_free/6.6.2/mingw_64/mkspecs/common/g++-base.conf:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/win32/windows_vulkan_sdk.prf:
../../../qt_free/6.6.2/mingw_64/mkspecs/common/windows-vulkan.conf:
../../../qt_free/6.6.2/mingw_64/mkspecs/common/g++-win32.conf:
../../../qt_free/6.6.2/mingw_64/mkspecs/common/windows-desktop.conf:
../../../qt_free/6.6.2/mingw_64/mkspecs/qconfig.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_ext_freetype.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_ext_libjpeg.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_ext_libpng.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_concurrent.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_concurrent_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_core.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_core_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_dbus.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_dbus_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_designer.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_designer_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_designercomponents_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_entrypoint_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_example_icons_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_fb_support_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_freetype_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_gui.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_gui_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_harfbuzz_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_help.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_help_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_jpeg_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_labsanimation.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_labsanimation_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_labsfolderlistmodel.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_labsfolderlistmodel_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_labsqmlmodels.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_labsqmlmodels_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_labssettings.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_labssettings_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_labssharedimage.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_labssharedimage_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_labswavefrontmesh.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_labswavefrontmesh_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_linguist.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_linguist_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_network.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_network_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_opengl.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_opengl_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_openglwidgets.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_openglwidgets_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_packetprotocol_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_png_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_printsupport.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_printsupport_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qdoccatch_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qdoccatchconversionsprivate.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qdoccatchconversionsprivate_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qdoccatchgeneratorsprivate.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qdoccatchgeneratorsprivate_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qml.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qml_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmlcompiler.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmlcompiler_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmlcore.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmlcore_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmldebug_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmldom_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmlintegration.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmlintegration_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmllocalstorage.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmllocalstorage_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmlls_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmlmodels.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmlmodels_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmltest.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmltest_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmltoolingsettings_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmltyperegistrar_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmlworkerscript.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmlworkerscript_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmlxmllistmodel.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_qmlxmllistmodel_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quick.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quick_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickcontrols2.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickcontrols2_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickcontrols2impl.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickcontrols2impl_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickcontrolstestutilsprivate_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickdialogs2.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickdialogs2_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickdialogs2quickimpl.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickdialogs2quickimpl_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickdialogs2utils.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickdialogs2utils_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickeffects_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quicklayouts.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quicklayouts_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickparticles_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickshapes_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quicktemplates2.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quicktemplates2_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quicktestutilsprivate_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickwidgets.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_quickwidgets_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_sql.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_sql_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_svg.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_svg_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_svgwidgets.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_svgwidgets_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_testlib.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_testlib_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_tools_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_uiplugin.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_uitools.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_uitools_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_widgets.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_widgets_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_xml.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_xml_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/modules/qt_lib_zlib_private.pri:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/qt_functions.prf:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/qt_config.prf:
../../../qt_free/6.6.2/mingw_64/mkspecs/win32-g++/qmake.conf:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/spec_post.prf:
.qmake.stash:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/exclusive_builds.prf:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/toolchain.prf:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/default_pre.prf:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/win32/default_pre.prf:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/resolve_config.prf:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/exclusive_builds_post.prf:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/default_post.prf:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/qml_debug.prf:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/precompile_header.prf:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/warn_on.prf:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/permissions.prf:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/qt.prf:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/resources_functions.prf:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/resources.prf:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/moc.prf:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/win32/opengl.prf:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/uic.prf:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/qmake_use.prf:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/file_copies.prf:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/win32/windows.prf:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/testcase_targets.prf:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/exceptions.prf:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/yacc.prf:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/lex.prf:
Tank_QT_v2.pro:
../../../qt_free/6.6.2/mingw_64/lib/Qt6Widgets.prl:
../../../qt_free/6.6.2/mingw_64/lib/Qt6Gui.prl:
../../../qt_free/6.6.2/mingw_64/lib/Qt6Core.prl:
../../../qt_free/6.6.2/mingw_64/lib/Qt6EntryPoint.prl:
../../../qt_free/6.6.2/mingw_64/mkspecs/features/build_pass.prf:
src.qrc:
qmake: FORCE
	@$(QMAKE) -o Makefile Tank_QT_v2.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug"

qmake_all: FORCE

make_first: debug-make_first release-make_first  FORCE
all: debug-all release-all  FORCE
clean: debug-clean release-clean  FORCE
distclean: debug-distclean release-distclean  FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) .qmake.stash

debug-mocclean:
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean:
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables:
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables:
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables

check: first

benchmark: first
FORCE:

.SUFFIXES:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile