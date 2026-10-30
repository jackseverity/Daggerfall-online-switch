// Daggerfall Online launcher for Nintendo Switch homebrew.
// Opens the Daggerfall Online browser client in the console's built-in web applet.
#include <stdio.h>
#include <switch.h>

#define DFO_URL "https://daggerfall.online/"

static void wait_for_exit(PadState *pad)
{
    printf("\nPress + to exit.\n");
    while (appletMainLoop()) {
        padUpdate(pad);
        if (padGetButtonsDown(pad) & HidNpadButton_Plus)
            break;
        consoleUpdate(NULL);
    }
}

int main(int argc, char *argv[])
{
    consoleInit(NULL);
    padConfigureInput(1, HidNpadStyleSet_NpadStandard);
    PadState pad;
    padInitializeDefault(&pad);

    AppletType type = appletGetAppletType();
    if (type != AppletType_Application && type != AppletType_SystemApplication) {
        // The web applet only works with full application memory.
        printf("Daggerfall Online Launcher\n\n");
        printf("This launcher must run in title-override mode.\n");
        printf("Close it, then hold R while starting any installed game\n");
        printf("to open the Homebrew Menu, and launch it from there.\n");
        wait_for_exit(&pad);
        consoleExit(NULL);
        return 0;
    }

    printf("Opening %s ...\n", DFO_URL);
    consoleUpdate(NULL);

    WebCommonConfig config;
    WebCommonReply reply;
    Result rc = webPageCreate(&config, DFO_URL);
    if (R_SUCCEEDED(rc))
        rc = webConfigSetWhitelist(&config, "^http*");
    if (R_SUCCEEDED(rc))
        rc = webConfigShow(&config, &reply);

    if (R_FAILED(rc)) {
        printf("\nThe web browser failed to open (error 0x%x).\n", rc);
        wait_for_exit(&pad);
    }

    consoleExit(NULL);
    return 0;
}
