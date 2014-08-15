/**********************************************************************************************************
*	                                  
*	ģ������ : ������
*	�ļ����� : main.c
*	��    �� : V1.0
*	˵    �� : Ӳ��������ʼ��
*	�޸ļ�¼ :
*		�汾��    ����        ����      ˵��
*		v1.0    2013-09-10    yjwpm   �������ļ���ST�̼���汾ΪV1.3.0
*
*		
*		
**********************************************************************************************************/
#include "bsp.h"

//��ջ��С����
#define  AppTaskUpdateStk       500u
#define  AppTaskCOMStk          500u
#define  AppTaskUserIFStk       500u
#define  AppTaskGUIStk          1000u
#define  AppTaskGUIRefreshStk   500u
//�������ȼ�����
#define  APP_CFG_TASK_UPDATE_PRIO        3u
#define  APP_CFG_TASK_COM_PRIO           4u
#define  APP_CFG_TASK_USER_IF_PRIO       5u
#define  APP_CFG_TASK_GUI_PRIO           10u
#define  APP_CFG_TASK_GUIRefresh_PRIO    11u

/*
*********************************************************************************************************
*	�� �� ��: AppTaskGUIUpdate
*	����˵��: LED��˸		
*	��    �Σ�pvParameters ���ڴ���������ʱ���ݵ��β�
*	�� �� ֵ: ��
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
*	�� �� ��: AppTaskCOM
*	����˵��: LED��˸		
*	��    �Σ�pvParameters ���ڴ���������ʱ���ݵ��β�
*	�� �� ֵ: ��
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
*	�� �� ��: AppTaskUserIF
*	����˵��: LED��˸		
*	��    �Σ�pvParameters ���ڴ���������ʱ���ݵ��β�
*	�� �� ֵ: ��
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
*	�� �� ��: AppTaskGUI
*	����˵��: LED��˸		
*	��    �Σ�pvParameters ���ڴ���������ʱ���ݵ��β�
*	�� �� ֵ: ��
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
*	�� �� ��: AppTaskGUI
*	����˵��: LED��˸		
*	��    �Σ�pvParameters ���ڴ���������ʱ���ݵ��β�
*	�� �� ֵ: ��
**********************************************************************************************************/
void AppTaskGUIRefresh( void *pvParameters )
{

    while(1)
    {
				vTaskDelay( 20 );
    }
}
/**********************************************************************************************************
*	�� �� ��: AppTaskCreate
*	����˵��: ����Ӧ������
*	��    �Σ���
*	�� �� ֵ: ��
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
*	�� �� ��: AppTaskObject
*	����˵��: ����Ӧ������
*	��    �Σ���
*	�� �� ֵ: ��
**********************************************************************************************************/
static void AppTaskObject (void)
{ 
  
}
/**********************************************************************************************************
*	�� �� ��: main
*	����˵��: ��׼c������ڡ�
*	��    �Σ���
*	�� �� ֵ: ��
**********************************************************************************************************/
int main(void)
{
		bsp_Init();/* Ӳ����ʼ�� */

		/* �������� */
		AppTaskCreate();

		/* ����*/
		AppTaskObject();

		/* �������ȣ���ʼִ������ */
		vTaskStartScheduler();
	
	  while(1)
	  {
		 
	  }
}

/**********************************************************************************************************/
