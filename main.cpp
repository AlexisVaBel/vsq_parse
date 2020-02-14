#include <iostream>

#include "lib/nuklear.h"
#include "lib/nuklear_xlib.h"


#include <getopt.h>
#include <memory>
#include <cstdarg>
#include <sys/time.h>
#include "vsqconstructor.h"

static const char *optString = "p:";
static char * CH_DEFAULT_XML_FILE = "../xml_files/simple.xml";

struct globalArgs_t{
    char *fullPath;
} globalArgs;

void fill_cmd_args(int &opt){
    switch (opt){
        case 'p' : globalArgs.fullPath = optarg;
    }
}

void prepare_args(){
    globalArgs.fullPath = CH_DEFAULT_XML_FILE;
}

void read_cmd_conf(int &argc, char ** argv){
    int opt = 0;
    prepare_args();
    do{
        opt = getopt(argc, argv, optString);
        fill_cmd_args(opt);
    }while (opt != -1);
}


typedef struct XWindow XWindow;
struct XWindow {
    Display *dpy;
    Window root;
    Visual *vis;
    Colormap cmap;
    XWindowAttributes attr;
    XSetWindowAttributes swa;
    Window win;
    int screen;
    XFont *font;
    unsigned int width;
    unsigned int height;
    Atom wm_delete_window;
};

static void
die(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    fputs("\n", stderr);
    exit(EXIT_FAILURE);
}

static long
timestamp(void)
{
    struct timeval tv;
    if (gettimeofday(&tv, NULL) < 0) return 0;
    return (long)((long)tv.tv_sec * 1000 + (long)tv.tv_usec/1000);
}

static void
sleep_for(long t)
{
    struct timespec req;
    const time_t sec = (int)(t/1000);
    const long ms = t - (sec * 1000);
    req.tv_sec = sec;
    req.tv_nsec = ms * 1000000L;
    while(-1 == nanosleep(&req, &req));
}





int main(int argc, char ** argv) {
    read_cmd_conf(argc, argv);

    std::string str = globalArgs.fullPath;

    std::unique_ptr<VsqConstructor> vsq_construct = std::make_unique<VsqConstructor>();
    if(vsq_construct->process_xml_ok(str))
        vsq_construct->process_items();

    return 0;
}
