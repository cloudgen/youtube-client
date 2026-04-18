# Changelog

All notable changes to **youtube-client** will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/), and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

---

## [1.0.2] - 2026-04-18

### Added
- Generic bookmark system: `menu_bookmark.c` + `menu_bookmark.h` providing reusable callback `on_menu_bookmark_clicked`
- YouTube-specific bookmark menu (`menu_bookmark_youtube.c`) now uses the centralized generic callback
- Centralized URL bar callbacks via new `url_bar_callbacks.h` for better cross-file and cross-project flexibility
- Full support for Enter key in URL bar (same behavior as Go button)
- Strong defensive documentation for SyncPrjs cloning compatibility in `project.h`

### Changed
- Renamed bookmark callback from `on_menu_item_clicked` to `on_menu_bookmark_clicked` for clarity and intent
- Updated all header comments and protection rules to reflect current modular architecture
- Improved documentation throughout the codebase with clearer CIAO protection rules
- `PROJECT_NAME` intentionally kept as `"Youtube (client)"` with detailed explanation for SyncPrjs workflow

### Improved
- Modular separation between generic logic and project-specific logic (better reusability for future forks)
- Signal handling architecture for URL bar (more robust and maintainable)
- Cross-file callback linkage safety (no `static` on callbacks used by `g_signal_connect`)

### Fixed
- Outdated comments in `menu_bookmark_youtube.h`
- Minor typo in include comment (`includ` → `include`)

---

## [1.0.0] - 2026-04-12

### Added
- Initial stable release of native YouTube client using WebKitGTK
- Persistent cookie storage (`~/.app/youtube-client/cookies/`)
- User-Agent spoofing menu (Chrome default + Firefox, Safari, Edge)
- Bookmark menu with Start Page and Profile Page
- URL bar with real-time updates (`notify::uri` + `load-changed`)
- Version dialog
- Centralized output system with `--quiet`, `--json`, and `DEBUG=1` support
- Full CIAO defensive coding style implementation

### Features
- Lightweight native GNOME application (no Electron)
- Proper GTK/WebKitGTK integration
- Defensive programming with extensive protection rules
- Multi-build system support (Make, Meson, etc.)

---

## Unreleased

### Planned for future versions
- Progress indicator during page load
- Reload menu item
- Keyboard shortcuts
- History support
- Flathub packaging

---

## How to Contribute

Please follow the existing **CIAO Defensive Coding Style** when submitting changes. All new modules must include proper protection rules and maintain Single Source of Truth principles.

---

**Project maintained with ❤️ using SyncPrjs workflow**