#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include "window.h"

using namespace std;

Xwindow::Xwindow(int width, int height) {

  d = XOpenDisplay(NULL);
  if (d == NULL) {
    cerr << "Cannot open display" << endl;
    exit(1);
  }
  s = DefaultScreen(d);
  w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, width, height, 1,
                          BlackPixel(d, s), WhitePixel(d, s));
  XSelectInput(d, w, ExposureMask | KeyPressMask);
  XMapRaised(d, w);

  Pixmap pix = XCreatePixmap(d,w,width,
        height,DefaultDepth(d,DefaultScreen(d)));
  gc = XCreateGC(d, pix, 0,(XGCValues *)0);

  XFlush(d);
  XFlush(d);

  // Set up colours.
  XColor xcolour;
  Colormap cmap;
  char color_vals[6][12]={"white", "black", "red", "green", "blue", "grey"};

  cmap=DefaultColormap(d,DefaultScreen(d));
  for(int i=0; i < 6; ++i) {
      XParseColor(d,cmap,color_vals[i],&xcolour);
      XAllocColor(d,cmap,&xcolour);
      colours[i]=xcolour.pixel;
  }

  XSetForeground(d,gc,colours[Black]);

  // Make window non-resizeable.
  XSizeHints hints;
  hints.flags = (USPosition | PSize | PMinSize | PMaxSize );
  hints.height = hints.base_height = hints.min_height = hints.max_height = height;
  hints.width = hints.base_width = hints.min_width = hints.max_width = width;
  XSetNormalHints(d, w, &hints);

  XSynchronize(d,True);

  usleep(1000);
}

Xwindow::~Xwindow() {
  XFreeGC(d, gc);
  XCloseDisplay(d);
}

void Xwindow::fillRectangle(int x, int y, int width, int height, int colour) {
  XSetForeground(d, gc, colours[colour]);
  XFillRectangle(d, w, gc, x, y, width, height);
  XSetForeground(d, gc, colours[Black]);
}

void Xwindow::drawString(int x, int y, string msg) {
  XDrawString(d, w, DefaultGC(d, s), x, y, msg.c_str(), msg.length());
}


void Xwindow::drawPiece(int x, int y, char c, int clr) {

    Pixmap bitmap;
    unsigned int bitmap_width, bitmap_height;                                          
    int hotspot_x, hotspot_y;
    string filename = "";
    filename += tolower(c);
    if(isupper(c)){
      filename += "1";
    }
    if(clr == 1){
      filename += "0";
    }
    filename += ".xbm";
    XSetBackground(d, gc, WhitePixel(d, DefaultScreen(d)));
    XReadBitmapFile(d, w,
                             filename.c_str(),
                             &bitmap_width, &bitmap_height,
                             &bitmap,
                             &hotspot_x, &hotspot_y);

    // switch (rc) {
    //     case BitmapOpenFailed:
    //         fprintf(stderr, "XReadBitmapFile - could not open file 'icon.bmp'.\n");
	  //   exit(1);
    //         break;
    //     case BitmapFileInvalid:
    //         fprintf(stderr,
    //                 "XReadBitmapFile - file '%s' doesn't contain a valid bitmap.\n",
    //                 "icon.bmp");
	  //   exit(1);
    //         break;
    //     case BitmapNoMemory:
    //         fprintf(stderr, "XReadBitmapFile - not enough memory.\n");
	  //   exit(1);
    //         break;
    // }

    /* start drawing the given pixmap on to our window. */
    {

          XCopyPlane(d, bitmap, w, gc,
                    0, 0,
                    bitmap_width, bitmap_height,
                    x*bitmap_width, y*bitmap_height,
                    1);
	  XSync(d, False);
    }
}
