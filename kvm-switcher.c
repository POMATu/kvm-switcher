#include <stdio.h>
#include <X11/Xlib.h>

int main(void) {  
   Display *dpy = XOpenDisplay(":0"); 
   XKeyboardState x;
   XGetKeyboardControl(dpy, &x);
   XCloseDisplay(dpy);
//   printf("led_mask=%lx\n", x.led_mask);
if (x.led_mask & 4) {
system("xset -led named \"Scroll Lock\"");
} else {
system("xset led named \"Scroll Lock\"");
}
printf("%s\n", (x.led_mask & 4) ? "on" : "off");
   return 0;
}
