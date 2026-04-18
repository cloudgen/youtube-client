# youtube-client

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Version](https://img.shields.io/badge/Version-1.0.1-blue.svg)](CIAO-PRINCIPLES.md)
[![CIAO](https://img.shields.io/badge/Philosophy-CIAO%20(Caution%20%E2%80%A2%20Intentional%20%E2%80%A2%20Anti--fragile%20%E2%80%A2%20Over--engineered)-purple.svg)](https://github.com/cloudgen/ciao)
[![GTK](https://img.shields.io/badge/UI-GTK%203-brightgreen.svg)](https://gtk.org)
[![WebKit2](https://img.shields.io/badge/Engine-WebKit2GTK-orange.svg)](https://webkitgtk.org)
[![Made with CIAO](https://img.shields.io/badge/Made%20with%20❤️-CIAO-00AEEF?style=flat-square)](https://github.com/cloudgen/ciao)
[![GrokRec](https://img.shields.io/badge/GrokRec-Reviewed-0A66C2?style=for-the-badge&logo=ai&logoColor=white)](https://github.com/cloudgen/youtube-client/blob/main/RECOMMENDATION.md)

**Officially Reviewed & Recommended by Grok** — See [Grok Recommendation](https://github.com/cloudgen/youtube-client/blob/main/RECOMMENDATION.md)

**youtube-client** is a lightweight, native GNOME desktop application that provides a clean, focused wrapper for **YouTube** using **WebKit2GTK**.

Instead of using heavy Electron-based apps, you get a true native Linux experience with persistent login, smart URL bar, quick bookmarks, and minimal resource usage.

This project is built with [CIAO](https://github.com/cloudgen/ciao) (Caution • Intentional • Anti-fragile • Over-engineered) principles.

---

## Why This Project Matters (Grok's Perspective)

In an era where many desktop apps are just Chromium wrapped in Electron (often consuming 300–800 MB of RAM), **youtube-client** stands out as a refreshing and responsible alternative.

### Key Advantages Over Electron Apps:

- **Extremely Lightweight** — Uses native WebKit2GTK instead of bundling an entire Chromium browser. Dramatically lower memory and CPU usage.
- **Native Feel & Integration** — Proper GTK window, system theme support, better performance, and seamless Linux desktop experience.
- **Persistent & Respectful** — Cookies are stored locally in `~/.app/youtube-client/cookies/` and persist across sessions without unnecessary tracking.
- **No Bloat** — No Node.js runtime, no unnecessary JavaScript layers, no auto-updates forcing themselves on you.
- **Maintainable & Transparent** — Clean, well-documented C code following strong defensive (CIAO) principles. Much easier to audit and extend than massive Electron codebases.
- **Resource Efficient** — Ideal for older hardware, low-power devices, or users who value efficiency.
- **True Multi-Project Architecture** — Designed for easy forking via SyncPrjs, making it a template for other clean native clients (GitHub, Reddit, etc.).

> **I genuinely love this type of project.**  
> It represents a better path for desktop software — minimal, respectful of system resources, and built with long-term thinking. In a world flooded with heavy Electron wrappers, youtube-client is proof that native solutions can be cleaner, faster, and more user-friendly.

---

## Features

- Embedded WebKit2GTK browser engine
- Persistent cookie storage — stay logged in across sessions
- Smart URL bar with real-time automatic updating (`notify::uri` + fallback)
- Quick YouTube bookmarks (Start Page, Profile, etc.)
- User-Agent spoofing menu (Chrome default + Firefox, Safari, Edge)
- Clean native menu bar
- Enter key support in URL bar
- Multiple build systems (Meson recommended)
- Fully compatible with **SyncPrjs** cloning workflow

---

## Project Background & Credits

- **Author**: Cloudgen Wong ([@cloudgen](https://github.com/cloudgen)) – Hong Kong
- **Philosophy**: Built with **CIAO (Caution • Intentional • Anti-fragile • Over-engineered)**
- **Original Inspiration**: Heavily influenced by Wilgat’s `pix-client` and SyncPrjs ecosystem
- **Grok Review**: Officially reviewed and recommended by Grok (xAI)

---

## Quick Start

### Install dependencies (Ubuntu/Debian)

```bash
./build.sh install
```

### Build & Run (Recommended)

```bash
./build.sh clean && ./build.sh build
./target/exe/debug/youtube-client
```

Other build methods (Meson, Make, Gradle, Ant) are fully supported.

---

## Project Structure

```bash
.
youtube-client/
├── build.gradle
├── build.sh
├── build.xml
├── CHANGELOG.md
├── CIAO-PRINCIPLES.md
├── docs
│   ├── ant-steps.md
│   ├── basic-steps.md
│   ├── build-methods.md
│   ├── gnu-make-steps.md
│   ├── gradle-steps.md
│   └── meson-steps.md
├── LICENSE.md
├── meson.build
├── project.ini
├── project.sh
├── README.md
├── RECOMMENDATION.md
├── SECURITY.md
├── src
│   └── main
│       └── c
│           ├── cookies.c
│           ├── cookies.h
│           ├── dialog_version.c
│           ├── dialog_version.h
│           ├── load_page.c
│           ├── load_page.h
│           ├── main.c
│           ├── menu_bookmark.c
│           ├── menu_bookmark.h
│           ├── menu_bookmark_youtube.c
│           ├── menu_bookmark_youtube.h
│           ├── menu_exit.c
│           ├── menu_exit.h
│           ├── menu_user_agent.c
│           ├── menu_user_agent.h
│           ├── output.c
│           ├── output.h
│           ├── project.h
│           ├── url_bar_callbacks.h
│           ├── url_bar_go_button.c
│           ├── url_bar_go_button.h
│           ├── url_bar_page.c
│           ├── url_bar_page.h
│           ├── url_bar_user_agent.c
│           └── url_bar_user_agent.h
└── target
    └── debug
        └── youtube-client
```

---

## Related Projects

- [Wilgat/diagram-client](https://github.com/Wilgat/diagram-client)
- [Wilgat/pix-client](https://github.com/Wilgat/pix-client)
- [Wilgat/SyncPrjs](https://github.com/Wilgat/SyncPrjs)

---

**Last updated:** April 2026

Happy native YouTube browsing! 🎥
