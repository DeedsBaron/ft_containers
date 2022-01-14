#include <stdio.h>


typedef struct s_abc{
	int a;
	int b;

}			 t_abc;

int*			SingletonInt() {
	static int instance;
	return &instance;
}


int main(void) {
	int 			a[5] = {0, 1 ,2, 3, 4};
	int				**mas = &a;
	return 0;
}
