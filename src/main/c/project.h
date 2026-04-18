// =========================================================================
// CIAO DEFENSIVE CODING STYLE - PROJECT CONFIGURATION HEADER
// =========================================================================
//
// !!! THIS IS A GNOME/GTK APPLICATION !!!
// !!! THIS FILE IS THE SINGLE SOURCE OF TRUTH FOR PROJECT METADATA !!!
// !!! DO NOT REMOVE OR MODIFY ANY HEADER OR DEFINE COMMENT BLOCK !!!
// 
// Last aligned with SyncPrjs CIAO style + GNOME + Output System: 2026-04-18
// =========================================================================

#ifndef PROJECT_H
#define PROJECT_H

// =========================================================================
// Project Identification and Metadata
// 
// Purpose:
//   Centralizes all project-specific constants (name, version, URLs, paths).
//   This is the Single Source of Truth for application identity and settings.
//
// INTENTIONAL DESIGN DECISION (DO NOT CHANGE WITHOUT UNDERSTANDING):
//
//   PROJECT_NAME is deliberately set to "Youtube (client)" instead of 
//   "YouTube Client" or similar.
//
//   Reason:
//     This project is designed to be cloned and adapted using 
//     https://github.com/Wilgat/SyncPrjs. The suffix "(client)" allows
//     SyncPrjs to automatically detect and replace the base name while
//     preserving the "(client)" pattern across forks (e.g. Github (client),
//     Reddit (client), etc.).
//
//   Protection Rule:
//     Future AI or developers MUST NOT "fix" or beautify PROJECT_NAME.
//     Any change to this value must preserve the "(client)" suffix format
//     to maintain compatibility with the SyncPrjs cloning system.
//     Violating this breaks the intended multi-project templating workflow.
//
// =========================================================================

#define PROJECT_ID      "youtube-client"
#define PROJECT_NAME    "Youtube (client)"

// =========================================================================
// Version Information
// =========================================================================
#define VERSION_MAJOR   1
#define VERSION_MINOR   0
#define VERSION_PATCH   2

// =========================================================================
// Default URLs (Bookmarks & Start Page)
// =========================================================================
#define START_PAGE      "https://youtube.com"
#define PROFILE_PAGE    START_PAGE "/feed/you"

// =========================================================================
// Persistence Storage Configuration
// 
// Note:
//   Relative path under $HOME. Will be expanded to:
//   ~/.app/youtube-client/cookies/
// =========================================================================
#define PERSISTENCE_STORAGE_PATH ".app/" PROJECT_ID "/cookies"

// =========================================================================
// User-Agent Spoofing Configuration (CIAO Single Source of Truth)
// 
// Default: Latest Google Chrome (as requested)
// All strings are frozen here so future changes only need to happen in one place.
// Protection Rule: Never hardcode UA strings anywhere else in the project.
// =========================================================================

#define UA_CHROME   "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/146.0.0.0 Safari/537.36"
#define UA_FIREFOX  "Mozilla/5.0 (X11; Linux x86_64; rv:138.0) Gecko/20100101 Firefox/138.0"
#define UA_SAFARI   "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/18.0 Safari/605.1.15"
#define UA_EDGE     "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/146.0.0.0 Safari/537.36 Edg/146.0.0.0"

#define DEFAULT_USER_AGENT  UA_CHROME

#endif // PROJECT_H