#include<iostream.h>
#include<conio.h>

void main() {
	int key = 0;
        char keys;
        while(key!=27) {
        	key = getch();
                keys = key;
                cout<<key<<" = "<<keys<<endl;
        }
}