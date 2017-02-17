#include "include.h"

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern UART_HandleTypeDef huart2;
void UsartReceive_IDLE(UART_HandleTypeDef *huart)  
{
	if(huart == &huart1)
	  	{
		    if((__HAL_UART_GET_FLAG(huart,UART_FLAG_IDLE) != RESET))  
		    {   
		        __HAL_UART_CLEAR_IDLEFLAG(&huart1);  
			data_from_wifi.dma_cndtr = huart1.hdmarx->Instance->NDTR; 
			HAL_TIM_Base_Start_IT(&htim3);
		    }  
	  	}
	
	if(huart == &huart2)
	  	{
		    if((__HAL_UART_GET_FLAG(huart,UART_FLAG_IDLE) != RESET))  
		    {   
		        __HAL_UART_CLEAR_IDLEFLAG(&huart2);  
			data_from_tcm300.dma_cndtr = huart2.hdmarx->Instance->NDTR; 
			HAL_TIM_Base_Start_IT(&htim2);
		    }  
	  	}
}



