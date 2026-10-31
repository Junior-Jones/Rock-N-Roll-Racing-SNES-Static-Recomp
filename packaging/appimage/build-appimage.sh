#!/bin/sh
# Build the Rock n' Roll Racing AppImage from an already-built Linux binary.
# Usage: packaging/appimage/build-appimage.sh <path-to-rock-n-roll-racing> [output.AppImage]
# Requires: appimagetool (https://github.com/AppImage/appimagetool), file
set -eu
BIN="${1:?usage: build-appimage.sh <binary> [output.AppImage]}"
OUT="${2:-Rock-n-Roll-Racing-x86_64.AppImage}"
HERE="$(dirname "$(readlink -f "$0")")"
WORK="$(mktemp -d)"
trap 'rm -rf "$WORK"' EXIT
APPDIR="$WORK/AppDir"
mkdir -p "$APPDIR/usr/bin" "$APPDIR/usr/share/applications" \
  "$APPDIR/usr/share/icons/hicolor/256x256/apps"
cp "$BIN" "$APPDIR/usr/bin/rock-n-roll-racing"
cp "$HERE/rock-n-roll-racing.desktop" "$APPDIR/usr/share/applications/"
cp "$HERE/AppRun" "$APPDIR/AppRun"
chmod +x "$APPDIR/AppRun"
# Icon: reuse repo icon if present, else generate a placeholder.
if [ -f "$HERE/rock-n-roll-racing.png" ]; then
  cp "$HERE/rock-n-roll-racing.png" "$APPDIR/usr/share/icons/hicolor/256x256/apps/"
else
  # 1x1 red PNG placeholder (replace with real icon)
  printf '\x89PNG\r\n\x1a\n\x00\x00\x00\rIHDR\x00\x00\x00\x01\x00\x00\x00\x01\x08\x02\x00\x00\x00\x90wS\xde\x00\x00\x00\x0cIDATx\x9cc\xf8\x0f\x00\x00\x01\x01\x00\x05\x18\xd8N\x00\x00\x00\x00IEND\xaeB`\x82' \
    > "$APPDIR/usr/share/icons/hicolor/256x256/apps/rock-n-roll-racing.png"
fi
cp "$APPDIR/usr/share/icons/hicolor/256x256/apps/rock-n-roll-racing.png" "$APPDIR/rock-n-roll-racing.png"
cp "$APPDIR/usr/share/icons/hicolor/256x256/apps/rock-n-roll-racing.png" "$APPDIR/.DirIcon"
cp "$HERE/rock-n-roll-racing.desktop" "$APPDIR/"
ARCH=x86_64 appimagetool "$APPDIR" "$OUT"
ls -lh "$OUT"
