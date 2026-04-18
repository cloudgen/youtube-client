// =========================================================================
// CIAO DEFENSIVE CODING STYLE - ABOUT DIALOG MODULE (GNOME + GTK)
// =========================================================================
//
// !!! THIS IS A GNOME/GTK APPLICATION !!!
// !!! ONLY g_print() / g_printerr() ARE ALLOWED THROUGH ciao_* FUNCTIONS !!!
// 
// Last aligned with SyncPrjs CIAO style + GNOME HIG: 2026-04-18
// =========================================================================

#include "dialog_about.h"
#include "output.h"
#include "project.h"
#include <gtk/gtk.h>
#include <glib.h>
#include <string.h>

#ifdef __linux__
#include <sys/utsname.h>
#endif

// =========================================================================
// Helper: Build platform + libc string
// =========================================================================
static gchar* get_platform_info(void)
{
    GString *info = g_string_new(NULL);

    // OS Information
    const gchar *os_name = g_get_os_info(G_OS_INFO_KEY_NAME);
    const gchar *os_version = g_get_os_info(G_OS_INFO_KEY_VERSION);
    
    if (os_name) {
        g_string_append_printf(info, "%s", os_name);
        if (os_version) g_string_append_printf(info, " %s", os_version);
    } else {
        g_string_append(info, "Linux");
    }

    // libc detection
    const gchar *libc = "unknown";
#ifdef __GLIBC__
    libc = "glibc";
    gchar *glibc_ver = g_strdup(gnu_get_libc_version());
    if (glibc_ver) {
        g_string_append_printf(info, " • glibc %s", glibc_ver);
        g_free(glibc_ver);
    }
#elif defined(__MUSL__)
    libc = "musl";
    g_string_append(info, " • musl");
#elif defined(__UCLIBC__)
    libc = "uClibc";
    g_string_append(info, " • uClibc");
#endif

    g_string_append_printf(info, " • %s", libc);

    // Architecture
    gchar *arch = g_strdup(g_getenv("HOSTTYPE"));
    if (!arch || !*arch) arch = g_strdup("unknown");
    g_string_append_printf(info, " • %s", arch);
    g_free(arch);

    return g_string_free(info, FALSE);
}

// =========================================================================
// About Dialog Callback
// =========================================================================
void on_show_about_activate(GtkMenuItem *menu_item, gpointer user_data)
{
    (void)menu_item; // unused

    GtkWindow *parent = user_data ? GTK_WINDOW(user_data) : NULL;

    GtkWidget *dialog = gtk_about_dialog_new();
    if (!dialog) {
        ciao_error("Failed to create GtkAboutDialog");
        return;
    }

    gchar *platform = get_platform_info();

    gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(dialog), PROJECT_NAME);
    gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog), 
        g_strdup_printf("%d.%d.%d", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH));
    gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dialog),
        "A lightweight native YouTube client built with WebKitGTK\n"
        "No Electron • No bloat • Pure GNOME experience");
    
    gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dialog),
        "© 2026 Cloudgen Wong. All rights reserved.");
    
    gtk_about_dialog_set_license_type(GTK_ABOUT_DIALOG(dialog), GTK_LICENSE_MIT);
    gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(dialog), "https://github.com/cloudgen/youtube-client");
    gtk_about_dialog_set_website_label(GTK_ABOUT_DIALOG(dialog), "GitHub Repository");
    gtk_about_dialog_set_authors(GTK_ABOUT_DIALOG(dialog), (const gchar*[]){"Cloudgen Wong (@cloudgen)", NULL});
    
    // Extra platform info
    gtk_about_dialog_set_logo_icon_name(GTK_ABOUT_DIALOG(dialog), "applications-internet");
    gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dialog),
        g_strdup_printf("Built for: %s\n\nA clean, efficient alternative to Electron-based clients.",
                        platform));

    ciao_debug("About dialog displayed for %s %d.%d.%d", 
               PROJECT_NAME, VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);

    // Run and clean up
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    g_free(platform);
}