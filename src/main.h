#define E_DEFAULT 0
#define E_SYNTAX 1
#define E_UNDEFINED 2

#define BASE_GOOGLE "google-chrome \"https://www.google.co.kr/search?q="
char help_man[] = "usage: qs [option]\nOptions and Comments\ngoogle: search with google-chrome commands, Usage: qs google \"King-God PHP\".\ncalc: execute gnome-calculator in few seconds.\nhelp: print the manual for how to use.";

typedef const char* String;

int throwError(int flags,String format, ...);
void printColor(int code);
void throwUsage(String str);

int throwError(int flags,String format, ...) {
   va_list arg;
   int done;

   va_start (arg, format);
   flags==E_DEFAULT ? printColor(33) : printColor(41);
   done = vfprintf (stdout, format, arg);
   printColor(0);
   va_end (arg);

   return done;
}
void printColor(int code) {
	printf("\x1b[%d;1m",code);
}
void throwUsage(String str) {
	throwError(E_DEFAULT,"Usage: %s help\n",str);
}