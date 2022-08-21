/*
 * flash_eeprom.h
 *
 *  Created on: 2018. 11. 11.
 *      Author: TestParts
 */

#ifndef FLASH_EEPROM_H_
#define FLASH_EEPROM_H_

#include "stm32f1xx_hal.h"
//#include "stm32f1xx_hal_flash.h"

// low(LD),medium(MD) density�� ���� 1KB, High(HD) density�� 2KB ������.
// STM32F1xx�� �޸� �����Դϴ�.

#define ADDR_FLASH_PAGE_63     ((uint32_t)0x0800FC00) /* Base @ of Page 63,  1 Kbyte */

#define ADDR_FLASH_PAGE_64     ((uint32_t)0x08010000) /* Base @ of Page 64,  1 Kbyte */
#define ADDR_FLASH_PAGE_65     ((uint32_t)0x08010400) /* Base @ of Page 65,  1 Kbyte */

#define ADDR_FLASH_PAGE_127    ((uint32_t)0x0801FC00) /* Base @ of Page 127,  1 Kbyte */


// ��� �� ���� �ּҸ� ������ �� �˴ϴ�..
// ADDR_FLASH_PAGE_64,    ADDR_FLASH_PAGE_127
#define FLASH_USER_START_ADDR   ADDR_FLASH_PAGE_64  /* Start @ of user Flash area */
#define FLASH_USER_END_ADDR     ADDR_FLASH_PAGE_127 + FLASH_PAGE_SIZE   /* End @ of user Flash area */


// �׸��� Flash memory�� ������ ����� �����͸� ���� �մϴ�.  ���������� 4byte ������ ����ϱ� ���� ��巹���� 4byte������ �������׽��ϴ�.

#define USER_DATA1     (FLASH_USER_START_ADDR)
#define USER_DATA2     (FLASH_USER_START_ADDR + 4)
#define USER_DATA3     (FLASH_USER_START_ADDR + 8)
#define USER_DATA4     (FLASH_USER_START_ADDR + 12)

// ������ ������ ����� �ֵ��� ����ü������ ������ �ְ� ������������� �����ݴϴ�.

void flash_memory_Init(void);
void flash_memory_erase(void);
void flash_memory_write(void);
void flash_memory_read(void);


#endif /* FLASH_EEPROM_H_ */

