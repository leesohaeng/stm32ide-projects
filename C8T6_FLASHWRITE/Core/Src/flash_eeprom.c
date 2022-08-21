/*
 * flash_eeprom.c
 *
 *  Created on: 2018. 11. 11.
 *      Author: TestParts
 */

#include "flash_eeprom.h"
// #include "stm32f1xx_hal_flash_ex.h"


// �����͸� ���� �������ؼ��� ���� ������ ������ �޸𸮸� ���� ��� �մϴ�.
static FLASH_EraseInitTypeDef EraseInitStruct;
static uint32_t PAGEError;

void flash_memory_Init(void)
{
	EraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGES;  //0x00
	EraseInitStruct.PageAddress = FLASH_USER_START_ADDR;  // ����� �������� ���� ��巹��
	EraseInitStruct.NbPages     = (FLASH_USER_END_ADDR - FLASH_USER_START_ADDR) / FLASH_PAGE_SIZE; //���� ������ ��
}

void flash_memory_erase(void)
{
	//Flash�޸𸮸� ���� �� �� �ֵ��� ���� Ǯ�� �ݴϴ�.
	HAL_FLASH_Unlock();

	//������ ����⿡ �����ϸ� ���ѷ����� ������ �Ͽ� ����� ���۵��� �����մϴ�.
	if (HAL_FLASHEx_Erase(&EraseInitStruct, &PAGEError) != HAL_OK) {
		printf("Eraser Error\r\n");
		while(1);
	}
}

void flash_memory_write(void)
{
	uint32_t test = 0xABCDEF00;

	 /////////������ ������ �������� ������ ���� ////////////////////////////////////////////////////
	 //HAL_StatusTypeDef HAL_FLASH_Program(uint32_t TypeProgram, uint32_t Address, uint64_t Data)

    for(int m=0;m<64;m++)
	for(int n=0;n<256;n++)
	{
	  while (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, USER_DATA1+(0x400*m)+(4*n), ((uint32_t)test)) != HAL_OK);
	}

	  /*
	  while (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, USER_DATA2, ((uint32_t)0x11111111)) != HAL_OK){
		  //printf("Write Error\r\n");
	  }
	  while (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, USER_DATA3, ((uint32_t)0x22222222)) != HAL_OK){
		  //printf("Write Error\r\n");
	  }
	  while (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, USER_DATA4, ((uint32_t)0x33333333)) != HAL_OK){
		  //printf("Write Error\r\n");
	  } */

	 HAL_FLASH_Lock();
}

void flash_memory_read(void)
{
	///////////////�޸𸮿��� ������ �б�////////////////////////////////////////////////////////////
	printf("Addr = %X, Data = %d\r\n", USER_DATA1, *(__IO uint32_t *)USER_DATA1);
	printf("Addr = %X, Data = %d\r\n", USER_DATA2, *(__IO uint32_t *)USER_DATA2);
	printf("Addr = %X, Data = %d\r\n", USER_DATA3, *(__IO uint32_t *)USER_DATA3);
	printf("Addr = %X, Data = %d\r\n", USER_DATA4, *(__IO uint32_t *)USER_DATA4);
	///////////////////////////////////////////////////////////////////////////////////////////////////
}


