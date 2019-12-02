#include 

int
main(int argc, char *argv[])
{
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
