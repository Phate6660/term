#include <vte/vte.h>

int
main(int argc, char *argv[]) {
    GtkWidget *window, *terminal;
    /* Initialise GTK, the window and the terminal */
    gtk_init(&argc, &argv);
    terminal = vte_terminal_new();
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    /* various settings and customizations */
    vte_terminal_set_scroll_on_output(VTE_TERMINAL(terminal), FALSE); // dont scroll on output
    vte_terminal_set_scroll_on_keystroke(VTE_TERMINAL(terminal), TRUE); // scroll on keypress
    vte_terminal_set_mouse_autohide(VTE_TERMINAL(terminal), TRUE); // autohide mouse when typing
    vte_terminal_set_cursor_blink_mode(VTE_TERMINAL(terminal), VTE_CURSOR_BLINK_OFF); // disable cursor blink
    vte_terminal_set_allow_bold(VTE_TERMINAL(terminal), TRUE); // allow bold text
    #define TERM_FONT "Misc Fixed 9" // set the font
    PangoFontDescription *descr;
    descr = pango_font_description_from_string(TERM_FONT);
    vte_terminal_set_font(terminal, descr);
    pango_font_description_free(descr);
    /* #define CLR_R(x)   (((x) & 0xff0000) >> 16)
    #define CLR_G(x)   (((x) & 0x00ff00) >>  8)
    #define CLR_B(x)   (((x) & 0x0000ff) >>  0)
    #define CLR_16(x)  ((double)(x) / 0xff)
    #define CLR_GDK(x) (const GdkRGBA){ .red = CLR_16(CLR_R(x)), \
                                        .green = CLR_16(CLR_G(x)), \
                                        .blue = CLR_16(CLR_B(x)), \
                                        .alpha = 0 }
    vte_terminal_set_colors(VTE_TERMINAL(terminal),
        &CLR_GDK(0xffffff),
        &(GdkRGBA){ .alpha = 0.85 },
        (const GdkRGBA[]){
            CLR_GDK(0x111111), // edit
            CLR_GDK(0xd36265), // these
            CLR_GDK(0xaece91), // to
            CLR_GDK(0xe7e18c), // change
            CLR_GDK(0x5297cf), // the
            CLR_GDK(0x963c59), // colorscheme
            CLR_GDK(0x5E7175), // edit
            CLR_GDK(0xbebebe), // these
            CLR_GDK(0x666666), // to
            CLR_GDK(0xef8171), // change
            CLR_GDK(0xcfefb3), // the
            CLR_GDK(0xfff796), // colorscheme
            CLR_GDK(0x74b8ef), // edit
            CLR_GDK(0xb85e7b), // these
            CLR_GDK(0xA3BABF), // to
            CLR_GDK(0xffffff) // change the colorsheme
    }, 16); */
    char* name = NULL;
    gtk_window_set_wmclass(GTK_WINDOW (window), name ? name : "valleyTERM", "valleyTERM");
    /* Start a new shell */
    gchar **envp = g_get_environ();
    gchar **command = (gchar *[]){g_strdup(g_environ_getenv(envp, "SHELL")), NULL };
    g_strfreev(envp);
    vte_terminal_spawn_async(VTE_TERMINAL(terminal),
        VTE_PTY_DEFAULT,
        NULL,       /* working directory  */
        command,    /* command */
        NULL,       /* environment */
        0,          /* spawn flags */
        NULL, NULL, /* child setup */
        NULL,       /* child pid */
        -1,         /* timeout */
        NULL, NULL, NULL);
    /* Connect some signals */
    g_signal_connect(window, "delete-event", gtk_main_quit, NULL);
    g_signal_connect(terminal, "child-exited", gtk_main_quit, NULL);
    /* Put widgets together and run the main loop */
    gtk_container_add(GTK_CONTAINER(window), terminal);
    gtk_widget_show_all(window);
    gtk_main();
}
