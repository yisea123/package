#include "bsp_config.h"
#include "exiq.h"

#ifdef  FPGA
//�弶Ӳ����ʼ��
void bsp_init()
{
	FSMC_FPGA_Init();
    USB_Mass_Init();
    gp_io_init();
    Adc_Init();
    Dac_Init();
    pwr_init();
    RTC_Init();
    EnCode_Init();
    Puls_Init();
    Led_Init();
    SysTim_Init();
    Can_Init(500);
    Uart_Init(DB485_SN,uart_sendbuf[0],uart_recvbuf[0],300,19200,30);
    Uart_Init(DB232_SN,uart_sendbuf[1],uart_recvbuf[1],300,19200,30);
    Eth_SetRmt(192,168,1,100,8089);
    Eth_SetLoc(192,168,1,32,8089);
		while(lwip_comm_init()!=0)
		{
		}
    Eth_Init(eth_rxbuf,sizeof(eth_rxbuf));
}
void bsp_exec()
{     
	//USART1�շ�
    UART_exeu();
    //��̫����ѯ
    Eth_excu();
    USB_Mass_exec();
    pwr_exec();
    EnCode_Exec();
    Led_Exec();
//    EXIQ();
    FSMC_FPGA_Exec();
}
#endif

#ifdef ARM
void bsp_init()
{
    USB_Mass_Init();
    gp_io_init();
    Adc_Init();
    Dac_Init();
    pwr_init();
//    RTC_Init();
    EnCode_Init();
    Puls_Init();
    Led_Init();
    SysTim_Init();
    Can_Init(500);
    Uart_Init(DB485_SN,uart_sendbuf[0],uart_recvbuf[0],300,19200,30);
    Uart_Init(DB232_SN,uart_sendbuf[1],uart_recvbuf[1],300,19200,30);
	  Eth_SetRmt(192,168,1,100,8089);
    Eth_SetLoc(192,168,1,32,8089);
		while(lwip_comm_init()!=0)
		{
		}
    Eth_Init(eth_rxbuf,sizeof(eth_rxbuf));
}
void bsp_exec()
{     
	//USART1�շ�
    UART_exeu();
    //��̫����ѯ
    Eth_excu();
    USB_Mass_exec();
    pwr_exec();
    EnCode_Exec();
    Led_Exec();
		IAP_Loop();
//    EXIQ();
}
#endif

#ifdef OLDVERSION
void bsp_init()
{
//    USB_Mass_Init();
    gp_io_init();
//    Adc_Init();
//    Dac_Init();
    pwr_init();
    RTC_Init();
    EnCode_Init();
    Puls_Init();
//    Led_Init();
    SysTim_Init();
    Can_Init(500);
    Uart_Init(DB485_SN,uart_sendbuf[0],uart_recvbuf[0],300,19200,30);
    Uart_Init(DB232_SN,uart_sendbuf[1],uart_recvbuf[1],300,19200,30);
    Eth_SetRmt(192,168,1,100,8089);
    Eth_SetLoc(192,168,1,30,8089);
    Eth_Init(eth_rxbuf,sizeof(eth_rxbuf));
}
void bsp_exec()
{     
	//USART1�շ�
    UART_exeu();
    //��̫����ѯ
    Eth_excu();
//    USB_Mass_exec();
    pwr_exec();
//    EnCode_Exec();
//    Led_Exec();
//    EXIQ();
}
#endif
