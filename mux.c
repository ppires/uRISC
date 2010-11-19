#include "mux.h"

Registrador mux4(Registrador opt1, Registrador opt2, Registrador opt3, Registrador opt4, int signal){
	Registrador array[] = {opt1, opt2, opt3, opt4};
	return array[signal];
}

Registrador mux2(Registrador opt1, Registrador opt2, int signal){
	Registrador array[] = {opt1, opt2};
	return array[signal];
}
