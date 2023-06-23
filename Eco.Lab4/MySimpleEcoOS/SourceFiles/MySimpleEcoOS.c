/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   EcoVFB1
 * </сводка>
 *
 * <описание>
 *   Данный исходный файл является точкой входа
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */


/* Eco OS */
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoMemoryManager1Lab.h"
#include "IEcoVirtualMemory1.h"
#include "IEcoTaskScheduler1.h"
#include "IdEcoTaskScheduler1Lab.h"
#include "IdEcoTimer1.h"
#include "IEcoTaskPriority1.h"
#include "IEcoSystemTimer1.h"
#include "IdEcoInterfaceBus1.h"
#include "IdEcoFileSystemManagement1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "IdEcoIPCCMailbox1.h"
#include "IdEcoVFB1.h"
#include "IdBubleSort.h"
#include "IdEcoString1.h"

/* Начало свободного участка памяти */
extern char_t __heap_start__;

/* Указатель на интерфейсы */
IEcoVFB1* g_pIVFB = 0;
IEcoSystemTimer1* g_pISysTimer = 0;

char_t g_strTask[2] = {0};


IBubleSort* pIBubleSort = 0;
IEcoString1* pIEcoString = 0;


void TimerHandler(void) {
    if (g_strTask[0] == '\\') {
        g_strTask[0] = '|';
    }
    else if (g_strTask[0] == '|') {
        g_strTask[0] = '/';
    }
    else if (g_strTask[0] == '/') {
        g_strTask[0] = '-';
    }
    else  {
        g_strTask[0] = '\\';
    }
}

void printProgress() {
    if (g_strTask[0] == '\\') {
        g_strTask[0] = '|';
    }
    else if (g_strTask[0] == '|') {
        g_strTask[0] = '/';
    }
    else if (g_strTask[0] == '/') {
        g_strTask[0] = '-';
    }
    else  {
        g_strTask[0] = '\\';
    }
    g_pIVFB->pVTbl->WriteString(g_pIVFB, 0, 0, 1, 0, CHARACTER_ATTRIBUTE_FORE_COLOR_WHITTE, g_strTask, 1);
}

int ECOCDECLMETHOD comparatori(const void * a, const void * b) { 
	int32_t data1 = *(int32_t *)a; 
	int32_t data2 = *(int32_t *)b;
    if (data1 > data2)
		return 1;
	else
		return 0;
}

int ECOCDECLMETHOD comparatord(const void * a, const void * b) { 
    double_t data1 = *(double_t *)a; 
	double_t data2 = *(double_t *)b;
    if (data1 > data2)
		return 1;
	else
		return 0;
}

int ECOCDECLMETHOD comparatorc(const void * a, const void * b) { 
    char_t data1 = *(char_t *)a; 
	char_t data2 = *(char_t *)b;
    if (data1 > data2)
		return 1;
	else
		return 0;
}

void Task1() {
	int32_t arr_int[30] = {99, -2, 76, 96, -68, 36, -26, -21, 34, 52, 59, 85, 6, 75, -70, -92, -77, 70, -65, -3, 53, 100, 94, 84, -53, -95, 89, -20, -31, -10};
	int16_t size = 30;
	uint64_t currentTime = g_pISysTimer->pVTbl->get_SingleTimerCounter(g_pISysTimer);
    uint64_t endTime = currentTime +  5000000ul;
    uint64_t changeTime = currentTime;
	char_t* char_from_int = 0;
	int16_t i = 0;
    
	g_pIVFB->pVTbl->WriteString(g_pIVFB, 0, 0, 0, 0, CHARACTER_ATTRIBUTE_FORE_COLOR_WHITTE, "1", 1);

	pIBubleSort->pVTbl->MyFunction(pIBubleSort, arr_int, size, sizeof(int32_t), comparatori);
    
    while ( endTime >= currentTime) {
        if (changeTime >= currentTime) {
            printProgress();
            changeTime += 50000ul;
        }
        currentTime = g_pISysTimer->pVTbl->get_SingleTimerCounter(g_pISysTimer);
    }
    
    for (i = 0; i < size; i++) {
		char_from_int = pIEcoString->pVTbl->ConvertIntToString(pIEcoString, arr_int[i]);
		g_pIVFB->pVTbl->WriteString(g_pIVFB, 0, 0, 30, i, CHARACTER_ATTRIBUTE_FORE_COLOR_WHITTE, char_from_int, 3);
	}
}

void Task2() {
	double_t arr_double[30] = {23.3083,70.2118,62.8812,16.4437,83.6103,48.9525,90.3603,70.3762,32.91,82.8918,81.0752,27.7077,97.2646,66.1746,80.7059,96.3442,93.0083,53.4421,28.3258,5.9416,70.6301,94.3844,50.879,90.7564,68.1696,28.374,69.9686,7.4785,35.6852,50.1796};
	int16_t size = 30;
	uint64_t currentTime = g_pISysTimer->pVTbl->get_SingleTimerCounter(g_pISysTimer);
    uint64_t endTime = currentTime +  5000000ul;
    uint64_t changeTime = currentTime;

	pIBubleSort->pVTbl->MyFunction(pIBubleSort, arr_double, size, sizeof(double_t), comparatord);
    g_pIVFB->pVTbl->WriteString(g_pIVFB, 0, 0, 0, 0, CHARACTER_ATTRIBUTE_FORE_COLOR_WHITTE, "2", 1);
    while ( endTime >= currentTime) {
        if (changeTime >= currentTime) {
           printProgress();
            changeTime += 50000ul;
        }
        currentTime = g_pISysTimer->pVTbl->get_SingleTimerCounter(g_pISysTimer);
    }
}

void Task3() {
	char_t arr_char[60] = {'J','S','B','9','b','C','Z','c','Z','K','W','D','f','m','U','3','5','a','e','c','Q','q','Y','t','d','7','p','j','g','f', 'J','S','B','9','b','C','Z','c','Z','K','W','D','f','m','U','3','5','a','e','c','Q','q','Y','t','d','7','p','j','g','f'};
	int16_t size = 60;
	uint64_t currentTime = g_pISysTimer->pVTbl->get_SingleTimerCounter(g_pISysTimer);
    uint64_t endTime = currentTime +  5000000ul;
    uint64_t changeTime = currentTime;
	int16_t i = 0;

	g_pIVFB->pVTbl->WriteString(g_pIVFB, 0, 0, 0, 0, CHARACTER_ATTRIBUTE_FORE_COLOR_WHITTE, "3", 1);

	pIBubleSort->pVTbl->MyFunction(pIBubleSort, arr_char, size, sizeof(char_t), comparatorc);
	
    while ( endTime >= currentTime) {
        if (changeTime >= currentTime) {
            printProgress();
            changeTime += 50000ul;
        }
        currentTime = g_pISysTimer->pVTbl->get_SingleTimerCounter(g_pISysTimer);
    }

    for (i = 0; i < size; i++){
		g_pIVFB->pVTbl->WriteString(g_pIVFB, 0, 0, 20, i, CHARACTER_ATTRIBUTE_FORE_COLOR_WHITTE, arr_char + i, 1);
	}
    
}

/*
 *
 * <сводка>
 *   Функция EcoMain
 * </сводка>
 *
 * <описание>
 *   Функция EcoMain - точка входа
 * </описание>
 *
 */
int16_t EcoMain(IEcoUnknown* pIUnk) {
    int16_t result = -1;
    /* Указатель на системный интерфейс */
    IEcoSystem1* pISys = 0;
    /* Указатель на интерфейс работы с системной интерфейсной шиной */
    IEcoInterfaceBus1* pIBus = 0;
    /* Указатель на интерфейс работы с памятью */
    IEcoMemoryAllocator1* pIMem = 0;
    IEcoMemoryManager1* pIMemMgr = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoVirtualMemory1* pIVrtMem = 0;
    /* Указатель на интерфейс для работы с планировщиком */
    IEcoTaskScheduler1* pIScheduler = 0;
	IEcoTaskPriority1* pIPriority = 0;
    IEcoTask1* pITask1 = 0;
    IEcoTask1* pITask2 = 0;
    IEcoTask1* pITask3 = 0;
    /* Указатель на интерфейс для работы c буфером кадров видеоустройства */
    IEcoVFB1* pIVFB = 0;
    /* Указатель на интерфейс для работы c системным таймером */
    IEcoSystemTimer1* pISysTimer = 0;
    /* Указатель на интерфейс для работы c таймером */
    IEcoTimer1* pITimer = 0;

	
    char_t* strHello = "Hello, World!";
    uint16_t offset = 0;
    uint16_t x1 = 0;
    uint16_t y1 = 32;
    uint16_t x2 = 70;
    byte_t color = 170; /* 3-3-2 bit RGB */

    /* Создание экземпляра интерфейсной шины */
    result = GetIEcoComponentFactoryPtr_00000000000000000000000042757331->pVTbl->Alloc(GetIEcoComponentFactoryPtr_00000000000000000000000042757331, 0, 0, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    /* Проверка */
    if (result != 0 && pIBus == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Регистрация статического компонента для работы с памятью */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoMemoryManager1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_0000000000000000000000004D656D31);
    //result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoMemoryManager1Lab, (IEcoUnknown*)GetIEcoComponentFactoryPtr_81589BFED0B84B1194524BEE623E1838);
    /* Проверка */
    if (result != 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Регистрация статического компонента для работы с ящиком прошивки */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoIPCCMailbox1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_F10BC39A4F2143CF8A1E104650A2C302);
    /* Проверка */
    if (result != 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Запрос расширения интерфейсной шины */
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void**)&pIMemExt);
    if (result == 0 && pIMemExt != 0) {
        /* Установка расширения менаджера памяти */
        pIMemExt->pVTbl->set_Manager(pIMemExt, &CID_EcoMemoryManager1);
      //  pIMemExt->pVTbl->set_Manager(pIMemExt, &CID_EcoMemoryManager1Lab);
        /* Установка разрешения расширения пула */
        pIMemExt->pVTbl->set_ExpandPool(pIMemExt, 1);
    }

    /* Получение интерфейса управления памятью */
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryManager1, (void**) &pIMemMgr);
    //pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1Lab, 0, &IID_IEcoMemoryManager1, (void**) &pIMemMgr);
    if (result != 0 || pIMemMgr == 0) {
        /* Возврат в случае ошибки */
        return result;
    }

    /* Выделение области памяти 512 КБ */
    pIMemMgr->pVTbl->Init(pIMemMgr, &__heap_start__, 0x080000);

    
    /* Регистрация статического компонента для работы с планировщиком */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoTaskScheduler1Lab, (IEcoUnknown*)GetIEcoComponentFactoryPtr_902ABA722D34417BB714322CC761620F);
    /* Проверка */
    if (result != 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

	/* Регистрация статического компонента для Bubble sort */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_BubleSort, (IEcoUnknown*)GetIEcoComponentFactoryPtr_680786EC2FB742F2A3C6C9D4B4ED74BE);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

	/* Регистрация статического компонента для IEcoString */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoString1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_84CC0A7DBABD44EEBE749C9A8312D37E);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Регистрация статического компонента для работы с таймером */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoTimer1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_8DB93F3DF5B947D4A67F7C100B569723);
    /* Проверка */
    if (result != 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Регистрация статического компонента для работы с VBF */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoVFB1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_939B1DCDB6404F7D9C072291AF252188);
    /* Проверка */
    if (result != 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Получение интерфейса для работы с планировщиком */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoTaskScheduler1Lab, 0, &IID_IEcoTaskScheduler1, (void**) &pIScheduler);
    /* Проверка */
    if (result != 0 || pIScheduler == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

	/* Получение интерфейса для BubbleSort */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_BubleSort, 0, &IID_IBubleSort, (void**) &pIBubleSort);
    if (result != 0 || pIBubleSort == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

	/* Получение интерфейса для IEcoString */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoString1, 0, &IID_IEcoString1, (void**) &pIEcoString);
    if (result != 0 || pIEcoString == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    /* Инициализация */
    pIScheduler->pVTbl->InitWith(pIScheduler, pIBus, &__heap_start__+0x090000, 0x080000);

    /* Создание статических задач */
    pIScheduler->pVTbl->NewTask(pIScheduler, Task1, 0, 0x100, &pITask1);
    pIScheduler->pVTbl->NewTask(pIScheduler, Task2, 0, 0x100, &pITask2);
    pIScheduler->pVTbl->NewTask(pIScheduler, Task3, 0, 0x100, &pITask3);
    
    pITask1->pVTbl->SetId(pITask1, 1);
    pITask1->pVTbl->SetId(pITask2, 2);
    pITask1->pVTbl->SetId(pITask3, 3);
    
    pITask1->pVTbl->SetDeadline(pITask1, 300);
    pITask1->pVTbl->SetDeadline(pITask2, 200);
    pITask1->pVTbl->SetDeadline(pITask3, 100);

    /* Получение интерфейса для работы с системным таймером */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoTimer1, 0, &IID_IEcoSystemTimer1, (void**) &pISysTimer);
    /* Проверка */
    if (result != 0 || pISysTimer == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    g_pISysTimer = pISysTimer;

    /* Установка обработчика прерывания программируемого таймера */
    result = pISysTimer->pVTbl->QueryInterface(pISysTimer, &IID_IEcoTimer1, (void**)&pITimer);
    /* Проверка */
    if (result != 0 || pITimer == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    pITimer->pVTbl->set_Interval(pITimer, 100000);
    pITimer->pVTbl->set_IrqHandler(pITimer, TimerHandler);
    pITimer->pVTbl->Start(pITimer);

    /* Получение интерфейса для работы с видео сервисами VBF */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoVFB1, 0, &IID_IEcoVFB1, (void**) &pIVFB);
    /* Проверка */
    if (result != 0 || pIVFB == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Вывод 1 строки "Эко ОС!!!" - кодовая страница 1251 */
    pIVFB->pVTbl->WriteString(pIVFB, 0, 0, 0, 1, CHARACTER_ATTRIBUTE_FORE_COLOR_YELLOW, "\xdd\xea\xee\x20\xce\xd1\x21\x21\x21", 9);

    /* Рисуем линию - подчеркивание */
    for (offset = x1; offset <= x2; offset++) {
        pIVFB->pVTbl->set_ColorPixel(pIVFB, color, offset, y1);
    }

    /* Вывод 4 строки "Привет Мир!" */
    //pIVFB->pVTbl->WriteString(pIVFB, 0, 0, 4, 4, CHARACTER_ATTRIBUTE_FORE_COLOR_GREEN, "\xcf\xf0\xe8\xe2\xe5\xf2\x20\xcc\xe8\xf0\x21", 11);
    //pIVFB->pVTbl->WriteString(pIVFB, 0, 0, 4, 5, CHARACTER_ATTRIBUTE_FORE_COLOR_WHITTE, strHello, 13);
    g_pIVFB = pIVFB;
    pIScheduler->pVTbl->Start(pIScheduler);

    while(1) {
        asm volatile ("NOP\n\t" ::: "memory");
    }

Release:

    /* Освобождение интерфейса для работы с интерфейсной шиной */
    if (pIBus != 0) {
        pIBus->pVTbl->Release(pIBus);
    }

    /* Освобождение интерфейса работы с памятью */
    if (pIMem != 0) {
        pIMem->pVTbl->Release(pIMem);
    }

    /* Освобождение интерфейса VFB */
    if (pIVFB != 0) {
        pIVFB->pVTbl->Release(pIVFB);
    }

    /* Освобождение системного интерфейса */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}
