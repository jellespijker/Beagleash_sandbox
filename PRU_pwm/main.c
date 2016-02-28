/***************************************************************************************
 * MAIN.C
 *
 * Description: main source file for PRU development
 *
 * Rafael de Souza
 * (C) 2015 Texas Instruments, Inc
 * 
 * Built with Code Composer Studio v6
 **************************************************************************************/

#include <stdint.h>
#include <pru_cfg.h>
#include <pru_ctrl.h>
#include "resource_table_empty.h"

volatile register uint32_t __R30;
volatile register uint32_t __R31;

void setPin(register uint32_t) {

}

int main(void) {
	/* Clear SYSCFG[STANDBY_INIT] to enable OCP master port */
	CT_CFG.SYSCFG_bit.STANDBY_INIT = 0;

	/* TODO: Create stop condition, else it will toggle indefinitely */
	while(1){
		__R30 ^= 1 << 1;
		__delay_cycles(100000000);
	}

	/* Halt the PRU core */
	__halt();
	
	/* Should never return */
	return 0;
}
