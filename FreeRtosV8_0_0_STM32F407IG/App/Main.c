/**********************************************************************************************************
*	                                  
*	模块名称 : 主函数
*	文件名称 : main.c
*	版    本 : V1.0
*	说    明 : 硬件驱动初始化
*	修改记录 :
*		版本号    日期        作者      说明
*		v1.0    2013-09-10    yjwpm   创建该文件，ST固件库版本为V1.3.0
*
*		
*		
**********************************************************************************************************/
#include "bsp.h"

//堆栈大小定义
#define  AppTaskUpdateStk       500u
#define  AppTaskCOMStk          500u
#define  AppTaskUserIFStk       500u
#define  AppTaskGUIStk          1000u
#define  AppTaskGUIRefreshStk   500u
//任务优先级定义
#define  APP_CFG_TASK_UPDATE_PRIO        3u
#define  APP_CFG_TASK_COM_PRIO           4u
#define  APP_CFG_TASK_USER_IF_PRIO       5u
#define  APP_CFG_TASK_GUI_PRIO           10u
#define  APP_CFG_TASK_GUIRefresh_PRIO    11u

/*
*********************************************************************************************************
*	函 数 名: AppTaskGUIUpdate
*	功能说明: LED闪烁		
*	形    参：pvParameters 是在创建该任务时传递的形参
*	返 回 值: 无
*********************************************************************************************************
*/
void AppTaskGUIUpdate( void *pvParameters )
{
    while(1)
    {
				bsp_LedToggle(1);
				vTaskDelay( 2000 );
    }
}
/**********************************************************************************************************
*	函 数 名: AppTaskCOM
*	功能说明: LED闪烁		
*	形    参：pvParameters 是在创建该任务时传递的形参
*	返 回 值: 无
**********************************************************************************************************/
void AppTaskCOM( void *pvParameters )
{

    while(1)
    {
				bsp_LedToggle(2);
				vTaskDelay( 500 );
    }
}

/**********************************************************************************************************
*	函 数 名: AppTaskUserIF
*	功能说明: LED闪烁		
*	形    参：pvParameters 是在创建该任务时传递的形参
*	返 回 值: 无
**********************************************************************************************************/
void AppTaskUserIF( void *pvParameters )
{

    while(1)
    {
				bsp_LedToggle(3);
			  vTaskDelay( 200 );
    }
}

/**********************************************************************************************************
*	函 数 名: AppTaskGUI
*	功能说明: LED闪烁		
*	形    参：pvParameters 是在创建该任务时传递的形参
*	返 回 值: 无
**********************************************************************************************************/
void AppTaskGUI( void *pvParameters )
{

    while(1)
    {
				bsp_LedToggle(4);
			  vTaskDelay( 100 );
    }
}

/**********************************************************************************************************
*	函 数 名: AppTaskGUI
*	功能说明: LED闪烁		
*	形    参：pvParameters 是在创建该任务时传递的形参
*	返 回 值: 无
**********************************************************************************************************/
void AppTaskGUIRefresh( void *pvParameters )
{

    while(1)
    {
				vTaskDelay( 20 );
    }
}
/**********************************************************************************************************
*	函 数 名: AppTaskCreate
*	功能说明: 创建应用任务
*	形    参：无
*	返 回 值: 无
**********************************************************************************************************/
static void AppTaskCreate (void)
{
	/* Create one task. */
    xTaskCreate(    AppTaskGUIUpdate,         /* Pointer to the function that implements the task.              */
                    "App Task Update",        /* Text name for the task.  This is to facilitate debugging only. */
                    AppTaskUpdateStk,         /* Stack depth in words.                                          */
                    NULL,                     /* We are not using the task parameter.                           */
                    APP_CFG_TASK_UPDATE_PRIO, /* This task will run at priority 1.                              */
                    NULL );                   /* We are not using the task handle.                              */	
	
	/* Create one task. */
    xTaskCreate(    AppTaskCOM,               /* Pointer to the function that implements the task.              */
                    "App Task COM",           /* Text name for the task.  This is to facilitate debugging only. */
                    AppTaskCOMStk,            /* Stack depth in words.                                          */
                    NULL,                     /* We are not using the task parameter.                           */
                    APP_CFG_TASK_COM_PRIO,    /* This task will run at priority 1.                              */
                    NULL );                   /* We are not using the task handle.                              */	

	/* Create one task. */
    xTaskCreate(    AppTaskUserIF,               /* Pointer to the function that implements the task.              */
                    "App Task UserIF",           /* Text name for the task.  This is to facilitate debugging only. */
                    AppTaskUserIFStk,            /* Stack depth in words.                                          */
                    NULL,                        /* We are not using the task parameter.                           */
                    APP_CFG_TASK_USER_IF_PRIO,   /* This task will run at priority 1.                              */
                    NULL );   

	/* Create one task. */
    xTaskCreate(    AppTaskGUI,               /* Pointer to the function that implements the task.              */
                    "App Task GUI",           /* Text name for the task.  This is to facilitate debugging only. */
                    AppTaskGUIStk,            /* Stack depth in words.                                          */
                    NULL,                     /* We are not using the task parameter.                           */
                    APP_CFG_TASK_GUI_PRIO,    /* This task will run at priority 1.                              */
                    NULL );   
										
	/* Create one task. */
    xTaskCreate(    AppTaskGUIRefresh,             /* Pointer to the function that implements the task.              */
                    "App Task GUIRefresh",         /* Text name for the task.  This is to facilitate debugging only. */
                    AppTaskGUIRefreshStk,          /* Stack depth in words.                                          */
                    NULL,                          /* We are not using the task parameter.                           */
                    APP_CFG_TASK_GUIRefresh_PRIO,  /* This task will run at priority 1.                              */
                    NULL );  										
}

/**********************************************************************************************************
*	函 数 名: AppTaskObject
*	功能说明: 创建应用任务
*	形    参：无
*	返 回 值: 无
**********************************************************************************************************/
static void AppTaskObject (void)
{ 
  
}
/**********************************************************************************************************
*	函 数 名: main
*	功能说明: 标准c程序入口。
*	形    参：无
*	返 回 值: 无
**********************************************************************************************************/
int main(void)
{
		bsp_Init();/* 硬件初始化 */

		/* 创建任务 */
		AppTaskCreate();

		/* 创建*/
		AppTaskObject();

		/* 启动调度，开始执行任务 */
		vTaskStartScheduler();
	
	  while(1)
	  {
		 
	  }
}

/**********************************************************************************************************/
