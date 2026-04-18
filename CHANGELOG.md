# Changelog

All notable changes to **youtube-client** will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/), and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

---

## [1.0.2] - 2026-04-18

### Added
- Rich **About Dialog** (`dialog_about.c` + `dialog_about.h`) using `GtkAboutDialog`
  - Displays application name, version, description, author, GitHub link
  - Shows platform, OS version, architecture, and libc information (glibc/musl/etc.)
  - Proper MIT license display
- Both **"About"** (rich information) and **"Show Version"** (simple version dialog) available in the menu
- Platform detection helper with detailed system information
- Dual About menu structure following GNOME HIG recommendations

### Changed
- `on_show_about_activate()` now provides comprehensive application and system information
- Updated menu structure in `main.c` to include both About and Version entries under the "About" submenu
- Improved version dialog (`dialog_version.c`) consistency with new About dialog

### Improved
- Better user experience with modern, informative About dialog
- Enhanced transparency by showing build/platform details
- Stronger alignment with GNOME Human Interface Guidelines

### Fixed
- Build compatibility issues in `dialog_about.c` (`GTK_LICENSE_MIT` → `GTK_LICENSE_CUSTOM`, proper libc header inclusion)

---

## [1.0.1] - 2026-04-18

### Added
- Generic bookmark system: `menu_bookmark.c` + `menu_bookmark.h` providing reusable callback `on_menu_bookmark_clicked`
- YouTube-specific bookmark menu now uses the centralized generic callback
- Centralized URL bar callbacks via `url_bar_callbacks.h`
- Full support for Enter key in URL bar
- Strong defensive documentation for SyncPrjs cloning compatibility

### Changed
- Renamed bookmark callback to `on_menu_bookmark_clicked` for better clarity
- Improved modular separation and documentation

---

## [1.0.0] - 2026-04-12

### Added
- Initial stable release of native YouTube client using WebKitGTK
- Persistent cookie storage
- User-Agent spoofing menu
- Bookmark menu
- Smart URL bar with real-time updates
- Version dialog
- Centralized output system with `--quiet`, `--json`, `DEBUG=1`
- Full CIAO defensive coding style

### Features
- Lightweight native GNOME application (no Electron)
- Multi-build system support

---

## Unreleased

### Planned for future versions
- Progress indicator during page load
- Reload menu item / button
- Keyboard shortcuts (e.g. F5, Ctrl+R)
- Basic history support
- Flathub packaging

---

## How to Contribute

Please follow the existing **CIAO Defensive Coding Style** when submitting changes. All new modules must include proper protection rules and maintain Single Source of Truth principles.

---

**Project maintained with ❤️ using SyncPrjs workflow**