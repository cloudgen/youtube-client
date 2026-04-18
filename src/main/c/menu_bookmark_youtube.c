// =========================================================================
// CIAO DEFENSIVE CODING STYLE - YOUTUBE BOOKMARK MENU
// =========================================================================
//
// YouTube-specific menu creation only.
// Uses the generic callback on_menu_bookmark_clicked from menu_bookmark.c
// =========================================================================

#include "menu_bookmark_youtube.h"
#include "menu_bookmark.h"
#include "project.h"
#include "output.h"
#include <gtk/gtk.h>

GtkWidget* add_bookmark_menu_youtube(GtkEntry *url_entry)
{
    if (url_entry == NULL) {
        ciao_error("add_bookmark_menu_youtube: url_entry is NULL");
        return NULL;
    }

    GtkWidget *bookmark_menu = gtk_menu_new();

    GtkWidget *start_menu_item   = gtk_menu_item_new_with_label("Start Page");
    GtkWidget *profile_menu_item = gtk_menu_item_new_with_label("Profile Page");

    // Attach URL entry reference (used by generic callback)
    g_object_set_data(G_OBJECT(start_menu_item),   "url_entry", url_entry);
    g_object_set_data(G_OBJECT(profile_menu_item), "url_entry", url_entry);

    // Connect to centralized generic callback with YouTube-specific URLs
    g_signal_connect_data(start_menu_item,   "activate",
                         G_CALLBACK(on_menu_bookmark_clicked),
                         (gpointer)START_PAGE, NULL, 0);

    g_signal_connect_data(profile_menu_item, "activate",
                         G_CALLBACK(on_menu_bookmark_clicked),
                         (gpointer)PROFILE_PAGE, NULL, 0);

    gtk_menu_shell_append(GTK_MENU_SHELL(bookmark_menu), start_menu_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(bookmark_menu), profile_menu_item);

    GtkWidget *bookmark_menu_item = gtk_menu_item_new_with_label("Bookmark");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(bookmark_menu_item), bookmark_menu);

    ciao_debug("YouTube bookmark menu created successfully");

    return bookmark_menu_item;
}