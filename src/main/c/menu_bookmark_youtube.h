// =========================================================================
// CIAO DEFENSIVE CODING STYLE - YOUTUBE BOOKMARK MENU HEADER (GNOME + GTK)
// =========================================================================
//
// !!! THIS IS A GNOME/GTK APPLICATION !!!
// !!! DO NOT REMOVE OR MODIFY ANY HEADER OR FUNCTION COMMENT BLOCK !!!
// 
// Last aligned with SyncPrjs CIAO style + GNOME + Output System: 2026-04-18
// =========================================================================

#ifndef MENU_BOOKMARK_YOUTUBE_H
#define MENU_BOOKMARK_YOUTUBE_H

#include <gtk/gtk.h>

// =========================================================================
// Public API - YouTube Bookmark Menu Module
// 
// Purpose:
//   Provides a bookmark submenu with quick links to important YouTube pages
//   (Start Page, Profile Page, etc.).
// 
// Design Rules:
//   - Only public function is exposed.
//   - Uses the generic callback (on_menu_bookmark_clicked) from menu_bookmark.c
//   - Uses data passing via g_object_set_data for clean GTK integration.
// 
// Protection Rule:
//   Future AI must NOT expose internal functions or change the public
//   function signature. All menu creation must go through this module.
// =========================================================================

// =========================================================================
// Create and return the Bookmark menu item with submenu
// 
// Parameters:
//   url_entry : The main URL bar (GtkEntry) used to pass context to menu items
// 
// Returns:
//   GtkWidget* - The top-level "Bookmark" menu item (with submenu attached)
// =========================================================================
GtkWidget* add_bookmark_menu_youtube(GtkEntry *url_entry);

#endif // MENU_BOOKMARK_YOUTUBE_H