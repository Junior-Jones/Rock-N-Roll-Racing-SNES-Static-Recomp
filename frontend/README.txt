ROCK N' ROLL RACING WINDOWS FRONTEND PORT

Status: SOURCE_PORTED_UNBUILT
Reference snapshot:
  ../03-RockNRollRacing-Frontend-Reference

This directory replaces the old empty/Linux-era frontend boundary with the
Windows host structure requested for the project. Frontend work remains
separate from static-core authority.

A playable Launcher.exe may be built only after the current core exposes:

  - exact ROM inspection and rejection;
  - one natural-frame execution call;
  - a completed core-owned framebuffer;
  - frame-synchronous SNES controller reports;
  - core-owned native-rate stereo PCM;
  - reset, failure and diagnostic status.

The port must retain the Rock n' Roll Racing host behavior and structure while
replacing every foreign product string, core symbol, ROM identity and storage
identifier. Unsupported commands must be removed. The final window title is
Rock n' Roll Racing (SNES), and the executable name is Launcher.exe.

Qualification is tracked in config/frontend-port-audit.json.
