#include <cutils/properties.h>
#include "camdev.h"

int main(int argc, char *argv[])
{
    void   *cam = NULL;
    char    dev[32] = "/dev/video0";
    int     sub     = 0;
    int     w       = 640;
    int     h       = 480;

    switch (argc) {
    case 5: h = atoi(argv[4]);
    case 4: w = atoi(argv[3]);
    case 3: sub = atoi(argv[2]);
    case 2: strcpy(dev, argv[1]);
    }
    printf("dev = %s, sub = %d, w = %d, h = %d\n", dev, sub, w, h);

    // set exit flag to 0
    property_set("sys.v4l2.test.exit", "0");

    // create a client to surfaceflinger
    sp<SurfaceComposerClient> client = new SurfaceComposerClient();
    sp<IBinder> dtoken(SurfaceComposerClient::getBuiltInDisplay(
            ISurfaceComposer::eDisplayIdMain));

    DisplayInfo dinfo;
    status_t status = SurfaceComposerClient::getDisplayInfo(dtoken, &dinfo);
    if (status) {
        return -1;
    }

    sp<SurfaceControl> surfaceControl = client->createSurface(String8("yuvtest_surface"),
            dinfo.w, dinfo.h, PIXEL_FORMAT_RGBX_8888, 0);

    SurfaceComposerClient::openGlobalTransaction();
    surfaceControl->setLayer(0x40000000);
//  surfaceControl->setPosition(0, 0);
//  surfaceControl->setSize(320, 180);
    SurfaceComposerClient::closeGlobalTransaction();

    sp<Surface>   surface = surfaceControl->getSurface();
    sp<ANativeWindow> win = surface;

    // init camdev
    cam = camdev_init(dev, sub, w, h, 30);
    if (!cam) {
        printf("failed to create camdev !\n");
        exit(1);
    }

    // startpreview
    camdev_set_preview_window(cam, win);
    camdev_capture_start(cam);
    camdev_preview_start(cam);

    // wait exit
    while (1) {
        char exit[PROP_VALUE_MAX];
        property_get("sys.v4l2.test.exit", exit, "0");
        if (strcmp(exit, "1") == 0) {
            break;
        }
        usleep(100*1000);
    }

    // stoppreview
    camdev_preview_stop(cam);
    camdev_capture_stop(cam);

    // close camdev
    camdev_close(cam);

    return 0;
}

