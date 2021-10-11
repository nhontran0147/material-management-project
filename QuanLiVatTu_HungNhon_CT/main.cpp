#include "DoHoa.h"
int main(int argc, char *argv[]){
	DrawWin();
	DrawLogIn();
	LogIn();
	while(!kbhit()) delay(1);		// pause screen	
	return 0;
}
