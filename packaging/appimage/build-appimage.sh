#!/bin/sh
# Build the Rock n' Roll Racing AppImage from an already-built Linux binary.
# Usage: packaging/appimage/build-appimage.sh <path-to-rock-n-roll-racing> [output.AppImage]
# Requires: appimagetool (https://github.com/AppImage/appimagetool), file
# Optional: set UPDATE_INFO, e.g.
#   UPDATE_INFO="gh-releases-zsync|herijooj|Rock-N-Roll-Racing-SNES-Static-Recomp|latest|*.AppImage.zsync"
set -eu
BIN="${1:?usage: build-appimage.sh <binary> [output.AppImage]}"
OUT="${2:-Rock-n-Roll-Racing-x86_64.AppImage}"
HERE="$(dirname "$(readlink -f "$0")")"
if ! command -v file >/dev/null 2>&1; then
  echo "error: the 'file' command is required by appimagetool" >&2
  exit 1
fi
# Build the AppDir under the source tree (git-ignored build/) rather than
# mktemp's TMPDIR: some sandboxed shells (e.g. nix-shell) use a private
# TMPDIR that appimagetool's AppDir validation cannot traverse.
# Override with APPIMAGE_WORKDIR to place it elsewhere.
WORK_BASE="${APPIMAGE_WORKDIR:-$PWD/build}"
mkdir -p "$WORK_BASE"
WORK="$(mktemp -d "$WORK_BASE/appdir-tmp.XXXXXX")"
trap 'rm -rf "$WORK"' EXIT
APPDIR="$WORK/AppDir"
mkdir -p "$APPDIR/usr/bin" "$APPDIR/usr/share/applications" \
  "$APPDIR/usr/share/icons/hicolor/256x256/apps" \
  "$APPDIR/usr/share/metainfo"
cp "$BIN" "$APPDIR/usr/bin/rock-n-roll-racing"
cp "$HERE/AppRun" "$APPDIR/AppRun"
cp "$HERE/rock-n-roll-racing.desktop" "$APPDIR/usr/share/applications/"
cp "$HERE/rock-n-roll-racing.png" "$APPDIR/usr/share/icons/hicolor/256x256/apps/"
cp "$HERE/com.github.herijooj.rock-n-roll-racing.metainfo.xml" "$APPDIR/usr/share/metainfo/"
chmod +x "$APPDIR/usr/bin/rock-n-roll-racing"
cp "$APPDIR/usr/share/icons/hicolor/256x256/apps/rock-n-roll-racing.png" "$APPDIR/rock-n-roll-racing.png"
cp "$APPDIR/usr/share/icons/hicolor/256x256/apps/rock-n-roll-racing.png" "$APPDIR/.DirIcon"
cp "$HERE/rock-n-roll-racing.desktop" "$APPDIR/"
if [ -n "${UPDATE_INFO:-}" ]; then
  ARCH=x86_64 appimagetool -u "$UPDATE_INFO" "$APPDIR" "$OUT"
else
  ARCH=x86_64 appimagetool "$APPDIR" "$OUT"
fi
ls -lh "$OUT"
