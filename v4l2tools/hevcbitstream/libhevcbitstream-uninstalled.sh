# generated by configure / remove this line to disable regeneration
prefix="/usr/local"
exec_prefix="${prefix}"
bindir="${exec_prefix}/bin"
libdir="/home/pi/workspace/V4L2-apps/v4l2tools/hevcbitstream"
datarootdir="${prefix}/share"
datadir="${datarootdir}"
sysconfdir="${prefix}/etc"
includedir="/home/pi/workspace/V4L2-apps/v4l2tools/hevcbitstream/."
package="hevcbitstream"
suffix=""

for option; do case "$option" in --list-all|--name) echo  "libhevcbitstream"
;; --help) pkg-config --help ; echo Buildscript Of "libhevcbitstream Library"
;; --modversion|--version) echo "0.2.0"
;; --requires) echo : ""
;; --libs) echo -L${libdir} "-lm" "${libdir}/libhevcbitstream.la"
       :
;; --cflags) echo -I${includedir} ""
       :
;; --variable=*) eval echo '$'`echo $option | sed -e 's/.*=//'`
;; --uninstalled) exit 0 
;; *) ;; esac done
