#include <stdio.h>
#include <stdafx.h>
extern "C"{
	int funcName();
	int __cdecl funcName1(int a, int b, int c);
}

int main(){
printf("%d", funcName());
getchar();
}

int __cdecl funcName1(int a, int b, int c){
	return a+b+c;}
